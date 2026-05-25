// ProjectForge C++ port — GPL v3 — www.projectforge.org
#pragma once
#include "org/projectforge/business/BaseDao.hpp"
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>

namespace org::projectforge::business::calendar {

struct CalendarEntity {
    DECLARE_ENTITY_FIELDS();
    std::string title;
    std::string description;
    std::string color = "#3366CC";
    int64_t ownerId = -1;
    std::string type = "PERSONAL";
    bool visible = true;
    nlohmann::json toJson() const {
        nlohmann::json j; JSON_ENTITY_BASE(j);
        j["title"]=title; if(!description.empty())j["description"]=description;
        j["color"]=color; j["type"]=type; j["visible"]=visible;
        return j;
    }
};

struct CalendarEventEntity {
    DECLARE_ENTITY_FIELDS();
    std::string subject;
    std::string location;
    std::string note;
    int64_t startDate = 0;
    int64_t endDate = 0;
    bool allDay = false;
    std::string recurrenceRule;
    int64_t organizerId = -1;
    int64_t calendarId = -1;
    std::string uid;
    std::string status = "CONFIRMED";
    nlohmann::json toJson() const {
        nlohmann::json j; JSON_ENTITY_BASE(j);
        if(!subject.empty())j["subject"]=subject;
        if(!location.empty())j["location"]=location;
        if(startDate>0)j["startDate"]=startDate;
        if(endDate>0)j["endDate"]=endDate;
        j["allDay"]=allDay; j["status"]=status;
        if(calendarId>=0)j["calendarId"]=calendarId;
        return j;
    }
};

class CalendarEventDao : public BaseDao<CalendarEventEntity> {
public:
    explicit CalendarEventDao(Storage& storage) : BaseDao<CalendarEventEntity>(storage) {}
    std::vector<CalendarEventEntity> getByCalendar(int64_t calId) {
        auto all = getAll(); std::vector<CalendarEventEntity> r;
        for(auto& e : all) if(!e.deleted && e.calendarId == calId) r.push_back(e);
        return r;
    }
    std::vector<CalendarEventEntity> getByDateRange(int64_t start, int64_t end) {
        auto all = getAll(); std::vector<CalendarEventEntity> r;
        for(auto& e : all) {
            if(e.deleted) continue;
            if(e.allDay) {
                if(e.startDate <= end && e.endDate >= start) r.push_back(e);
            } else {
                if(e.startDate >= start && e.startDate <= end) r.push_back(e);
            }
        }
        return r;
    }
    std::vector<CalendarEventEntity> getByOrganizer(int64_t orgId) {
        auto all = getAll(); std::vector<CalendarEventEntity> r;
        for(auto& e : all) if(!e.deleted && e.organizerId == orgId) r.push_back(e);
        return r;
    }
    std::vector<CalendarEventEntity> getUpcomingEvents(int64_t calId, int limit=10) {
        auto now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        auto evts = getByCalendar(calId);
        std::sort(evts.begin(), evts.end(), [](auto& a, auto& b){return a.startDate < b.startDate;});
        std::vector<CalendarEventEntity> r;
        for(auto& e : evts) {
            if(e.endDate >= now) { r.push_back(e); if((int)r.size()>=limit) break; }
        }
        return r;
    }
    std::string exportAsICal(int64_t eventId) {
        auto e = getById(eventId);
        if(!e.has_value()) return "";
        std::ostringstream ss;
        ss<<"BEGIN:VCALENDAR\\nVERSION:2.0\\nPRODID:-//ProjectForge//NONSGML//EN\\n";
        ss<<"BEGIN:VEVENT\\n";
        ss<<"UID:"<<e->uid<<"\\n";
        ss<<"DTSTART:"<<formatICalDate(e->startDate)<<"\\n";
        ss<<"DTEND:"<<formatICalDate(e->endDate)<<"\\n";
        ss<<"SUMMARY:"<<e->subject<<"\\n";
        if(!e->location.empty()) ss<<"LOCATION:"<<e->location<<"\\n";
        if(!e->note.empty()) ss<<"DESCRIPTION:"<<e->note<<"\\n";
        ss<<"END:VEVENT\\nEND:VCALENDAR\\n";
        return ss.str();
    }
private:
    static std::string formatICalDate(int64_t millis) {
        if(millis<=0) return "";
        auto t=std::chrono::system_clock::to_time_t(std::chrono::system_clock::from_time_t(millis/1000));
        std::ostringstream ss; ss<<std::put_time(std::gmtime(&t),"%Y%m%dT%H%M%SZ");
        return ss.str();
    }
};

// Team calendar - synced calendars for teams
struct TeamCalendarEntity {
    DECLARE_ENTITY_FIELDS();
    std::string title;
    std::string icalUrl;
    int64_t teamId = -1;
    int64_t syncIntervalMinutes = 15;
    int64_t lastSync = 0;
    bool active = true;
    std::string externalCalendarId;
};

class TeamCalendarDao : public BaseDao<TeamCalendarEntity> {
public:
    explicit TeamCalendarDao(Storage& storage) : BaseDao<TeamCalendarEntity>(storage) {}
    std::vector<TeamCalendarEntity> getActiveCalendars() {
        auto all = getAll();
        std::vector<TeamCalendarEntity> r;
        for(auto& c : all) if(!c.deleted && c.active) r.push_back(c);
        return r;
    }
    std::vector<TeamCalendarEntity> getByTeam(int64_t teamId) {
        auto all = getAll();
        std::vector<TeamCalendarEntity> r;
        for(auto& c : all) if(!c.deleted && c.teamId == teamId) r.push_back(c);
        return r;
    }
};

} // namespace
