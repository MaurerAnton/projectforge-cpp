// ProjectForge C++ port — GPL v3 — www.projectforge.org
#pragma once

#include <org/projectforge/rest/RestController.hpp>
#include <org/projectforge/rest/JsonSerializer.hpp>
#include <org/projectforge/business/TimesheetDao.hpp>
#include <drogon/HttpController.h>
#include <memory>
#include <cstdint>

namespace org::projectforge::rest {

class TimesheetPagesRest : public RestController {
public:
    TimesheetPagesRest(std::shared_ptr<org::projectforge::business::timesheet::TimesheetDao> timesheetDao);

    // GET /api/v1/timesheets
    void list(const drogon::HttpRequestPtr& req, HttpCallback&& callback);
    // GET /api/v1/timesheets/:id
    void get(const drogon::HttpRequestPtr& req, HttpCallback&& callback, int64_t id);
    // POST /api/v1/timesheets
    void create(const drogon::HttpRequestPtr& req, HttpCallback&& callback);
    // PUT /api/v1/timesheets/:id
    void update(const drogon::HttpRequestPtr& req, HttpCallback&& callback, int64_t id);
    // DELETE /api/v1/timesheets/:id
    void remove(const drogon::HttpRequestPtr& req, HttpCallback&& callback, int64_t id);
    // POST /api/v1/timesheets/start — Start timesheet (clock in)
    void start(const drogon::HttpRequestPtr& req, HttpCallback&& callback);
    // POST /api/v1/timesheets/:id/stop — Stop timesheet (clock out)
    void stop(const drogon::HttpRequestPtr& req, HttpCallback&& callback, int64_t id);
    // POST /api/v1/timesheets/stop-running — Stop any running timesheet
    void stopRunning(const drogon::HttpRequestPtr& req, HttpCallback&& callback);
    // GET /api/v1/timesheets/running — Get running timesheet
    void getRunning(const drogon::HttpRequestPtr& req, HttpCallback&& callback);
    // GET /api/v1/timesheets/week/:year/:week
    void byWeek(const drogon::HttpRequestPtr& req, HttpCallback&& callback, int32_t year, int32_t week);
    // GET /api/v1/timesheets/date-range
    void byDateRange(const drogon::HttpRequestPtr& req, HttpCallback&& callback);
    // GET /api/v1/timesheets/unbooked
    void unbooked(const drogon::HttpRequestPtr& req, HttpCallback&& callback);
    // POST /api/v1/timesheets/:id/book
    void markBooked(const drogon::HttpRequestPtr& req, HttpCallback&& callback, int64_t id);
    // POST /api/v1/timesheets/:id/unbook
    void markUnbooked(const drogon::HttpRequestPtr& req, HttpCallback&& callback, int64_t id);
    // POST /api/v1/timesheets/book-bulk
    void bulkBook(const drogon::HttpRequestPtr& req, HttpCallback&& callback);
    // GET /api/v1/timesheets/templates
    void getTemplates(const drogon::HttpRequestPtr& req, HttpCallback&& callback);
    // POST /api/v1/timesheets/templates
    void saveTemplate(const drogon::HttpRequestPtr& req, HttpCallback&& callback);
    // DELETE /api/v1/timesheets/templates/:id
    void deleteTemplate(const drogon::HttpRequestPtr& req, HttpCallback&& callback, int64_t id);
    // POST /api/v1/timesheets/from-template/:templateId
    void createFromTemplate(const drogon::HttpRequestPtr& req, HttpCallback&& callback, int64_t templateId);
    // GET /api/v1/timesheets/stats
    void stats(const drogon::HttpRequestPtr& req, HttpCallback&& callback);
    // GET /api/v1/timesheets/export
    void exportTimesheets(const drogon::HttpRequestPtr& req, HttpCallback&& callback);
    // GET /api/v1/timesheets/total
    void totalDuration(const drogon::HttpRequestPtr& req, HttpCallback&& callback);

private:
    std::shared_ptr<org::projectforge::business::timesheet::TimesheetDao> timesheetDao_;
    json timesheetToApiJson(const org::projectforge::business::timesheet::Timesheet& ts) const;
    bool validateTimesheetData(const json& data, bool isUpdate, std::string& errorMsg) const;
};

} // namespace org::projectforge::rest
