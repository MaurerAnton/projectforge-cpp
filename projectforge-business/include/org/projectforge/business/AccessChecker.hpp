#pragma once

#include <string>
#include <vector>
#include <memory>
#include <unordered_set>
#include <cstdint>

namespace sqlite_orm { class database; }

namespace org::projectforge::business::access {

struct AccessRight {
    std::string right_id;
    std::string description;
    std::string category;
};

class AccessChecker {
public:
    explicit AccessChecker(std::shared_ptr<sqlite_orm::database> db);

    bool hasRight(int64_t userId, const std::string& rightId) const;
    bool hasAnyRight(int64_t userId, const std::vector<std::string>& rightIds) const;
    bool hasAllRights(int64_t userId, const std::vector<std::string>& rightIds) const;

    bool isAdmin(int64_t userId) const;
    bool isFinanceUser(int64_t userId) const;
    bool isHrUser(int64_t userId) const;
    bool isProjectManager(int64_t userId) const;

    std::vector<std::string> getUserRights(int64_t userId) const;
    std::vector<AccessRight> getAllDefinedRights() const;
    AccessRight getAccessRightInfo(const std::string& rightId) const;

    bool grantRight(int64_t userId, const std::string& rightId, int64_t grantedBy);
    bool revokeRight(int64_t userId, const std::string& rightId);

    // Group-based access
    bool groupHasRight(int64_t groupId, const std::string& rightId) const;
    bool grantGroupRight(int64_t groupId, const std::string& rightId, int64_t grantedBy);
    bool revokeGroupRight(int64_t groupId, const std::string& rightId);

    // Resource-level access
    enum class ResourceType { TASK, TIMESHEET, ADDRESS, CALENDAR, RECHNUNG, KONTO, AUFTRAG, KOST2, HR, VACATION, BOOK, CONFIG };
    enum class AccessLevel { NONE = 0, READ = 1, WRITE = 2, ADMIN = 3 };

    bool canAccess(int64_t userId, ResourceType resource, int64_t resourceId, AccessLevel level) const;
    bool canAccessResource(int64_t userId, ResourceType resource, AccessLevel level) const;

    // Audit log
    struct AccessLog {
        int64_t user_id;
        std::string action;
        std::string resource_type;
        int64_t resource_id;
        std::string result; // GRANTED, DENIED
        int64_t timestamp;
    };
    void logAccess(const AccessLog& log);
    std::vector<AccessLog> getAccessLogs(int64_t userId, int64_t from, int64_t to) const;

    // Check helpers
    static constexpr const char* RIGHT_ADMIN = "ADMIN";
    static constexpr const char* RIGHT_FIBU_READ = "FIBU_READ";
    static constexpr const char* RIGHT_FIBU_WRITE = "FIBU_WRITE";
    static constexpr const char* RIGHT_FIBU_EXPORT = "FIBU_EXPORT";
    static constexpr const char* RIGHT_HR_READ = "HR_READ";
    static constexpr const char* RIGHT_HR_WRITE = "HR_WRITE";
    static constexpr const char* RIGHT_HR_PLANNING = "HR_PLANNING";
    static constexpr const char* RIGHT_TASK_READ = "TASK_READ";
    static constexpr const char* RIGHT_TASK_WRITE = "TASK_WRITE";
    static constexpr const char* RIGHT_TIMESHEET_READ = "TIMESHEET_READ";
    static constexpr const char* RIGHT_TIMESHEET_WRITE = "TIMESHEET_WRITE";
    static constexpr const char* RIGHT_ADDRESS_READ = "ADDRESS_READ";
    static constexpr const char* RIGHT_ADDRESS_WRITE = "ADDRESS_WRITE";
    static constexpr const char* RIGHT_CALENDAR_READ = "CALENDAR_READ";
    static constexpr const char* RIGHT_CALENDAR_WRITE = "CALENDAR_WRITE";
    static constexpr const char* RIGHT_CONFIG_READ = "CONFIG_READ";
    static constexpr const char* RIGHT_CONFIG_WRITE = "CONFIG_WRITE";
    static constexpr const char* RIGHT_USER_ADMIN = "USER_ADMIN";
    static constexpr const char* RIGHT_SCRIPTING = "SCRIPTING";
    static constexpr const char* RIGHT_EXPORT = "EXPORT";

private:
    std::shared_ptr<sqlite_orm::database> db_;
    static std::vector<AccessRight> s_definedRights;
};

} // namespace org::projectforge::business::access
