// ProjectForge C++ port — GPL v3 — www.projectforge.org
#pragma once
#include "org/projectforge/business/BaseDao.hpp"
#include <string>
#include <vector>

namespace org::projectforge::business::user {

struct GroupEntity {
    DECLARE_ENTITY_FIELDS();
    std::string name;
    std::string description;
    bool localGroup = true;
    std::vector<int64_t> userIds;

    nlohmann::json toJson() const {
        nlohmann::json j;
        JSON_ENTITY_BASE(j);
        j["name"] = name;
        if (!description.empty()) j["description"] = description;
        j["localGroup"] = localGroup;
        return j;
    }
    void fromJson(const nlohmann::json& j) {
        FROMJSON_ENTITY_BASE(j);
        if (j.contains("name")) name = j["name"];
        if (j.contains("description")) description = j["description"];
        if (j.contains("localGroup")) localGroup = j["localGroup"];
    }
};

class GroupDao : public BaseDao<GroupEntity> {
public:
    explicit GroupDao(Storage& storage) : BaseDao<GroupEntity>(storage) {}

    std::optional<GroupEntity> findByName(const std::string& name) {
        try {
            auto r = storage_.template get_all<GroupEntity>(
                sqlite_orm::where(sqlite_orm::c(&GroupEntity::name) == name));
            return r.empty() ? std::nullopt : std::optional(r[0]);
        } catch (...) { return std::nullopt; }
    }

    std::vector<GroupEntity> getUserGroups(int64_t userId) {
        auto all = getAll();
        std::vector<GroupEntity> result;
        for (auto& g : all) {
            if (std::find(g.userIds.begin(), g.userIds.end(), userId) != g.userIds.end()) {
                result.push_back(g);
            }
        }
        return result;
    }

    bool addUserToGroup(int64_t groupId, int64_t userId) {
        auto g = getById(groupId);
        if (!g.has_value()) return false;
        if (std::find(g->userIds.begin(), g->userIds.end(), userId) == g->userIds.end()) {
            g->userIds.push_back(userId);
            save(*g);
        }
        return true;
    }

    bool removeUserFromGroup(int64_t groupId, int64_t userId) {
        auto g = getById(groupId);
        if (!g.has_value()) return false;
        auto it = std::remove(g->userIds.begin(), g->userIds.end(), userId);
        if (it != g->userIds.end()) {
            g->userIds.erase(it, g->userIds.end());
            save(*g);
        }
        return true;
    }
};
}