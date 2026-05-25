// ProjectForge C++ port — GPL v3 — www.projectforge.org
#pragma once
#include "org/projectforge/business/BaseDao.hpp"
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>
#include <sstream>
#include <nlohmann/json.hpp>

namespace org::projectforge::business::teamcal {

struct TeamCalEventEntity {
    DECLARE_ENTITY_FIELDS();
    std::string uid;
    std::string subject;
    std::string description;
    std::string location;
    int64_t startDate = 0;
    int64_t endDate = 0;
    bool allDay = false;
    std::string recurrenceRule;
    std::string recurrenceId;
    int64_t calendarId = -1;
    int64_t organizerId = -1;
    std::vector<int64_t> attendeeIds;
    std::string status = "CONFIRMED";
    std::string transparency = "OPAQUE";
    int sequence = 0;
    std::string categories;

    nlohmann::json toJson() const {
        nlohmann::json j; JSON_ENTITY_BASE(j);
        toJsonImpl(j);
        return j;
    }
    void fromJson(const nlohmann::json& j) {
        FROMJSON_ENTITY_BASE(j);
        fromJsonImpl(j);
    }
private:
    void toJsonImpl(nlohmann::json& j) const;
    void fromJsonImpl(const nlohmann::json& j);
};

class TeamCalEventDao : public BaseDao<TeamCalEventEntity> {
public:
    explicit TeamCalEventDao() {}
    std::vector<TeamCalEventEntity> getRecent(int limit=20) {
        auto all = getAll();
        std::sort(all.begin(), all.end(), [](auto& a, auto& b){ return a.lastUpdate > b.lastUpdate; });
        if ((int)all.size()>limit) all.resize(limit);
        return all;
    }
    std::vector<TeamCalEventEntity> search(const std::string& q, int limit=100) {
        auto all = getAll(); std::vector<TeamCalEventEntity> r;
        std::string lower=q; std::transform(lower.begin(),lower.end(),lower.begin(),::tolower);
        for(auto& e : all) {
            if(e.deleted) continue;
            if(searchMatch(e,lower)) { r.push_back(e); if((int)r.size()>=limit) break; }
        }
        return r;
    }
    std::vector<TeamCalEventEntity> getByCalendar(int64_t cid) {
        auto all = getAll(); std::vector<TeamCalEventEntity> r;
        for(auto& e : all) if(!e.deleted && e.calendarId==cid) r.push_back(e);
        return r;
    }
    std::vector<TeamCalEventEntity> getByDateRange(int64_t start, int64_t end) {
        auto all = getAll(); std::vector<TeamCalEventEntity> r;
        for(auto& e : all) {
            if(e.deleted) continue;
            if(e.startDate<=end && e.endDate>=start) r.push_back(e);
        }
        return r;
    }
    std::vector<TeamCalEventEntity> getByOrganizer(int64_t uid) {
        auto all = getAll(); std::vector<TeamCalEventEntity> r;
        for(auto& e : all) if(!e.deleted && e.organizerId==uid) r.push_back(e);
        return r;
    }
    std::vector<TeamCalEventEntity> getUpcoming(int64_t cid, int limit=10) {
        auto now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        auto events = getByCalendar(cid);
        std::sort(events.begin(), events.end(), [](auto& a, auto& b){return a.startDate<b.startDate;});
        std::vector<TeamCalEventEntity> r;
        for(auto& e : events){if(e.endDate>=now){r.push_back(e);if((int)r.size()>=limit)break;}}
        return r;
    }
    std::string exportICal(int64_t eventId) {
        auto e = getById(eventId); if(!e.has_value()) return "";
        std::ostringstream ss;
        ss<<"BEGIN:VCALENDAR\nVERSION:2.0\nPRODID:-//ProjectForge//NONSGML//EN\n";
        ss<<"BEGIN:VEVENT\nUID:"<<e->uid<<"\nDTSTART:"<<formatICal(e->startDate)<<"\nDTEND:"<<formatICal(e->endDate)<<"\n";
        ss<<"SUMMARY:"<<e->subject<<"\n"; if(!e->location.empty()) ss<<"LOCATION:"<<e->location<<"\n";
        if(!e->description.empty()) ss<<"DESCRIPTION:"<<e->description<<"\n";
        if(!e->recurrenceRule.empty()) ss<<"RRULE:"<<e->recurrenceRule<<"\n";
        ss<<"STATUS:"<<e->status<<"\nEND:VEVENT\nEND:VCALENDAR";
        return ss.str();
    }
private:
    std::string formatICal(int64_t millis) {
        auto t=std::chrono::system_clock::to_time_t(std::chrono::system_clock::from_time_t(millis/1000));
        char buf[30]; std::strftime(buf,sizeof(buf),"%Y%m%dT%H%M%SZ",std::gmtime(&t));
        return buf;
    }
protected:
    bool searchMatch(const TeamCalEventEntity& e, const std::string& q);
};

} // namespace
