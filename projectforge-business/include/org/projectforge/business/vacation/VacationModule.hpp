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

namespace org::projectforge::business::vacation {

struct LeaveAccountEntryEntity {
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

class LeaveAccountEntryDao : public BaseDao<LeaveAccountEntryEntity> {
public:
    explicit LeaveAccountEntryDao() {}
    std::vector<LeaveAccountEntryEntity> getActive() {
        auto all=getAll(); std::vector<LeaveAccountEntryEntity> r;
        for(auto& e:all) if(!e.deleted && e.active) r.push_back(e);
        return r;
    }
    std::vector<LeaveAccountEntryEntity> search(const std::string& q, int limit=100) {
        auto all=getAll(); std::vector<LeaveAccountEntryEntity> r;
        std::string lq=q; std::transform(lq.begin(),lq.end(),lq.begin(),::tolower);
        for(auto& e:all) {
            if(e.deleted)continue;
            std::string n=e.name; std::transform(n.begin(),n.end(),n.begin(),::tolower);
            if(n.find(lq)!=std::string::npos){r.push_back(e);if((int)r.size()>=limit)break;}
        }
        return r;
    }
};

struct RemainingLeaveEntity {
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

class RemainingLeaveDao : public BaseDao<RemainingLeaveEntity> {
public:
    explicit RemainingLeaveDao() {}
    std::vector<RemainingLeaveEntity> getActive() {
        auto all=getAll(); std::vector<RemainingLeaveEntity> r;
        for(auto& e:all) if(!e.deleted && e.active) r.push_back(e);
        return r;
    }
    std::vector<RemainingLeaveEntity> search(const std::string& q, int limit=100) {
        auto all=getAll(); std::vector<RemainingLeaveEntity> r;
        std::string lq=q; std::transform(lq.begin(),lq.end(),lq.begin(),::tolower);
        for(auto& e:all) {
            if(e.deleted)continue;
            std::string n=e.name; std::transform(n.begin(),n.end(),n.begin(),::tolower);
            if(n.find(lq)!=std::string::npos){r.push_back(e);if((int)r.size()>=limit)break;}
        }
        return r;
    }
};

struct VacationEntity {
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

class VacationDao : public BaseDao<VacationEntity> {
public:
    explicit VacationDao() {}
    std::vector<VacationEntity> getActive() {
        auto all=getAll(); std::vector<VacationEntity> r;
        for(auto& e:all) if(!e.deleted && e.active) r.push_back(e);
        return r;
    }
    std::vector<VacationEntity> search(const std::string& q, int limit=100) {
        auto all=getAll(); std::vector<VacationEntity> r;
        std::string lq=q; std::transform(lq.begin(),lq.end(),lq.begin(),::tolower);
        for(auto& e:all) {
            if(e.deleted)continue;
            std::string n=e.name; std::transform(n.begin(),n.end(),n.begin(),::tolower);
            if(n.find(lq)!=std::string::npos){r.push_back(e);if((int)r.size()>=limit)break;}
        }
        return r;
    }
};

} // namespace org::projectforge::business::vacation
