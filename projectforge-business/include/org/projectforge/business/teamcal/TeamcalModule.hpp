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

namespace org::projectforge::business::teamcal {

struct TeamCalEntity {
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

class TeamCalDao : public BaseDao<TeamCalEntity> {
public:
    explicit TeamCalDao(Storage& s) : BaseDao<TeamCalEntity>(s) {}
    std::vector<TeamCalEntity> getActive() {
        auto all=getAll(); std::vector<TeamCalEntity> r;
        for(auto& e:all) if(!e.deleted && e.active) r.push_back(e);
        return r;
    }
    std::vector<TeamCalEntity> search(const std::string& q, int limit=100) {
        auto all=getAll(); std::vector<TeamCalEntity> r;
        std::string lq=q; std::transform(lq.begin(),lq.end(),lq.begin(),::tolower);
        for(auto& e:all) {
            if(e.deleted)continue;
            std::string n=e.name; std::transform(n.begin(),n.end(),n.begin(),::tolower);
            if(n.find(lq)!=std::string::npos){r.push_back(e);if((int)r.size()>=limit)break;}
        }
        return r;
    }
};

struct TeamEventEntity {
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

class TeamEventDao : public BaseDao<TeamEventEntity> {
public:
    explicit TeamEventDao(Storage& s) : BaseDao<TeamEventEntity>(s) {}
    std::vector<TeamEventEntity> getActive() {
        auto all=getAll(); std::vector<TeamEventEntity> r;
        for(auto& e:all) if(!e.deleted && e.active) r.push_back(e);
        return r;
    }
    std::vector<TeamEventEntity> search(const std::string& q, int limit=100) {
        auto all=getAll(); std::vector<TeamEventEntity> r;
        std::string lq=q; std::transform(lq.begin(),lq.end(),lq.begin(),::tolower);
        for(auto& e:all) {
            if(e.deleted)continue;
            std::string n=e.name; std::transform(n.begin(),n.end(),n.begin(),::tolower);
            if(n.find(lq)!=std::string::npos){r.push_back(e);if((int)r.size()>=limit)break;}
        }
        return r;
    }
};

} // namespace org::projectforge::business::teamcal
