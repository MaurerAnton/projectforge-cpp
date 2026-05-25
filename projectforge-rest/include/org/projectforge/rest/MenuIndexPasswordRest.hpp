// ProjectForge C++ port — GPL v3 — www.projectforge.org
#pragma once

#include <org/projectforge/rest/RestController.hpp>
#include <drogon/HttpController.h>
#include <memory>

namespace org::projectforge::rest {

class MyMenuPageRest : public RestController {
public:
    MyMenuPageRest();

    // GET /api/v1/menu
    void getMenu(const drogon::HttpRequestPtr& req, HttpCallback&& callback);
    // GET /api/v1/menu/items
    void getMenuItems(const drogon::HttpRequestPtr& req, HttpCallback&& callback);
    // GET /api/v1/menu/favorites
    void getFavorites(const drogon::HttpRequestPtr& req, HttpCallback&& callback);
    // POST /api/v1/menu/favorites/:entityType/:entityId
    void addFavorite(const drogon::HttpRequestPtr& req, HttpCallback&& callback,
                     const std::string& entityType, int64_t entityId);
    // DELETE /api/v1/menu/favorites/:entityType/:entityId
    void removeFavorite(const drogon::HttpRequestPtr& req, HttpCallback&& callback,
                        const std::string& entityType, int64_t entityId);
    // GET /api/v1/menu/breadcrumb/:path
    void getBreadcrumb(const drogon::HttpRequestPtr& req, HttpCallback&& callback,
                       const std::string& path);

private:
    json buildMenuStructure(int64_t userId, const std::vector<std::string>& rights);
};

class ChangePasswordPageRest : public RestController {
public:
    ChangePasswordPageRest(
        std::shared_ptr<org::projectforge::business::login::LoginService> loginService,
        std::shared_ptr<org::projectforge::business::user::UserDao> userDao);

    // POST /api/v1/auth/changePassword
    void changePassword(const drogon::HttpRequestPtr& req, HttpCallback&& callback);
    // POST /api/v1/auth/resetPassword
    void resetPassword(const drogon::HttpRequestPtr& req, HttpCallback&& callback);

private:
    std::shared_ptr<org::projectforge::business::login::LoginService> loginService_;
    std::shared_ptr<org::projectforge::business::user::UserDao> userDao_;
};

class IndexRest : public RestController {
public:
    IndexRest();

    // GET /api/v1/index — System information
    void getIndex(const drogon::HttpRequestPtr& req, HttpCallback&& callback);
    // GET /api/v1/health — Health check
    void health(const drogon::HttpRequestPtr& req, HttpCallback&& callback);
    // GET /api/v1/info — Server info
    void info(const drogon::HttpRequestPtr& req, HttpCallback&& callback);
    // GET /api/v1/stats — Statistics
    void stats(const drogon::HttpRequestPtr& req, HttpCallback&& callback);
    // GET /api/v1/version
    void version(const drogon::HttpRequestPtr& req, HttpCallback&& callback);

private:
    std::string version_ = "8.2.0";
};

} // namespace org::projectforge::rest
