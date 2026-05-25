#pragma once

#include <org/projectforge/business/BaseDao.hpp>
#include <string>
#include <vector>
#include <optional>
#include <cstdint>

namespace org::projectforge::business::gantt {

struct GanttTask {
    int64_t id = 0;
    int64_t project_id = 0;
    int64_t parent_id = 0;
    std::string name;
    std::string description;
    int64_t start_date = 0;
    int64_t end_date = 0;
    int64_t duration_days = 0;
    int32_t progress = 0; // 0-100
    std::string status;
    int64_t assigned_user_id = 0;
    int32_t order_position = 0;
    std::string color;
    bool is_milestone = false;
    std::string dependencies; // JSON array of task IDs
    int32_t level = 0;
    int64_t created_at = 0;
    int64_t updated_at = 0;
};

inline auto make_gantt_task_table() {
    using namespace sqlite_orm;
    return make_table("t_gantt_task",
        make_column("id", &GanttTask::id, primary_key().autoincrement()),
        make_column("project_id", &GanttTask::project_id),
        make_column("parent_id", &GanttTask::parent_id),
        make_column("name", &GanttTask::name),
        make_column("description", &GanttTask::description),
        make_column("start_date", &GanttTask::start_date),
        make_column("end_date", &GanttTask::end_date),
        make_column("duration_days", &GanttTask::duration_days),
        make_column("progress", &GanttTask::progress),
        make_column("status", &GanttTask::status),
        make_column("assigned_user_id", &GanttTask::assigned_user_id),
        make_column("order_position", &GanttTask::order_position),
        make_column("color", &GanttTask::color),
        make_column("is_milestone", &GanttTask::is_milestone),
        make_column("dependencies", &GanttTask::dependencies),
        make_column("level", &GanttTask::level),
        make_column("created_at", &GanttTask::created_at),
        make_column("updated_at", &GanttTask::updated_at));
}

class GanttDao : public BaseDao<GanttTask> {
public:
    explicit GanttDao(std::shared_ptr<sqlite_orm::database> db);

    std::vector<GanttTask> findByProject(int64_t projectId) const;
    std::vector<GanttTask> findByParent(int64_t parentId) const;
    std::vector<GanttTask> findByAssignedUser(int64_t userId) const;
    std::vector<GanttTask> findMilestones(int64_t projectId) const;
    std::vector<GanttTask> findRootTasks(int64_t projectId) const;
    std::vector<GanttTask> findOverdue(int64_t now) const;

    bool updateProgress(int64_t taskId, int32_t progress);
    bool updateDates(int64_t taskId, int64_t startDate, int64_t endDate);
    bool reorderTasks(int64_t projectId, const std::vector<std::pair<int64_t, int32_t>>& taskPositions);
    bool moveTask(int64_t taskId, int64_t newParentId, int32_t newPosition);

    // Calculations
    int64_t calculateProjectEnd(int64_t projectId) const;
    int64_t calculateCriticalPathDuration(int64_t projectId) const;
    std::vector<int64_t> getCriticalPath(int64_t projectId) const;
    void recalculateLevels(int64_t projectId);
    void recalculateDependentDates(int64_t taskId);

    json toJson(const GanttTask& task) const override;
    GanttTask fromJson(const json& j) const override;
};

} // namespace org::projectforge::business::gantt
