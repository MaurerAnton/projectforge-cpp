// ProjectForge C++ port - Logging Framework
#include "org/projectforge/common/Logging.hpp"
#include <spdlog/spdlog.h>
#include <nlohmann/json.hpp>
#include <chrono>
#include <sstream>
#include <queue>
#include <mutex>
#include <atomic>
#include <map>
#include <vector>
#include <functional>

namespace org::projectforge::common {

class LoggingConfig {
public:
    std::string level="info", filePath="logs/projectforge.log";
    int maxFileSizeMB=10, maxFiles=5;
    bool consoleOutput=true, fileOutput=true, jsonFormat=false;
    std::string pattern="[%Y-%m-%d %H:%M:%S.%e] [%^%l%$] [%n] %v";
};

class LogEvent {
public:
    std::string level, logger, message, threadName, file, function;
    int line=0;
    int64_t timestamp=0;
    nlohmann::json toJson() const {
        nlohmann::json j;
        j["timestamp"]=timestamp; j["level"]=level; j["logger"]=logger;
        j["message"]=message; j["thread"]=threadName;
        if(!file.empty()) { j["file"]=file; j["line"]=line; j["function"]=function; }
        return j;
    }
};

class LogQueue {
    std::queue<LogEvent> queue;
    mutable std::mutex mtx;
    std::atomic<int> dropped{0};
    int maxSize=10000;
public:
    void push(const LogEvent& e) {
        std::lock_guard<std::mutex> lk(mtx);
        if((int)queue.size()>=maxSize) { queue.pop(); dropped++; }
        queue.push(e);
    }
    std::vector<LogEvent> drain(int max=1000) {
        std::lock_guard<std::mutex> lk(mtx);
        std::vector<LogEvent> r;
        while(!queue.empty()&&(int)r.size()<max) { r.push_back(queue.front()); queue.pop(); }
        return r;
    }
    int getDroppedCount() const { return dropped; }
    size_t size() const { std::lock_guard<std::mutex> lk(mtx); return queue.size(); }
};

class LogFilter {
    std::vector<std::string> includedLoggers, excludedLoggers, includedLevels;
    int minLevel=0;
public:
    bool accept(const LogEvent& e) const {
        if(!includedLevels.empty()&&std::find(includedLevels.begin(),includedLevels.end(),e.level)==includedLevels.end()) return false;
        if(!includedLoggers.empty()&&std::find(includedLoggers.begin(),includedLoggers.end(),e.logger)==includedLoggers.end()) return false;
        if(!excludedLoggers.empty()&&std::find(excludedLoggers.begin(),excludedLoggers.end(),e.logger)!=excludedLoggers.end()) return false;
        return true;
    }
    void addIncludedLogger(const std::string& l) { includedLoggers.push_back(l); }
    void addExcludedLogger(const std::string& l) { excludedLoggers.push_back(l); }
};

class LogSubscription {
    std::function<void(const LogEvent&)> callback;
    LogFilter filter;
    bool active=true;
public:
    explicit LogSubscription(std::function<void(const LogEvent&)> cb) : callback(cb) {}
    void deliver(const LogEvent& e) { if(active&&filter.accept(e)) callback(e); }
    void setActive(bool a) { active=a; }
    LogFilter& getFilter() { return filter; }
};

class LogManager {
    std::vector<std::shared_ptr<LogSubscription>> subscriptions;
    mutable std::mutex mtx;
    LogQueue queue;
    LogFilter globalFilter;
public:
    static LogManager& instance() { static LogManager lm; return lm; }
    void subscribe(std::shared_ptr<LogSubscription> sub) { std::lock_guard<std::mutex> lk(mtx); subscriptions.push_back(sub); }
    void unsubscribe(std::shared_ptr<LogSubscription> sub) { std::lock_guard<std::mutex> lk(mtx); std::erase(subscriptions,sub); }
    void broadcast(const LogEvent& e) {
        std::lock_guard<std::mutex> lk(mtx);
        queue.push(e);
        for(auto& sub : subscriptions) sub->deliver(e);
    }
    LogQueue& getQueue() { return queue; }
    LogFilter& getGlobalFilter() { return globalFilter; }
};

class PerformanceProfiler {
    struct Entry {
        std::string name;
        int64_t startTime, duration;
        int callCount=0;
        int64_t totalDuration=0, minDuration=INT64_MAX, maxDuration=0;
    };
    std::map<std::string,Entry> entries;
    mutable std::mutex mtx;
public:
    void start(const std::string& name) {
        std::lock_guard<std::mutex> lk(mtx);
        entries[name].name=name;
        entries[name].startTime=std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now().time_since_epoch()).count();
    }
    void stop(const std::string& name) {
        std::lock_guard<std::mutex> lk(mtx);
        auto& e = entries[name];
        e.duration=std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now().time_since_epoch()).count()-e.startTime;
        e.callCount++;
        e.totalDuration+=e.duration;
        e.minDuration=std::min(e.minDuration,e.duration);
        e.maxDuration=std::max(e.maxDuration,e.duration);
    }
    nlohmann::json getReport() {
        std::lock_guard<std::mutex> lk(mtx);
        nlohmann::json r=nlohmann::json::array();
        for(auto& kv : entries) {
            auto& e = kv.second;
            nlohmann::json j;
            j["name"]=e.name; j["calls"]=e.callCount;
            j["totalMs"]=e.totalDuration/1000.0;
            j["avgMs"]=e.callCount>0?e.totalDuration/1000.0/e.callCount:0;
            j["minMs"]=e.minDuration/1000.0; j["maxMs"]=e.maxDuration/1000.0;
            r.push_back(j);
        }
        return r;
    }
    void reset() { std::lock_guard<std::mutex> lk(mtx); entries.clear(); }
};

class MemoryTracker {
    std::atomic<int64_t> allocatedBytes{0}, allocatedCount{0}, freedCount{0};
    std::map<std::string,int64_t> allocationsByCategory;
    mutable std::mutex mtx;
public:
    void trackAllocation(const std::string& cat, int64_t bytes) {
        allocatedBytes+=bytes; allocatedCount++;
        std::lock_guard<std::mutex> lk(mtx);
        allocationsByCategory[cat]+=bytes;
    }
    void trackFree(const std::string& cat, int64_t bytes) {
        allocatedBytes-=bytes; freedCount++;
        std::lock_guard<std::mutex> lk(mtx);
        allocationsByCategory[cat]-=bytes;
    }
    nlohmann::json getReport() {
        nlohmann::json r;
        r["allocatedBytes"]=allocatedBytes.load();
        r["allocatedMB"]=allocatedBytes/1048576.0;
        r["allocationCount"]=allocatedCount.load();
        r["freeCount"]=freedCount.load();
        nlohmann::json cats=nlohmann::json::array();
        std::lock_guard<std::mutex> lk(mtx);
        for(auto& kv : allocationsByCategory)
            if(kv.second>0) cats.push_back({{"category",kv.first},{"bytes",kv.second},{"mb",kv.second/1048576.0}});
        r["byCategory"]=cats;
        return r;
    }
};

} // namespace
