#pragma once

#include <string>
#include <vector>
#include <memory>
#include <functional>
#include <chrono>
#include <cstdint>
#include <nlohmann/json.hpp>

namespace sqlite_orm { class database; }

namespace org::projectforge::business::jobs {

using json = nlohmann::json;

struct JobDefinition {
    int64_t id = 0;
    std::string name;
    std::string description;
    std::string job_type; // SCRIPT, EMAIL, EXPORT, BACKUP, CLEANUP, SYNC
    std::string cron_expression;
    bool enabled = true;
    int64_t last_run = 0;
    int64_t next_run = 0;
    json parameters;
    int32_t max_retries = 3;
    int32_t timeout_seconds = 300;
    int64_t created_at = 0;
    int64_t updated_at = 0;
};

struct JobExecution {
    int64_t id = 0;
    int64_t job_id = 0;
    int64_t started_at = 0;
    int64_t finished_at = 0;
    std::string status; // RUNNING, SUCCESS, FAILED, CANCELLED, RETRYING
    std::string output;
    std::string error_message;
    int32_t retry_count = 0;
    int64_t triggered_by = 0; // 0 = system/scheduler
};

class JobService {
public:
    explicit JobService(std::shared_ptr<sqlite_orm::database> db);

    // Job definitions
    std::vector<JobDefinition> getAllJobs() const;
    std::optional<JobDefinition> getJob(int64_t jobId) const;
    std::optional<JobDefinition> getJobByName(const std::string& name) const;
    JobDefinition createJob(const JobDefinition& job);
    JobDefinition updateJob(const JobDefinition& job);
    bool deleteJob(int64_t jobId);
    bool enableJob(int64_t jobId, bool enabled);

    // Scheduling
    std::vector<JobDefinition> getDueJobs(int64_t now) const;
    void scheduleJob(int64_t jobId, int64_t nextRunTime);
    void calculateNextRun(int64_t jobId);

    // Execution
    JobExecution executeJob(int64_t jobId, int64_t triggeredBy = 0);
    std::vector<JobExecution> getJobHistory(int64_t jobId, int limit = 50) const;
    std::vector<JobExecution> getRunningJobs() const;
    std::optional<JobExecution> getExecution(int64_t executionId) const;
    bool cancelJob(int64_t jobId);

    // Job processing
    int32_t processDueJobs();
    bool retryFailedJob(int64_t executionId);
    int32_t cleanupOldExecutions(int64_t olderThan, int32_t maxToKeep = 1000);

    // Statistics
    struct JobStats {
        int64_t job_id;
        std::string job_name;
        size_t total_executions;
        size_t successful;
        size_t failed;
        double success_rate;
        int64_t average_duration_ms;
        int64_t last_execution;
    };
    std::vector<JobStats> getJobStatistics() const;

    // Cron parsing
    static bool isValidCronExpression(const std::string& cronExpr);
    static int64_t calculateNextCronTime(const std::string& cronExpr, int64_t fromTime);

    json toJson(const JobDefinition& job) const;
    JobDefinition fromJson(const json& j) const;

private:
    std::shared_ptr<sqlite_orm::database> db_;

    struct CronField {
        std::vector<int32_t> values;
        bool has_wildcard = false;
        int32_t step = 1;
    };
    static CronField parseCronField(const std::string& field, int32_t minVal, int32_t maxVal);
    static bool matchCronField(const CronField& field, int32_t value);
    std::string getNextJobName() const;
};

} // namespace org::projectforge::business::jobs
