// ProjectForge C++ port — GPL v3 — www.projectforge.org
#pragma once
#include "AbstractBaseObject.hpp"
#include <string>
#include <nlohmann/json.hpp>

namespace org::projectforge::model::rest {

class AddressObject : public AbstractBaseObject {
public:
    std::string name;
    std::string firstName;
    std::string lastName;
    std::string organization;
    std::string street;
    std::string zipCode;
    std::string city;
    std::string country;
    std::string email;
    std::string phone;
    std::string mobilePhone;
    std::string website;
    std::string remarks;
    int64_t contactStatusId = -1;
    std::string addressType;

    nlohmann::json toJson() const override {
        auto j = AbstractBaseObject::toJson();
        if (!name.empty()) j["name"] = name;
        if (!firstName.empty()) j["firstName"] = firstName;
        if (!lastName.empty()) j["lastName"] = lastName;
        if (!organization.empty()) j["organization"] = organization;
        if (!street.empty()) j["street"] = street;
        if (!zipCode.empty()) j["zipCode"] = zipCode;
        if (!city.empty()) j["city"] = city;
        if (!country.empty()) j["country"] = country;
        if (!email.empty()) j["email"] = email;
        if (!phone.empty()) j["phone"] = phone;
        if (!mobilePhone.empty()) j["mobilePhone"] = mobilePhone;
        if (!website.empty()) j["website"] = website;
        if (!remarks.empty()) j["remarks"] = remarks;
        if (contactStatusId >= 0) j["contactStatusId"] = contactStatusId;
        if (!addressType.empty()) j["addressType"] = addressType;
        return j;
    }
};
}