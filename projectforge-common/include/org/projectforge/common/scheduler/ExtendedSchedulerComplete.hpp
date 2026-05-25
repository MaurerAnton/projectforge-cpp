// ProjectForge C++ port — GPL v3

#pragma once
#include <string>
#include <vector>
#include <map>
#include <functional>
#include <thread>
#include <chrono>
#include <atomic>
#include <mutex>
#include <spdlog/spdlog.h>
#include <nlohmann/json.hpp>
namespace com { namespace projectforge { namespace scheduler { namespace extended {
using json = nlohmann::json;
class Scheduler1 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler2 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler3 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler4 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler5 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler6 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler7 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler8 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler9 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler10 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler11 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler12 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler13 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler14 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler15 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler16 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler17 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler18 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler19 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler20 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler21 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler22 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler23 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler24 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler25 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler26 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler27 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler28 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler29 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler30 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler31 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler32 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler33 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler34 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler35 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler36 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler37 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler38 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler39 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler40 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler41 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler42 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler43 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler44 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler45 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler46 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler47 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler48 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler49 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler50 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler51 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler52 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler53 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler54 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler55 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler56 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler57 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler58 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler59 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler60 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler61 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler62 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler63 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler64 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler65 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler66 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler67 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler68 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler69 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler70 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler71 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler72 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler73 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler74 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler75 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler76 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler77 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler78 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler79 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler80 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler81 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler82 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler83 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler84 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler85 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler86 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler87 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler88 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler89 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler90 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler91 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler92 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler93 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler94 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler95 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler96 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler97 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler98 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler99 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler100 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler101 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler102 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler103 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler104 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler105 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler106 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler107 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler108 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler109 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler110 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler111 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler112 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler113 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler114 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler115 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler116 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler117 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler118 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler119 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler120 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler121 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler122 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler123 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler124 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler125 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler126 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler127 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler128 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler129 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler130 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler131 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler132 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler133 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler134 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler135 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler136 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler137 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler138 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler139 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler140 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler141 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler142 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler143 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler144 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler145 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler146 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler147 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler148 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler149 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler150 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler151 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler152 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler153 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler154 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler155 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler156 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler157 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler158 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler159 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler160 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler161 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler162 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler163 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler164 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler165 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler166 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler167 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler168 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler169 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler170 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler171 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler172 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler173 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler174 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler175 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler176 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler177 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler178 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler179 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler180 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler181 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler182 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler183 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler184 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler185 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler186 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler187 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler188 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler189 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler190 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler191 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler192 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler193 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler194 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler195 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler196 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler197 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler198 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler199 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler200 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler201 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler202 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler203 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler204 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler205 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler206 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler207 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler208 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler209 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler210 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler211 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler212 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler213 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler214 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler215 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler216 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler217 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler218 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler219 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler220 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler221 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler222 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler223 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler224 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler225 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler226 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler227 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler228 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler229 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler230 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler231 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler232 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler233 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler234 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler235 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler236 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler237 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler238 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler239 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler240 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler241 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler242 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler243 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler244 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler245 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler246 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler247 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler248 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler249 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler250 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler251 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler252 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler253 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler254 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler255 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler256 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler257 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler258 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler259 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler260 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler261 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler262 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler263 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler264 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler265 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler266 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler267 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler268 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler269 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler270 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler271 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler272 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler273 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler274 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler275 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler276 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler277 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler278 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler279 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler280 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler281 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler282 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler283 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler284 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler285 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler286 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler287 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler288 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler289 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler290 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler291 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler292 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler293 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler294 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler295 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler296 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler297 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler298 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler299 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler300 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler301 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler302 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler303 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler304 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler305 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler306 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler307 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler308 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler309 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler310 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler311 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler312 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler313 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler314 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler315 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler316 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler317 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler318 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler319 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler320 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler321 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler322 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler323 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler324 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler325 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler326 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler327 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler328 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler329 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler330 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler331 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler332 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler333 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler334 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler335 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler336 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler337 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler338 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler339 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler340 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler341 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler342 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler343 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler344 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler345 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler346 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler347 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler348 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler349 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler350 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler351 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler352 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler353 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler354 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler355 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler356 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler357 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler358 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler359 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler360 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler361 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler362 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler363 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler364 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler365 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler366 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler367 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler368 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler369 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler370 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler371 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler372 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler373 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler374 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler375 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler376 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler377 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler378 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler379 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler380 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler381 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler382 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler383 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler384 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler385 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler386 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler387 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler388 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler389 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler390 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler391 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler392 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler393 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler394 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler395 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler396 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler397 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler398 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler399 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler400 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler401 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler402 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler403 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler404 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler405 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler406 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler407 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler408 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler409 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler410 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler411 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler412 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler413 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler414 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler415 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler416 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler417 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler418 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler419 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler420 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler421 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler422 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler423 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler424 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler425 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler426 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler427 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler428 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler429 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler430 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler431 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler432 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler433 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler434 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler435 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler436 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler437 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler438 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler439 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler440 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler441 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler442 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler443 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler444 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler445 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler446 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler447 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler448 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler449 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler450 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler451 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler452 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler453 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler454 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler455 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler456 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler457 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler458 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler459 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler460 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler461 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler462 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler463 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler464 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler465 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler466 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler467 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler468 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler469 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler470 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler471 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler472 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler473 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler474 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler475 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler476 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler477 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler478 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler479 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler480 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler481 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler482 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler483 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler484 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler485 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler486 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler487 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler488 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler489 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler490 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler491 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler492 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler493 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler494 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler495 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler496 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler497 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler498 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler499 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
class Scheduler500 {
public:
    struct Task { std::string name;std::function<void()> fn;int64_t intervalMs,nextRunMs;bool active=true;int runCount=0;int64_t lastRun=0; };
    void addTask(const std::string& name,std::function<void()> fn,int64_t intervalMs) { std::lock_guard lock(mtx_); Task t;t.name=name;t.fn=fn;t.intervalMs=intervalMs;t.nextRunMs=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs;tasks_.push_back(t); }
    void start() { running_=true; thread_=std::thread([this](){ while(running_) { tick(); std::this_thread::sleep_for(std::chrono::seconds(1)); } }); }
    void stop() { running_=false; if(thread_.joinable()) thread_.join(); }
    void tick() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto&t:tasks_){if(t.active&&now>=t.nextRunMs){try{t.fn();}catch(...){}t.runCount++;t.lastRun=now;t.nextRunMs=now+t.intervalMs;}} }
    json getStatus() { json s=nlohmann::json::array();for(auto&t:tasks_)s.push_back({{"name",t.name},{"active",t.active},{"runs",t.runCount},{"nextRun",t.nextRunMs}});return s; }
private:
    std::vector<Task> tasks_;
    std::thread thread_;
    std::atomic<bool> running_{false};
    mutable std::mutex mtx_;
};
}}}} // namespace