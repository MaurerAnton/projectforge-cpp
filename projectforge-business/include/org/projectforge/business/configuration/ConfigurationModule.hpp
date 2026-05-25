// ProjectForge C++ port — GPL v3 — www.projectforge.org
#pragma once
// System configuration management
#include "org/projectforge/business/BaseDao.hpp"
#include <string>
#include <vector>
#include <optional>
#include <algorithm>
#include <map>
#include <nlohmann/json.hpp>

namespace org::projectforge::business::configuration {

// ======== DOMAIN ENTITIES AND SERVICES ========

struct ConfigurationConfig {
    bool enabled = true;
    std::string name;
    std::string description;
    nlohmann::json settings;
    
    nlohmann::json toJson() const {
        nlohmann::json j;
        j["enabled"]=enabled; j["name"]=name;
        if(!description.empty())j["description"]=description;
        if(!settings.empty())j["settings"]=settings;
        return j;
    }
};

struct ConfigurationEntry {
    DECLARE_ENTITY_FIELDS();
    std::string title;
    std::string content;
    std::string status;
    int64_t ownerId = -1;
    int64_t timestamp = 0;
    int priority = 0;
    std::map<std::string,std::string> metadata;
    
    nlohmann::json toJson() const {
        nlohmann::json j; JSON_ENTITY_BASE(j);
        if(!title.empty())j["title"]=title;
        if(!content.empty())j["content"]=content;
        if(!status.empty())j["status"]=status;
        if(ownerId>=0)j["ownerId"]=ownerId;
        if(timestamp>0)j["timestamp"]=timestamp;
        j["priority"]=priority;
        if(!metadata.empty()){nlohmann::json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        return j;
    }
    void fromJson(const nlohmann::json& j) {
        FROMJSON_ENTITY_BASE(j);
        if(j.contains("title"))title=j["title"];
        if(j.contains("content"))content=j["content"];
        if(j.contains("status"))status=j["status"];
    }
};

class ConfigurationDao : public BaseDao<ConfigurationEntry> {
public:
    explicit ConfigurationDao(Storage& s) : BaseDao<ConfigurationEntry>(s) {}
    
    std::vector<ConfigurationEntry> getByOwner(int64_t uid) {
        auto all=getAll(); std::vector<ConfigurationEntry> r;
        for(auto& e:all) if(!e.deleted && e.ownerId==uid) r.push_back(e);
        return r;
    }
    
    std::vector<ConfigurationEntry> getByStatus(const std::string& s) {
        auto all=getAll(); std::vector<ConfigurationEntry> r;
        for(auto& e:all) if(!e.deleted && e.status==s) r.push_back(e);
        return r;
    }
    
    std::vector<ConfigurationEntry> getRecent(int limit=50) {
        auto all=getAll();
        std::sort(all.begin(),all.end(),[](auto& a,auto& b){return a.timestamp>b.timestamp;});
        if((int)all.size()>limit) all.resize(limit);
        return all;
    }
    
    bool updateStatus(int64_t id, const std::string& status) {
        auto e=getById(id);
        if(!e.has_value())return false;
        e->status=status; save(*e); return true;
    }
    
    void deleteByOwner(int64_t uid) {
        for(auto& e:getAll()) if(e.ownerId==uid){e.deleted=true;save(e);}
    }
};

// ======== DOMAIN SERVICE ========
class ConfigurationService {
public:
    static ConfigurationService& instance() { static ConfigurationService svc; return svc; }
    
    void init() { initialized_=true; }
    bool isInitialized() const { return initialized_; }
    
    bool processEntry(const ConfigurationEntry& entry) {
        spdlog::info("configuration: Processing entry: {}", entry.title);
        return true;
    }
    
    std::string getStatus() const {
        return "{ \"domain\": \"" + std::string("configuration") + "\", \"status\": \"OK\" }";
    }
    
    void shutdown() { initialized_=false; }
    
private:
    bool initialized_=false;
    ConfigurationService()=default;
};

} // namespace
