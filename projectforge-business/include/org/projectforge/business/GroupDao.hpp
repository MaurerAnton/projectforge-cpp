#pragma once

#include <org/projectforge/business/BaseDao.hpp>
#include <string>
#include <vector>
#include <optional>

namespace org::projectforge::business::user {

struct Group {
    int64_t id = 0;
    std::string name;
    std::string description;
    int64_t created_at = 0;
    int64_t updated_at = 0;
    bool active = true;
    bool local_group = true;
};

inline auto make_group_table() {
    using namespace sqlite_orm;
    return make_table("t_group",
        make_column("id", &Group::id, primary_key().autoincrement()),
        make_column("name", &Group::name),
        make_column("description", &Group::description),
        make_column("created_at", &Group::created_at),
        make_column("updated_at", &Group::updated_at),
        make_column("active", &Group::active),
        make_column("local_group", &Group::local_group));
}

struct GroupRight {
    int64_t id = 0;
    int64_t group_id = 0;
    std::string right_id;
    int64_t granted_at = 0;
    int64_t granted_by = 0;
};

inline auto make_group_right_table() {
    using namespace sqlite_orm;
    return make_table("t_group_right",
        make_column("id", &GroupRight::id, primary_key().autoincrement()),
        make_column("group_id", &GroupRight::group_id),
        make_column("right_id", &GroupRight::right_id),
        make_column("granted_at", &GroupRight::granted_at),
        make_column("granted_by", &GroupRight::granted_by));
}

class GroupDao : public BaseDao<Group> {
public:
    explicit GroupDao(std::shared_ptr<sqlite_orm::database> db);

    std::optional<Group> findByName(const std::string& name) const;
    std::vector<Group> findActive() const;
    std::vector<Group> search(const std::string& query) const;

    bool grantRight(int64_t groupId, const std::string& rightId, int64_t grantedBy);
    bool revokeRight(int64_t groupId, const std::string& rightId);
    bool hasRight(int64_t groupId, const std::string& rightId) const;
    std::vector<GroupRight> getGroupRights(int64_t groupId) const;
    std::vector<std::string> getRightIds(int64_t groupId) const;

    std::vector<int64_t> getMemberIds(int64_t groupId) const;
    std::vector<int64_t> getGroupIdsForUser(int64_t userId) const;

    json toJson(const Group& group) const override;
    Group fromJson(const json& j) const override;
};

} // namespace org::projectforge::business::user
