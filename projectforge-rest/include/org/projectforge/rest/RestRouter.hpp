// ProjectForge C++ port — GPL v3 — www.projectforge.org
#pragma once

#include <drogon/HttpController.h>
#include <drogon/HttpAppFramework.h>
#include <memory>
#include <string>
#include <vector>
#include <functional>

namespace org::projectforge::rest {

class RestAuth;
class UserPagesRest;
class TimesheetPagesRest;
class TaskPagesRest;
class AddressPagesRest;
class CalendarPagesRest;
class FibuPagesRest;
class RechnungPagesRest;
class KontoPagesRest;
class AuftragPagesRest;
class MyMenuPageRest;
class ChangePasswordPageRest;
class IndexRest;
class VacationPagesRest;
class VacationExportPageRest;
class HRPlanningPagesRest;
class VisitorbookPagesRest;
class PostausgangPagesRest;
class ExportRest;
class FileRest;
class BookPagesRest;

struct RestRouteEntry {
    std::string method;       // GET, POST, PUT, PATCH, DELETE
    std::string path;         // e.g. "/api/v1/users"
    std::string handler;      // descriptive name
    bool requiresAuth = true;
    std::string requiredRight; // e.g. "ADMIN", "FIBU_READ", empty = any authenticated
};

class RestRouter {
public:
    RestRouter();
    ~RestRouter() = default;

    void initialize(std::shared_ptr<RestAuth> auth);

    void registerAllRoutes(drogon::HttpAppFramework& app);

    void registerUserRoutes(drogon::HttpAppFramework& app);
    void registerTaskRoutes(drogon::HttpAppFramework& app);
    void registerTimesheetRoutes(drogon::HttpAppFramework& app);
    void registerAddressRoutes(drogon::HttpAppFramework& app);
    void registerCalendarRoutes(drogon::HttpAppFramework& app);
    void registerFibuRoutes(drogon::HttpAppFramework& app);
    void registerRechnungRoutes(drogon::HttpAppFramework& app);
    void registerKontoRoutes(drogon::HttpAppFramework& app);
    void registerAuftragRoutes(drogon::HttpAppFramework& app);
    void registerAuthRoutes(drogon::HttpAppFramework& app);
    void registerVacationRoutes(drogon::HttpAppFramework& app);
    void registerHRPlanningRoutes(drogon::HttpAppFramework& app);
    void registerMenuRoutes(drogon::HttpAppFramework& app);
    void registerIndexRoutes(drogon::HttpAppFramework& app);
    void registerExportRoutes(drogon::HttpAppFramework& app);
    void registerFileRoutes(drogon::HttpAppFramework& app);
    void registerBookRoutes(drogon::HttpAppFramework& app);
    void registerVisitorbookRoutes(drogon::HttpAppFramework& app);
    void registerPostausgangRoutes(drogon::HttpAppFramework& app);

    // Route discovery / API documentation
    std::vector<RestRouteEntry> getAllRoutes() const;
    std::string generateOpenApiSpec() const;

    // CORS and global middleware
    void setupMiddleware(drogon::HttpAppFramework& app);
    void setupErrorHandlers(drogon::HttpAppFramework& app);

