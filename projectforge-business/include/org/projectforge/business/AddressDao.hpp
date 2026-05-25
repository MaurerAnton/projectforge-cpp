#pragma once

#include <org/projectforge/business/BaseDao.hpp>
#include <string>
#include <vector>
#include <optional>
#include <cstdint>

namespace org::projectforge::business::address {

struct Address {
    int64_t id = 0;
    std::string name;
    std::string first_name;
    std::string form_of_address;
    std::string title;
    std::string organization;
    std::string division;
    std::string position_text;
    std::string street;
    std::string zip_code;
    std::string city;
    std::string country;
    std::string state;
    std::string postal_address;
    std::string phone_business;
    std::string phone_mobile;
    std::string phone_private;
    std::string fax_business;
    std::string email;
    std::string website;
    std::string communication_language;
    std::string fingerprint;
    std::string public_key;
    std::string comment;
    std::string address_status;
    std::string vat_id;
    std::string data_privacy_agreement;
    std::string contact_status;
    int64_t created_at = 0;
    int64_t updated_at = 0;
    int64_t deleted_at = 0;
    int64_t birthday = 0;
    double latitude = 0.0;
    double longitude = 0.0;
    bool favorite = false;
};

inline auto make_address_table() {
    using namespace sqlite_orm;
    return make_table("t_address",
        make_column("id", &Address::id, primary_key().autoincrement()),
        make_column("name", &Address::name),
        make_column("first_name", &Address::first_name),
        make_column("form_of_address", &Address::form_of_address),
        make_column("title", &Address::title),
        make_column("organization", &Address::organization),
        make_column("division", &Address::division),
        make_column("position_text", &Address::position_text),
        make_column("street", &Address::street),
        make_column("zip_code", &Address::zip_code),
        make_column("city", &Address::city),
        make_column("country", &Address::country),
        make_column("state", &Address::state),
        make_column("postal_address", &Address::postal_address),
        make_column("phone_business", &Address::phone_business),
        make_column("phone_mobile", &Address::phone_mobile),
        make_column("phone_private", &Address::phone_private),
        make_column("fax_business", &Address::fax_business),
        make_column("email", &Address::email),
        make_column("website", &Address::website),
        make_column("communication_language", &Address::communication_language),
        make_column("fingerprint", &Address::fingerprint),
        make_column("public_key", &Address::public_key),
        make_column("comment", &Address::comment),
        make_column("address_status", &Address::address_status),
        make_column("vat_id", &Address::vat_id),
        make_column("data_privacy_agreement", &Address::data_privacy_agreement),
        make_column("contact_status", &Address::contact_status),
        make_column("created_at", &Address::created_at),
        make_column("updated_at", &Address::updated_at),
        make_column("deleted_at", &Address::deleted_at),
        make_column("birthday", &Address::birthday),
        make_column("latitude", &Address::latitude),
        make_column("longitude", &Address::longitude),
        make_column("favorite", &Address::favorite));
}

struct AddressImage {
    int64_t id = 0;
    int64_t address_id = 0;
    std::string filename;
    std::string content_type;
    int64_t file_size = 0;
    std::vector<uint8_t> content;
    int32_t order_position = 0;
};

inline auto make_address_image_table() {
    using namespace sqlite_orm;
    return make_table("t_address_image",
        make_column("id", &AddressImage::id, primary_key().autoincrement()),
        make_column("address_id", &AddressImage::address_id),
        make_column("filename", &AddressImage::filename),
        make_column("content_type", &AddressImage::content_type),
        make_column("file_size", &AddressImage::file_size),
        make_column("content", &AddressImage::content),
        make_column("order_position", &AddressImage::order_position));
}

class AddressDao : public BaseDao<Address> {
public:
    explicit AddressDao(std::shared_ptr<sqlite_orm::database> db);

    std::optional<Address> findByEmail(const std::string& email) const;
    std::vector<Address> findByOrganization(const std::string& org) const;
    std::vector<Address> findByCity(const std::string& city) const;
    std::vector<Address> findByCountry(const std::string& country) const;
    std::vector<Address> findByZipCode(const std::string& zip) const;
    std::vector<Address> findFavorites() const;
    std::vector<Address> findWithBirthdayToday(int64_t todayTimestamp) const;
    std::vector<Address> findByContactStatus(const std::string& status) const;
    std::vector<Address> search(const std::string& query) const;
    std::vector<Address> findInstantMessagingContacts() const;

    std::vector<std::string> getAllOrganizations() const;
    std::vector<std::string> getAllCities() const;
    std::vector<std::string> getAllCountries() const;

    bool softDelete(int64_t addressId, int64_t timestamp);
    bool restore(int64_t addressId);

    // Images
    std::vector<AddressImage> getImages(int64_t addressId) const;
    AddressImage addImage(const AddressImage& image);
    bool removeImage(int64_t imageId);
    std::optional<AddressImage> getImage(int64_t imageId) const;

    // Instant messaging
    struct InstantMessagingContact {
        std::string name;
        std::string type; // skype, etc.
        std::string identifier;
    };
    std::vector<InstantMessagingContact> buildInstantMessagingContactList() const;

    // VCard export
    std::string exportAsVCard(int64_t addressId) const;
    Address importFromVCard(const std::string& vcardData);

    json toJson(const Address& addr) const override;
    Address fromJson(const json& j) const override;
};

} // namespace org::projectforge::business::address
