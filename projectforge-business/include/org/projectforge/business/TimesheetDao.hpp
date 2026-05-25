#pragma once

#include <org/projectforge/business/BaseDao.hpp>
#include <string>
#include <vector>
#include <optional>
#include <cstdint>

namespace org::projectforge::business::timesheet {

struct Timesheet {
    int64_t id = 0;
    int64_t user_id = 0;
    int64_t task_id = 0;
    int64_t start_time = 0; // unix timestamp
    int64_t stop_time = 0;
    int64_t duration_seconds = 0;
    std::string description;
    std::string location;
    bool billable = true;
    bool booked = false;
    int64_t kost2_id = 0;
    double cost_to_bill = 0.0;
    std::string status; // RUNNING, STOPPED
    int64_t created_at = 0;
    int64_t updated_at = 0;
    double latitude = 0.0;
    double longitude = 0.0;
    int64_t week_of_year = 0;
    std::string reference;
};

inline auto make_timesheet_table() {
    using namespace sqlite_orm;
    return make_table("t_timesheet",
        make_column("id", &Timesheet::id, primary_key().autoincrement()),
        make_column("user_id", &Timesheet::user_id),
        make_column("task_id", &Timesheet::task_id),
        make_column("start_time", &Timesheet::start_time),
        make_column("stop_time", &Timesheet::stop_time),
        make_column("duration_seconds", &Timesheet::duration_seconds),
        make_column("description", &Timesheet::description),
        make_column("location", &Timesheet::location),
        make_column("billable", &Timesheet::billable),
        make_column("booked", &Timesheet::booked),
        make_column("kost2_id", &Timesheet::kost2_id),
        make_column("cost_to_bill", &Timesheet::cost_to_bill),
        make_column("status", &Timesheet::status),
        make_column("created_at", &Timesheet::created_at),
        make_column("updated_at", &Timesheet::updated_at),
        make_column("latitude", &Timesheet::latitude),
        make_column("longitude", &Timesheet::longitude),
        make_column("week_of_year", &Timesheet::week_of_year),
        make_column("reference", &Timesheet::reference));
}

struct TimesheetTemplate {
    int64_t id = 0;
    int64_t user_id = 0;
    std::string name;
    int64_t task_id = 0;
    int64_t kost2_id = 0;
    int32_t duration_hours = 0;
    int32_t duration_minutes = 0;
    std::string description;
    std::string location;
    bool billable = true;
};

inline auto make_timesheet_template_table() {
    using namespace sqlite_orm;
    return make_table("t_timesheet_template",
        make_column("id", &TimesheetTemplate::id, primary_key().autoincrement()),
        make_column("user_id", &TimesheetTemplate::user_id),
        make_column("name", &TimesheetTemplate::name),
        make_column("task_id", &TimesheetTemplate::task_id),
        make_column("kost2_id", &TimesheetTemplate::kost2_id),
        make_column("duration_hours", &TimesheetTemplate::duration_hours),
        make_column("duration_minutes", &TimesheetTemplate::duration_minutes),
        make_column("description", &TimesheetTemplate::description),
        make_column("location", &TimesheetTemplate::location),
        make_column("billable", &TimesheetTemplate::billable));
}

class TimesheetDao : public BaseDao<Timesheet> {
public:
    explicit TimesheetDao(std::shared_ptr<sqlite_orm::database> db);

    // Running timesheet (stopwatch)
    std::optional<Timesheet> getRunningTimesheet(int64_t userId) const;
    Timesheet startTimesheet(int64_t userId, int64_t taskId, const std::string& description);
    Timesheet stopTimesheet(int64_t timesheetId);
    bool stopRunningTimesheet(int64_t userId);

    // Queries
    std::vector<Timesheet> findByUser(int64_t userId) const;
    std::vector<Timesheet> findByTask(int64_t taskId) const;
    std::vector<Timesheet> findByDateRange(int64_t from, int64_t to) const;
    std::vector<Timesheet> findByUserAndDateRange(int64_t userId, int64_t from, int64_t to) const;
    std::vector<Timesheet> findByWeek(int64_t userId, int32_t year, int32_t week) const;
    std::vector<Timesheet> findByKost2(int64_t kost2Id) const;
    std::vector<Timesheet> findUnbooked() const;
    std::vector<Timesheet> findBillable() const;
    std::vector<Timesheet> search(const std::string& query) const;

    // Aggregations
    int64_t getTotalDuration(int64_t userId, int64_t from, int64_t to) const;
    int64_t getTotalDurationByTask(int64_t taskId) const;
    double getTotalCostToBill(int64_t userId, int64_t from, int64_t to) const;
    double getTotalCostByKost2(int64_t kost2Id) const;
    std::map<int64_t, int64_t> getDurationByTask(int64_t userId, int64_t from, int64_t to) const;
    std::map<int64_t, int64_t> getDurationByUser(int64_t from, int64_t to) const;

    // Booking
    bool markBooked(int64_t timesheetId);
    bool markBooked(const std::vector<int64_t>& ids);
    bool markUnbooked(int64_t timesheetId);

    // Templates
    std::vector<TimesheetTemplate> getTemplates(int64_t userId) const;
    TimesheetTemplate saveTemplate(const TimesheetTemplate& tmpl);
    bool deleteTemplate(int64_t templateId);
    Timesheet createFromTemplate(int64_t userId, int64_t templateId);

    // Validation
    bool isOverlapping(int64_t userId, int64_t start, int64_t stop, int64_t excludeId = 0) const;
    bool validateTimesheet(const Timesheet& ts, std::string& errorMsg) const;

    json toJson(const Timesheet& ts) const override;
    Timesheet fromJson(const json& j) const override;

    // Statistics
    struct DailyStats {
        int64_t date = 0;
        int64_t total_seconds = 0;
        size_t entry_count = 0;
    };
    std::vector<DailyStats> getDailyStats(int64_t userId, int64_t from, int64_t to) const;
};

} // namespace org::projectforge::business::timesheet
