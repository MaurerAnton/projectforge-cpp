// ProjectForge C++ port — GPL v3 — www.projectforge.org
#pragma once

#include <org/projectforge/rest/RestController.hpp>
#include <org/projectforge/rest/JsonSerializer.hpp>
#include <org/projectforge/business/TaskDao.hpp>
#include <drogon/HttpController.h>
#include <memory>

namespace org::projectforge::rest {

class TaskPagesRest : public RestController {
public:
    TaskPagesRest(std::shared_ptr<org::projectforge::business::task::TaskDao> taskDao);

    // GET /api/v1/tasks
    void list(const drogon::HttpRequestPtr& req, HttpCallback&& callback);
    // GET /api/v1/tasks/:id
    void get(const drogon::HttpRequestPtr& req, HttpCallback&& callback, int64_t id);
    // POST /api/v1/tasks
    void create(const drogon::HttpRequestPtr& req, HttpCallback&& callback);
    // PUT /api/v1/tasks/:id
    void update(const drogon::HttpRequestPtr& req, HttpCallback&& callback, int64_t id);
    // PATCH /api/v1/tasks/:id
    void patch(const drogon::HttpRequestPtr& req, HttpCallback&& callback, int64_t id);
    // DELETE /api/v1/tasks/:id
    void remove(const drogon::HttpRequestPtr& req, HttpCallback&& callback, int64_t id);
    // PUT /api/v1/tasks/:id/status
    void updateStatus(const drogon::HttpRequestPtr& req, HttpCallback&& callback, int64_t id);
    // PUT /api/v1/tasks/:id/progress
    void updateProgress(const drogon::HttpRequestPtr& req, HttpCallback&& callback, int64_t id);
    // PUT /api/v1/tasks/:id/assignee
    void updateAssignee(const drogon::HttpRequestPtr& req, HttpCallback&& callback, int64_t id);
    // GET /api/v1/tasks/:id/comments
    void getComments(const drogon::HttpRequestPtr& req, HttpCallback&& callback, int64_t id);
    // POST /api/v1/tasks/:id/comments
    void addComment(const drogon::HttpRequestPtr& req, HttpCallback&& callback, int64_t id);
    // PUT /api/v1/tasks/:id/comments/:commentId
    void updateComment(const drogon::HttpRequestPtr& req, HttpCallback&& callback, int64_t id, int64_t commentId);
    // DELETE /api/v1/tasks/:id/comments/:commentId
    void removeComment(const drogon::HttpRequestPtr& req, HttpCallback&& callback, int64_t id, int64_t commentId);
    // GET /api/v1/tasks/:id/attachments
    void getAttachments(const drogon::HttpRequestPtr& req, HttpCallback&& callback, int64_t id);
    // POST /api/v1/tasks/:id/attachments
    void addAttachment(const drogon::HttpRequestPtr& req, HttpCallback&& callback, int64_t id);
    // DELETE /api/v1/tasks/:id/attachments/:attachmentId
    void removeAttachment(const drogon::HttpRequestPtr& req, HttpCallback&& callback, int64_t id, int64_t attachmentId);
    // GET /api/v1/tasks/:id/subtasks
    void getSubTasks(const drogon::HttpRequestPtr& req, HttpCallback&& callback, int64_t id);
    // GET /api/v1/tasks/search
    void search(const drogon::HttpRequestPtr& req, HttpCallback&& callback);
    // GET /api/v1/tasks/my — Current user's tasks
    void myTasks(const drogon::HttpRequestPtr& req, HttpCallback&& callback);
    // GET /api/v1/tasks/overdue
    void overdue(const drogon::HttpRequestPtr& req, HttpCallback&& callback);
    // GET /api/v1/tasks/export
    void exportTasks(const drogon::HttpRequestPtr& req, HttpCallback&& callback);
    // POST /api/v1/tasks/bulk
    void bulkOperation(const drogon::HttpRequestPtr& req, HttpCallback&& callback);
    // POST /api/v1/tasks/bulk-status
    void bulkUpdateStatus(const drogon::HttpRequestPtr& req, HttpCallback&& callback);

private:
    std::shared_ptr<org::projectforge::business::task::TaskDao> taskDao_;
    json taskToApiJson(const org::projectforge::business::task::Task& task) const;
    bool validateTaskData(const json& data, bool isUpdate, std::string& errorMsg) const;
};

} // namespace org::projectforge::rest
