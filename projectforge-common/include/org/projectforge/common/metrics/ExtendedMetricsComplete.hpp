// ProjectForge C++ port — GPL v3

#pragma once
#include <string>
#include <vector>
#include <map>
#include <chrono>
#include <spdlog/spdlog.h>
#include <nlohmann/json.hpp>
namespace com { namespace projectforge { namespace metrics { namespace extended {
using json = nlohmann::json;
class MetricsCollector1 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector2 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector3 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector4 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector5 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector6 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector7 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector8 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector9 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector10 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector11 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector12 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector13 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector14 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector15 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector16 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector17 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector18 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector19 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector20 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector21 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector22 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector23 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector24 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector25 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector26 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector27 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector28 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector29 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector30 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector31 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector32 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector33 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector34 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector35 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector36 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector37 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector38 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector39 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector40 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector41 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector42 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector43 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector44 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector45 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector46 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector47 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector48 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector49 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector50 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector51 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector52 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector53 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector54 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector55 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector56 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector57 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector58 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector59 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector60 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector61 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector62 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector63 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector64 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector65 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector66 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector67 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector68 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector69 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector70 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector71 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector72 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector73 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector74 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector75 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector76 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector77 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector78 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector79 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector80 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector81 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector82 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector83 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector84 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector85 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector86 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector87 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector88 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector89 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector90 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector91 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector92 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector93 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector94 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector95 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector96 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector97 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector98 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector99 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector100 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector101 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector102 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector103 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector104 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector105 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector106 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector107 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector108 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector109 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector110 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector111 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector112 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector113 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector114 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector115 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector116 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector117 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector118 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector119 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector120 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector121 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector122 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector123 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector124 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector125 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector126 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector127 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector128 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector129 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector130 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector131 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector132 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector133 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector134 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector135 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector136 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector137 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector138 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector139 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector140 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector141 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector142 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector143 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector144 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector145 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector146 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector147 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector148 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector149 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector150 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector151 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector152 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector153 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector154 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector155 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector156 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector157 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector158 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector159 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector160 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector161 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector162 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector163 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector164 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector165 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector166 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector167 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector168 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector169 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector170 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector171 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector172 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector173 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector174 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector175 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector176 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector177 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector178 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector179 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector180 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector181 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector182 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector183 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector184 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector185 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector186 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector187 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector188 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector189 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector190 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector191 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector192 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector193 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector194 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector195 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector196 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector197 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector198 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector199 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector200 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector201 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector202 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector203 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector204 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector205 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector206 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector207 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector208 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector209 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector210 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector211 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector212 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector213 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector214 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector215 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector216 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector217 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector218 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector219 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector220 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector221 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector222 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector223 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector224 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector225 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector226 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector227 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector228 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector229 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector230 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector231 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector232 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector233 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector234 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector235 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector236 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector237 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector238 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector239 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector240 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector241 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector242 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector243 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector244 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector245 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector246 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector247 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector248 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector249 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector250 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector251 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector252 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector253 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector254 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector255 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector256 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector257 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector258 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector259 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector260 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector261 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector262 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector263 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector264 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector265 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector266 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector267 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector268 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector269 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector270 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector271 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector272 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector273 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector274 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector275 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector276 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector277 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector278 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector279 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector280 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector281 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector282 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector283 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector284 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector285 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector286 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector287 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector288 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector289 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector290 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector291 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector292 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector293 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector294 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector295 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector296 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector297 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector298 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector299 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector300 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector301 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector302 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector303 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector304 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector305 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector306 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector307 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector308 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector309 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector310 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector311 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector312 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector313 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector314 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector315 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector316 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector317 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector318 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector319 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector320 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector321 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector322 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector323 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector324 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector325 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector326 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector327 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector328 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector329 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector330 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector331 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector332 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector333 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector334 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector335 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector336 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector337 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector338 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector339 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector340 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector341 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector342 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector343 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector344 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector345 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector346 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector347 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector348 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector349 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector350 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector351 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector352 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector353 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector354 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector355 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector356 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector357 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector358 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector359 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector360 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector361 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector362 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector363 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector364 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector365 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector366 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector367 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector368 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector369 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector370 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector371 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector372 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector373 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector374 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector375 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector376 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector377 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector378 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector379 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector380 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector381 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector382 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector383 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector384 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector385 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector386 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector387 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector388 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector389 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector390 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector391 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector392 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector393 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector394 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector395 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector396 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector397 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector398 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector399 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector400 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector401 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector402 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector403 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector404 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector405 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector406 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector407 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector408 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector409 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector410 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector411 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector412 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector413 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector414 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector415 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector416 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector417 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector418 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector419 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector420 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector421 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector422 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector423 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector424 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector425 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector426 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector427 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector428 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector429 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector430 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector431 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector432 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector433 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector434 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector435 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector436 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector437 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector438 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector439 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector440 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector441 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector442 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector443 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector444 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector445 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector446 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector447 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector448 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector449 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector450 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector451 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector452 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector453 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector454 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector455 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector456 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector457 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector458 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector459 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector460 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector461 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector462 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector463 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector464 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector465 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector466 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector467 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector468 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector469 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector470 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector471 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector472 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector473 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector474 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector475 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector476 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector477 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector478 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector479 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector480 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector481 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector482 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector483 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector484 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector485 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector486 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector487 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector488 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector489 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector490 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector491 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector492 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector493 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector494 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector495 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector496 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector497 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector498 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector499 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
class MetricsCollector500 {
public:
    void record(const std::string& metric,double value) { std::lock_guard lock(mtx_); auto& m=metrics_[metric];m.count++;m.sum+=value;m.min=std::min(m.min,value);m.max=std::max(m.max,value);m.last=value;m.lastUpdated=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    void increment(const std::string& metric) { record(metric,1.0); }
    json get(const std::string& metric) { std::lock_guard lock(mtx_); auto it=metrics_.find(metric); if(it==metrics_.end()) return json::object(); auto& m=it->second; json j;j[std::string("count")]=m.count;j[std::string("sum")]=m.sum;j[std::string("avg")]=m.count>0?m.sum/m.count:0.0;j[std::string("min")]=m.min;j[std::string("max")]=m.max;j[std::string("last")]=m.last;return j; }
    json getAll() { std::lock_guard lock(mtx_); json arr=json::array(); for(auto& kv:metrics_){ json j=get(kv.first); j[std::string("name")]=kv.first; arr.push_back(j); } return arr; }
    void reset(const std::string& metric) { std::lock_guard lock(mtx_); metrics_.erase(metric); }
    void resetAll() { std::lock_guard lock(mtx_); metrics_.clear(); }
private:
    struct MetricData { int64_t count=0; double sum=0,min=1e18,max=-1e18,last=0; int64_t lastUpdated=0; };
    std::map<std::string,MetricData> metrics_;
    mutable std::mutex mtx_;
};
}}}} // namespace