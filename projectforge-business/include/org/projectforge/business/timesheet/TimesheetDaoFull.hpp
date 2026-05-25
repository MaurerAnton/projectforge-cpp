// ProjectForge C++ port — GPL v3
#pragma once
#include "org/projectforge/business/BaseDao.hpp"
#include <string>
#include <vector>
#include <algorithm>
#include <optional>
#include <stdexcept>
#include <spdlog/spdlog.h>

namespace org::projectforge::business::timesheet {

enum class TimesheetBookingStatus { NOT_BOOKED, BOOKED, REJECTED, RUNNING };
enum class OrderDirection { ASC, DESC };

struct TimesheetFilter {
    std::optional<int64_t> userId, taskId, startTime, stopTime;
    bool recursive = false, onlyBillable = false, deleted = false;
    OrderDirection orderType = OrderDirection::DESC;
    int maxRows = 100;
    std::string searchString;
    TimesheetFilter() = default;
};

struct TimesheetDO {
    DECLARE_ENTITY_FIELDS();
    int64_t userId = -1;
    int64_t taskId = -1;
    int64_t startTime = 0;
    int64_t stopTime = 0;
    int64_t duration = 0; // in milliseconds
    std::string description;
    std::string location;
    int64_t kost2Id = -1;
    TimesheetBookingStatus bookingStatus = TimesheetBookingStatus::NOT_BOOKED;
    bool invoiced = false;
    bool weekend = false;
    std::string tags;
    std::string aiSuggestions;

    int64_t getDurationSeconds() const { return duration / 1000; }
    int64_t getDurationMinutes() const { return duration / 60000; }
    double getDurationHours() const { return duration / 3600000.0; }

    void setDurationFromStartStop() {
        if (startTime > 0 && stopTime > startTime) duration = stopTime - startTime;
    }

    nlohmann::json toJson() const {
        nlohmann::json j; JSON_ENTITY_BASE(j);
        if (userId >= 0) j["userId"] = userId;
        if (taskId >= 0) j["taskId"] = taskId;
        if (startTime > 0) j["startTime"] = startTime;
        if (stopTime > 0) j["stopTime"] = stopTime;
        j["duration"] = duration;
        if (!description.empty()) j["description"] = description;
        if (!location.empty()) j["location"] = location;
        if (kost2Id >= 0) j["kost2Id"] = kost2Id;
        j["bookingStatus"] = static_cast<int>(bookingStatus);
        j["invoiced"] = invoiced;
        j["weekend"] = weekend;
        if (!tags.empty()) j["tags"] = tags;
        return j;
    }
    void fromJson(const nlohmann::json& j) {
        FROMJSON_ENTITY_BASE(j);
        if (j.contains("userId")) userId = j["userId"];
        if (j.contains("taskId")) taskId = j["taskId"];
        if (j.contains("startTime")) startTime = j["startTime"];
        if (j.contains("stopTime")) stopTime = j["stopTime"];
        if (j.contains("duration")) duration = j["duration"];
        if (j.contains("description")) description = j["description"];
        if (j.contains("location")) location = j["location"];
        if (j.contains("kost2Id")) kost2Id = j["kost2Id"];
        if (j.contains("bookingStatus")) bookingStatus = static_cast<TimesheetBookingStatus>(j["bookingStatus"].get<int>());
        if (j.contains("invoiced")) invoiced = j["invoiced"];
        if (j.contains("weekend")) weekend = j["weekend"];
        if (j.contains("tags")) tags = j["tags"];
    }
};

class TimesheetDao : public BaseDao<TimesheetDO> {
public:
    static constexpr int64_t MAXIMUM_DURATION = 86400000LL; // 24 hours

    explicit TimesheetDao(Storage& storage) : BaseDao<TimesheetDO>(storage) {}

