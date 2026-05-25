#pragma once

#include <org/projectforge/business/BaseDao.hpp>
#include <string>
#include <vector>
#include <optional>
#include <chrono>

namespace org::projectforge::business::user {

struct User {
    int64_t id = 0;
    std::string username;
    std::string password_hash;
    std::string email;
    std::string first_name;
    std::string last_name;
    std::string organization;
    std::string phone;
    std::string mobile_phone;
    std::string description;
    std::string locale;
    std::string timezone;
    std::string authentication_token;
    int64_t last_login = 0; // unix timestamp
    int64_t created_at = 0;
    int64_t updated_at = 0;
    int64_t deleted_at = 0;
    bool active = true;
    bool local_user = true;
    bool restricted_user = false;
    bool stay_logged_in = false;
    bool tfa_enabled = false;
    std::string tfa_secret;
    std::string avatar_url;
    int32_t login_failures = 0;
    int64_t last_failed_login = 0;
    int64_t password_changed_at = 0;
    std::string personal_phone_identifiers;
    std::string description_of_employment;
    std::string type; // STAFF, EXTERNAL, etc.
    std::string hr_status; // employed, left, etc.
    int64_t kost2_id = 0;
    int32_t default_task_duration_hours = 0;
    int32_t default_task_duration_minutes = 0;
    bool receives_business_mails = true;
    bool receives_newsletter = false;
    std::string instant_messaging_skype;
    std::string instant_messaging_the_others;
};

inline auto make_user_table() {
    using namespace sqlite_orm;
    return make_table("t_user",
        make_column("id", &User::id, primary_key().autoincrement()),
        make_column("username", &User::username),
        make_column("password_hash", &User::password_hash),
        make_column("email", &User::email),
        make_column("first_name", &User::first_name),
        make_column("last_name", &User::last_name),
        make_column("organization", &User::organization),
        make_column("phone", &User::phone),
        make_column("mobile_phone", &User::mobile_phone),
        make_column("description", &User::description),
        make_column("locale", &User::locale),
        make_column("timezone", &User::timezone),
        make_column("authentication_token", &User::authentication_token),
        make_column("last_login", &User::last_login),
        make_column("created_at", &User::created_at),
        make_column("updated_at", &User::updated_at),
        make_column("deleted_at", &User::deleted_at),
        make_column("active", &User::active),
        make_column("local_user", &User::local_user),
        make_column("restricted_user", &User::restricted_user),
        make_column("stay_logged_in", &User::stay_logged_in),
        make_column("tfa_enabled", &User::tfa_enabled),
        make_column("tfa_secret", &User::tfa_secret),
        make_column("avatar_url", &User::avatar_url),
        make_column("login_failures", &User::login_failures),
        make_column("last_failed_login", &User::last_failed_login),
        make_column("password_changed_at", &User::password_changed_at),
        make_column("personal_phone_identifiers", &User::personal_phone_identifiers),
        make_column("description_of_employment", &User::description_of_employment),
        make_column("type", &User::type),
        make_column("hr_status", &User::hr_status),
        make_column("kost2_id", &User::kost2_id),
        make_column("default_task_duration_hours", &User::default_task_duration_hours),
        make_column("default_task_duration_minutes", &User::default_task_duration_minutes),
        make_column("receives_business_mails", &User::receives_business_mails),
        make_column("receives_newsletter", &User::receives_newsletter),
        make_column("instant_messaging_skype", &User::instant_messaging_skype),
        make_column("instant_messaging_the_others", &User::instant_messaging_the_others));
}

struct UserRight {
    int64_t id = 0;
    int64_t user_id = 0;
    std::string right_id; // e.g. "FIBU_READ", "ADMIN"
    int64_t granted_at = 0;
    int64_t granted_by = 0;
};

inline auto make_user_right_table() {
    using namespace sqlite_orm;
    return make_table("t_user_right",
        make_column("id", &UserRight::id, primary_key().autoincrement()),
        make_column("user_id", &UserRight::user_id),
        make_column("right_id", &UserRight::right_id),
        make_column("granted_at", &UserRight::granted_at),
        make_column("granted_by", &UserRight::granted_by));
}

struct UserGroup {
    int64_t id = 0;
    int64_t user_id = 0;
    int64_t group_id = 0;
};

inline auto make_user_group_table() {
    using namespace sqlite_orm;
    return make_table("t_user_group",
        make_column("id", &UserGroup::id, primary_key().autoincrement()),
        make_column("user_id", &UserGroup::user_id),
        make_column("group_id", &UserGroup::group_id));
}

struct UserFilter {
    int64_t id = 0;
    int64_t user_id = 0;
    std::string filter_name;
    std::string filter_data; // JSON blob
    bool shared = false;
    int64_t created_at = 0;
};

inline auto make_user_filter_table() {
    using namespace sqlite_orm;
    return make_table("t_user_filter",
        make_column("id", &UserFilter::id, primary_key().autoincrement()),
        make_column("user_id", &UserFilter::user_id),
        make_column("filter_name", &UserFilter::filter_name),
        make_column("filter_data", &UserFilter::filter_data),
        make_column("shared", &UserFilter::shared),
        make_column("created_at", &UserFilter::created_at));
}

class UserDao : public BaseDao<User> {
public:
    explicit UserDao(std::shared_ptr<sqlite_orm::database> db);

    std::optional<User> findByUsername(const std::string& username) const;
    std::optional<User> findByEmail(const std::string& email) const;
    std::vector<User> findActive() const;
    std::vector<User> findByOrganization(const std::string& org) const;
    std::vector<User> findByType(const std::string& type) const;
    std::vector<User> findByHrStatus(const std::string& status) const;
    std::vector<User> search(const std::string& query) const;
    std::vector<User> findWithRight(const std::string& rightId) const;
    std::vector<User> findStaffUsers() const;
    std::vector<User> findDeletedUsers() const;

    bool authenticatePassword(const User& user, const std::string& password) const;
    bool updatePassword(int64_t userId, const std::string& newPasswordHash);
    bool updateLastLogin(int64_t userId, int64_t timestamp);
    bool incrementLoginFailure(int64_t userId);
    bool resetLoginFailures(int64_t userId);
    bool deactivateUser(int64_t userId);
    bool activateUser(int64_t userId);
    bool softDelete(int64_t userId, int64_t timestamp);
    bool restoreUser(int64_t userId);

    bool hasRight(int64_t userId, const std::string& rightId) const;
    bool grantRight(int64_t userId, const std::string& rightId, int64_t grantedBy);
    bool revokeRight(int64_t userId, const std::string& rightId);
    std::vector<UserRight> getUserRights(int64_t userId) const;
    std::vector<std::string> getRightIds(int64_t userId) const;

    bool addToGroup(int64_t userId, int64_t groupId);
    bool removeFromGroup(int64_t userId, int64_t groupId);
    std::vector<int64_t> getUserGroupIds(int64_t userId) const;

    std::vector<UserFilter> getUserFilters(int64_t userId) const;
    UserFilter saveFilter(const UserFilter& filter);
    bool deleteFilter(int64_t filterId);
    std::vector<UserFilter> getSharedFilters() const;

    json toJson(const User& user) const override;
    User fromJson(const json& j) const override;

    static std::string hashPassword(const std::string& password, const std::string& salt = "");
    static bool verifyTfaToken(const std::string& secret, const std::string& token);
    static std::string generateTfaSecret();

private:
    std::string generatePasswordHash(const std::string& password) const;
};

} // namespace org::projectforge::business::user
