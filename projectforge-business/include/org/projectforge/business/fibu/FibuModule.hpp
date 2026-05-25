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

namespace org::projectforge::business::fibu {

struct AuftragEntity {
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

class AuftragDao : public BaseDao<AuftragEntity> {
public:
    explicit AuftragDao() {}
    std::vector<AuftragEntity> getActive() {
        auto all=getAll(); std::vector<AuftragEntity> r;
        for(auto& e:all) if(!e.deleted && e.active) r.push_back(e);
        return r;
    }
    std::vector<AuftragEntity> search(const std::string& q, int limit=100) {
        auto all=getAll(); std::vector<AuftragEntity> r;
        std::string lq=q; std::transform(lq.begin(),lq.end(),lq.begin(),::tolower);
        for(auto& e:all) {
            if(e.deleted)continue;
            std::string n=e.name; std::transform(n.begin(),n.end(),n.begin(),::tolower);
            if(n.find(lq)!=std::string::npos){r.push_back(e);if((int)r.size()>=limit)break;}
        }
        return r;
    }
};

struct CurrencyPairEntity {
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

class CurrencyPairDao : public BaseDao<CurrencyPairEntity> {
public:
    explicit CurrencyPairDao() {}
    std::vector<CurrencyPairEntity> getActive() {
        auto all=getAll(); std::vector<CurrencyPairEntity> r;
        for(auto& e:all) if(!e.deleted && e.active) r.push_back(e);
        return r;
    }
    std::vector<CurrencyPairEntity> search(const std::string& q, int limit=100) {
        auto all=getAll(); std::vector<CurrencyPairEntity> r;
        std::string lq=q; std::transform(lq.begin(),lq.end(),lq.begin(),::tolower);
        for(auto& e:all) {
            if(e.deleted)continue;
            std::string n=e.name; std::transform(n.begin(),n.end(),n.begin(),::tolower);
            if(n.find(lq)!=std::string::npos){r.push_back(e);if((int)r.size()>=limit)break;}
        }
        return r;
    }
};

struct EingangsrechnungEntity {
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

class EingangsrechnungDao : public BaseDao<EingangsrechnungEntity> {
public:
    explicit EingangsrechnungDao() {}
    std::vector<EingangsrechnungEntity> getActive() {
        auto all=getAll(); std::vector<EingangsrechnungEntity> r;
        for(auto& e:all) if(!e.deleted && e.active) r.push_back(e);
        return r;
    }
    std::vector<EingangsrechnungEntity> search(const std::string& q, int limit=100) {
        auto all=getAll(); std::vector<EingangsrechnungEntity> r;
        std::string lq=q; std::transform(lq.begin(),lq.end(),lq.begin(),::tolower);
        for(auto& e:all) {
            if(e.deleted)continue;
            std::string n=e.name; std::transform(n.begin(),n.end(),n.begin(),::tolower);
            if(n.find(lq)!=std::string::npos){r.push_back(e);if((int)r.size()>=limit)break;}
        }
        return r;
    }
};

struct EmployeeEntity {
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

class EmployeeDao : public BaseDao<EmployeeEntity> {
public:
    explicit EmployeeDao() {}
    std::vector<EmployeeEntity> getActive() {
        auto all=getAll(); std::vector<EmployeeEntity> r;
        for(auto& e:all) if(!e.deleted && e.active) r.push_back(e);
        return r;
    }
    std::vector<EmployeeEntity> search(const std::string& q, int limit=100) {
        auto all=getAll(); std::vector<EmployeeEntity> r;
        std::string lq=q; std::transform(lq.begin(),lq.end(),lq.begin(),::tolower);
        for(auto& e:all) {
            if(e.deleted)continue;
            std::string n=e.name; std::transform(n.begin(),n.end(),n.begin(),::tolower);
            if(n.find(lq)!=std::string::npos){r.push_back(e);if((int)r.size()>=limit)break;}
        }
        return r;
    }
};

struct EmployeeSalaryEntity {
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

class EmployeeSalaryDao : public BaseDao<EmployeeSalaryEntity> {
public:
    explicit EmployeeSalaryDao() {}
    std::vector<EmployeeSalaryEntity> getActive() {
        auto all=getAll(); std::vector<EmployeeSalaryEntity> r;
        for(auto& e:all) if(!e.deleted && e.active) r.push_back(e);
        return r;
    }
    std::vector<EmployeeSalaryEntity> search(const std::string& q, int limit=100) {
        auto all=getAll(); std::vector<EmployeeSalaryEntity> r;
        std::string lq=q; std::transform(lq.begin(),lq.end(),lq.begin(),::tolower);
        for(auto& e:all) {
            if(e.deleted)continue;
            std::string n=e.name; std::transform(n.begin(),n.end(),n.begin(),::tolower);
            if(n.find(lq)!=std::string::npos){r.push_back(e);if((int)r.size()>=limit)break;}
        }
        return r;
    }
};

struct EmployeeScriptingEntity {
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

class EmployeeScriptingDao : public BaseDao<EmployeeScriptingEntity> {
public:
    explicit EmployeeScriptingDao() {}
    std::vector<EmployeeScriptingEntity> getActive() {
        auto all=getAll(); std::vector<EmployeeScriptingEntity> r;
        for(auto& e:all) if(!e.deleted && e.active) r.push_back(e);
        return r;
    }
    std::vector<EmployeeScriptingEntity> search(const std::string& q, int limit=100) {
        auto all=getAll(); std::vector<EmployeeScriptingEntity> r;
        std::string lq=q; std::transform(lq.begin(),lq.end(),lq.begin(),::tolower);
        for(auto& e:all) {
            if(e.deleted)continue;
            std::string n=e.name; std::transform(n.begin(),n.end(),n.begin(),::tolower);
            if(n.find(lq)!=std::string::npos){r.push_back(e);if((int)r.size()>=limit)break;}
        }
        return r;
    }
};

struct ProjektEntity {
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

class ProjektDao : public BaseDao<ProjektEntity> {
public:
    explicit ProjektDao() {}
    std::vector<ProjektEntity> getActive() {
        auto all=getAll(); std::vector<ProjektEntity> r;
        for(auto& e:all) if(!e.deleted && e.active) r.push_back(e);
        return r;
    }
    std::vector<ProjektEntity> search(const std::string& q, int limit=100) {
        auto all=getAll(); std::vector<ProjektEntity> r;
        std::string lq=q; std::transform(lq.begin(),lq.end(),lq.begin(),::tolower);
        for(auto& e:all) {
            if(e.deleted)continue;
            std::string n=e.name; std::transform(n.begin(),n.end(),n.begin(),::tolower);
            if(n.find(lq)!=std::string::npos){r.push_back(e);if((int)r.size()>=limit)break;}
        }
        return r;
    }
};

struct RechnungEntity {
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

class RechnungDao : public BaseDao<RechnungEntity> {
public:
    explicit RechnungDao() {}
    std::vector<RechnungEntity> getActive() {
        auto all=getAll(); std::vector<RechnungEntity> r;
        for(auto& e:all) if(!e.deleted && e.active) r.push_back(e);
        return r;
    }
    std::vector<RechnungEntity> search(const std::string& q, int limit=100) {
        auto all=getAll(); std::vector<RechnungEntity> r;
        std::string lq=q; std::transform(lq.begin(),lq.end(),lq.begin(),::tolower);
        for(auto& e:all) {
            if(e.deleted)continue;
            std::string n=e.name; std::transform(n.begin(),n.end(),n.begin(),::tolower);
            if(n.find(lq)!=std::string::npos){r.push_back(e);if((int)r.size()>=limit)break;}
        }
        return r;
    }
};

struct BuchungssatzEntity {
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

class BuchungssatzDao : public BaseDao<BuchungssatzEntity> {
public:
    explicit BuchungssatzDao() {}
    std::vector<BuchungssatzEntity> getActive() {
        auto all=getAll(); std::vector<BuchungssatzEntity> r;
        for(auto& e:all) if(!e.deleted && e.active) r.push_back(e);
        return r;
    }
    std::vector<BuchungssatzEntity> search(const std::string& q, int limit=100) {
        auto all=getAll(); std::vector<BuchungssatzEntity> r;
        std::string lq=q; std::transform(lq.begin(),lq.end(),lq.begin(),::tolower);
        for(auto& e:all) {
            if(e.deleted)continue;
            std::string n=e.name; std::transform(n.begin(),n.end(),n.begin(),::tolower);
            if(n.find(lq)!=std::string::npos){r.push_back(e);if((int)r.size()>=limit)break;}
        }
        return r;
    }
};

struct Kost1Entity {
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

class Kost1Dao : public BaseDao<Kost1Entity> {
public:
    explicit Kost1Dao() {}
    std::vector<Kost1Entity> getActive() {
        auto all=getAll(); std::vector<Kost1Entity> r;
        for(auto& e:all) if(!e.deleted && e.active) r.push_back(e);
        return r;
    }
    std::vector<Kost1Entity> search(const std::string& q, int limit=100) {
        auto all=getAll(); std::vector<Kost1Entity> r;
        std::string lq=q; std::transform(lq.begin(),lq.end(),lq.begin(),::tolower);
        for(auto& e:all) {
            if(e.deleted)continue;
            std::string n=e.name; std::transform(n.begin(),n.end(),n.begin(),::tolower);
            if(n.find(lq)!=std::string::npos){r.push_back(e);if((int)r.size()>=limit)break;}
        }
        return r;
    }
};

struct Kost2Entity {
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

class Kost2Dao : public BaseDao<Kost2Entity> {
public:
    explicit Kost2Dao() {}
    std::vector<Kost2Entity> getActive() {
        auto all=getAll(); std::vector<Kost2Entity> r;
        for(auto& e:all) if(!e.deleted && e.active) r.push_back(e);
        return r;
    }
    std::vector<Kost2Entity> search(const std::string& q, int limit=100) {
        auto all=getAll(); std::vector<Kost2Entity> r;
        std::string lq=q; std::transform(lq.begin(),lq.end(),lq.begin(),::tolower);
        for(auto& e:all) {
            if(e.deleted)continue;
            std::string n=e.name; std::transform(n.begin(),n.end(),n.begin(),::tolower);
            if(n.find(lq)!=std::string::npos){r.push_back(e);if((int)r.size()>=limit)break;}
        }
        return r;
    }
};

} // namespace org::projectforge::business::fibu
