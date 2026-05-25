// ProjectForge C++ port — GPL v3 — www.projectforge.org
#pragma once
#include <string>
#include <vector>
#include <map>
#include <set>
#include <optional>
#include <memory>
#include <stdexcept>

namespace org::projectforge::framework::access {

enum class OperationType {
    SELECT, INSERT, UPDATE, DELETE, ADMIN
};

enum class AccessType {
    ALLOW, DENY, INHERIT
};

// Access entry for a specific user/group on a specific entity
struct AccessEntry {
    int64_t id = -1;
    int64_t userId = -1;  // -1 means applies to groups
    int64_t groupId = -1; // -1 means applies to users
    std::string entityType;
    int64_t entityId = -1; // -1 means all entities of this type
    AccessType accessType = AccessType::ALLOW;
    std::set<OperationType> operations;
    bool recursive = false; // applies to children too

    bool matchesOperation(OperationType op) const {
        return operations.count(op) > 0 || operations.count(OperationType::ADMIN) > 0;
    }
    bool matchesEntity(int64_t eid, const std::string& etype) const {
        return entityType == etype && (entityId == -1 || entityId == eid);
    }
};

// Group-task access
struct GroupTaskAccessEntry {
    int64_t id = -1;
    int64_t groupId = -1;
    int64_t taskId = -1;
    AccessType accessType = AccessType::ALLOW;
    std::set<OperationType> operations;
    bool recursive = false;
};

// Access checker - determines if a user has permission
class AccessChecker {
public:
    static AccessChecker& instance() { static AccessChecker ac; return ac; }

    void addAccessEntry(const AccessEntry& entry) { entries_.push_back(entry); }
    void addGroupTaskAccess(const GroupTaskAccessEntry& entry) { groupTaskEntries_.push_back(entry); }
    void setUserGroups(int64_t userId, const std::vector<int64_t>& groupIds) {
        userGroups_[userId] = std::set<int64_t>(groupIds.begin(), groupIds.end());
    }
    void addUserRight(int64_t userId, const std::string& rightId) {
        userRights_[userId].insert(rightId);
    }

    bool hasAccess(int64_t userId, const std::string& entityType, int64_t entityId, OperationType op) {
        if (userId < 0) return false;
        auto userGroups = userGroups_.find(userId);

        // Check deny entries first
        for (auto& entry : entries_) {
            if (!entry.matchesEntity(entityId, entityType)) continue;
            if (!entry.matchesOperation(op)) continue;
            if (entry.accessType != AccessType::DENY) continue;

            if (entry.userId == userId) return false;
            if (entry.groupId >= 0 && userGroups != userGroups_.end() &&
                userGroups->second.count(entry.groupId) > 0) return false;
        }

        // Check allow entries
        for (auto& entry : entries_) {
            if (!entry.matchesEntity(entityId, entityType)) continue;
            if (!entry.matchesOperation(op)) continue;
            if (entry.accessType != AccessType::ALLOW) continue;

            if (entry.userId == userId) return true;
            if (entry.groupId >= 0 && userGroups != userGroups_.end() &&
                userGroups->second.count(entry.groupId) > 0) return true;
        }

        // Check user rights
        auto rights = userRights_.find(userId);
        if (rights != userRights_.end() && rights->second.count("ADMIN") > 0) return true;

        return false;
    }

    bool hasInsertAccess(int64_t userId, const std::string& entityType, int64_t entityId=-1) {
        return hasAccess(userId, entityType, entityId, OperationType::INSERT);
    }
    bool hasUpdateAccess(int64_t userId, const std::string& entityType, int64_t entityId) {
        return hasAccess(userId, entityType, entityId, OperationType::UPDATE);
    }
    bool hasDeleteAccess(int64_t userId, const std::string& entityType, int64_t entityId) {
        return hasAccess(userId, entityType, entityId, OperationType::DELETE);
    }
    bool hasSelectAccess(int64_t userId, const std::string& entityType, int64_t entityId=-1) {
        return hasAccess(userId, entityType, entityId, OperationType::SELECT);
    }
    bool hasAdminAccess(int64_t userId) {
        auto rights = userRights_.find(userId);
        return rights != userRights_.end() && rights->second.count("ADMIN") > 0;
    }

    bool hasTaskAccess(int64_t userId, int64_t taskId, OperationType op) {
        auto userGroups = userGroups_.find(userId);
        for (auto& entry : groupTaskEntries_) {
            if (entry.taskId != taskId) continue;
            if (!entry.operations.count(op) && !entry.operations.count(OperationType::ADMIN)) continue;
            if (entry.groupId >= 0 && userGroups != userGroups_.end() &&
                userGroups->second.count(entry.groupId) > 0) {
                return entry.accessType == AccessType::ALLOW;
            }
        }
        return false;
    }

    void clear() {
        entries_.clear();
        groupTaskEntries_.clear();
        userGroups_.clear();
        userRights_.clear();
    }

private:
    std::vector<AccessEntry> entries_;
    std::vector<GroupTaskAccessEntry> groupTaskEntries_;
    std::map<int64_t, std::set<int64_t>> userGroups_;
    std::map<int64_t, std::set<std::string>> userRights_;
};

class AccessException : public std::runtime_error {
public:
    explicit AccessException(const std::string& msg) : std::runtime_error(msg) {}
};

} // namespace
