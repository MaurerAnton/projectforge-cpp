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

namespace org::projectforge::business::address {

struct AddressEntity {
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

class AddressDao : public BaseDao<AddressEntity> {
public:
    explicit AddressDao() {}
    std::vector<AddressEntity> getActive() {
        auto all=getAll(); std::vector<AddressEntity> r;
        for(auto& e:all) if(!e.deleted && e.active) r.push_back(e);
        return r;
    }
    std::vector<AddressEntity> search(const std::string& q, int limit=100) {
        auto all=getAll(); std::vector<AddressEntity> r;
        std::string lq=q; std::transform(lq.begin(),lq.end(),lq.begin(),::tolower);
        for(auto& e:all) {
            if(e.deleted)continue;
            std::string n=e.name; std::transform(n.begin(),n.end(),n.begin(),::tolower);
            if(n.find(lq)!=std::string::npos){r.push_back(e);if((int)r.size()>=limit)break;}
        }
        return r;
    }
};

struct AddressImageEntity {
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

class AddressImageDao : public BaseDao<AddressImageEntity> {
public:
    explicit AddressImageDao() {}
    std::vector<AddressImageEntity> getActive() {
        auto all=getAll(); std::vector<AddressImageEntity> r;
        for(auto& e:all) if(!e.deleted && e.active) r.push_back(e);
        return r;
    }
    std::vector<AddressImageEntity> search(const std::string& q, int limit=100) {
        auto all=getAll(); std::vector<AddressImageEntity> r;
        std::string lq=q; std::transform(lq.begin(),lq.end(),lq.begin(),::tolower);
        for(auto& e:all) {
            if(e.deleted)continue;
            std::string n=e.name; std::transform(n.begin(),n.end(),n.begin(),::tolower);
            if(n.find(lq)!=std::string::npos){r.push_back(e);if((int)r.size()>=limit)break;}
        }
        return r;
    }
};

struct AddressbookEntity {
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

class AddressbookDao : public BaseDao<AddressbookEntity> {
public:
    explicit AddressbookDao() {}
    std::vector<AddressbookEntity> getActive() {
        auto all=getAll(); std::vector<AddressbookEntity> r;
        for(auto& e:all) if(!e.deleted && e.active) r.push_back(e);
        return r;
    }
    std::vector<AddressbookEntity> search(const std::string& q, int limit=100) {
        auto all=getAll(); std::vector<AddressbookEntity> r;
        std::string lq=q; std::transform(lq.begin(),lq.end(),lq.begin(),::tolower);
        for(auto& e:all) {
            if(e.deleted)continue;
            std::string n=e.name; std::transform(n.begin(),n.end(),n.begin(),::tolower);
            if(n.find(lq)!=std::string::npos){r.push_back(e);if((int)r.size()>=limit)break;}
        }
        return r;
    }
};

struct PersonalAddressEntity {
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

class PersonalAddressDao : public BaseDao<PersonalAddressEntity> {
public:
    explicit PersonalAddressDao() {}
    std::vector<PersonalAddressEntity> getActive() {
        auto all=getAll(); std::vector<PersonalAddressEntity> r;
        for(auto& e:all) if(!e.deleted && e.active) r.push_back(e);
        return r;
    }
    std::vector<PersonalAddressEntity> search(const std::string& q, int limit=100) {
        auto all=getAll(); std::vector<PersonalAddressEntity> r;
        std::string lq=q; std::transform(lq.begin(),lq.end(),lq.begin(),::tolower);
        for(auto& e:all) {
            if(e.deleted)continue;
            std::string n=e.name; std::transform(n.begin(),n.end(),n.begin(),::tolower);
            if(n.find(lq)!=std::string::npos){r.push_back(e);if((int)r.size()>=limit)break;}
        }
        return r;
    }
};

} // namespace org::projectforge::business::address
