// ProjectForge C++ port — GPL v3 — www.projectforge.org
#pragma once

#include <org/projectforge/rest/RestController.hpp>
#include <org/projectforge/rest/JsonSerializer.hpp>
#include <org/projectforge/business/VacationDao.hpp>
#include <drogon/HttpController.h>
#include <memory>
#include <cstdint>

namespace org::projectforge::rest {

class VacationPagesRest : public RestController {
public:
    VacationPagesRest(std::shared_ptr<org::projectforge::business::vacation::VacationDao> vacationDao);

    // GET /api/v1/vacation
    void list(const drogon::HttpRequestPtr& req, HttpCallback&& callback);
    // GET /api/v1/vacation/:id
    void get(const drogon::HttpRequestPtr& req, HttpCallback&& callback, int64_t id);
    // POST /api/v1/vacation
    void create(const drogon::HttpRequestPtr& req, HttpCallback&& callback);
    // PUT /api/v1/vacation/:id
    void update(const drogon::HttpRequestPtr& req, HttpCallback&& callback, int64_t id);
    // DELETE /api/v1/vacation/:id
    void remove(const drogon::HttpRequestPtr& req, HttpCallback&& callback, int64_t id);
    // PUT /api/v1/vacation/:id/approve
    void approve(const drogon::HttpRequestPtr& req, HttpCallback&& callback, int64_t id);
    // PUT /api/v1/vacation/:id/reject
    void reject(const drogon::HttpRequestPtr& req, HttpCallback&& callback, int64_t id);
    // PUT /api/v1/vacation/:id/cancel
    void cancel(const drogon::HttpRequestPtr& req, HttpCallback&& callback, int64_t id);
    // GET /api/v1/vacation/pending
    void pendingApprovals(const drogon::HttpRequestPtr& req, HttpCallback&& callback);
    // GET /api/v1/vacation/overlapping
    void overlapping(const drogon::HttpRequestPtr& req, HttpCallback&& callback);
    // GET /api/v1/vacation/team
    void teamVacations(const drogon::HttpRequestPtr& req, HttpCallback&& callback);
    // GET /api/v1/vacation/account
    void account(const drogon::HttpRequestPtr& req, HttpCallback&& callback);
    // PUT /api/v1/vacation/account
    void updateAccount(const drogon::HttpRequestPtr& req, HttpCallback&& callback);
    // GET /api/v1/vacation/stats
    void stats(const drogon::HttpRequestPtr& req, HttpCallback&& callback);
    // POST /api/v1/vacation/:id/substitute-accept
    void acceptSubstitution(const drogon::HttpRequestPtr& req, HttpCallback&& callback, int64_t id);
    // GET /api/v1/vacation/export
    void exportVacations(const drogon::HttpRequestPtr& req, HttpCallback&& callback);

private:
    std::shared_ptr<org::projectforge::business::vacation::VacationDao> vacationDao_;
    json vacationToApiJson(const org::projectforge::business::vacation::Vacation& v) const;
    json accountToApiJson(const org::projectforge::business::vacation::VacationAccount& a) const;
    bool validateVacationData(const json& data, bool isUpdate, std::string& errorMsg) const;
};

class VacationExportPageRest : public RestController {
public:
    VacationExportPageRest(std::shared_ptr<org::projectforge::business::vacation::VacationDao> vacationDao);

    // GET /api/v1/vacation/export/pdf
    void exportPdf(const drogon::HttpRequestPtr& req, HttpCallback&& callback);
    // GET /api/v1/vacation/export/csv
    void exportCsv(const drogon::HttpRequestPtr& req, HttpCallback&& callback);
    // GET /api/v1/vacation/export/excel
    void exportExcel(const drogon::HttpRequestPtr& req, HttpCallback&& callback);
    // GET /api/v1/vacation/export/ical
    void exportICal(const drogon::HttpRequestPtr& req, HttpCallback&& callback);

private:
    std::shared_ptr<org::projectforge::business::vacation::VacationDao> vacationDao_;
    std::string generateCsv(const std::vector<org::projectforge::business::vacation::Vacation>& vacs) const;
    std::string generateICal(const std::vector<org::projectforge::business::vacation::Vacation>& vacs) const;
};

class HRPlanningPagesRest : public RestController {
public:
    HRPlanningPagesRest(std::shared_ptr<org::projectforge::business::humanresources::HrDao> hrDao);

    // GET /api/v1/hrplanning
    void list(const drogon::HttpRequestPtr& req, HttpCallback&& callback);
    // GET /api/v1/hrplanning/:id
    void get(const drogon::HttpRequestPtr& req, HttpCallback&& callback, int64_t id);
    // POST /api/v1/hrplanning
    void create(const drogon::HttpRequestPtr& req, HttpCallback&& callback);
    // PUT /api/v1/hrplanning/:id
    void update(const drogon::HttpRequestPtr& req, HttpCallback&& callback, int64_t id);
    // DELETE /api/v1/hrplanning/:id
    void remove(const drogon::HttpRequestPtr& req, HttpCallback&& callback, int64_t id);
    // GET /api/v1/hrplanning/entries
    void entries(const drogon::HttpRequestPtr& req, HttpCallback&& callback);
    // POST /api/v1/hrplanning/entries
    void addEntry(const drogon::HttpRequestPtr& req, HttpCallback&& callback);
    // PUT /api/v1/hrplanning/entries/:id
    void updateEntry(const drogon::HttpRequestPtr& req, HttpCallback&& callback, int64_t id);
    // DELETE /api/v1/hrplanning/entries/:id
    void removeEntry(const drogon::HttpRequestPtr& req, HttpCallback&& callback, int64_t id);
    // GET /api/v1/hrplanning/weekly
    void weeklyPlanning(const drogon::HttpRequestPtr& req, HttpCallback&& callback);
    // GET /api/v1/hrplanning/capacity
    void capacityReport(const drogon::HttpRequestPtr& req, HttpCallback&& callback);
    // GET /api/v1/hrplanning/utilization
    void utilization(const drogon::HttpRequestPtr& req, HttpCallback&& callback);
    // GET /api/v1/hrplanning/export
    void exportPlanning(const drogon::HttpRequestPtr& req, HttpCallback&& callback);

private:
    std::shared_ptr<org::projectforge::business::humanresources::HrDao> hrDao_;
    json entryToApiJson(const org::projectforge::business::humanresources::HrPlanningEntry& e) const;
    json planningToApiJson(const org::projectforge::business::humanresources::HrPlanning& p) const;
};

} // namespace org::projectforge::rest
