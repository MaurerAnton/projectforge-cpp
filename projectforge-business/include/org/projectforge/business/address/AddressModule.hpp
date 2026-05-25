// ProjectForge C++ port — GPL v3 — www.projectforge.org
#pragma once

#include "org/projectforge/business/BaseDao.hpp"
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <regex>

namespace org::projectforge::business::address {

struct AddressEntity {
    DECLARE_ENTITY_FIELDS();
    std::string name;
    std::string firstName;
    std::string lastName;
    std::string formOfAddress;
    std::string title;
    std::string organization;
    std::string division;
    std::string street;
    std::string zipCode;
    std::string city;
    std::string country = "DE";
    std::string state;
    std::string postalBox;
    std::string email;
    std::string website;
    std::string phone;
    std::string mobilePhone;
    std::string fax;
    std::string privateEmail;
    std::string privatePhone;
    std::string privateMobile;
    std::string privateStreet;
    std::string privateZipCode;
    std::string privateCity;
    std::string privateCountry;
    std::string remarks;
    std::string vatId;
    std::string commercialRegister;
    std::string iban;
    std::string bic;
    std::string bankName;
    std::string accountHolder;
    std::string paymentType = "BANK_TRANSFER";
    int64_t contactStatusId = -1;
    std::string addressType = "BUSINESS";
    std::string communicationLanguage = "DE";
    double discount = 0.0;
    int paymentDays = 30;
    bool favorite = false;
    double longitude = 0.0;
    double latitude = 0.0;

    std::string getFullName() const {
        if (!title.empty() && !firstName.empty() && !lastName.empty())
            return title + " " + firstName + " " + lastName;
        if (!firstName.empty() && !lastName.empty()) return firstName + " " + lastName;
        if (!lastName.empty()) return lastName;
        if (!organization.empty()) return organization;
        return name;
    }

    std::string getFormattedAddress() const {
        std::ostringstream ss;
        if (!organization.empty()) ss << organization << "\\n";
        ss << getFullName() << "\\n";
        if (!street.empty()) ss << street << "\\n";
        if (!zipCode.empty() || !city.empty()) ss << zipCode << " " << city << "\\n";
        if (!country.empty()) ss << country;
        return ss.str();
    }

    nlohmann::json toJson() const {
        nlohmann::json j; JSON_ENTITY_BASE(j);
        if (!name.empty()) j["name"] = name;
        if (!firstName.empty()) j["firstName"] = firstName;
        if (!lastName.empty()) j["lastName"] = lastName;
        if (!organization.empty()) j["organization"] = organization;
        if (!email.empty()) j["email"] = email;
        if (!phone.empty()) j["phone"] = phone;
        if (!mobilePhone.empty()) j["mobilePhone"] = mobilePhone;
        if (!street.empty()) j["street"] = street;
        if (!zipCode.empty()) j["zipCode"] = zipCode;
        if (!city.empty()) j["city"] = city;
        if (!country.empty()) j["country"] = country;
        if (!website.empty()) j["website"] = website;
        if (!remarks.empty()) j["remarks"] = remarks;
        j["addressType"] = addressType; j["favorite"] = favorite;
        if (contactStatusId >= 0) j["contactStatusId"] = contactStatusId;
        if (!iban.empty()) { j["iban"] = iban; j["bic"] = bic; j["bankName"] = bankName; }
        return j;
    }
    void fromJson(const nlohmann::json& j) {
        FROMJSON_ENTITY_BASE(j);
        if (j.contains("name")) name = j["name"];
        if (j.contains("firstName")) firstName = j["firstName"];
        if (j.contains("lastName")) lastName = j["lastName"];
        if (j.contains("organization")) organization = j["organization"];
        if (j.contains("email")) email = j["email"];
        if (j.contains("phone")) phone = j["phone"];
        if (j.contains("mobilePhone")) mobilePhone = j["mobilePhone"];
        if (j.contains("street")) street = j["street"];
        if (j.contains("zipCode")) zipCode = j["zipCode"];
        if (j.contains("city")) city = j["city"];
        if (j.contains("country")) country = j["country"];
    }
};

class AddressDao : public BaseDao<AddressEntity> {
public:
    explicit AddressDao(Storage& storage) : BaseDao<AddressEntity>(storage) {}

