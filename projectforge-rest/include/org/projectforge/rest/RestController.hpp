// ProjectForge C++ port — GPL v3 — www.projectforge.org
#pragma once

#include <org/projectforge/rest/PaginationHelper.hpp>
#include <org/projectforge/rest/RestException.hpp>
#include <drogon/HttpController.h>
#include <drogon/HttpRequest.h>
#include <drogon/HttpResponse.h>
#include <spdlog/spdlog.h>
#include <nlohmann/json.hpp>
#include <functional>
#include <memory>
#include <string>
#include <map>
#include <optional>

namespace org::projectforge::rest {

using json = nlohmann::json;

using HttpCallback = std::function<void(const drogon::HttpResponsePtr&)>;

struct RequestContext {
    int64_t userId = 0;
    std::string username;
    std::string sessionToken;
    std::vector<std::string> rights;
    bool isAuthenticated = false;
    bool isAdmin = false;
    std::string clientIp;
    std::string userAgent;

    json toJson() const {
        json j;
        j["userId"] = userId;
        j["username"] = username;
        j["authenticated"] = isAuthenticated;
        j["isAdmin"] = isAdmin;
        if (!clientIp.empty()) j["clientIp"] = clientIp;
        return j;
    }
};

class RestController {
public:
    RestController() = default;
    virtual ~RestController() = default;

    virtual void registerRoutes() {}

    // Request parsing helpers
    static std::optional<json> parseJsonBody(const drogon::HttpRequestPtr& req);
    static std::optional<int64_t> extractPathId(const drogon::HttpRequestPtr& req, size_t position = 0);
    static std::string getHeader(const drogon::HttpRequestPtr& req, const std::string& name,
                                 const std::string& defaultValue = "");
    static std::string getQueryParam(const drogon::HttpRequestPtr& req, const std::string& name,
                                     const std::string& defaultValue = "");
    static json getAllQueryParams(const drogon::HttpRequestPtr& req);

    // Response helpers
    static drogon::HttpResponsePtr ok(const json& body = {});
    static drogon::HttpResponsePtr created(const json& body = {});
    static drogon::HttpResponsePtr noContent();
    static drogon::HttpResponsePtr error(int statusCode, const std::string& message,
                                         const std::string& detail = "");
    static drogon::HttpResponsePtr error(const RestException& ex);
    static drogon::HttpResponsePtr pagedResponse(const PagedResponse& paged);
    static drogon::HttpResponsePtr fileResponse(const std::string& filename,
                                                const std::string& contentType,
                                                const std::vector<uint8_t>& content);
    static drogon::HttpResponsePtr csvResponse(const std::string& csvContent,
                                               const std::string& filename = "export.csv");

    // Validation helpers
    static bool validateRequired(const json& body, const std::string& field, std::string& errorMsg);
    static bool validateRequired(const json& body, const std::vector<std::string>& fields,
                                 std::string& errorMsg);
    static bool validateStringLength(const std::string& value, size_t minLen, size_t maxLen,
                                     const std::string& fieldName, std::string& errorMsg);
    static bool validateEmail(const std::string& email, std::string& errorMsg);
    static bool validateNumeric(const std::string& value, const std::string& fieldName,
                                std::string& errorMsg);

    // Auth context
    void setAuthContext(const RequestContext& ctx) { authContext_ = ctx; }
    const RequestContext& authContext() const { return authContext_; }
    int64_t currentUserId() const { return authContext_.userId; }
    bool isAuthenticated() const { return authContext_.isAuthenticated; }
    bool hasRight(const std::string& right) const;

    // Logging
    void logRequest(const drogon::HttpRequestPtr& req);
    void logResponse(const drogon::HttpResponsePtr& resp);
    void logError(const std::string& message, const std::exception& e);

protected:
    RequestContext authContext_;
    std::shared_ptr<spdlog::logger> logger_ = spdlog::get("projectforge.rest");

    void initLogger() {
        if (!logger_) logger_ = spdlog::default_logger();
    }
};

} // namespace org::projectforge::rest
