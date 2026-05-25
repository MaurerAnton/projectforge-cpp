#pragma once

#include <org/projectforge/business/BaseDao.hpp>
#include <string>
#include <vector>
#include <optional>
#include <chrono>

namespace org::projectforge::business::task {

struct Task {
    int64_t id = 0;
    std::string title;
    std::string description;
    std::string reference;
    std::string task_path; // hierarchical path
    int64_t parent_task_id = 0;
    int64_t responsible_user_id = 0;
    int64_t assigned_user_id = 0;
    int64_t reporter_user_id = 0;
    int64_t max_hours = 0;
    int64_t duration_hours = 0;
    int64_t duration_minutes = 0;
    int32_t priority = 0; // 0=low, 1=normal, 2=high, 3=critical
    std::string status; // NEW, OPEN, IN_PROGRESS, RESOLVED, CLOSED
    std::string task_type; // TASK, BUG, FEATURE, etc.
    int64_t created_at = 0;
    int64_t updated_at = 0;
    int64_t deadline = 0;
    int64_t start_date = 0;
    int64_t resolved_at = 0;
    int64_t closed_at = 0;
    int64_t kost2_id = 0;
    int64_t project_id = 0;
    int32_t progress = 0; // 0-100
    int32_t story_points = 0;
    double planned_hours = 0.0;
    double actual_hours = 0.0;
    double remaining_hours = 0.0;
    bool billable = true;
    bool protection_of_privacy = false;
    std::string additional_info;
    std::string latest_comment;
    int32_t order_position = 0;
};

inline auto make_task_table() {
    using namespace sqlite_orm;
    return make_table("t_task",
        make_column("id", &Task::id, primary_key().autoincrement()),
        make_column("title", &Task::title),
        make_column("description", &Task::description),
        make_column("reference", &Task::reference),
        make_column("task_path", &Task::task_path),
        make_column("parent_task_id", &Task::parent_task_id),
        make_column("responsible_user_id", &Task::responsible_user_id),
        make_column("assigned_user_id", &Task::assigned_user_id),
        make_column("reporter_user_id", &Task::reporter_user_id),
        make_column("max_hours", &Task::max_hours),
        make_column("duration_hours", &Task::duration_hours),
        make_column("duration_minutes", &Task::duration_minutes),
        make_column("priority", &Task::priority),
        make_column("status", &Task::status),
        make_column("task_type", &Task::task_type),
        make_column("created_at", &Task::created_at),
        make_column("updated_at", &Task::updated_at),
        make_column("deadline", &Task::deadline),
        make_column("start_date", &Task::start_date),
        make_column("resolved_at", &Task::resolved_at),
        make_column("closed_at", &Task::closed_at),
        make_column("kost2_id", &Task::kost2_id),
        make_column("project_id", &Task::project_id),
        make_column("progress", &Task::progress),
        make_column("story_points", &Task::story_points),
        make_column("planned_hours", &Task::planned_hours),
        make_column("actual_hours", &Task::actual_hours),
        make_column("remaining_hours", &Task::remaining_hours),
        make_column("billable", &Task::billable),
        make_column("protection_of_privacy", &Task::protection_of_privacy),
        make_column("additional_info", &Task::additional_info),
        make_column("latest_comment", &Task::latest_comment),
        make_column("order_position", &Task::order_position));
}

struct TaskAttachment {
    int64_t id = 0;
    int64_t task_id = 0;
    std::string filename;
    std::string content_type;
    int64_t file_size = 0;
    std::vector<uint8_t> content;
    int64_t created_at = 0;
    int64_t created_by = 0;
};

inline auto make_task_attachment_table() {
    using namespace sqlite_orm;
    return make_table("t_task_attachment",
        make_column("id", &TaskAttachment::id, primary_key().autoincrement()),
        make_column("task_id", &TaskAttachment::task_id),
        make_column("filename", &TaskAttachment::filename),
        make_column("content_type", &TaskAttachment::content_type),
        make_column("file_size", &TaskAttachment::file_size),
        make_column("content", &TaskAttachment::content),
        make_column("created_at", &TaskAttachment::created_at),
        make_column("created_by", &TaskAttachment::created_by));
}

struct TaskComment {
    int64_t id = 0;
    int64_t task_id = 0;
    int64_t user_id = 0;
    std::string comment;
    int64_t created_at = 0;
    int64_t updated_at = 0;
};

inline auto make_task_comment_table() {
    using namespace sqlite_orm;
    return make_table("t_task_comment",
        make_column("id", &TaskComment::id, primary_key().autoincrement()),
        make_column("task_id", &TaskComment::task_id),
        make_column("user_id", &TaskComment::user_id),
        make_column("comment", &TaskComment::comment),
        make_column("created_at", &TaskComment::created_at),
        make_column("updated_at", &TaskComment::updated_at));
}

class TaskDao : public BaseDao<Task> {
public:
    explicit TaskDao(std::shared_ptr<sqlite_orm::database> db);

    std::vector<Task> findByParent(int64_t parentId) const;
    std::vector<Task> findByResponsibleUser(int64_t userId) const;
    std::vector<Task> findByAssignedUser(int64_t userId) const;
    std::vector<Task> findByStatus(const std::string& status) const;
    std::vector<Task> findByPriority(int32_t minPriority) const;
    std::vector<Task> findByProject(int64_t projectId) const;
    std::vector<Task> findByKost2(int64_t kost2Id) const;
    std::vector<Task> findOverdue(int64_t now) const;
    std::vector<Task> findDueSoon(int64_t now, int64_t threshold) const;
    std::vector<Task> findRecent(int64_t userId, int limit = 20) const;
    std::vector<Task> search(const std::string& query) const;
    std::vector<Task> findBillable() const;
    std::vector<Task> findRoots() const;

    bool updateStatus(int64_t taskId, const std::string& newStatus, int64_t timestamp);
    bool updateProgress(int64_t taskId, int32_t progress);
    bool updateAssignee(int64_t taskId, int64_t userId);
    bool updateDeadline(int64_t taskId, int64_t deadline);
    bool updatePriority(int64_t taskId, int32_t priority);

    double calculateTotalPlannedHours(int64_t projectId) const;
    double calculateTotalActualHours(int64_t taskId) const;
    std::vector<Task> getSubTasks(int64_t parentId) const;
    std::string buildTaskPath(int64_t taskId) const;

    // Attachments
    std::vector<TaskAttachment> getAttachments(int64_t taskId) const;
    TaskAttachment addAttachment(const TaskAttachment& attachment);
    bool removeAttachment(int64_t attachmentId);
    std::optional<TaskAttachment> getAttachment(int64_t attachmentId) const;

    // Comments
    std::vector<TaskComment> getComments(int64_t taskId) const;
    TaskComment addComment(const TaskComment& comment);
    bool updateComment(const TaskComment& comment);
    bool removeComment(int64_t commentId);

    json toJson(const Task& task) const override;
    Task fromJson(const json& j) const override;

    // Bulk operations
    std::vector<Task> bulkUpdateStatus(const std::vector<int64_t>& ids, const std::string& status);
};

} // namespace org::projectforge::business::task
