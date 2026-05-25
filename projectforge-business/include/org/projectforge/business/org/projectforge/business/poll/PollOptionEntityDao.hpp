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

struct PollOptionEntity {
    DECLARE_ENTITY_FIELDS();
    int64_t pollId = -1;
    std::string text;
    int position = 0;
    int voteCount = 0;

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

class PollOptionDao : public BaseDao<PollOptionEntity> {
public:
    explicit PollOptionDao() {}
    std::vector<PollOptionEntity> getRecent(int limit=20) {
        auto all = getAll();
        std::sort(all.begin(), all.end(), [](auto& a, auto& b){ return a.lastUpdate > b.lastUpdate; });
        if ((int)all.size()>limit) all.resize(limit);
        return all;
    }
    std::vector<PollOptionEntity> search(const std::string& q, int limit=100) {
        auto all = getAll(); std::vector<PollOptionEntity> r;
        std::string lower=q; std::transform(lower.begin(),lower.end(),lower.begin(),::tolower);
        for(auto& e : all) {
            if(e.deleted) continue;
            if(searchMatch(e,lower)) { r.push_back(e); if((int)r.size()>=limit) break; }
        }
        return r;
    }
    std::vector<PollOptionEntity> getByPoll(int64_t pid) {
        auto all = getAll(); std::vector<PollOptionEntity> r;
        for(auto& o : all) if(!o.deleted && o.pollId==pid) r.push_back(o);
        std::sort(r.begin(), r.end(), [](auto& a, auto& b){return a.position<b.position;});
        return r;
    }
    void addVote(int64_t optionId) {
        auto o = getById(optionId); if(o.has_value()){o->voteCount++; save(*o);}
    }
protected:
    bool searchMatch(const PollOptionEntity& e, const std::string& q);
};

} // namespace
