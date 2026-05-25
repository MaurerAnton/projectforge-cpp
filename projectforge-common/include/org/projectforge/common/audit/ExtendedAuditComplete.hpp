// ProjectForge C++ port — GPL v3

#pragma once
#include <string>
#include <vector>
#include <chrono>
#include <spdlog/spdlog.h>
#include <nlohmann/json.hpp>
namespace com { namespace projectforge { namespace audit { namespace extended {
using json = nlohmann::json;
class AuditLogger1 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[1]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger2 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[2]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger3 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[3]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger4 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[4]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger5 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[5]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger6 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[6]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger7 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[7]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger8 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[8]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger9 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[9]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger10 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[10]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger11 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[11]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger12 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[12]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger13 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[13]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger14 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[14]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger15 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[15]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger16 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[16]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger17 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[17]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger18 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[18]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger19 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[19]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger20 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[20]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger21 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[21]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger22 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[22]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger23 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[23]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger24 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[24]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger25 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[25]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger26 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[26]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger27 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[27]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger28 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[28]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger29 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[29]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger30 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[30]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger31 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[31]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger32 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[32]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger33 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[33]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger34 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[34]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger35 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[35]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger36 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[36]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger37 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[37]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger38 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[38]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger39 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[39]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger40 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[40]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger41 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[41]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger42 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[42]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger43 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[43]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger44 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[44]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger45 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[45]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger46 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[46]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger47 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[47]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger48 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[48]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger49 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[49]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger50 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[50]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger51 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[51]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger52 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[52]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger53 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[53]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger54 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[54]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger55 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[55]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger56 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[56]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger57 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[57]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger58 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[58]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger59 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[59]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger60 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[60]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger61 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[61]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger62 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[62]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger63 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[63]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger64 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[64]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger65 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[65]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger66 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[66]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger67 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[67]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger68 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[68]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger69 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[69]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger70 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[70]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger71 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[71]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger72 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[72]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger73 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[73]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger74 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[74]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger75 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[75]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger76 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[76]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger77 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[77]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger78 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[78]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger79 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[79]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger80 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[80]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger81 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[81]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger82 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[82]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger83 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[83]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger84 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[84]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger85 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[85]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger86 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[86]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger87 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[87]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger88 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[88]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger89 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[89]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger90 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[90]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger91 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[91]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger92 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[92]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger93 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[93]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger94 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[94]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger95 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[95]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger96 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[96]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger97 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[97]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger98 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[98]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger99 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[99]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger100 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[100]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger101 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[101]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger102 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[102]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger103 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[103]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger104 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[104]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger105 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[105]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger106 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[106]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger107 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[107]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger108 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[108]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger109 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[109]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger110 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[110]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger111 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[111]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger112 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[112]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger113 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[113]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger114 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[114]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger115 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[115]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger116 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[116]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger117 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[117]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger118 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[118]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger119 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[119]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger120 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[120]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger121 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[121]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger122 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[122]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger123 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[123]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger124 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[124]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger125 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[125]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger126 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[126]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger127 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[127]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger128 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[128]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger129 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[129]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger130 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[130]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger131 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[131]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger132 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[132]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger133 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[133]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger134 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[134]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger135 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[135]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger136 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[136]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger137 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[137]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger138 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[138]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger139 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[139]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger140 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[140]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger141 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[141]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger142 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[142]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger143 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[143]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger144 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[144]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger145 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[145]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger146 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[146]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger147 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[147]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger148 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[148]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger149 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[149]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger150 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[150]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger151 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[151]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger152 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[152]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger153 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[153]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger154 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[154]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger155 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[155]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger156 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[156]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger157 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[157]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger158 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[158]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger159 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[159]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger160 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[160]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger161 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[161]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger162 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[162]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger163 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[163]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger164 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[164]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger165 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[165]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger166 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[166]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger167 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[167]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger168 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[168]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger169 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[169]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger170 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[170]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger171 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[171]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger172 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[172]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger173 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[173]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger174 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[174]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger175 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[175]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger176 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[176]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger177 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[177]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger178 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[178]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger179 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[179]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger180 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[180]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger181 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[181]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger182 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[182]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger183 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[183]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger184 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[184]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger185 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[185]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger186 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[186]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger187 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[187]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger188 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[188]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger189 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[189]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger190 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[190]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger191 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[191]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger192 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[192]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger193 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[193]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger194 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[194]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger195 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[195]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger196 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[196]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger197 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[197]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger198 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[198]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger199 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[199]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger200 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[200]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger201 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[201]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger202 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[202]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger203 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[203]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger204 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[204]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger205 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[205]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger206 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[206]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger207 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[207]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger208 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[208]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger209 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[209]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger210 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[210]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger211 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[211]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger212 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[212]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger213 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[213]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger214 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[214]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger215 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[215]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger216 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[216]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger217 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[217]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger218 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[218]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger219 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[219]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger220 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[220]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger221 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[221]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger222 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[222]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger223 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[223]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger224 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[224]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger225 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[225]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger226 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[226]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger227 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[227]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger228 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[228]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger229 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[229]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger230 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[230]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger231 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[231]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger232 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[232]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger233 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[233]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger234 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[234]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger235 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[235]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger236 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[236]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger237 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[237]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger238 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[238]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger239 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[239]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger240 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[240]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger241 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[241]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger242 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[242]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger243 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[243]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger244 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[244]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger245 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[245]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger246 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[246]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger247 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[247]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger248 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[248]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger249 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[249]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger250 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[250]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger251 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[251]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger252 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[252]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger253 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[253]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger254 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[254]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger255 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[255]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger256 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[256]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger257 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[257]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger258 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[258]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger259 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[259]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger260 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[260]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger261 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[261]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger262 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[262]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger263 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[263]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger264 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[264]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger265 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[265]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger266 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[266]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger267 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[267]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger268 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[268]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger269 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[269]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger270 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[270]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger271 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[271]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger272 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[272]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger273 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[273]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger274 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[274]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger275 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[275]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger276 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[276]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger277 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[277]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger278 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[278]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger279 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[279]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger280 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[280]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger281 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[281]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger282 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[282]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger283 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[283]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger284 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[284]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger285 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[285]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger286 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[286]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger287 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[287]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger288 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[288]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger289 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[289]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger290 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[290]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger291 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[291]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger292 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[292]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger293 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[293]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger294 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[294]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger295 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[295]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger296 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[296]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger297 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[297]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger298 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[298]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger299 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[299]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger300 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[300]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger301 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[301]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger302 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[302]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger303 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[303]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger304 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[304]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger305 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[305]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger306 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[306]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger307 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[307]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger308 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[308]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger309 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[309]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger310 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[310]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger311 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[311]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger312 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[312]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger313 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[313]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger314 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[314]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger315 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[315]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger316 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[316]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger317 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[317]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger318 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[318]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger319 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[319]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger320 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[320]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger321 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[321]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger322 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[322]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger323 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[323]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger324 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[324]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger325 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[325]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger326 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[326]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger327 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[327]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger328 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[328]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger329 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[329]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger330 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[330]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger331 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[331]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger332 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[332]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger333 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[333]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger334 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[334]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger335 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[335]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger336 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[336]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger337 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[337]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger338 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[338]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger339 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[339]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger340 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[340]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger341 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[341]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger342 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[342]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger343 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[343]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger344 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[344]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger345 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[345]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger346 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[346]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger347 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[347]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger348 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[348]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger349 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[349]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger350 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[350]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger351 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[351]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger352 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[352]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger353 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[353]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger354 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[354]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger355 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[355]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger356 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[356]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger357 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[357]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger358 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[358]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger359 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[359]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger360 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[360]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger361 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[361]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger362 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[362]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger363 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[363]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger364 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[364]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger365 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[365]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger366 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[366]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger367 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[367]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger368 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[368]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger369 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[369]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger370 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[370]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger371 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[371]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger372 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[372]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger373 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[373]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger374 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[374]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger375 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[375]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger376 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[376]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger377 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[377]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger378 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[378]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger379 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[379]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger380 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[380]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger381 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[381]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger382 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[382]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger383 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[383]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger384 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[384]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger385 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[385]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger386 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[386]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger387 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[387]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger388 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[388]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger389 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[389]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger390 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[390]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger391 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[391]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger392 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[392]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger393 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[393]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger394 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[394]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger395 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[395]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger396 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[396]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger397 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[397]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger398 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[398]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger399 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[399]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger400 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[400]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger401 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[401]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger402 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[402]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger403 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[403]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger404 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[404]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger405 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[405]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger406 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[406]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger407 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[407]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger408 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[408]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger409 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[409]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger410 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[410]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger411 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[411]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger412 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[412]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger413 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[413]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger414 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[414]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger415 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[415]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger416 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[416]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger417 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[417]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger418 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[418]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger419 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[419]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger420 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[420]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger421 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[421]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger422 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[422]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger423 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[423]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger424 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[424]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger425 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[425]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger426 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[426]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger427 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[427]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger428 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[428]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger429 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[429]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger430 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[430]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger431 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[431]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger432 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[432]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger433 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[433]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger434 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[434]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger435 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[435]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger436 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[436]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger437 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[437]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger438 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[438]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger439 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[439]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger440 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[440]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger441 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[441]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger442 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[442]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger443 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[443]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger444 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[444]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger445 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[445]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger446 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[446]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger447 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[447]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger448 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[448]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger449 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[449]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger450 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[450]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger451 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[451]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger452 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[452]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger453 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[453]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger454 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[454]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger455 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[455]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger456 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[456]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger457 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[457]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger458 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[458]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger459 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[459]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger460 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[460]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger461 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[461]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger462 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[462]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger463 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[463]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger464 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[464]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger465 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[465]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger466 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[466]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger467 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[467]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger468 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[468]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger469 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[469]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger470 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[470]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger471 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[471]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger472 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[472]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger473 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[473]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger474 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[474]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger475 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[475]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger476 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[476]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger477 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[477]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger478 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[478]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger479 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[479]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger480 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[480]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger481 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[481]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger482 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[482]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger483 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[483]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger484 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[484]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger485 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[485]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger486 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[486]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger487 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[487]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger488 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[488]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger489 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[489]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger490 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[490]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger491 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[491]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger492 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[492]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger493 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[493]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger494 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[494]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger495 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[495]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger496 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[496]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger497 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[497]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger498 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[498]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger499 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[499]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
class AuditLogger500 {
public:
    struct Entry { int64_t id,timestamp,userId; std::string action,entity,details,ipAddress,userAgent; json oldValue,newValue; json toJson() const { json j;j["id"]=id;j["timestamp"]=timestamp;j["action"]=action;j["entity"]=entity;j["details"]=details;return j; } };
    void log(const std::string& action,const std::string& entity,const std::string& details="",int64_t userId=-1) {
        Entry e;e.id=nextId_++;e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        e.action=action;e.entity=entity;e.details=details;e.userId=userId;entries_.push_back(e);
        spdlog::info("AUDIT[500]: {} {} - {}",action,entity,details);
    }
    std::vector<Entry> getEntries(int limit=100) { std::vector<Entry> r;size_t s=entries_.size()>limit?entries_.size()-limit:0;for(size_t i=s;i<entries_.size();i++)r.push_back(entries_[i]);return r; }
    json getReport() { json r=nlohmann::json::array();for(auto&e:entries_)r.push_back(e.toJson());return r; }
    void clear() { entries_.clear(); }
    size_t count() const { return entries_.size(); }
private:
    std::vector<Entry> entries_;
    int64_t nextId_=1;
};
}}}} // namespace