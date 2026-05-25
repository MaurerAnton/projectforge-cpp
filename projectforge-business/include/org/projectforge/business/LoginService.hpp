#pragma once

#include <string>
#include <optional>
#include <memory>
#include <cstdint>
#include <functional>
#include <nlohmann/json.hpp>

namespace sqlite_orm { class database; }

namespace org::projectforge::business::login {

using json = nlohmann::json;

struct LoginResult {
    bool success = false;
    int64_t user_id = 0;
    std::string username;
    std::string token;
    std::string error_message;
    bool requires_tfa = false;
    int64_t last_login = 0;
};

struct TwoFactorSetup {
    std::string secret;
    std::string qr_code_url;
    std::string manual_entry_key;
};

class LoginService {
public:
    explicit LoginService(std::shared_ptr<sqlite_orm::database> db);

    LoginResult authenticate(const std::string& username, const std::string& password);
    LoginResult authenticateWithToken(const std::string& token);
    LoginResult verifyTwoFactor(int64_t userId, const std::string& tfaCode);

    bool changePassword(int64_t userId, const std::string& oldPassword, const std::string& newPassword);
    bool resetPassword(int64_t userId, const std::string& newPassword, int64_t resetBy);
    std::string generatePasswordResetToken(int64_t userId);
    bool validatePasswordResetToken(const std::string& token, int64_t& userId);

    TwoFactorSetup setupTwoFactor(int64_t userId);
    bool enableTwoFactor(int64_t userId, const std::string& tfaCode);
    bool disableTwoFactor(int64_t userId);

    std::string generateSessionToken(int64_t userId);
    bool validateSessionToken(const std::string& token, int64_t& userId) const;
    bool invalidateSessionToken(const std::string& token);
    void invalidateAllUserSessions(int64_t userId);

    bool lockAccount(int64_t userId);
    bool unlockAccount(int64_t userId);
    bool isAccountLocked(int64_t userId) const;

    // Security policies
    bool validatePasswordStrength(const std::string& password, std::string& errorMsg) const;
    bool isPasswordExpired(int64_t userId) const;
    int32_t getPasswordExpiryDays() const;

    json exportUserSessions(int64_t userId) const;

private:
    std::shared_ptr<sqlite_orm::database> db_;
    std::string hashPassword(const std::string& password, const std::string& salt = "") const;
    bool verifyPassword(const std::string& password, const std::string& hash) const;
    std::string generateToken(size_t length = 64) const;
    std::string generateTfaSecret() const;
    bool verifyTfaCode(const std::string& secret, const std::string& code) const;
};

} // namespace org::projectforge::business::login
