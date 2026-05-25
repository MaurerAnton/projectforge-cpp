// ProjectForge C++ port — GPL v3 — www.projectforge.org
#pragma once
#include "org/projectforge/business/BaseDao.hpp"
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>
#include <sstream>
#include <nlohmann/json.hpp>

namespace org::projectforge::business::poll {

struct PollEntity {
    DECLARE_ENTITY_FIELDS();
    std::string question;
    std::string description;
    int64_t ownerId = -1;
    int64_t startDate = 0;
    int64_t endDate = 0;
    bool multipleChoice = false;
    bool isActive = true;
    int totalVotes = 0;

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

class PollDao : public BaseDao<PollEntity> {
public:
    explicit PollDao(Storage& storage) : BaseDao<PollEntity>(storage) {}
    std::vector<PollEntity> getRecent(int limit=20) {
        auto all = getAll();
        std::sort(all.begin(), all.end(), [](auto& a, auto& b){ return a.lastUpdate > b.lastUpdate; });
        if ((int)all.size()>limit) all.resize(limit);
        return all;
    }
    std::vector<PollEntity> search(const std::string& q, int limit=100) {
        auto all = getAll(); std::vector<PollEntity> r;
        std::string lower=q; std::transform(lower.begin(),lower.end(),lower.begin(),::tolower);
        for(auto& e : all) {
            if(e.deleted) continue;
            if(searchMatch(e,lower)) { r.push_back(e); if((int)r.size()>=limit) break; }
        }
        return r;
    }
    std::vector<PollEntity> getActivePolls() {
        auto all = getAll(); std::vector<PollEntity> r;
        for(auto& p : all) if(!p.deleted && p.isActive) r.push_back(p);
        return r;
    }
    std::vector<PollEntity> getByOwner(int64_t uid) {
        auto all = getAll(); std::vector<PollEntity> r;
        for(auto& p : all) if(!p.deleted && p.ownerId==uid) r.push_back(p);
        return r;
    }
protected:
    bool searchMatch(const PollEntity& e, const std::string& q);
};

} // namespace