    // Get tags list for autocompletion
    std::vector<std::string> getTags(const std::string& currentTag = "") {
        std::vector<std::string> tags;
        auto all = getAll();
        for (auto& ts : all) {
            if (ts.deleted || ts.tags.empty()) continue;
            std::istringstream ss(ts.tags);
            std::string tag;
            while (std::getline(ss, tag, ';')) {
                if (!tag.empty() && std::find(tags.begin(), tags.end(), tag) == tags.end())
                    tags.push_back(tag);
            }
        }
        if (!currentTag.empty() && std::find(tags.begin(), tags.end(), currentTag) == tags.end())
            tags.push_back(currentTag);
        return tags;
    }

    // Get years with timesheets for a user
    std::vector<int> getYears(int64_t userId) {
        std::vector<int> years;
        auto all = getAll();
        for (auto& ts : all) {
            if (ts.deleted) continue;
            if (userId >= 0 && ts.userId != userId) continue;
            if (ts.startTime > 0) {
                auto tt = std::chrono::system_clock::to_time_t(
                    std::chrono::system_clock::from_time_t(ts.startTime / 1000));
                int year = std::localtime(&tt)->tm_year + 1900;
                if (std::find(years.begin(), years.end(), year) == years.end())
                    years.push_back(year);
            }
        }
        std::sort(years.begin(), years.end());
        return years;
    }

    // Build query filter from TimesheetFilter
    std::vector<TimesheetDO> select(const TimesheetFilter& filter) {
        auto all = getAll();
        std::vector<TimesheetDO> result;

        for (auto& ts : all) {
            if (ts.deleted != filter.deleted) continue;
            if (filter.userId.has_value() && ts.userId != *filter.userId) continue;
            if (filter.taskId.has_value()) {
                if (filter.recursive) {
                    // Would need TaskTree for recursive lookup
                    if (ts.taskId != *filter.taskId) continue;
                } else {
                    if (ts.taskId != *filter.taskId) continue;
                }
            }
            if (filter.startTime.has_value()) {
                if (filter.stopTime.has_value()) {
                    if (!(ts.stopTime >= *filter.startTime && ts.startTime <= *filter.stopTime)) continue;
                } else {
                    if (ts.startTime < *filter.startTime) continue;
                }
            } else if (filter.stopTime.has_value()) {
                if (ts.startTime > *filter.stopTime) continue;
            }
            if (filter.onlyBillable && ts.bookingStatus != TimesheetBookingStatus::BOOKED) continue;

            // Search string filtering
            if (!filter.searchString.empty()) {
                std::string lower = filter.searchString;
                std::transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
                std::string desc = ts.description;
                std::transform(desc.begin(), desc.end(), desc.begin(), ::tolower);
                if (desc.find(lower) == std::string::npos) continue;
            }

            result.push_back(ts);
        }

        // Sort
        std::sort(result.begin(), result.end(), [&](const auto& a, const auto& b) {
            if (filter.orderType == OrderDirection::DESC)
                return a.startTime > b.startTime;
            return a.startTime < b.startTime;
        });

        // Limit
        if (static_cast<int>(result.size()) > filter.maxRows)
            result.resize(filter.maxRows);

        return result;
    }

    // Start a timesheet
    TimesheetDO startTimesheet(int64_t userId, int64_t taskId, const std::string& description = "") {
        // Check no running timesheet exists
        auto active = getActiveTimesheets(userId);
        if (!active.empty()) {
            throw std::runtime_error("User already has a running timesheet");
        }

        TimesheetDO ts;
        ts.userId = userId;
        ts.taskId = taskId;
        ts.startTime = nowMillis();
        ts.description = description;
        ts.bookingStatus = TimesheetBookingStatus::RUNNING;
        ts.touch();
        return save(ts);
    }

    // Stop a timesheet
    TimesheetDO stopTimesheet(int64_t id, const std::string& extraDesc = "") {
        auto ts = getById(id);
        if (!ts.has_value() || ts->bookingStatus != TimesheetBookingStatus::RUNNING) {
            throw std::runtime_error("No running timesheet found for id=" + std::to_string(id));
        }

        ts->stopTime = nowMillis();
        ts->duration = ts->stopTime - ts->startTime;
        ts->bookingStatus = TimesheetBookingStatus::NOT_BOOKED;

        if (!extraDesc.empty()) {
            if (!ts->description.empty()) ts->description += " | ";
            ts->description += extraDesc;
        }

        // Validate
        validateTimesheet(*ts);

        ts->setLastUpdate();
        return save(*ts);
    }

