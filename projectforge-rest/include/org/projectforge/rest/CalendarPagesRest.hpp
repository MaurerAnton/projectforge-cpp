// ProjectForge C++ port — GPL v3 — www.projectforge.org
#pragma once

#include <org/projectforge/rest/RestController.hpp>
#include <org/projectforge/rest/JsonSerializer.hpp>
#include <org/projectforge/business/CalendarDao.hpp>
#include <drogon/HttpController.h>
#include <memory>
#include <cstdint>

namespace org::projectforge::rest {

class CalendarPagesRest : public RestController {
public:
    CalendarPagesRest(std::shared_ptr<org::projectforge::business::calendar::CalendarDao> calendarDao);

    // GET /api/v1/calendars
    void list(const drogon::HttpRequestPtr& req, HttpCallback&& callback);
    // GET /api/v1/calendars/:id
    void get(const drogon::HttpRequestPtr& req, HttpCallback&& callback, int64_t id);
    // POST /api/v1/calendars
    void create(const drogon::HttpRequestPtr& req, HttpCallback&& callback);
    // PUT /api/v1/calendars/:id
    void update(const drogon::HttpRequestPtr& req, HttpCallback&& callback, int64_t id);
    // DELETE /api/v1/calendars/:id
    void remove(const drogon::HttpRequestPtr& req, HttpCallback&& callback, int64_t id);
    // GET /api/v1/calendars/date-range
    void byDateRange(const drogon::HttpRequestPtr& req, HttpCallback&& callback);
    // GET /api/v1/calendars/upcoming
    void upcoming(const drogon::HttpRequestPtr& req, HttpCallback&& callback);
    // GET /api/v1/calendars/recurring
    void recurring(const drogon::HttpRequestPtr& req, HttpCallback&& callback);
    // GET /api/v1/calendars/:id/expand
    void expandRecurrence(const drogon::HttpRequestPtr& req, HttpCallback&& callback, int64_t id);
    // GET /api/v1/calendars/conflicts
    void conflicts(const drogon::HttpRequestPtr& req, HttpCallback&& callback);
    // GET /api/v1/calendars/reminders
    void reminders(const drogon::HttpRequestPtr& req, HttpCallback&& callback);
    // POST /api/v1/calendars/:id/reminded
    void markReminded(const drogon::HttpRequestPtr& req, HttpCallback&& callback, int64_t id);
    // GET /api/v1/calendars/subscriptions
    void getSubscriptions(const drogon::HttpRequestPtr& req, HttpCallback&& callback);
    // POST /api/v1/calendars/subscriptions
    void saveSubscription(const drogon::HttpRequestPtr& req, HttpCallback&& callback);
    // DELETE /api/v1/calendars/subscriptions/:id
    void deleteSubscription(const drogon::HttpRequestPtr& req, HttpCallback&& callback, int64_t id);
    // GET /api/v1/calendars/:id/ical
    void exportICal(const drogon::HttpRequestPtr& req, HttpCallback&& callback, int64_t id);
    // GET /api/v1/calendars/ical-range
    void exportICalRange(const drogon::HttpRequestPtr& req, HttpCallback&& callback);
    // POST /api/v1/calendars/import-ical
    void importICal(const drogon::HttpRequestPtr& req, HttpCallback&& callback);
    // GET /api/v1/calendars/team
    void team(const drogon::HttpRequestPtr& req, HttpCallback&& callback);
    // GET /api/v1/calendars/export
    void exportCalendar(const drogon::HttpRequestPtr& req, HttpCallback&& callback);

private:
    std::shared_ptr<org::projectforge::business::calendar::CalendarDao> calendarDao_;
    json eventToApiJson(const org::projectforge::business::calendar::CalendarEvent& evt) const;
    bool validateEventData(const json& data, bool isUpdate, std::string& errorMsg) const;
};

} // namespace org::projectforge::rest
