// ProjectForge C++ port — GPL v3 — www.projectforge.org
#pragma once
#include "AbstractBaseObject.hpp"
#include <string>
#include <nlohmann/json.hpp>

namespace org::projectforge::model::rest {

class CalendarObject : public AbstractBaseObject {
public:
    std::string subject;
    std::string location;
    std::string note;
    int64_t startDate = 0;
    int64_t endDate = 0;
    bool allDay = false;
    std::string recurrenceRule;
    int64_t ownerId = -1;
    int64_t calendarId = -1;
    std::string color;

    nlohmann::json toJson() const override {
        auto j = AbstractBaseObject::toJson();
        if (!subject.empty()) j["subject"] = subject;
        if (!location.empty()) j["location"] = location;
        if (!note.empty()) j["note"] = note;
        if (startDate > 0) j["startDate"] = startDate;
        if (endDate > 0) j["endDate"] = endDate;
        j["allDay"] = allDay;
        if (!recurrenceRule.empty()) j["recurrenceRule"] = recurrenceRule;
        if (ownerId >= 0) j["ownerId"] = ownerId;
        if (calendarId >= 0) j["calendarId"] = calendarId;
        if (!color.empty()) j["color"] = color;
        return j;
    }
};
}