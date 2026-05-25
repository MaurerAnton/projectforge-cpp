#pragma once

#include <string>
#include <vector>
#include <memory>
#include <functional>
#include <map>
#include <cstdint>
#include <nlohmann/json.hpp>

namespace sqlite_orm { class database; }

namespace org::projectforge::business::admin {

using json = nlohmann::json;

struct SystemInfo {
    std::string version;
    std::string build_date;
    int64_t uptime_seconds;
    size_t total_users;
    size_t active_users;
    size_t total_tasks;
    size_t total_timesheets;
    size_t database_size_bytes;
    double memory_usage_mb;
    int32_t cpu_usage_percent;
};

struct DatabaseStats {
    size_t user_count = 0;
    size_t task_count = 0;
    size_t timesheet_count = 0;
    size_t address_count = 0;
    size_t calendar_count = 0;
    size_t rechnung_count = 0;
    size_t konto_count = 0;
    size_t auftrag_count = 0;
    size_t kost2_count = 0;
    size_t vacation_count = 0;
    size_t book_count = 0;
    int64_t total_database_size = 0;
};

class AdminService {
public:
    explicit AdminService(std::shared_ptr<sqlite_orm::database> db);

    // System info
    SystemInfo getSystemInfo() const;
    DatabaseStats getDatabaseStats() const;

    // Health checks
    bool checkDatabaseHealth(std::string& status) const;
    bool checkDiskSpace(std::string& status) const;
    bool checkMemoryUsage(std::string& status) const;

    // Maintenance
    bool vacuumDatabase();
    bool reindexDatabase();
    bool clearExpiredSessions();
    bool clearOldAuditLogs(int64_t olderThanTimestamp);
    bool backupDatabase(const std::string& backupPath);
    bool restoreDatabase(const std::string& backupPath);

    // User management
    struct UserSummary {
        int64_t id;
        std::string username;
        std::string email;
        bool active;
        int64_t last_login;
        size_t group_count;
        size_t right_count;
    };
    std::vector<UserSummary> getAllUserSummaries() const;
    bool setUserActive(int64_t userId, bool active);
    bool setUserType(int64_t userId, const std::string& type);

    // Data integrity
    struct IntegrityReport {
        size_t orphaned_tasks = 0;
        size_t orphaned_timesheets = 0;
        size_t orphaned_rechnungen = 0;
        size_t orphaned_addresses = 0;
        size_t inconsistencies_fixed = 0;
        std::vector<std::string> issues;
    };
    IntegrityReport runIntegrityCheck();
    IntegrityReport fixIntegrityIssues();

    // System configuration
    json getSystemConfiguration() const;
    bool updateSystemConfiguration(const json& config);
    bool reloadConfiguration();

    // Logs
    std::vector<std::string> getRecentErrors(int limit = 100) const;
    json getSystemMetrics() const;

private:
    std::shared_ptr<sqlite_orm::database> db_;
    int64_t getTableCount(const std::string& tableName) const;
    std::string getCurrentTimestamp() const;
};

} // namespace org::projectforge::business::admin
