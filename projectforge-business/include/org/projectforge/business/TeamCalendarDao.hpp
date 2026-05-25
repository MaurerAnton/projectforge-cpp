#pragma once

#include <org/projectforge/business/BaseDao.hpp>
#include <string>
#include <vector>
#include <optional>
#include <cstdint>
#include <map>

namespace org::projectforge::business::teamcal {

struct TeamCalendar {
    int64_t id = 0;
    std::string name;
    std::string description;
    int64_t owner_id = 0;
    std::string color;
    bool active = true;
    bool shared_to_all = false;
    int64_t created_at = 0;
    int64_t updated_at = 0;
};

inline auto make_team_calendar_table() {
    using namespace sqlite_orm;
    return make_table("t_team_calendar",
        make_column("id", &TeamCalendar::id, primary_key().autoincrement()),
        make_column("name", &TeamCalendar::name),
        make_column("description", &TeamCalendar::description),
        make_column("owner_id", &TeamCalendar::owner_id),
        make_column("color", &TeamCalendar::color),
        make_column("active", &TeamCalendar::active),
        make_column("shared_to_all", &TeamCalendar::shared_to_all),
        make_column("created_at", &TeamCalendar::created_at),
        make_column("updated_at", &TeamCalendar::updated_at));
}

struct TeamCalMember {
    int64_t id = 0;
    int64_t calendar_id = 0;
    int64_t user_id = 0;
    std::string access_level; // READ, WRITE, ADMIN
    int64_t added_at = 0;
};

inline auto make_team_cal_member_table() {
    using namespace sqlite_orm;
    return make_table("t_team_cal_member",
        make_column("id", &TeamCalMember::id, primary_key().autoincrement()),
        make_column("calendar_id", &TeamCalMember::calendar_id),
        make_column("user_id", &TeamCalMember::user_id),
        make_column("access_level", &TeamCalMember::access_level),
        make_column("added_at", &TeamCalMember::added_at));
}

class TeamCalendarDao : public BaseDao<TeamCalendar> {
public:
    explicit TeamCalendarDao(std::shared_ptr<sqlite_orm::database> db);

    std::vector<TeamCalendar> findByOwner(int64_t ownerId) const;
    std::vector<TeamCalendar> findAccessible(int64_t userId) const;
    std::vector<TeamCalendar> findSharedToAll() const;
    std::vector<TeamCalendar> findActive() const;
    std::vector<TeamCalendar> search(const std::string& query) const;

    // Members
    std::vector<TeamCalMember> getMembers(int64_t calendarId) const;
    bool addMember(int64_t calendarId, int64_t userId, const std::string& accessLevel);
    bool removeMember(int64_t calendarId, int64_t userId);
    bool updateMemberAccess(int64_t calendarId, int64_t userId, const std::string& accessLevel);
    bool isMember(int64_t calendarId, int64_t userId) const;
    std::string getAccessLevel(int64_t calendarId, int64_t userId) const;

    // Access check
    bool canRead(int64_t calendarId, int64_t userId) const;
    bool canWrite(int64_t calendarId, int64_t userId) const;
    bool canAdmin(int64_t calendarId, int64_t userId) const;

    // Visibility helpers
    std::vector<int64_t> getVisibleCalendarIds(int64_t userId) const;
    std::map<int64_t, std::string> getCalendarColorMap(const std::vector<int64_t>& calendarIds) const;

    json toJson(const TeamCalendar& cal) const override;
    TeamCalendar fromJson(const json& j) const override;
};

} // namespace org::projectforge::business::teamcal
