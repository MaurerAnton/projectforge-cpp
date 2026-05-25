// ProjectForge C++ port — GPL v3 — www.projectforge.org
#pragma once
#include "org/projectforge/business/BaseDao.hpp"
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>
#include <numeric>

namespace org::projectforge::business::timesheet {

struct TimesheetEntity {
    DECLARE_ENTITY_FIELDS();
    int64_t userId = -1;
    int64_t taskId = -1;
    int64_t startTime = 0;
    int64_t stopTime = 0;
    int64_t durationSeconds = 0;
    std::string description;
    std::string location;
    int64_t kost2Id = -1;
    std::string bookingStatus = "NOT_BOOKED";
    bool invoiced = false;
    bool weekend = false;

    nlohmann::json toJson() const {
        nlohmann::json j;
        JSON_ENTITY_BASE(j);
        if (userId >= 0) j["userId"] = userId;
        if (taskId >= 0) j["taskId"] = taskId;
        if (startTime > 0) j["startTime"] = startTime;
        if (stopTime > 0) j["stopTime"] = stopTime;
        j["durationSeconds"] = durationSeconds;
        if (!description.empty()) j["description"] = description;
        if (!location.empty()) j["location"] = location;
        if (kost2Id >= 0) j["kost2Id"] = kost2Id;
        j["bookingStatus"] = bookingStatus; j["invoiced"] = invoiced;
        j["weekend"] = weekend;
        return j;
    }

    void fromJson(const nlohmann::json& j) {
        FROMJSON_ENTITY_BASE(j);
        if (j.contains("userId")) userId = j["userId"];
        if (j.contains("taskId")) taskId = j["taskId"];
        if (j.contains("startTime")) startTime = j["startTime"];
        if (j.contains("stopTime")) stopTime = j["stopTime"];
        if (j.contains("durationSeconds")) durationSeconds = j["durationSeconds"];
        if (j.contains("description")) description = j["description"];
        if (j.contains("location")) location = j["location"];
        if (j.contains("kost2Id")) kost2Id = j["kost2Id"];
        if (j.contains("bookingStatus")) bookingStatus = j["bookingStatus"];
        if (j.contains("invoiced")) invoiced = j["invoiced"];
        if (j.contains("weekend")) weekend = j["weekend"];
    }
};

class TimesheetDao : public BaseDao<TimesheetEntity> {
public:
    explicit TimesheetDao() {}

    std::vector<TimesheetEntity> getByUser(int64_t userId, int64_t startDate = 0, int64_t endDate = 0) {
        auto all = getAll();
        std::vector<TimesheetEntity> result;
        for (auto& t : all) {
            if (t.deleted || t.userId != userId) continue;
            if (startDate > 0 && t.startTime < startDate) continue;
            if (endDate > 0 && t.startTime > endDate) continue;
            result.push_back(t);
        }
        std::sort(result.begin(), result.end(), [](const auto& a, const auto& b) {
            return a.startTime > b.startTime;
        });
        return result;
    }

    std::vector<TimesheetEntity> getByTask(int64_t taskId) {
        auto all = getAll();
        std::vector<TimesheetEntity> result;
        std::copy_if(all.begin(), all.end(), std::back_inserter(result), [&](const auto& t) {
            return !t.deleted && t.taskId == taskId;
        });
        return result;
    }

    std::vector<TimesheetEntity> getByDateRange(int64_t start, int64_t end) {
        auto all = getAll();
        std::vector<TimesheetEntity> result;
        for (auto& t : all) {
            if (t.deleted) continue;
            if (t.startTime >= start && t.startTime <= end) result.push_back(t);
            else if (t.stopTime >= start && t.stopTime <= end) result.push_back(t);
        }
        return result;
    }

    std::vector<TimesheetEntity> getUnbooked(int64_t userId = -1) {
        auto all = getAll();
        std::vector<TimesheetEntity> result;
        for (auto& t : all) {
            if (t.deleted || t.bookingStatus == "BOOKED") continue;
            if (userId >= 0 && t.userId != userId) continue;
            result.push_back(t);
        }
        return result;
    }

    TimesheetEntity startTimesheet(int64_t userId, int64_t taskId, const std::string& desc = "") {
        TimesheetEntity t;
        t.userId = userId;
        t.taskId = taskId;
        t.startTime = nowMillis();
        t.description = desc;
        t.bookingStatus = "RUNNING";
        save(t);
        return t;
    }

    TimesheetEntity stopTimesheet(int64_t id, const std::string& desc = "") {
        auto t = getById(id);
        if (!t.has_value()) throw std::runtime_error("Timesheet not found");
        t->stopTime = nowMillis();
        t->durationSeconds = (t->stopTime - t->startTime) / 1000;
        t->bookingStatus = "NOT_BOOKED";
        if (!desc.empty()) t->description = desc;
        save(*t);
        return *t;
    }

    int64_t getTotalDurationForTask(int64_t taskId) {
        auto sheets = getByTask(taskId);
        int64_t total = 0;
        for (auto& s : sheets) total += s.durationSeconds;
        return total;
    }

    int64_t getTotalDurationForUser(int64_t userId, int64_t fromDate = 0, int64_t toDate = 0) {
        auto sheets = getByUser(userId, fromDate, toDate);
        int64_t total = 0;
        for (auto& s : sheets) total += s.durationSeconds;
        return total;
    }

    std::vector<TimesheetEntity> getForInvoicing(int64_t kost2Id = -1) {
        auto all = getAll();
        std::vector<TimesheetEntity> result;
        for (auto& t : all) {
            if (t.deleted || t.invoiced || t.bookingStatus != "BOOKED") continue;
            if (kost2Id >= 0 && t.kost2Id != kost2Id) continue;
            result.push_back(t);
        }
        return result;
    }

    bool markInvoiced(const std::vector<int64_t>& ids) {
        for (auto id : ids) {
            auto t = getById(id);
            if (!t.has_value()) continue;
            t->invoiced = true;
            save(*t);
        }
        return true;
    }

    bool setBookingStatus(int64_t id, const std::string& status) {
        static const std::vector<std::string> valid = {"RUNNING","NOT_BOOKED","BOOKED","REJECTED"};
        if (std::find(valid.begin(),valid.end(),status) == valid.end()) return false;
        auto t = getById(id);
        if (!t.has_value()) return false;
        t->bookingStatus = status;
        save(*t);
        return true;
    }

    std::vector<TimesheetEntity> getActiveTimesheets() {
        auto all = getAll();
        std::vector<TimesheetEntity> result;
        for (auto& t : all) {
            if (!t.deleted && t.bookingStatus == "RUNNING") result.push_back(t);
        }
        return result;
    }

    void deleteUserTimesheets(int64_t userId) {
        auto sheets = getByUser(userId);
        for (auto& s : sheets) {
            s.deleted = true;
            save(s);
        }
    }

private:
    static int64_t nowMillis() {
        return std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::system_clock::now().time_since_epoch()).count();
    }
};
} // namespace org::projectforge::business::timesheet
