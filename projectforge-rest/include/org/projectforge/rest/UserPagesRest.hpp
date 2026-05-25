// ProjectForge C++ port — GPL v3 — www.projectforge.org
#pragma once

#include <org/projectforge/rest/RestController.hpp>
#include <org/projectforge/rest/JsonSerializer.hpp>
#include <org/projectforge/rest/ResponseBuilder.hpp>
#include <org/projectforge/rest/RequestParamsDef.hpp>
#include <org/projectforge/rest/RestException.hpp>
#include <org/projectforge/business/UserDao.hpp>
#include <org/projectforge/business/GroupDao.hpp>
#include <drogon/HttpController.h>
#include <memory>
#include <vector>
#include <string>
#include <algorithm>

namespace org::projectforge::rest {

class UserPagesRest : public RestController {
public:
    UserPagesRest(std::shared_ptr<org::projectforge::business::user::UserDao> userDao,
                  std::shared_ptr<org::projectforge::business::group::GroupDao> groupDao);

    // GET /api/v1/users — List users with pagination, filtering, sorting
    void list(const drogon::HttpRequestPtr& req, HttpCallback&& callback);

    // GET /api/v1/users/:id — Get single user
    void get(const drogon::HttpRequestPtr& req, HttpCallback&& callback, int64_t id);

    // POST /api/v1/users — Create user
    void create(const drogon::HttpRequestPtr& req, HttpCallback&& callback);

    // PUT /api/v1/users/:id — Update user
    void update(const drogon::HttpRequestPtr& req, HttpCallback&& callback, int64_t id);

    // PATCH /api/v1/users/:id — Partial update
    void patch(const drogon::HttpRequestPtr& req, HttpCallback&& callback, int64_t id);

    // DELETE /api/v1/users/:id — Delete/soft-delete user
    void remove(const drogon::HttpRequestPtr& req, HttpCallback&& callback, int64_t id);

    // PUT /api/v1/users/:id/deactivate
    void deactivate(const drogon::HttpRequestPtr& req, HttpCallback&& callback, int64_t id);

    // PUT /api/v1/users/:id/activate
    void activate(const drogon::HttpRequestPtr& req, HttpCallback&& callback, int64_t id);

    // GET /api/v1/users/:id/groups
    void getGroups(const drogon::HttpRequestPtr& req, HttpCallback&& callback, int64_t id);

    // POST /api/v1/users/:id/groups
    void addToGroup(const drogon::HttpRequestPtr& req, HttpCallback&& callback, int64_t id);

    // DELETE /api/v1/users/:id/groups/:groupId
    void removeFromGroup(const drogon::HttpRequestPtr& req, HttpCallback&& callback,
                         int64_t id, int64_t groupId);

    // GET /api/v1/users/:id/rights
    void getRights(const drogon::HttpRequestPtr& req, HttpCallback&& callback, int64_t id);

    // POST /api/v1/users/:id/rights
    void grantRight(const drogon::HttpRequestPtr& req, HttpCallback&& callback, int64_t id);

    // DELETE /api/v1/users/:id/rights/:rightId
    void revokeRight(const drogon::HttpRequestPtr& req, HttpCallback&& callback,
                     int64_t id, const std::string& rightId);

    // GET /api/v1/users/:id/filters
    void getFilters(const drogon::HttpRequestPtr& req, HttpCallback&& callback, int64_t id);

    // POST /api/v1/users/:id/filters
    void saveFilter(const drogon::HttpRequestPtr& req, HttpCallback&& callback, int64_t id);

    // DELETE /api/v1/users/:id/filters/:filterId
    void deleteFilter(const drogon::HttpRequestPtr& req, HttpCallback&& callback,
                      int64_t id, int64_t filterId);

    // GET /api/v1/users/search — Search users
    void search(const drogon::HttpRequestPtr& req, HttpCallback&& callback);

    // GET /api/v1/users/active — List active users
    void listActive(const drogon::HttpRequestPtr& req, HttpCallback&& callback);

    // GET /api/v1/users/me — Current user profile
    void me(const drogon::HttpRequestPtr& req, HttpCallback&& callback);

    // PUT /api/v1/users/me — Update own profile
    void updateMe(const drogon::HttpRequestPtr& req, HttpCallback&& callback);

    // GET /api/v1/users/export — Export users to CSV/JSON
    void exportUsers(const drogon::HttpRequestPtr& req, HttpCallback&& callback);

    // POST /api/v1/users/bulk — Bulk operations
    void bulkOperation(const drogon::HttpRequestPtr& req, HttpCallback&& callback);

private:
    std::shared_ptr<org::projectforge::business::user::UserDao> userDao_;
    std::shared_ptr<org::projectforge::business::group::GroupDao> groupDao_;

    // Helper: convert internal User to API-friendly JSON
    json userToApiJson(const org::projectforge::business::user::User& user) const;
    json usersToApiJson(const std::vector<org::projectforge::business::user::User>& users) const;

    // Helper: validate create/update data
    bool validateUserData(const json& data, bool isUpdate, std::string& errorMsg) const;
    void applyUserUpdates(org::projectforge::business::user::User& user, const json& data) const;
};

} // namespace org::projectforge::rest
