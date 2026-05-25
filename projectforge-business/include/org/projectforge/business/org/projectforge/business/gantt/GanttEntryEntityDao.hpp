// ProjectForge C++ port — GPL v3 — www.projectforge.org
#pragma once
#include "org/projectforge/business/BaseDao.hpp"
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>
#include <sstream>
#include <nlohmann/json.hpp>

namespace org::projectforge::business::gantt {

struct GanttEntryEntity {
    DECLARE_ENTITY_FIELDS();
    int64_t taskId = -1;
    int64_t startDate = 0;
    int64_t endDate = 0;
    int64_t duration = 0;
    std::string dependencyType;
    std::vector<int64_t> dependencies;
    int progress = 0;
    std::string color;

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

class GanttEntryDao : public BaseDao<GanttEntryEntity> {
public:
    explicit GanttEntryDao() {}
    std::vector<GanttEntryEntity> getRecent(int limit=20) {
        auto all = getAll();
        std::sort(all.begin(), all.end(), [](auto& a, auto& b){ return a.lastUpdate > b.lastUpdate; });
        if ((int)all.size()>limit) all.resize(limit);
        return all;
    }
    std::vector<GanttEntryEntity> search(const std::string& q, int limit=100) {
        auto all = getAll(); std::vector<GanttEntryEntity> r;
        std::string lower=q; std::transform(lower.begin(),lower.end(),lower.begin(),::tolower);
        for(auto& e : all) {
            if(e.deleted) continue;
            if(searchMatch(e,lower)) { r.push_back(e); if((int)r.size()>=limit) break; }
        }
        return r;
    }
    std::vector<GanttEntryEntity> getByTask(int64_t tid) {
        auto all = getAll(); std::vector<GanttEntryEntity> r;
        for(auto& g : all) if(!g.deleted && g.taskId==tid) r.push_back(g);
        return r;
    }
    std::vector<GanttEntryEntity> getWithDependencies() {
        auto all = getAll(); std::vector<GanttEntryEntity> r;
        for(auto& g : all) if(!g.deleted && !g.dependencies.empty()) r.push_back(g);
        return r;
    }
protected:
    bool searchMatch(const GanttEntryEntity& e, const std::string& q);
};

} // namespace
