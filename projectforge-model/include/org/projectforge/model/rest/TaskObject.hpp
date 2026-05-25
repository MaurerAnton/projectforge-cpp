// ProjectForge C++ port — GPL v3 — www.projectforge.org
#pragma once
#include "AbstractBaseObject.hpp"
#include <string>
#include <vector>
#include <nlohmann/json.hpp>

namespace org::projectforge::model::rest {

class TaskObject : public AbstractBaseObject {
public:
    std::string title;
    std::string shortDescription;
    std::string description;
    int64_t parentTaskId = -1;
    int64_t responsibleUserId = -1;
    std::vector<int64_t> assignedUserIds;
    std::string status;
    int priority = 3;
    int progress = 0;
    int64_t startDate = 0;
    int64_t deadline = 0;
    int64_t duration = 0;
    int64_t costBudget = 0;
    bool favorite = false;
    int order = 0;

    nlohmann::json toJson() const override {
        auto j = AbstractBaseObject::toJson();
        if (!title.empty()) j["title"] = title;
        if (!shortDescription.empty()) j["shortDescription"] = shortDescription;
        if (!description.empty()) j["description"] = description;
        if (parentTaskId >= 0) j["parentTaskId"] = parentTaskId;
        if (responsibleUserId >= 0) j["responsibleUserId"] = responsibleUserId;
        if (!status.empty()) j["status"] = status;
        j["priority"] = priority;
        j["progress"] = progress;
        if (startDate > 0) j["startDate"] = startDate;
        if (deadline > 0) j["deadline"] = deadline;
        if (duration > 0) j["duration"] = duration;
        if (costBudget > 0) j["costBudget"] = costBudget;
        j["favorite"] = favorite;
        return j;
    }
};
}