    std::vector<AddressEntity> search(const std::string& query, int limit = 100) {
        auto all = getAll();
        std::vector<AddressEntity> r;
        std::string q = query;
        std::transform(q.begin(), q.end(), q.begin(), ::tolower);
        for (auto& a : all) {
            if (a.deleted) continue;
            std::string full = a.getFullName() + " " + a.organization + " " + a.email;
            std::transform(full.begin(), full.end(), full.begin(), ::tolower);
            if (full.find(q) != std::string::npos) {
                r.push_back(a);
                if (static_cast<int>(r.size()) >= limit) break;
            }
        }
        return r;
    }

    std::vector<AddressEntity> getByType(const std::string& type) {
        auto all = getAll();
        std::vector<AddressEntity> r;
        for (auto& a : all) if (!a.deleted && a.addressType == type) r.push_back(a);
        return r;
    }

    std::vector<AddressEntity> getBusinessAddresses() { return getByType("BUSINESS"); }
    std::vector<AddressEntity> getPrivateAddresses() { return getByType("PRIVATE"); }

    std::vector<AddressEntity> getFavorites() {
        auto all = getAll();
        std::vector<AddressEntity> r;
        for (auto& a : all) if (!a.deleted && a.favorite) r.push_back(a);
        return r;
    }

    std::vector<AddressEntity> findByEmail(const std::string& email) {
        auto all = getAll();
        std::vector<AddressEntity> r;
        for (auto& a : all) {
            if (!a.deleted && (a.email == email || a.privateEmail == email)) r.push_back(a);
        }
        return r;
    }

    std::vector<AddressEntity> findByCity(const std::string& city) {
        auto all = getAll();
        std::vector<AddressEntity> r;
        std::string c = city;
        std::transform(c.begin(), c.end(), c.begin(), ::tolower);
        for (auto& a : all) {
            std::string ac = a.city;
            std::transform(ac.begin(), ac.end(), ac.begin(), ::tolower);
            if (!a.deleted && ac == c) r.push_back(a);
        }
        return r;
    }

    std::vector<AddressEntity> getRecentAddresses(int limit = 20) {
        auto all = getAll();
        std::sort(all.begin(), all.end(), [](const auto& a, const auto& b) {
            return a.lastUpdate > b.lastUpdate;
        });
        if (static_cast<int>(all.size()) > limit) all.resize(limit);
        return all;
    }

    std::string exportAsVCard(int64_t addressId) {
        auto a = getById(addressId);
        if (!a.has_value()) return "";
        std::ostringstream ss;
        ss << "BEGIN:VCARD\\nVERSION:4.0\\n";
        ss << "FN:" << a->getFullName() << "\\n";
        if (!a->organization.empty()) ss << "ORG:" << a->organization << "\\n";
        if (!a->email.empty()) ss << "EMAIL;TYPE=work:" << a->email << "\\n";
        if (!a->phone.empty()) ss << "TEL;TYPE=work:" << a->phone << "\\n";
        if (!a->mobilePhone.empty()) ss << "TEL;TYPE=cell:" << a->mobilePhone << "\\n";
        if (!a->street.empty()) {
            ss << "ADR;TYPE=work:;;" << a->street << ";" << a->city << ";;" << a->zipCode << ";" << a->country << "\\n";
        }
        ss << "END:VCARD\\n";
        return ss.str();
    }

    std::vector<AddressEntity> getDuplicates() {
        auto all = getAll();
        std::vector<AddressEntity> dups;
        for (size_t i = 0; i < all.size(); ++i) {
            if (all[i].deleted) continue;
            for (size_t j = i + 1; j < all.size(); ++j) {
                if (all[j].deleted) continue;
                if (!all[i].email.empty() && all[i].email == all[j].email) {
                    dups.push_back(all[i]); dups.push_back(all[j]);
                }
            }
        }
        return dups;
    }