    // Set dependencies
    void setUserController(std::shared_ptr<UserPagesRest> ctrl) { userCtrl_ = ctrl; }
    void setTaskController(std::shared_ptr<TaskPagesRest> ctrl) { taskCtrl_ = ctrl; }
    void setTimesheetController(std::shared_ptr<TimesheetPagesRest> ctrl) { timesheetCtrl_ = ctrl; }
    void setAddressController(std::shared_ptr<AddressPagesRest> ctrl) { addressCtrl_ = ctrl; }
    void setCalendarController(std::shared_ptr<CalendarPagesRest> ctrl) { calendarCtrl_ = ctrl; }
    void setFibuController(std::shared_ptr<FibuPagesRest> ctrl) { fibuCtrl_ = ctrl; }
    void setRechnungController(std::shared_ptr<RechnungPagesRest> ctrl) { rechnungCtrl_ = ctrl; }
    void setKontoController(std::shared_ptr<KontoPagesRest> ctrl) { kontoCtrl_ = ctrl; }
    void setAuftragController(std::shared_ptr<AuftragPagesRest> ctrl) { auftragCtrl_ = ctrl; }
    void setMenuController(std::shared_ptr<MyMenuPageRest> ctrl) { menuCtrl_ = ctrl; }
    void setChangePasswordController(std::shared_ptr<ChangePasswordPageRest> ctrl) { changePwCtrl_ = ctrl; }
    void setIndexController(std::shared_ptr<IndexRest> ctrl) { indexCtrl_ = ctrl; }
    void setVacationController(std::shared_ptr<VacationPagesRest> ctrl) { vacationCtrl_ = ctrl; }
    void setVacationExportController(std::shared_ptr<VacationExportPageRest> ctrl) { vacExportCtrl_ = ctrl; }
    void setHRPlanningController(std::shared_ptr<HRPlanningPagesRest> ctrl) { hrCtrl_ = ctrl; }
    void setVisitorbookController(std::shared_ptr<VisitorbookPagesRest> ctrl) { visitorbookCtrl_ = ctrl; }
    void setPostausgangController(std::shared_ptr<PostausgangPagesRest> ctrl) { postausgangCtrl_ = ctrl; }
    void setExportController(std::shared_ptr<ExportRest> ctrl) { exportCtrl_ = ctrl; }
    void setFileController(std::shared_ptr<FileRest> ctrl) { fileCtrl_ = ctrl; }
    void setBookController(std::shared_ptr<BookPagesRest> ctrl) { bookCtrl_ = ctrl; }

private:
    std::shared_ptr<RestAuth> auth_;

    // Controllers
    std::shared_ptr<UserPagesRest> userCtrl_;
    std::shared_ptr<TaskPagesRest> taskCtrl_;
    std::shared_ptr<TimesheetPagesRest> timesheetCtrl_;
    std::shared_ptr<AddressPagesRest> addressCtrl_;
    std::shared_ptr<CalendarPagesRest> calendarCtrl_;
    std::shared_ptr<FibuPagesRest> fibuCtrl_;
    std::shared_ptr<RechnungPagesRest> rechnungCtrl_;
    std::shared_ptr<KontoPagesRest> kontoCtrl_;
    std::shared_ptr<AuftragPagesRest> auftragCtrl_;
    std::shared_ptr<MyMenuPageRest> menuCtrl_;
    std::shared_ptr<ChangePasswordPageRest> changePwCtrl_;
    std::shared_ptr<IndexRest> indexCtrl_;
    std::shared_ptr<VacationPagesRest> vacationCtrl_;
    std::shared_ptr<VacationExportPageRest> vacExportCtrl_;
    std::shared_ptr<HRPlanningPagesRest> hrCtrl_;
    std::shared_ptr<VisitorbookPagesRest> visitorbookCtrl_;
    std::shared_ptr<PostausgangPagesRest> postausgangCtrl_;
    std::shared_ptr<ExportRest> exportCtrl_;
    std::shared_ptr<FileRest> fileCtrl_;
    std::shared_ptr<BookPagesRest> bookCtrl_;

    std::vector<RestRouteEntry> routes_;

    // Helper to add route with auth check
    void addAuthenticatedRoute(const std::string& method, const std::string& path,
                               std::function<void(const drogon::HttpRequestPtr&,
                                                  std::function<void(const drogon::HttpResponsePtr&)>)> handler);
    void addPublicRoute(const std::string& method, const std::string& path,
                        std::function<void(const drogon::HttpRequestPtr&,
                                           std::function<void(const drogon::HttpResponsePtr&)>)> handler);
};

} // namespace org::projectforge::rest
