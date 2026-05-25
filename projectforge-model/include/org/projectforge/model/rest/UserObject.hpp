// ProjectForge C++ port — GPL v3 — www.projectforge.org
#pragma once
#include "AbstractBaseObject.hpp"
#include <string>
#include <vector>
#include <nlohmann/json.hpp>

namespace org::projectforge::model::rest {

class UserObject : public AbstractBaseObject {
public:
    std::string username;
    std::string firstName;
    std::string lastName;
    std::string email;
    std::string phone;
    std::string mobilePhone;
    std::string description;
    std::string organization;
    std::string position;
    std::string locale = "en";
    std::vector<int64_t> groupIds;
    bool localUser = true;
    bool restrictedUser = false;
    bool hrPlanning = false;
    bool deactivated = false;

    nlohmann::json toJson() const override {
        auto j = AbstractBaseObject::toJson();
        j["username"] = username;
        if (!firstName.empty()) j["firstName"] = firstName;
        if (!lastName.empty()) j["lastName"] = lastName;
        if (!email.empty()) j["email"] = email;
        if (!phone.empty()) j["phone"] = phone;
        if (!mobilePhone.empty()) j["mobilePhone"] = mobilePhone;
        if (!description.empty()) j["description"] = description;
        if (!organization.empty()) j["organization"] = organization;
        if (!position.empty()) j["position"] = position;
        j["locale"] = locale;
        j["localUser"] = localUser;
        j["restrictedUser"] = restrictedUser;
        j["hrPlanning"] = hrPlanning;
        j["deactivated"] = deactivated;
        return j;
    }

    void fromJson(const nlohmann::json& j) override {
        AbstractBaseObject::fromJson(j);
        if (j.contains("username")) username = j["username"];
        if (j.contains("firstName")) firstName = j["firstName"];
        if (j.contains("lastName")) lastName = j["lastName"];
        if (j.contains("email")) email = j["email"];
        if (j.contains("phone")) phone = j["phone"];
        if (j.contains("mobilePhone")) mobilePhone = j["mobilePhone"];
        if (j.contains("description")) description = j["description"];
        if (j.contains("organization")) organization = j["organization"];
        if (j.contains("position")) position = j["position"];
        if (j.contains("locale")) locale = j["locale"];
        if (j.contains("localUser")) localUser = j["localUser"];
        if (j.contains("restrictedUser")) restrictedUser = j["restrictedUser"];
        if (j.contains("hrPlanning")) hrPlanning = j["hrPlanning"];
        if (j.contains("deactivated")) deactivated = j["deactivated"];
    }
};
}