    std::vector<AddressEntity> getByVatId(const std::string& vatId) {
        auto all = getAll();
        std::vector<AddressEntity> r;
        for (auto& a : all) if (!a.deleted && a.vatId == vatId) r.push_back(a);
        return r;
    }

    // Address validation
    static bool isValidEmail(const std::string& email) {
        static std::regex emailRe(R"(^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$)");
        return std::regex_match(email, emailRe);
    }

    static bool isValidIBAN(const std::string& iban) {
        // Simplified IBAN validation - checks length and basic format
        return iban.size() >= 15 && iban.size() <= 34 && std::isalpha(iban[0]) && std::isalpha(iban[1]);
    }

    static bool isValidVatId(const std::string& vatId, const std::string& country = "DE") {
        if (country == "DE") { std::regex re(R"(DE\d{9})"); return std::regex_match(vatId, re); }
        return !vatId.empty();
    }
};

// Contact status entity
struct ContactStatusEntity {
    DECLARE_ENTITY_FIELDS();
    std::string name;
    std::string description;
    bool isActive = true;
};

class ContactStatusDao : public BaseDao<ContactStatusEntity> {
public:
    explicit ContactStatusDao(Storage& storage) : BaseDao<ContactStatusEntity>(storage) {}
    std::vector<ContactStatusEntity> getActive() {
        auto all = getAll();
        std::vector<ContactStatusEntity> r;
        for (auto& s : all) if (!s.deleted && s.isActive) r.push_back(s);
        return r;
    }
};

// VCard import/export service
class VCardService {
public:
    static std::vector<AddressEntity> parseVCard(const std::string& vcardData) {
        std::vector<AddressEntity> result;
        AddressEntity current;
        std::istringstream ss(vcardData);
        std::string line;
        bool inVCard = false;
        while (std::getline(ss, line)) {
            if (line.empty()) continue;
            if (line == "BEGIN:VCARD") { current = AddressEntity{}; inVCard = true; continue; }
            if (line == "END:VCARD") { if (inVCard) result.push_back(current); inVCard = false; continue; }
            if (!inVCard) continue;
            auto colon = line.find(':');
            if (colon == std::string::npos) continue;
            std::string key = line.substr(0, colon);
            std::string value = line.substr(colon + 1);
            // Normalize key
            auto semi = key.find(';');
            if (semi != std::string::npos) key = key.substr(0, semi);
            if (key == "FN") current.name = value;
            else if (key == "ORG") current.organization = value;
            else if (key == "EMAIL") current.email = value;
            else if (key == "TEL") {
                if (line.find("TYPE=cell") != std::string::npos) current.mobilePhone = value;
                else current.phone = value;
            } else if (key == "ADR") {
                auto parts = splitVCardAdr(value);
                if (parts.size() >= 3) { current.street = parts[2]; }
                if (parts.size() >= 4) { current.city = parts[3]; }
                if (parts.size() >= 6) { current.zipCode = parts[5]; }
                if (parts.size() >= 7) { current.country = parts[6]; }
            } else if (key == "URL") current.website = value;
            else if (key == "NOTE") current.remarks = value;
        }
        if (inVCard) result.push_back(current);
        return result;
    }

private:
    static std::vector<std::string> splitVCardAdr(const std::string& adr) {
        std::vector<std::string> parts;
        std::string current;
        for (size_t i = 0; i < adr.size(); ++i) {
            if (adr[i] == ';') { parts.push_back(current); current.clear(); }
            else if (adr[i] == '\\' && i + 1 < adr.size() && adr[i+1] == ';') { current += ';'; ++i; }
            else current += adr[i];
        }
        parts.push_back(current);
        return parts;
    }
};

} // namespace
