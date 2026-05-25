// ProjectForge C++ port — GPL v3 — www.projectforge.org
#pragma once
#include "AbstractBaseObject.hpp"
#include <string>
#include <vector>
#include <nlohmann/json.hpp>

namespace org::projectforge::model::rest {

class TimesheetObject : public AbstractBaseObject {
public:
    int64_t userId = -1;
    int64_t taskId = -1;
    int64_t startTime = 0;
    int64_t stopTime = 0;
    int64_t durationSeconds = 0;
    std::string description;
    std::string location;
    int64_t cost2Id = -1;
    std::string bookingStatus;
    bool invoiced = false;
    bool weekend = false;

    nlohmann::json toJson() const override {
        auto j = AbstractBaseObject::toJson();
        if (userId >= 0) j["userId"] = userId;
        if (taskId >= 0) j["taskId"] = taskId;
        if (startTime > 0) j["startTime"] = startTime;
        if (stopTime > 0) j["stopTime"] = stopTime;
        j["durationSeconds"] = durationSeconds;
        if (!description.empty()) j["description"] = description;
        if (!location.empty()) j["location"] = location;
        if (cost2Id >= 0) j["cost2Id"] = cost2Id;
        if (!bookingStatus.empty()) j["bookingStatus"] = bookingStatus;
        j["invoiced"] = invoiced;
        j["weekend"] = weekend;
        return j;
    }
};
}