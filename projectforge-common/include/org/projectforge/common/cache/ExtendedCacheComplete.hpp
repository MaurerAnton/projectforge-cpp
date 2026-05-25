// ProjectForge C++ port — GPL v3

#pragma once
#include <string>
#include <map>
#include <mutex>
#include <chrono>
#include <optional>
#include <spdlog/spdlog.h>
#include <nlohmann/json.hpp>
namespace com { namespace projectforge { namespace cache { namespace extended {
using json = nlohmann::json;
class CacheManager1 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager2 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager3 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager4 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager5 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager6 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager7 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager8 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager9 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager10 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager11 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager12 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager13 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager14 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager15 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager16 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager17 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager18 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager19 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager20 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager21 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager22 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager23 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager24 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager25 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager26 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager27 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager28 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager29 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager30 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager31 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager32 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager33 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager34 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager35 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager36 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager37 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager38 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager39 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager40 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager41 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager42 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager43 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager44 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager45 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager46 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager47 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager48 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager49 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager50 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager51 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager52 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager53 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager54 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager55 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager56 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager57 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager58 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager59 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager60 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager61 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager62 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager63 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager64 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager65 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager66 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager67 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager68 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager69 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager70 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager71 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager72 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager73 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager74 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager75 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager76 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager77 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager78 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager79 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager80 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager81 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager82 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager83 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager84 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager85 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager86 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager87 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager88 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager89 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager90 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager91 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager92 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager93 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager94 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager95 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager96 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager97 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager98 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager99 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager100 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager101 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager102 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager103 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager104 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager105 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager106 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager107 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager108 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager109 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager110 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager111 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager112 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager113 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager114 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager115 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager116 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager117 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager118 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager119 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager120 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager121 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager122 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager123 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager124 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager125 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager126 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager127 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager128 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager129 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager130 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager131 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager132 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager133 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager134 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager135 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager136 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager137 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager138 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager139 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager140 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager141 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager142 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager143 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager144 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager145 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager146 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager147 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager148 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager149 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager150 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager151 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager152 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager153 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager154 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager155 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager156 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager157 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager158 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager159 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager160 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager161 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager162 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager163 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager164 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager165 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager166 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager167 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager168 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager169 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager170 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager171 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager172 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager173 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager174 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager175 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager176 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager177 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager178 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager179 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager180 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager181 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager182 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager183 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager184 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager185 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager186 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager187 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager188 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager189 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager190 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager191 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager192 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager193 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager194 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager195 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager196 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager197 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager198 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager199 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager200 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager201 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager202 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager203 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager204 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager205 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager206 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager207 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager208 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager209 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager210 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager211 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager212 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager213 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager214 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager215 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager216 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager217 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager218 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager219 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager220 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager221 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager222 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager223 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager224 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager225 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager226 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager227 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager228 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager229 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager230 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager231 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager232 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager233 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager234 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager235 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager236 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager237 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager238 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager239 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager240 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager241 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager242 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager243 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager244 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager245 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager246 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager247 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager248 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager249 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager250 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager251 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager252 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager253 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager254 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager255 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager256 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager257 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager258 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager259 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager260 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager261 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager262 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager263 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager264 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager265 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager266 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager267 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager268 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager269 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager270 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager271 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager272 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager273 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager274 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager275 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager276 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager277 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager278 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager279 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager280 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager281 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager282 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager283 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager284 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager285 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager286 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager287 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager288 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager289 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager290 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager291 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager292 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager293 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager294 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager295 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager296 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager297 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager298 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager299 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager300 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager301 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager302 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager303 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager304 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager305 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager306 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager307 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager308 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager309 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager310 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager311 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager312 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager313 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager314 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager315 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager316 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager317 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager318 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager319 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager320 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager321 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager322 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager323 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager324 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager325 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager326 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager327 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager328 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager329 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager330 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager331 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager332 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager333 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager334 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager335 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager336 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager337 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager338 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager339 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager340 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager341 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager342 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager343 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager344 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager345 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager346 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager347 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager348 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager349 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager350 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager351 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager352 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager353 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager354 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager355 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager356 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager357 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager358 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager359 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager360 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager361 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager362 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager363 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager364 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager365 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager366 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager367 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager368 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager369 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager370 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager371 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager372 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager373 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager374 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager375 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager376 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager377 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager378 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager379 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager380 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager381 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager382 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager383 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager384 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager385 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager386 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager387 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager388 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager389 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager390 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager391 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager392 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager393 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager394 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager395 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager396 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager397 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager398 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager399 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager400 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager401 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager402 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager403 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager404 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager405 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager406 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager407 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager408 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager409 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager410 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager411 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager412 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager413 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager414 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager415 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager416 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager417 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager418 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager419 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager420 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager421 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager422 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager423 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager424 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager425 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager426 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager427 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager428 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager429 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager430 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager431 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager432 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager433 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager434 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager435 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager436 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager437 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager438 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager439 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager440 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager441 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager442 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager443 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager444 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager445 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager446 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager447 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager448 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager449 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager450 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager451 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager452 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager453 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager454 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager455 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager456 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager457 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager458 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager459 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager460 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager461 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager462 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager463 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager464 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager465 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager466 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager467 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager468 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager469 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager470 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager471 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager472 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager473 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager474 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager475 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager476 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager477 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager478 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager479 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager480 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager481 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager482 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager483 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager484 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager485 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager486 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager487 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager488 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager489 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager490 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager491 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager492 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager493 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager494 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager495 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager496 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager497 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager498 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager499 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
class CacheManager500 {
public:
    struct Entry { std::string key; json value; int64_t createdAt,expiresAt; int accessCount=0;int64_t lastAccessed=0; };
    void set(const std::string& key,const json& value,int64_t ttlMs=300000) { std::lock_guard lock(mtx_); Entry e;e.key=key;e.value=value;e.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();e.expiresAt=e.createdAt+ttlMs;entries_[key]=e; }
    std::optional<json> get(const std::string& key) { std::lock_guard lock(mtx_); auto it=entries_.find(key);if(it==entries_.end())return std::nullopt;int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();if(now>it->second.expiresAt){entries_.erase(it);return std::nullopt;}it->second.accessCount++;it->second.lastAccessed=now;return it->second.value; }
    bool remove(const std::string& key) { std::lock_guard lock(mtx_); return entries_.erase(key)>0; }
    void clear() { std::lock_guard lock(mtx_); entries_.clear(); }
    size_t size() const { return entries_.size(); }
    void evictExpired() { std::lock_guard lock(mtx_); int64_t now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto it=entries_.begin();it!=entries_.end();){if(now>it->second.expiresAt)it=entries_.erase(it);else ++it;} }
    json getStats() { json s;s["size"]=entries_.size();return s; }
private:
    std::map<std::string,Entry> entries_;
    mutable std::mutex mtx_;
};
}}}} // namespace