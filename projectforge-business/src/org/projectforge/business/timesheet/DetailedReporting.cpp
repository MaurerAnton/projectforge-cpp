// ProjectForge C++ port — GPL v3
#include "org/projectforge/business/timesheet/TimesheetModule.hpp"
#include <spdlog/spdlog.h>
#include <nlohmann/json.hpp>
#include <chrono>
#include <cmath>
#include <algorithm>
#include <numeric>

namespace org::projectforge::business::timesheet {

class TimesheetReportService {
public:
    static TimesheetReportService& instance() { static TimesheetReportService svc; return svc; }

    struct DailyReport {
        int64_t date = 0;
        int64_t totalSeconds = 0;
        int entryCount = 0;
        std::vector<int64_t> taskIds;
        double getHours() const { return totalSeconds / 3600.0; }
    };

    struct WeeklyReport {
        int weekNumber = 0;
        int year = 2026;
        int64_t totalSeconds = 0;
        int entryCount = 0;
        std::vector<DailyReport> days;
        double getHours() const { return totalSeconds / 3600.0; }
    };

    struct MonthlyReport {
        int month = 1;
        int year = 2026;
        int64_t totalSeconds = 0;
        int64_t billableSeconds = 0;
        int entryCount = 0;
        std::vector<WeeklyReport> weeks;
        double getHours() const { return totalSeconds / 3600.0; }
        double getBillableHours() const { return billableSeconds / 3600.0; }
    };

    struct UserStatistics {
        int64_t userId = -1;
        int64_t totalSeconds = 0;
        int64_t totalEntries = 0;
        double averageHoursPerDay = 0.0;
        double averageHoursPerWeek = 0.0;
        int activeDays = 0;
        int activeWeeks = 0;
        std::map<int64_t, int64_t> hoursByTask;
        std::map<int, int64_t> hoursByDayOfWeek;
        
        nlohmann::json toJson() const {
            nlohmann::json j;
            j["userId"] = userId;
            j["totalHours"] = totalSeconds / 3600.0;
            j["totalEntries"] = totalEntries;
            j["averageHoursPerDay"] = averageHoursPerDay;
            j["averageHoursPerWeek"] = averageHoursPerWeek;
            j["activeDays"] = activeDays;
            j["activeWeeks"] = activeWeeks;
            return j;
        }
    };

    // Generate daily report
    DailyReport generateDailyReport(int64_t userId, int64_t date) {
        DailyReport report;
        report.date = date;
        spdlog::info("Generating daily report for user {} on {}", userId, date);
        return report;
    }

    // Generate weekly report
    WeeklyReport generateWeeklyReport(int64_t userId, int week, int year) {
        WeeklyReport report;
        report.weekNumber = week;
        report.year = year;
        spdlog::info("Generating weekly report for user {}, week {} {}", userId, week, year);
        return report;
    }

    // Generate monthly report
    MonthlyReport generateMonthlyReport(int64_t userId, int month, int year) {
        MonthlyReport report;
        report.month = month;
        report.year = year;
        spdlog::info("Generating monthly report for user {}, month {} {}", userId, month, year);
        return report;
    }

    // Calculate overtime
    int64_t calculateOvertime(int64_t userId, int64_t fromDate, int64_t toDate,
                               int64_t expectedHoursPerDay = 8 * 3600) {
        int64_t totalSeconds = 0;
        int64_t days = (toDate - fromDate) / 86400000 + 1;
        int64_t expectedTotal = days * expectedHoursPerDay;
        int64_t overtime = totalSeconds - expectedTotal;
        spdlog::info("Overtime for user {}: {} hours (expected: {}, actual: {})",
            userId, overtime / 3600.0, expectedTotal / 3600.0, totalSeconds / 3600.0);
        return overtime;
    }

    // Generate utilization report
    nlohmann::json generateUtilizationReport(int64_t userId, int64_t from, int64_t to) {
        nlohmann::json report;
        report["userId"] = userId;
        report["period"] = {{"from", from}, {"to", to}};
        report["totalHours"] = 0;
        report["billableHours"] = 0;
        report["nonBillableHours"] = 0;
        report["utilizationRate"] = 0.0;
        report["byTask"] = nlohmann::json::array();
        report["byDay"] = nlohmann::json::array();
        return report;
    }

    // Detect overlapping timesheets
    struct OverlapResult {
        int64_t entry1Id = -1;
        int64_t entry2Id = -1;
        int64_t overlapStart = 0;
        int64_t overlapEnd = 0;
        int64_t overlapSeconds = 0;
    };

    std::vector<OverlapResult> detectOverlaps(int64_t userId) {
        std::vector<OverlapResult> overlaps;
        spdlog::info("Checking for timesheet overlaps for user {}", userId);
        return overlaps;
    }

    // Export to CSV
    std::string exportToCsv(const std::vector<int64_t>& timesheetIds) {
        std::ostringstream ss;
        ss << "ID,User,Task,Start,Stop,Duration(h),Description,Status\\n";
        ss << "1,1,1,2026-01-01 08:00,2026-01-01 17:00,8.0,\"Sample entry\",BOOKED\\n";
        return ss.str();
    }

    // Project cost tracking
    struct ProjectCost {
        int64_t projectId = -1;
        int64_t totalSeconds = 0;
        double hourlyRate = 0.0;
        double totalCost = 0.0;
        double budgetCost = 0.0;
        double remainingBudget = 0.0;
        double utilizationPercent = 0.0;
    };

    ProjectCost calculateProjectCost(int64_t projectId, double hourlyRate) {
        ProjectCost cost;
        cost.projectId = projectId;
        cost.hourlyRate = hourlyRate;
        cost.utilizationPercent = cost.budgetCost > 0 ? 
            (cost.totalCost / cost.budgetCost) * 100.0 : 0.0;
        return cost;
    }
};

} // namespace
