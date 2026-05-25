// ProjectForge C++ port — GPL v3 — www.projectforge.org
#pragma once
#include "org/projectforge/business/BaseDao.hpp"
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>
#include <sstream>
#include <nlohmann/json.hpp>

namespace org::projectforge::business::admin {

struct AdminDashboardEntity {
    DECLARE_ENTITY_FIELDS();
    std::string title;
    std::string widgetType;
    std::string config;
    int position = 0;
    int64_t userId = -1;

    nlohmann::json toJson() const {
        nlohmann::json j; JSON_ENTITY_BASE(j);
        toJsonImpl(j);
        return j;
    }
    void fromJson(const nlohmann::json& j) {
        FROMJSON_ENTITY_BASE(j);
        fromJsonImpl(j);
    }
private:
    void toJsonImpl(nlohmann::json& j) const;
    void fromJsonImpl(const nlohmann::json& j);
};

class AdminDashboardDao : public BaseDao<AdminDashboardEntity> {
public:
    explicit AdminDashboardDao() {}
    std::vector<AdminDashboardEntity> getRecent(int limit=20) {
        auto all = getAll();
        std::sort(all.begin(), all.end(), [](auto& a, auto& b){ return a.lastUpdate > b.lastUpdate; });
        if ((int)all.size()>limit) all.resize(limit);
        return all;
    }
    std::vector<AdminDashboardEntity> search(const std::string& q, int limit=100) {
        auto all = getAll(); std::vector<AdminDashboardEntity> r;
        std::string lower=q; std::transform(lower.begin(),lower.end(),lower.begin(),::tolower);
        for(auto& e : all) {
            if(e.deleted) continue;
            if(searchMatch(e,lower)) { r.push_back(e); if((int)r.size()>=limit) break; }
        }
        return r;
    }
    std::vector<AdminDashboardEntity> getByUser(int64_t uid) {
        auto all = getAll(); std::vector<AdminDashboardEntity> r;
        for(auto& d : all) if(!d.deleted && d.userId==uid) r.push_back(d);
        std::sort(r.begin(),r.end(),[](auto& a, auto& b){return a.position<b.position;});
        return r;
    }
protected:
    bool searchMatch(const AdminDashboardEntity& e, const std::string& q);
};

} // namespace
