// ProjectForge C++ port — GPL v3 — www.projectforge.org
#pragma once

#include <stdexcept>
#include <string>
#include <nlohmann/json.hpp>

namespace org::projectforge::rest {

using json = nlohmann::json;

class RestException : public std::runtime_error {
public:
    enum class Status {
        BAD_REQUEST = 400,
        UNAUTHORIZED = 401,
        FORBIDDEN = 403,
        NOT_FOUND = 404,
        METHOD_NOT_ALLOWED = 405,
        CONFLICT = 409,
        GONE = 410,
        UNPROCESSABLE_ENTITY = 422,
        TOO_MANY_REQUESTS = 429,
        INTERNAL_SERVER_ERROR = 500,
        SERVICE_UNAVAILABLE = 503,
    };

    RestException(Status status, std::string message, std::string detail = "")
        : std::runtime_error(message), status_(status), message_(std::move(message)),
          detail_(std::move(detail)), errorCode_("") {}

    RestException(Status status, std::string message, std::string detail, std::string errorCode)
        : std::runtime_error(message), status_(status), message_(std::move(message)),
          detail_(std::move(detail)), errorCode_(std::move(errorCode)) {}

    Status status() const { return status_; }
    int statusCode() const { return static_cast<int>(status_); }
    const std::string& message() const { return message_; }
    const std::string& detail() const { return detail_; }
    const std::string& errorCode() const { return errorCode_; }

    json toJson() const {
        json j;
        j["status"] = statusCode();
        j["error"] = statusName();
        j["message"] = message_;
        if (!detail_.empty()) j["detail"] = detail_;
        if (!errorCode_.empty()) j["errorCode"] = errorCode_;
        j["timestamp"] = std::time(nullptr);
        return j;
    }

    static RestException badRequest(const std::string& msg, const std::string& detail = "") {
        return RestException(Status::BAD_REQUEST, msg, detail);
    }
    static RestException unauthorized(const std::string& msg = "Authentication required") {
        return RestException(Status::UNAUTHORIZED, msg);
    }
    static RestException forbidden(const std::string& msg = "Access denied") {
        return RestException(Status::FORBIDDEN, msg);
    }
    static RestException notFound(const std::string& resource = "Resource") {
        return RestException(Status::NOT_FOUND, resource + " not found");
    }
    static RestException conflict(const std::string& msg) {
        return RestException(Status::CONFLICT, msg);
    }
    static RestException unprocessableEntity(const std::string& msg) {
        return RestException(Status::UNPROCESSABLE_ENTITY, msg);
    }
    static RestException internalError(const std::string& msg = "Internal server error") {
        return RestException(Status::INTERNAL_SERVER_ERROR, msg);
    }

private:
    Status status_;
    std::string message_;
    std::string detail_;
    std::string errorCode_;

    const char* statusName() const {
        switch (status_) {
            case Status::BAD_REQUEST: return "Bad Request";
            case Status::UNAUTHORIZED: return "Unauthorized";
            case Status::FORBIDDEN: return "Forbidden";
            case Status::NOT_FOUND: return "Not Found";
            case Status::METHOD_NOT_ALLOWED: return "Method Not Allowed";
            case Status::CONFLICT: return "Conflict";
            case Status::GONE: return "Gone";
            case Status::UNPROCESSABLE_ENTITY: return "Unprocessable Entity";
            case Status::TOO_MANY_REQUESTS: return "Too Many Requests";
            case Status::INTERNAL_SERVER_ERROR: return "Internal Server Error";
            case Status::SERVICE_UNAVAILABLE: return "Service Unavailable";
            default: return "Unknown Error";
        }
    }
};

class ValidationException : public RestException {
public:
    ValidationException(const std::string& field, const std::string& message)
        : RestException(Status::UNPROCESSABLE_ENTITY, "Validation failed: " + field,
                        message, "VALIDATION_ERROR"),
          field_(field) {}
    const std::string& field() const { return field_; }

private:
    std::string field_;
};

} // namespace org::projectforge::rest
