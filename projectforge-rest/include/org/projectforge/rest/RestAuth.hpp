// ProjectForge C++ port — GPL v3 — www.projectforge.org
#pragma once

#include <org/projectforge/rest/RestController.hpp>
#include <org/projectforge/business/LoginService.hpp>
#include <org/projectforge/business/UserDao.hpp>
#include <jwt-cpp/jwt.h>
#include <drogon/HttpFilter.h>
#include <drogon/HttpRequest.h>
#include <drogon/HttpResponse.h>
#include <spdlog/spdlog.h>
#include <nlohmann/json.hpp>
#include <memory>
#include <string>
#include <regex>
#include <chrono>

namespace org::projectforge::rest {

using json = nlohmann::json;

class RestAuth {
public:
    RestAuth(std::shared_ptr<org::projectforge::business::login::LoginService> loginService,
             std::shared_ptr<sqlite_orm::database> db,
             const std::string& jwtSecret = "");

    // JWT Token management
    std::string generateToken(int64_t userId, const std::string& username,
                              const std::vector<std::string>& rights,
                              int expirySeconds = 86400);
    bool validateToken(const std::string& token, RequestContext& ctx);
    std::string refreshToken(const std::string& token);
    bool invalidateToken(const std::string& token);
    void invalidateAllUserTokens(int64_t userId);

    // Authentication endpoints
    void handleLogin(const drogon::HttpRequestPtr& req, HttpCallback&& callback);
    void handleLogout(const drogon::HttpRequestPtr& req, HttpCallback&& callback);
    void handleRefreshToken(const drogon::HttpRequestPtr& req, HttpCallback&& callback);
    void handleTwoFactorSetup(const drogon::HttpRequestPtr& req, HttpCallback&& callback);
    void handleTwoFactorVerify(const drogon::HttpRequestPtr& req, HttpCallback&& callback);
    void handleTwoFactorDisable(const drogon::HttpRequestPtr& req, HttpCallback&& callback);
    void handlePasswordReset(const drogon::HttpRequestPtr& req, HttpCallback&& callback);
    void handlePasswordResetConfirm(const drogon::HttpRequestPtr& req, HttpCallback&& callback);

    // Middleware / filters
    bool authenticate(const drogon::HttpRequestPtr& req, RequestContext& ctx);
    bool checkRight(const RequestContext& ctx, const std::string& requiredRight) const;
    bool checkAnyRight(const RequestContext& ctx,
                       const std::vector<std::string>& requiredRights) const;
    std::optional<std::string> extractToken(const drogon::HttpRequestPtr& req) const;

    // Session management
    struct SessionInfo {
        int64_t userId;
        std::string username;
        std::string token;
        int64_t issuedAt;
        int64_t expiresAt;
        std::string clientIp;
        std::string userAgent;
    };
    std::vector<SessionInfo> getActiveSessions(int64_t userId) const;
    bool terminateSession(const std::string& sessionId);

    // Security helpers
    static std::string hashPassword(const std::string& password);
    static bool verifyPassword(const std::string& password, const std::string& hash);
    static bool validatePasswordStrength(const std::string& password, std::string& errorMsg);
    static std::string generateRandomToken(size_t length = 64);

    // Configuration
    void setTokenExpiry(int seconds) { tokenExpirySeconds_ = seconds; }
    int tokenExpiry() const { return tokenExpirySeconds_; }
    void setMaxLoginAttempts(int max) { maxLoginAttempts_ = max; }
    void setLockoutDuration(int minutes) { lockoutDurationMinutes_ = minutes; }

private:
    std::shared_ptr<org::projectforge::business::login::LoginService> loginService_;
    std::shared_ptr<org::projectforge::business::user::UserDao> userDao_;
    std::shared_ptr<sqlite_orm::database> db_;
    std::string jwtSecret_;
    int tokenExpirySeconds_ = 86400; // 24 hours
    int maxLoginAttempts_ = 5;
    int lockoutDurationMinutes_ = 30;
    std::shared_ptr<spdlog::logger> logger_;

    std::string buildClaims(int64_t userId, const std::string& username,
                            const std::vector<std::string>& rights, int expirySeconds);
    bool verifyJwt(const std::string& token, json& payload);
    std::string signJwt(const json& payload);
};

class RestAuthFilter : public drogon::HttpFilter<RestAuthFilter> {
public:
    RestAuthFilter() = default;

    void setAuth(std::shared_ptr<RestAuth> auth) { auth_ = auth; }

    void doFilter(const drogon::HttpRequestPtr& req,
                  drogon::FilterCallback&& fcb,
                  drogon::FilterChainCallback&& fccb) override;

private:
    std::shared_ptr<RestAuth> auth_;
};

class AdminAuthFilter : public drogon::HttpFilter<AdminAuthFilter> {
public:
    void setAuth(std::shared_ptr<RestAuth> auth) { auth_ = auth; }

    void doFilter(const drogon::HttpRequestPtr& req,
                  drogon::FilterCallback&& fcb,
                  drogon::FilterChainCallback&& fccb) override;

private:
    std::shared_ptr<RestAuth> auth_;
};

} // namespace org::projectforge::rest
