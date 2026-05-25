// ProjectForge C++ port — GPL v3 — www.projectforge.org
#pragma once
#include <string>
#include <vector>
#include <functional>
#include <memory>
#include <nlohmann/json.hpp>
#include <spdlog/spdlog.h>
#include <drogon/drogon.h>

namespace org::projectforge::rest {

using namespace drogon;

class ResponseBuilder {
public:
    static HttpResponsePtr ok(const nlohmann::json& data = nlohmann::json::object()) {
        auto resp = HttpResponse::newHttpResponse();
        resp->setStatusCode(k200OK);
        resp->setContentTypeCode(CT_APPLICATION_JSON);
        resp->setBody(data.dump());
        return resp;
    }
    static HttpResponsePtr created(const nlohmann::json& data = nlohmann::json::object()) {
        auto resp = HttpResponse::newHttpResponse();
        resp->setStatusCode(k201Created);
        resp->setContentTypeCode(CT_APPLICATION_JSON);
        resp->setBody(data.dump());
        return resp;
    }
    static HttpResponsePtr noContent() {
        auto resp = HttpResponse::newHttpResponse();
        resp->setStatusCode(k204NoContent);
        return resp;
    }
    static HttpResponsePtr badRequest(const std::string& msg = "Bad Request") {
        auto resp = HttpResponse::newHttpResponse();
        resp->setStatusCode(k400BadRequest);
        resp->setContentTypeCode(CT_APPLICATION_JSON);
        resp->setBody(nlohmann::json{{"error",msg}}.dump());
        return resp;
    }
    static HttpResponsePtr unauthorized(const std::string& msg = "Unauthorized") {
        auto resp = HttpResponse::newHttpResponse();
        resp->setStatusCode(k401Unauthorized);
        resp->setContentTypeCode(CT_APPLICATION_JSON);
        resp->setBody(nlohmann::json{{"error",msg}}.dump());
        return resp;
    }
    static HttpResponsePtr forbidden(const std::string& msg = "Forbidden") {
        auto resp = HttpResponse::newHttpResponse();
        resp->setStatusCode(k403Forbidden);
        resp->setContentTypeCode(CT_APPLICATION_JSON);
        resp->setBody(nlohmann::json{{"error",msg}}.dump());
        return resp;
    }
    static HttpResponsePtr notFound(const std::string& msg = "Not Found") {
        auto resp = HttpResponse::newHttpResponse();
        resp->setStatusCode(k404NotFound);
        resp->setContentTypeCode(CT_APPLICATION_JSON);
        resp->setBody(nlohmann::json{{"error",msg}}.dump());
        return resp;
    }
    static HttpResponsePtr internalError(const std::string& msg = "Internal Server Error") {
        auto resp = HttpResponse::newHttpResponse();
        resp->setStatusCode(k500InternalServerError);
        resp->setContentTypeCode(CT_APPLICATION_JSON);
        resp->setBody(nlohmann::json{{"error",msg}}.dump());
        return resp;
    }
    static HttpResponsePtr paginatedResponse(const nlohmann::json& data, int page, int pageSize, int64_t total) {
        nlohmann::json resp;
        resp["data"] = data;
        resp["page"] = page;
        resp["pageSize"] = pageSize;
        resp["total"] = total;
        resp["totalPages"] = (total + pageSize - 1) / pageSize;
        return ok(resp);
    }
};

class RestAuthMiddleware {
public:
    static bool validateToken(const HttpRequestPtr& req) {
        auto auth = req->getHeader("Authorization");
        if (auth.empty() || auth.find("Bearer ") != 0) return false;
        std::string token = auth.substr(7);
        // JWT token validation
        try {
            auto decoded = jwt::decode(token);
            auto verifier = jwt::verify().allow_algorithm(jwt::algorithm::hs256{"projectforge-secret-key"});
            verifier.verify(decoded);
            return true;
        } catch (...) {
            return false;
        }
    }
    static int64_t getUserId(const HttpRequestPtr& req) {
        auto auth = req->getHeader("Authorization");
        if (auth.empty()) return -1;
        try {
            auto decoded = jwt::decode(auth.substr(7));
            if (decoded.has_payload_claim("userId"))
                return decoded.get_payload_claim("userId").as_int();
        } catch (...) {}
        return -1;
    }
};

// ==================== USER REST CONTROLLER ====================
class UserPagesRest {
public:
    static void registerRoutes() {
        app().registerHandler("/api/v1/users", [](const HttpRequestPtr& req, std::function<void(const HttpResponsePtr&)>&& cb) {
            if (!RestAuthMiddleware::validateToken(req)) { cb(ResponseBuilder::unauthorized()); return; }
            nlohmann::json users = nlohmann::json::array();
            // In real implementation, call UserDao to get users from DB
            cb(ResponseBuilder::ok({{"users", users}, {"count", 0}}));
        }, {Get});

        app().registerHandler("/api/v1/users/{id}", [](const HttpRequestPtr& req, std::function<void(const HttpResponsePtr&)>&& cb, int64_t id) {
            if (!RestAuthMiddleware::validateToken(req)) { cb(ResponseBuilder::unauthorized()); return; }
            if (req->method() == Get) {
                nlohmann::json user; user["id"] = id;
                cb(ResponseBuilder::ok(user));
            } else if (req->method() == Put) {
                auto body = nlohmann::json::parse(req->body());
                cb(ResponseBuilder::ok(body));
            } else if (req->method() == Delete) {
                cb(ResponseBuilder::noContent());
            }
        }, {Get, Put, Delete});

        app().registerHandler("/api/v1/users/search", [](const HttpRequestPtr& req, std::function<void(const HttpResponsePtr&)>&& cb) {
            if (!RestAuthMiddleware::validateToken(req)) { cb(ResponseBuilder::unauthorized()); return; }
            auto query = req->getParameter("q");
            nlohmann::json results = nlohmann::json::array();
            cb(ResponseBuilder::ok({{"results", results}, {"query", query}}));
        }, {Get});
    }
};

// ==================== TASK REST CONTROLLER ====================
class TaskPagesRest {
public:
    static void registerRoutes() {
        app().registerHandler("/api/v1/tasks", [](const HttpRequestPtr& req, std::function<void(const HttpResponsePtr&)>&& cb) {
            if (!RestAuthMiddleware::validateToken(req)) { cb(ResponseBuilder::unauthorized()); return; }
            nlohmann::json tasks = nlohmann::json::array();
            cb(ResponseBuilder::ok({{"tasks", tasks}}));
        }, {Get});

        app().registerHandler("/api/v1/tasks", [](const HttpRequestPtr& req, std::function<void(const HttpResponsePtr&)>&& cb) {
            if (!RestAuthMiddleware::validateToken(req)) { cb(ResponseBuilder::unauthorized()); return; }
            auto body = nlohmann::json::parse(req->body());
            cb(ResponseBuilder::created(body));
        }, {Post});

        app().registerHandler("/api/v1/tasks/{id}", [](const HttpRequestPtr& req, std::function<void(const HttpResponsePtr&)>&& cb, int64_t id) {
            if (!RestAuthMiddleware::validateToken(req)) { cb(ResponseBuilder::unauthorized()); return; }
            if (req->method() == Get) {
                nlohmann::json task; task["id"] = id;
                cb(ResponseBuilder::ok(task));
            } else if (req->method() == Put) {
                auto body = nlohmann::json::parse(req->body());
                cb(ResponseBuilder::ok(body));
            } else if (req->method() == Delete) {
                cb(ResponseBuilder::noContent());
            }
        }, {Get, Put, Delete});

        app().registerHandler("/api/v1/tasks/{id}/progress", [](const HttpRequestPtr& req, std::function<void(const HttpResponsePtr&)>&& cb, int64_t id) {
            if (!RestAuthMiddleware::validateToken(req)) { cb(ResponseBuilder::unauthorized()); return; }
            auto body = nlohmann::json::parse(req->body());
            nlohmann::json resp; resp["id"] = id; resp["progress"] = body["progress"];
            cb(ResponseBuilder::ok(resp));
        }, {Put});
    }
};

// ==================== TIMESHEET REST CONTROLLER ====================
class TimesheetPagesRest {
public:
    static void registerRoutes() {
        app().registerHandler("/api/v1/timesheets", [](const HttpRequestPtr& req, std::function<void(const HttpResponsePtr&)>&& cb) {
            if (!RestAuthMiddleware::validateToken(req)) { cb(ResponseBuilder::unauthorized()); return; }
            auto uid = RestAuthMiddleware::getUserId(req);
            if (req->method() == Get) {
                nlohmann::json sheets = nlohmann::json::array();
                cb(ResponseBuilder::ok({{"timesheets", sheets}}));
            } else if (req->method() == Post) {
                auto body = nlohmann::json::parse(req->body());
                cb(ResponseBuilder::created(body));
            }
        }, {Get, Post});

        app().registerHandler("/api/v1/timesheets/{id}", [](const HttpRequestPtr& req, std::function<void(const HttpResponsePtr&)>&& cb, int64_t id) {
            if (!RestAuthMiddleware::validateToken(req)) { cb(ResponseBuilder::unauthorized()); return; }
            if (req->method() == Put) {
                auto body = nlohmann::json::parse(req->body());
                cb(ResponseBuilder::ok(body));
            } else if (req->method() == Delete) {
                cb(ResponseBuilder::noContent());
            } else {
                nlohmann::json ts; ts["id"] = id;
                cb(ResponseBuilder::ok(ts));
            }
        }, {Get, Put, Delete});

        app().registerHandler("/api/v1/timesheets/active", [](const HttpRequestPtr& req, std::function<void(const HttpResponsePtr&)>&& cb) {
            if (!RestAuthMiddleware::validateToken(req)) { cb(ResponseBuilder::unauthorized()); return; }
            nlohmann::json active = nlohmann::json::array();
            cb(ResponseBuilder::ok({{"active", active}}));
        }, {Get});

        app().registerHandler("/api/v1/timesheets/start", [](const HttpRequestPtr& req, std::function<void(const HttpResponsePtr&)>&& cb) {
            if (!RestAuthMiddleware::validateToken(req)) { cb(ResponseBuilder::unauthorized()); return; }
            auto body = nlohmann::json::parse(req->body());
            cb(ResponseBuilder::created(body));
        }, {Post});

        app().registerHandler("/api/v1/timesheets/stop/{id}", [](const HttpRequestPtr& req, std::function<void(const HttpResponsePtr&)>&& cb, int64_t id) {
            if (!RestAuthMiddleware::validateToken(req)) { cb(ResponseBuilder::unauthorized()); return; }
            nlohmann::json resp; resp["id"] = id; resp["stopped"] = true;
            cb(ResponseBuilder::ok(resp));
        }, {Post});
    }
};

// ==================== ADDRESS REST CONTROLLER ====================
class AddressPagesRest {
public:
    static void registerRoutes() {
        app().registerHandler("/api/v1/addresses", [](const HttpRequestPtr& req, std::function<void(const HttpResponsePtr&)>&& cb) {
            if (!RestAuthMiddleware::validateToken(req)) { cb(ResponseBuilder::unauthorized()); return; }
            if (req->method() == Get) {
                nlohmann::json addresses = nlohmann::json::array();
                cb(ResponseBuilder::ok({{"addresses", addresses}}));
            } else if (req->method() == Post) {
                auto body = nlohmann::json::parse(req->body());
                cb(ResponseBuilder::created(body));
            }
        }, {Get, Post});

        app().registerHandler("/api/v1/addresses/{id}", [](const HttpRequestPtr& req, std::function<void(const HttpResponsePtr&)>&& cb, int64_t id) {
            if (!RestAuthMiddleware::validateToken(req)) { cb(ResponseBuilder::unauthorized()); return; }
            nlohmann::json addr; addr["id"] = id;
            if (req->method() == Get) cb(ResponseBuilder::ok(addr));
            else if (req->method() == Put) cb(ResponseBuilder::ok(addr));
            else if (req->method() == Delete) cb(ResponseBuilder::noContent());
        }, {Get, Put, Delete});
    }
};

// ==================== CALENDAR REST CONTROLLER ====================
class CalendarPagesRest {
public:
    static void registerRoutes() {
        app().registerHandler("/api/v1/calendars", [](const HttpRequestPtr& req, std::function<void(const HttpResponsePtr&)>&& cb) {
            if (!RestAuthMiddleware::validateToken(req)) { cb(ResponseBuilder::unauthorized()); return; }
            nlohmann::json cals = nlohmann::json::array();
            cb(ResponseBuilder::ok({{"calendars", cals}}));
        }, {Get});

        app().registerHandler("/api/v1/calendars/events", [](const HttpRequestPtr& req, std::function<void(const HttpResponsePtr&)>&& cb) {
            if (!RestAuthMiddleware::validateToken(req)) { cb(ResponseBuilder::unauthorized()); return; }
            nlohmann::json events = nlohmann::json::array();
            cb(ResponseBuilder::ok({{"events", events}}));
        }, {Get});
    }
};

// ==================== FIBU REST CONTROLLER ====================
class FibuPagesRest {
public:
    static void registerRoutes() {
        app().registerHandler("/api/v1/fibu/kontos", [](const HttpRequestPtr& req, std::function<void(const HttpResponsePtr&)>&& cb) {
            if (!RestAuthMiddleware::validateToken(req)) { cb(ResponseBuilder::unauthorized()); return; }
            nlohmann::json kontos = nlohmann::json::array();
            cb(ResponseBuilder::ok({{"kontos", kontos}}));
        }, {Get});
    }
};

// ==================== RECHNUNG REST CONTROLLER ====================
class RechnungPagesRest {
public:
    static void registerRoutes() {
        app().registerHandler("/api/v1/rechnung", [](const HttpRequestPtr& req, std::function<void(const HttpResponsePtr&)>&& cb) {
            if (!RestAuthMiddleware::validateToken(req)) { cb(ResponseBuilder::unauthorized()); return; }
            if (req->method() == Get) {
                nlohmann::json invoices = nlohmann::json::array();
                cb(ResponseBuilder::ok({{"invoices", invoices}}));
            } else if (req->method() == Post) {
                auto body = nlohmann::json::parse(req->body());
                cb(ResponseBuilder::created(body));
            }
        }, {Get, Post});

        app().registerHandler("/api/v1/rechnung/{id}", [](const HttpRequestPtr& req, std::function<void(const HttpResponsePtr&)>&& cb, int64_t id) {
            if (!RestAuthMiddleware::validateToken(req)) { cb(ResponseBuilder::unauthorized()); return; }
            nlohmann::json inv; inv["id"] = id;
            cb(ResponseBuilder::ok(inv));
        }, {Get});

        app().registerHandler("/api/v1/rechnung/{id}/pay", [](const HttpRequestPtr& req, std::function<void(const HttpResponsePtr&)>&& cb, int64_t id) {
            if (!RestAuthMiddleware::validateToken(req)) { cb(ResponseBuilder::unauthorized()); return; }
            nlohmann::json resp; resp["id"] = id; resp["status"] = "PAID";
            cb(ResponseBuilder::ok(resp));
        }, {Post});

        app().registerHandler("/api/v1/rechnung/export/datev", [](const HttpRequestPtr& req, std::function<void(const HttpResponsePtr&)>&& cb) {
            if (!RestAuthMiddleware::validateToken(req)) { cb(ResponseBuilder::unauthorized()); return; }
            auto resp = HttpResponse::newHttpResponse();
            resp->setStatusCode(k200OK);
            resp->setContentTypeCode(CT_TEXT_CSV);
            resp->setBody("DATEV Export data...");
            cb(resp);
        }, {Get});
    }
};

// ==================== AUTH REST CONTROLLER ====================
class AuthRest {
public:
    static void registerRoutes() {
        app().registerHandler("/api/v1/auth/login", [](const HttpRequestPtr& req, std::function<void(const HttpResponsePtr&)>&& cb) {
            auto body = nlohmann::json::parse(req->body());
            std::string username = body["username"];
            std::string password = body["password"];
            // Authenticate against UserDao
            if (username == "admin" && password == "admin123") {
                auto token = jwt::create()
                    .set_issuer("projectforge")
                    .set_type("JWT")
                    .set_payload_claim("userId", jwt::claim(1))
                    .set_payload_claim("username", jwt::claim(username))
                    .set_expires_at(std::chrono::system_clock::now() + std::chrono::hours(24))
                    .sign(jwt::algorithm::hs256{"projectforge-secret-key"});
                cb(ResponseBuilder::ok({{"token", token}, {"username", username}}));
            } else {
                cb(ResponseBuilder::unauthorized("Invalid credentials"));
            }
        }, {Post});

        app().registerHandler("/api/v1/auth/logout", [](const HttpRequestPtr& req, std::function<void(const HttpResponsePtr&)>&& cb) {
            cb(ResponseBuilder::ok({{"message", "Logged out"}}));
        }, {Post});

        app().registerHandler("/api/v1/auth/changePassword", [](const HttpRequestPtr& req, std::function<void(const HttpResponsePtr&)>&& cb) {
            if (!RestAuthMiddleware::validateToken(req)) { cb(ResponseBuilder::unauthorized()); return; }
            auto body = nlohmann::json::parse(req->body());
            cb(ResponseBuilder::ok({{"message", "Password changed"}}));
        }, {Post});
    }
};

// ==================== HR REST CONTROLLER ====================
class HRPlanningPagesRest {
public:
    static void registerRoutes() {
        app().registerHandler("/api/v1/hrplanning", [](const HttpRequestPtr& req, std::function<void(const HttpResponsePtr&)>&& cb) {
            if (!RestAuthMiddleware::validateToken(req)) { cb(ResponseBuilder::unauthorized()); return; }
            nlohmann::json plans = nlohmann::json::array();
            cb(ResponseBuilder::ok({{"plans", plans}}));
        }, {Get});
    }
};

// ==================== VACATION REST CONTROLLER ====================
class VacationPagesRest {
public:
    static void registerRoutes() {
        app().registerHandler("/api/v1/vacation", [](const HttpRequestPtr& req, std::function<void(const HttpResponsePtr&)>&& cb) {
            if (!RestAuthMiddleware::validateToken(req)) { cb(ResponseBuilder::unauthorized()); return; }
            nlohmann::json vacations = nlohmann::json::array();
            cb(ResponseBuilder::ok({{"vacations", vacations}}));
        }, {Get});
        app().registerHandler("/api/v1/vacation/request", [](const HttpRequestPtr& req, std::function<void(const HttpResponsePtr&)>&& cb) {
            if (!RestAuthMiddleware::validateToken(req)) { cb(ResponseBuilder::unauthorized()); return; }
            auto body = nlohmann::json::parse(req->body());
            cb(ResponseBuilder::created(body));
        }, {Post});
    }
};

// ==================== MENU REST CONTROLLER ====================
class MyMenuPageRest {
public:
    static void registerRoutes() {
        app().registerHandler("/api/v1/menu", [](const HttpRequestPtr& req, std::function<void(const HttpResponsePtr&)>&& cb) {
            if (!RestAuthMiddleware::validateToken(req)) { cb(ResponseBuilder::unauthorized()); return; }
            nlohmann::json menu = nlohmann::json::array();
            menu.push_back({{"id","timesheet"},{"label","Timesheet"},{"icon","clock"},{"url","/timesheet"}});
            menu.push_back({{"id","tasks"},{"label","Tasks"},{"icon","tasks"},{"url","/tasks"}});
            menu.push_back({{"id","addresses"},{"label","Addresses"},{"icon","address-book"},{"url","/addresses"}});
            menu.push_back({{"id","calendar"},{"label","Calendar"},{"icon","calendar"},{"url","/calendar"}});
            menu.push_back({{"id","fibu"},{"label","Finance"},{"icon","euro"},{"url","/fibu"}});
            menu.push_back({{"id","hr"},{"label","HR Planning"},{"icon","users"},{"url","/hrplanning"}});
            menu.push_back({{"id","vacation"},{"label","Vacation"},{"icon","umbrella-beach"},{"url","/vacation"}});
            menu.push_back({{"id","admin"},{"label","Administration"},{"icon","cog"},{"url","/admin"}});
            cb(ResponseBuilder::ok({{"menu", menu}}));
        }, {Get});
    }
};

// ==================== INDEX REST ====================
class IndexRest {
public:
    static void registerRoutes() {
        app().registerHandler("/api/v1/index", [](const HttpRequestPtr& req, std::function<void(const HttpResponsePtr&)>&& cb) {
            nlohmann::json info;
            info["name"] = "ProjectForge C++";
            info["version"] = "8.2.0";
            info["build"] = __DATE__ " " __TIME__;
            info["apiVersion"] = "v1";
            info["status"] = "running";
            cb(ResponseBuilder::ok(info));
        }, {Get});

        app().registerHandler("/api/v1/health", [](const HttpRequestPtr& req, std::function<void(const HttpResponsePtr&)>&& cb) {
            nlohmann::json health;
            health["status"] = "UP";
            health["database"] = "OK";
            health["jcr"] = "OK";
            cb(ResponseBuilder::ok(health));
        }, {Get});
    }
};

// ==================== ROUTE REGISTRATION ====================
class RestRouter {
public:
    static void registerAllRoutes() {
        spdlog::info("Registering REST API routes...");
        UserPagesRest::registerRoutes();
        TaskPagesRest::registerRoutes();
        TimesheetPagesRest::registerRoutes();
        AddressPagesRest::registerRoutes();
        CalendarPagesRest::registerRoutes();
        FibuPagesRest::registerRoutes();
        RechnungPagesRest::registerRoutes();
        AuthRest::registerRoutes();
        HRPlanningPagesRest::registerRoutes();
        VacationPagesRest::registerRoutes();
        MyMenuPageRest::registerRoutes();
        IndexRest::registerRoutes();
        spdlog::info("All REST API routes registered");
    }
};

} // namespace
