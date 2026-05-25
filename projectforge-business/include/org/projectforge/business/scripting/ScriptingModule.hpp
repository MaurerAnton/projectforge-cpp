// ProjectForge C++ port — GPL v3 — www.projectforge.org
#pragma once
#include "org/projectforge/business/BaseDao.hpp"
#include <string>
#include <vector>
#include <map>
#include <optional>
#include <algorithm>
#include <functional>
#include <chrono>
#include <nlohmann/json.hpp>
#include <spdlog/spdlog.h>

namespace org::projectforge::business::scripting {

struct AbstractScriptEntity {
    DECLARE_ENTITY_FIELDS();
    std::string name;
    std::string description;
    int order = 0;
    bool active = true;
    
    nlohmann::json toJson() const {
        nlohmann::json j; JSON_ENTITY_BASE(j);
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["active"]=active;
        return j;
    }
    void fromJson(const nlohmann::json& j) {
        FROMJSON_ENTITY_BASE(j);
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("active"))active=j["active"];
    }
};

class AbstractScriptDao : public BaseDao<AbstractScriptEntity> {
public:
    explicit AbstractScriptDao() {}
    std::vector<AbstractScriptEntity> getActive() {
        auto all=getAll(); std::vector<AbstractScriptEntity> r;
        for(auto& e:all) if(!e.deleted && e.active) r.push_back(e);
        return r;
    }
    std::vector<AbstractScriptEntity> search(const std::string& q, int limit=100) {
        auto all=getAll(); std::vector<AbstractScriptEntity> r;
        std::string lq=q; std::transform(lq.begin(),lq.end(),lq.begin(),::tolower);
        for(auto& e:all) {
            if(e.deleted)continue;
            std::string n=e.name; std::transform(n.begin(),n.end(),n.begin(),::tolower);
            if(n.find(lq)!=std::string::npos){r.push_back(e);if((int)r.size()>=limit)break;}
        }
        return r;
    }
};

struct MyScriptEntity {
    DECLARE_ENTITY_FIELDS();
    std::string name;
    std::string description;
    int order = 0;
    bool active = true;
    
    nlohmann::json toJson() const {
        nlohmann::json j; JSON_ENTITY_BASE(j);
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["active"]=active;
        return j;
    }
    void fromJson(const nlohmann::json& j) {
        FROMJSON_ENTITY_BASE(j);
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("active"))active=j["active"];
    }
};

class MyScriptDao : public BaseDao<MyScriptEntity> {
public:
    explicit MyScriptDao() {}
    std::vector<MyScriptEntity> getActive() {
        auto all=getAll(); std::vector<MyScriptEntity> r;
        for(auto& e:all) if(!e.deleted && e.active) r.push_back(e);
        return r;
    }
    std::vector<MyScriptEntity> search(const std::string& q, int limit=100) {
        auto all=getAll(); std::vector<MyScriptEntity> r;
        std::string lq=q; std::transform(lq.begin(),lq.end(),lq.begin(),::tolower);
        for(auto& e:all) {
            if(e.deleted)continue;
            std::string n=e.name; std::transform(n.begin(),n.end(),n.begin(),::tolower);
            if(n.find(lq)!=std::string::npos){r.push_back(e);if((int)r.size()>=limit)break;}
        }
        return r;
    }
};

struct ScriptEntity {
    DECLARE_ENTITY_FIELDS();
    std::string name;
    std::string description;
    int order = 0;
    bool active = true;
    
    nlohmann::json toJson() const {
        nlohmann::json j; JSON_ENTITY_BASE(j);
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["active"]=active;
        return j;
    }
    void fromJson(const nlohmann::json& j) {
        FROMJSON_ENTITY_BASE(j);
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("active"))active=j["active"];
    }
};

class ScriptDao : public BaseDao<ScriptEntity> {
public:
    explicit ScriptDao() {}
    std::vector<ScriptEntity> getActive() {
        auto all=getAll(); std::vector<ScriptEntity> r;
        for(auto& e:all) if(!e.deleted && e.active) r.push_back(e);
        return r;
    }
    std::vector<ScriptEntity> search(const std::string& q, int limit=100) {
        auto all=getAll(); std::vector<ScriptEntity> r;
        std::string lq=q; std::transform(lq.begin(),lq.end(),lq.begin(),::tolower);
        for(auto& e:all) {
            if(e.deleted)continue;
            std::string n=e.name; std::transform(n.begin(),n.end(),n.begin(),::tolower);
            if(n.find(lq)!=std::string::npos){r.push_back(e);if((int)r.size()>=limit)break;}
        }
        return r;
    }
};

struct ScriptingEntity {
    DECLARE_ENTITY_FIELDS();
    std::string name;
    std::string description;
    int order = 0;
    bool active = true;
    
    nlohmann::json toJson() const {
        nlohmann::json j; JSON_ENTITY_BASE(j);
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["active"]=active;
        return j;
    }
    void fromJson(const nlohmann::json& j) {
        FROMJSON_ENTITY_BASE(j);
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("active"))active=j["active"];
    }
};

class ScriptingDao : public BaseDao<ScriptingEntity> {
public:
    explicit ScriptingDao() {}
    std::vector<ScriptingEntity> getActive() {
        auto all=getAll(); std::vector<ScriptingEntity> r;
        for(auto& e:all) if(!e.deleted && e.active) r.push_back(e);
        return r;
    }
    std::vector<ScriptingEntity> search(const std::string& q, int limit=100) {
        auto all=getAll(); std::vector<ScriptingEntity> r;
        std::string lq=q; std::transform(lq.begin(),lq.end(),lq.begin(),::tolower);
        for(auto& e:all) {
            if(e.deleted)continue;
            std::string n=e.name; std::transform(n.begin(),n.end(),n.begin(),::tolower);
            if(n.find(lq)!=std::string::npos){r.push_back(e);if((int)r.size()>=limit)break;}
        }
        return r;
    }
};

} // namespace org::projectforge::business::scripting