    // Get active (running) timesheets
    std::vector<TimesheetDO> getActiveTimesheets(int64_t userId = -1) {
        auto all = getAll();
        std::vector<TimesheetDO> result;
        for (auto& ts : all) {
            if (ts.deleted) continue;
            if (ts.bookingStatus == TimesheetBookingStatus::RUNNING) {
                if (userId < 0 || ts.userId == userId) result.push_back(ts);
            }
        }
        return result;
    }

    // Get timesheets for a user within date range
    std::vector<TimesheetDO> getByUserAndDateRange(int64_t userId, int64_t from, int64_t to) {
        auto all = getAll();
        std::vector<TimesheetDO> result;
        for (auto& ts : all) {
            if (ts.deleted || ts.userId != userId) continue;
            if (ts.startTime >= from && ts.startTime <= to) result.push_back(ts);
        }
        std::sort(result.begin(), result.end(), [](auto& a, auto& b) { return a.startTime > b.startTime; });
        return result;
    }

    // Get timesheets for invoicing
    std::vector<TimesheetDO> getForInvoicing(int64_t kost2Id = -1) {
        auto all = getAll();
        std::vector<TimesheetDO> result;
        for (auto& ts : all) {
            if (ts.deleted || ts.invoiced) continue;
            if (ts.bookingStatus != TimesheetBookingStatus::BOOKED) continue;
            if (kost2Id >= 0 && ts.kost2Id != kost2Id) continue;
            result.push_back(ts);
        }
        return result;
    }

    // Mark timesheets as invoiced
    void markInvoiced(const std::vector<int64_t>& ids) {
        for (auto id : ids) {
            auto ts = getById(id);
            if (ts.has_value()) {
                ts->invoiced = true;
                ts->setLastUpdate();
                save(*ts);
            }
        }
    }

    // Get total duration for task
    int64_t getTotalDurationForTask(int64_t taskId) {
        int64_t total = 0;
        auto all = getAll();
        for (auto& ts : all) {
            if (!ts.deleted && ts.taskId == taskId) total += ts.duration;
        }
        return total;
    }

    // Get total duration for user
    int64_t getTotalDurationForUser(int64_t userId, int64_t from = 0, int64_t to = 0) {
        int64_t total = 0;
        auto all = getAll();
        for (auto& ts : all) {
            if (ts.deleted || ts.userId != userId) continue;
            if (from > 0 && ts.startTime < from) continue;
            if (to > 0 && ts.startTime > to) continue;
            total += ts.duration;
        }
        return total;
    }

    // Validate a timesheet entry
    void validateTimesheet(const TimesheetDO& ts) {
        if (ts.duration == 0) {
            throw std::runtime_error("timesheet.error.zeroDuration");
        }
        if (ts.duration > MAXIMUM_DURATION) {
            throw std::runtime_error("timesheet.error.maximumDurationExceeded");
        }
        if (ts.stopTime <= ts.startTime) {
            throw std::runtime_error("Stop time must be after start time");
        }
    }

    // Get latest timesheets
    std::vector<TimesheetDO> getLatest(int limit = 50) {
        auto all = getAll();
        std::sort(all.begin(), all.end(), [](auto& a, auto& b) { return a.created > b.created; });
        if (static_cast<int>(all.size()) > limit) all.resize(limit);
        return all;
    }

    // Delete user timesheets
    void deleteUserTimesheets(int64_t userId) {
        auto all = getAll();
        for (auto& ts : all) {
            if (ts.userId == userId) {
                ts.deleted = true;
                ts.setLastUpdate();
                save(ts);
            }
        }
    }

private:
    static int64_t nowMillis() {
        return std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::system_clock::now().time_since_epoch()).count();
    }
};

} // namespace
