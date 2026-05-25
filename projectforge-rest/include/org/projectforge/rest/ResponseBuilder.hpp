// ProjectForge C++ port — GPL v3 — www.projectforge.org
#pragma once

#include <drogon/HttpResponse.h>
#include <nlohmann/json.hpp>
#include <string>
#include <vector>
#include <cstdint>
#include <chrono>
#include <sstream>

namespace org::projectforge::rest {

using json = nlohmann::json;

class ResponseBuilder {
public:
    // Success responses
    static drogon::HttpResponsePtr ok() {
        return build(200, json::object());
    }

    static drogon::HttpResponsePtr ok(const json& data) {
        return build(200, data);
    }

    static drogon::HttpResponsePtr ok(const std::string& message) {
        json j;
        j["message"] = message;
        return build(200, j);
    }

    static drogon::HttpResponsePtr created(const json& data) {
        return build(201, data);
    }

    static drogon::HttpResponsePtr created(int64_t id, const json& data = {}) {
        json j = data.is_object() ? data : json::object();
        j["id"] = id;
        return build(201, j);
    }

    static drogon::HttpResponsePtr accepted(const json& data = {}) {
        return build(202, data);
    }

    static drogon::HttpResponsePtr noContent() {
        auto resp = drogon::HttpResponse::newHttpResponse();
        resp->setStatusCode(drogon::k204NoContent);
        return resp;
    }

    // Error responses
    static drogon::HttpResponsePtr badRequest(const std::string& message,
                                              const std::string& detail = "") {
        return error(400, "Bad Request", message, detail);
    }

    static drogon::HttpResponsePtr unauthorized(const std::string& message = "Authentication required") {
        return error(401, "Unauthorized", message);
    }

    static drogon::HttpResponsePtr forbidden(const std::string& message = "Access denied") {
        return error(403, "Forbidden", message);
    }

    static drogon::HttpResponsePtr notFound(const std::string& resource = "Resource") {
        return error(404, "Not Found", resource + " not found");
    }

    static drogon::HttpResponsePtr methodNotAllowed(const std::string& method) {
        return error(405, "Method Not Allowed", "Method " + method + " is not allowed");
    }

    static drogon::HttpResponsePtr conflict(const std::string& message) {
        return error(409, "Conflict", message);
    }

    static drogon::HttpResponsePtr unprocessableEntity(const std::string& message) {
        return error(422, "Unprocessable Entity", message);
    }

    static drogon::HttpResponsePtr tooManyRequests(const std::string& message = "Rate limit exceeded") {
        auto resp = error(429, "Too Many Requests", message);
        resp->addHeader("Retry-After", "60");
        return resp;
    }

    static drogon::HttpResponsePtr internalError(const std::string& message = "Internal server error") {
        return error(500, "Internal Server Error", message);
    }

    static drogon::HttpResponsePtr serviceUnavailable(const std::string& message = "Service temporarily unavailable") {
        return error(503, "Service Unavailable", message);
    }

    // Paginated response
    static drogon::HttpResponsePtr paged(const json& data, size_t total, size_t page, size_t pageSize,
                                         const std::string& sortField = "",
                                         const std::string& sortDir = "asc",
                                         const json& filters = {}) {
        json resp;
        resp["data"] = data;
        resp["pagination"]["page"] = page;
        resp["pagination"]["pageSize"] = pageSize;
        resp["pagination"]["total"] = total;
        resp["pagination"]["totalPages"] = pageSize > 0 ? (total + pageSize - 1) / pageSize : 0;
        resp["pagination"]["hasNext"] = page * pageSize < total;
        resp["pagination"]["hasPrevious"] = page > 1;
        if (!sortField.empty()) {
            resp["sort"]["field"] = sortField;
            resp["sort"]["direction"] = sortDir;
        }
        if (!filters.empty()) resp["filters"] = filters;
        return build(200, resp);
    }

    // File response
    static drogon::HttpResponsePtr file(const std::string& filename,
                                        const std::string& contentType,
                                        const std::string& content) {
        auto resp = drogon::HttpResponse::newHttpResponse();
        resp->setStatusCode(drogon::k200OK);
        resp->setContentTypeString(contentType);
        resp->setBody(content);
        resp->addHeader("Content-Disposition", "attachment; filename=\"" + filename + "\"");
        resp->addHeader("Cache-Control", "no-cache");
        return resp;
    }

