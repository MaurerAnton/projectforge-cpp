// ProjectForge C++ port — GPL v3 — www.projectforge.org
#pragma once
#include "org/projectforge/business/BaseDao.hpp"
#include <string>
#include <vector>

namespace org::projectforge::business::user {

struct UserEntity {
    DECLARE_ENTITY_FIELDS();
    std::string username;
    std::string passwordHash;
    std::string salt;
    std::string firstName;
    std::string lastName;
    std::string email;
    std::string phone;
    std::string mobilePhone;
    std::string description;
    std::string organization;
    std::string position;
    std::string locale = "en";
    bool localUser = true;
    bool restrictedUser = false;
    bool hrPlanning = false;
    bool deactivated = false;
    bool stayLoggedIn = false;
    int failedLoginAttempts = 0;
    int64_t lastLogin = 0;
    int64_t passwordChanged = 0;

    nlohmann::json toJson() const {
        nlohmann::json j;
        JSON_ENTITY_BASE(j);
        if (!username.empty()) j["username"] = username;
        if (!firstName.empty()) j["firstName"] = firstName;
        if (!lastName.empty()) j["lastName"] = lastName;
        if (!email.empty()) j["email"] = email;
        if (!phone.empty()) j["phone"] = phone;
        if (!mobilePhone.empty()) j["mobilePhone"] = mobilePhone;
        if (!description.empty()) j["description"] = description;
        if (!organization.empty()) j["organization"] = organization;
        if (!position.empty()) j["position"] = position;
        j["locale"] = locale; j["localUser"] = localUser;
        j["restrictedUser"] = restrictedUser; j["hrPlanning"] = hrPlanning;
        j["deactivated"] = deactivated; j["stayLoggedIn"] = stayLoggedIn;
        j["failedLoginAttempts"] = failedLoginAttempts;
        if (lastLogin > 0) j["lastLogin"] = lastLogin;
        if (passwordChanged > 0) j["passwordChanged"] = passwordChanged;
        return j;
    }

    void fromJson(const nlohmann::json& j) {
        FROMJSON_ENTITY_BASE(j);
        if (j.contains("username")) username = j["username"];
        if (j.contains("firstName")) firstName = j["firstName"];
        if (j.contains("lastName")) lastName = j["lastName"];
        if (j.contains("email")) email = j["email"];
        if (j.contains("phone")) phone = j["phone"];
        if (j.contains("mobilePhone")) mobilePhone = j["mobilePhone"];
        if (j.contains("locale")) locale = j["locale"];
        if (j.contains("deactivated")) deactivated = j["deactivated"];
    }

    std::string getFullname() const {
        if (!firstName.empty()) return firstName + " " + lastName;
        if (!lastName.empty()) return lastName;
        return username;
    }
};

auto createUserTable() {
    using namespace sqlite_orm;
    return make_table("pf_user",
        make_column("id", &UserEntity::id, primary_key().autoincrement()),
        make_column("username", &UserEntity::username, unique()),
        make_column("password_hash", &UserEntity::passwordHash),
        make_column("salt", &UserEntity::salt),
        make_column("first_name", &UserEntity::firstName),
        make_column("last_name", &UserEntity::lastName),
        make_column("email", &UserEntity::email),
        make_column("phone", &UserEntity::phone),
        make_column("mobile_phone", &UserEntity::mobilePhone),
        make_column("description", &UserEntity::description),
        make_column("organization", &UserEntity::organization),
        make_column("position", &UserEntity::position),
        make_column("locale", &UserEntity::locale),
        make_column("local_user", &UserEntity::localUser),
        make_column("restricted_user", &UserEntity::restrictedUser),
        make_column("hr_planning", &UserEntity::hrPlanning),
        make_column("deactivated", &UserEntity::deactivated),
        make_column("stay_logged_in", &UserEntity::stayLoggedIn),
        make_column("failed_login_attempts", &UserEntity::failedLoginAttempts),
        make_column("last_login", &UserEntity::lastLogin),
        make_column("password_changed", &UserEntity::passwordChanged),
        make_column("created", &UserEntity::created),
        make_column("last_update", &UserEntity::lastUpdate),
        make_column("deleted", &UserEntity::deleted)
    );
}
}