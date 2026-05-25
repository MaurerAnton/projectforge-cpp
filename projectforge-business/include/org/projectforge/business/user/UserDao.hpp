// ProjectForge C++ port — GPL v3 — www.projectforge.org
#pragma once
#include "UserEntity.hpp"
#include "org/projectforge/business/BaseDao.hpp"
#include "org/projectforge/common/CryptoHelper.hpp"
#include <algorithm>
#include <regex>

namespace org::projectforge::business::user {

class UserDao : public BaseDao<UserEntity> {
public:
    explicit UserDao(Storage& storage) : BaseDao<UserEntity>(storage) {}

    std::optional<UserEntity> findByUsername(const std::string& username) {
        try {
            auto result = storage_.template get_all<UserEntity>(
                sqlite_orm::where(sqlite_orm::c(&UserEntity::username) == username));
            return result.empty() ? std::nullopt : std::optional(result[0]);
        } catch (const std::exception& e) {
            spdlog::error("UserDao::findByUsername: {}", e.what());
            return std::nullopt;
        }
    }

    std::optional<UserEntity> findByEmail(const std::string& email) {
        try {
            auto result = storage_.template get_all<UserEntity>(
                sqlite_orm::where(sqlite_orm::c(&UserEntity::email) == email));
            return result.empty() ? std::nullopt : std::optional(result[0]);
        } catch (...) { return std::nullopt; }
    }

    std::vector<UserEntity> findActiveUsers() {
        return storage_.template get_all<UserEntity>(
            sqlite_orm::where(sqlite_orm::c(&UserEntity::deactivated) == false));
    }

    std::vector<UserEntity> searchUsers(const std::string& query, int limit = 50) {
        std::vector<UserEntity> result;
        auto all = getAll();
        std::string lowerQ = query;
        std::transform(lowerQ.begin(), lowerQ.end(), lowerQ.begin(), ::tolower);
        for (auto& u : all) {
            std::string fl = u.getFullname();
            std::transform(fl.begin(), fl.end(), fl.begin(), ::tolower);
            std::string un = u.username;
            std::transform(un.begin(), un.end(), un.begin(), ::tolower);
            if (fl.find(lowerQ) != std::string::npos || un.find(lowerQ) != std::string::npos) {
                result.push_back(u);
                if (static_cast<int>(result.size()) >= limit) break;
            }
        }
        return result;
    }

    bool authenticateUser(const std::string& username, const std::string& password) {
        auto user = findByUsername(username);
        if (!user.has_value() || user->deactivated) return false;
        return CryptoHelper::verifyPassword(password, user->passwordHash, user->salt);
    }

    bool changePassword(int64_t userId, const std::string& oldPassword, const std::string& newPassword) {
        auto user = getById(userId);
        if (!user.has_value()) return false;
        if (!CryptoHelper::verifyPassword(oldPassword, user->passwordHash, user->salt)) return false;
        user->salt = CryptoHelper::generateSalt();
        user->passwordHash = CryptoHelper::hashPassword(newPassword, user->salt);
        user->lastUpdate = nowMillis();
        user->passwordChanged = nowMillis();
        save(*user);
        return true;
    }

    bool setPassword(int64_t userId, const std::string& newPassword) {
        auto user = getById(userId);
        if (!user.has_value()) return false;
        user->salt = CryptoHelper::generateSalt();
        user->passwordHash = CryptoHelper::hashPassword(newPassword, user->salt);
        user->lastUpdate = nowMillis();
        user->passwordChanged = nowMillis();
        save(*user);
        return true;
    }

    void recordLogin(int64_t userId, bool success) {
        auto user = getById(userId);
        if (!user.has_value()) return;
        if (success) {
            user->failedLoginAttempts = 0;
            user->lastLogin = nowMillis();
        } else {
            user->failedLoginAttempts++;
        }
        save(*user);
    }

    bool isUsernameAvailable(const std::string& username) {
        return !findByUsername(username).has_value();
    }

    bool validatePasswordStrength(const std::string& password) {
        if (password.size() < 8) return false;
        bool hasUpper = false, hasLower = false, hasDigit = false, hasSpecial = false;
        for (char c : password) {
            if (std::isupper(c)) hasUpper = true;
            else if (std::islower(c)) hasLower = true;
            else if (std::isdigit(c)) hasDigit = true;
            else hasSpecial = true;
        }
        return hasUpper && hasLower && hasDigit;
    }

    std::vector<UserEntity> getUsersWithRole(const std::string& role) {
        // Simplified - in real PF this would check group memberships
        return getAll();
    }

    int64_t countActiveUsers() {
        return storage_.template count<UserEntity>(
            sqlite_orm::where(sqlite_orm::c(&UserEntity::deactivated) == false));
    }

private:
    static int64_t nowMillis() {
        return std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::system_clock::now().time_since_epoch()).count();
    }
};
}