    static drogon::HttpResponsePtr fileBinary(const std::string& filename,
                                              const std::string& contentType,
                                              const std::vector<uint8_t>& content) {
        auto resp = drogon::HttpResponse::newHttpResponse();
        resp->setStatusCode(drogon::k200OK);
        resp->setContentTypeString(contentType);
        resp->setBody(std::string(reinterpret_cast<const char*>(content.data()), content.size()));
        resp->addHeader("Content-Disposition", "attachment; filename=\"" + filename + "\"");
        resp->addHeader("Content-Length", std::to_string(content.size()));
        resp->addHeader("Cache-Control", "no-cache");
        return resp;
    }

    // CSV export
    static drogon::HttpResponsePtr csv(const std::string& csvContent, const std::string& filename = "export.csv") {
        return file(filename, "text/csv; charset=utf-8", csvContent);
    }

    // JSON stream (for large datasets)
    static drogon::HttpResponsePtr jsonStream(const std::string& jsonContent) {
        auto resp = drogon::HttpResponse::newHttpResponse();
        resp->setStatusCode(drogon::k200OK);
        resp->setContentTypeString("application/json; charset=utf-8");
        resp->setBody(jsonContent);
        return resp;
    }

    // HATEOAS link helpers
    static json buildLink(const std::string& rel, const std::string& href,
                          const std::string& method = "GET") {
        return {{"rel", rel}, {"href", href}, {"method", method}};
    }

    static json buildHalResponse(const json& data, const std::vector<json>& links = {},
                                 const json& embedded = {}) {
        json resp = data;
        if (!links.empty()) {
            json linksObj;
            for (auto& link : links) {
                std::string rel = link["rel"];
                link.erase("rel");
                if (linksObj.contains(rel)) {
                    if (!linksObj[rel].is_array()) {
                        linksObj[rel] = json::array({linksObj[rel]});
                    }
                    linksObj[rel].push_back(link);
                } else {
                    linksObj[rel] = link;
                }
            }
            resp["_links"] = linksObj;
        }
        if (!embedded.empty()) resp["_embedded"] = embedded;
        return resp;
    }

    // Validation error response
    static drogon::HttpResponsePtr validationError(
        const std::vector<std::pair<std::string, std::string>>& errors) {
        json errorList = json::array();
        for (auto& [field, msg] : errors) {
            errorList.push_back({{"field", field}, {"message", msg}});
        }
        json resp;
        resp["status"] = 422;
        resp["error"] = "Validation Error";
        resp["message"] = "Validation failed";
        resp["errors"] = errorList;
        return build(422, resp);
    }

    // Health check response
    static drogon::HttpResponsePtr health(bool ok, const json& details = {}) {
        json resp;
        resp["status"] = ok ? "UP" : "DOWN";
        resp["timestamp"] = std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::system_clock::now().time_since_epoch()).count();
        if (!details.empty()) resp["details"] = details;
        return build(ok ? 200 : 503, resp);
    }

private:
    static drogon::HttpResponsePtr build(int statusCode, const json& body) {
        auto resp = drogon::HttpResponse::newHttpResponse();
        resp->setStatusCode(static_cast<drogon::HttpStatusCode>(statusCode));
        resp->setContentTypeString("application/json; charset=utf-8");
        resp->setBody(body.dump());
        resp->addHeader("X-Content-Type-Options", "nosniff");
        resp->addHeader("X-Frame-Options", "DENY");
        resp->addHeader("X-XSS-Protection", "1; mode=block");
        return resp;
    }

    static drogon::HttpResponsePtr error(int statusCode, const std::string& error,
                                         const std::string& message,
                                         const std::string& detail = "") {
        json resp;
        resp["status"] = statusCode;
        resp["error"] = error;
        resp["message"] = message;
        if (!detail.empty()) resp["detail"] = detail;
        resp["timestamp"] = std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::system_clock::now().time_since_epoch()).count();
        return build(statusCode, resp);
    }
};

} // namespace org::projectforge::rest
