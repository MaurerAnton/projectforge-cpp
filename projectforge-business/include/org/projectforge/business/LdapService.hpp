#pragma once

#include <string>
#include <vector>
#include <optional>
#include <memory>
#include <cstdint>

namespace sqlite_orm { class database; }

namespace org::projectforge::business::ldap {

struct LdapConfig {
    std::string server_url;
    int32_t port = 389;
    bool use_ssl = false;
    std::string base_dn;
    std::string bind_dn;
    std::string bind_password;
    std::string user_search_filter = "(uid={0})";
    std::string user_search_base;
    std::string group_search_base;
    std::string group_search_filter = "(member={0})";
    bool enabled = false;
    int32_t sync_interval_minutes = 60;
};

struct LdapUser {
    std::string uid;
    std::string cn;
    std::string given_name;
    std::string sn;
    std::string mail;
    std::string telephone_number;
    std::string mobile;
    std::string organization;
    std::string department;
    std::vector<std::string> member_of;
};

class LdapService {
public:
    explicit LdapService(std::shared_ptr<sqlite_orm::database> db);

    bool initialize(const LdapConfig& config);
    bool testConnection() const;
    bool authenticateLdapUser(const std::string& username, const std::string& password) const;

    std::vector<LdapUser> searchUsers(const std::string& query, int limit = 100) const;
    std::optional<LdapUser> findUser(const std::string& username) const;
    std::vector<LdapUser> getAllLdapUsers() const;

    bool syncUserFromLdap(const std::string& username);
    int32_t syncAllUsers();
    bool syncGroupMembership(const std::string& groupName);

    std::vector<std::string> getPosixGroupsForUser(const std::string& username) const;

    LdapConfig getConfig() const;
    bool updateConfig(const LdapConfig& config);
    bool isEnabled() const;

    struct SyncResult {
        int32_t users_created = 0;
        int32_t users_updated = 0;
        int32_t users_deactivated = 0;
        int32_t groups_synced = 0;
        int32_t errors = 0;
        std::vector<std::string> error_messages;
    };
    SyncResult performFullSync();

private:
    std::shared_ptr<sqlite_orm::database> db_;
    LdapConfig config_;
    bool initialized_ = false;

    bool connectLdap(void*& ldapHandle) const;
    void disconnectLdap(void* ldapHandle) const;
    bool createOrUpdateLocalUser(const LdapUser& ldapUser) const;
    bool deactivateMissingUsers(const std::vector<std::string>& ldapUsernames) const;
};

} // namespace org::projectforge::business::ldap
