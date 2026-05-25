#pragma once

#include <org/projectforge/business/BaseDao.hpp>
#include <string>
#include <vector>
#include <optional>
#include <cstdint>

namespace org::projectforge::business::humanresources {

struct HrPlanningEntry {
    int64_t id = 0;
    int64_t user_id = 0;
    int64_t task_id = 0;
    int64_t projekt_id = 0;
    int64_t start_date = 0;
    int64_t end_date = 0;
    double planned_hours = 0.0;
    double actual_hours = 0.0;
    std::string status; // PLANNED, ACTIVE, COMPLETED, CANCELLED
    std::string description;
    int64_t kost2_id = 0;
    int64_t created_at = 0;
    int64_t updated_at = 0;
    int32_t week_of_year = 0;
    int32_t year = 0;
};

inline auto make_hr_planning_table() {
    using namespace sqlite_orm;
    return make_table("t_hr_planning",
        make_column("id", &HrPlanningEntry::id, primary_key().autoincrement()),
        make_column("user_id", &HrPlanningEntry::user_id),
        make_column("task_id", &HrPlanningEntry::task_id),
        make_column("projekt_id", &HrPlanningEntry::projekt_id),
        make_column("start_date", &HrPlanningEntry::start_date),
        make_column("end_date", &HrPlanningEntry::end_date),
        make_column("planned_hours", &HrPlanningEntry::planned_hours),
        make_column("actual_hours", &HrPlanningEntry::actual_hours),
        make_column("status", &HrPlanningEntry::status),
        make_column("description", &HrPlanningEntry::description),
        make_column("kost2_id", &HrPlanningEntry::kost2_id),
        make_column("created_at", &HrPlanningEntry::created_at),
        make_column("updated_at", &HrPlanningEntry::updated_at),
        make_column("week_of_year", &HrPlanningEntry::week_of_year),
        make_column("year", &HrPlanningEntry::year));
}

struct HrPlanning {
    int64_t id = 0;
    std::string name;
    std::string description;
    int64_t start_date = 0;
    int64_t end_date = 0;
    int64_t owner_id = 0;
    std::string status;
    int64_t created_at = 0;
    int64_t updated_at = 0;
};

inline auto make_hr_planning_master_table() {
    using namespace sqlite_orm;
    return make_table("t_hr_planning_master",
        make_column("id", &HrPlanning::id, primary_key().autoincrement()),
        make_column("name", &HrPlanning::name),
        make_column("description", &HrPlanning::description),
        make_column("start_date", &HrPlanning::start_date),
        make_column("end_date", &HrPlanning::end_date),
        make_column("owner_id", &HrPlanning::owner_id),
        make_column("status", &HrPlanning::status),
        make_column("created_at", &HrPlanning::created_at),
        make_column("updated_at", &HrPlanning::updated_at));
}

class HrDao : public BaseDao<HrPlanning> {
public:
    explicit HrDao(std::shared_ptr<sqlite_orm::database> db);

    // Entries
    std::vector<HrPlanningEntry> getEntries(int64_t planningId) const;
    std::vector<HrPlanningEntry> getEntriesByUser(int64_t userId) const;
    std::vector<HrPlanningEntry> getEntriesByDateRange(int64_t from, int64_t to) const;
    std::vector<HrPlanningEntry> getEntriesByWeek(int64_t userId, int32_t year, int32_t week) const;
    std::vector<HrPlanningEntry> getEntriesByTask(int64_t taskId) const;
    std::vector<HrPlanningEntry> getEntriesByProject(int64_t projectId) const;
    HrPlanningEntry addEntry(const HrPlanningEntry& entry);
    HrPlanningEntry updateEntry(const HrPlanningEntry& entry);
    bool removeEntry(int64_t entryId);

    // Aggregation
    double getTotalPlannedHours(int64_t userId, int64_t from, int64_t to) const;
    double getTotalActualHours(int64_t userId, int64_t from, int64_t to) const;
    double getUtilizationRate(int64_t userId, int64_t from, int64_t to) const;
    double getTotalPlannedByProject(int64_t projectId) const;

    struct WeeklyPlanning {
        int32_t year;
        int32_t week;
        double planned_hours;
        double actual_hours;
        double available_hours = 40.0;
    };
    std::vector<WeeklyPlanning> getWeeklyPlanning(int64_t userId, int64_t from, int64_t to) const;
    std::vector<WeeklyPlanning> getTeamWeeklyPlanning(const std::vector<int64_t>& userIds, int64_t from, int64_t to) const;

    // Capacity planning
    struct CapacityInfo {
        int64_t user_id;
        double total_planned;
        double total_actual;
        double capacity;
        double remaining;
    };
    std::vector<CapacityInfo> getCapacityReport(int64_t from, int64_t to) const;

    json toJson(const HrPlanning& planning) const override;
    HrPlanning fromJson(const json& j) const override;
};

} // namespace org::projectforge::business::humanresources
