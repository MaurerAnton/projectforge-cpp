/////////////////////////////////////////////////////////////////////////////
//
// Project ProjectForge Community Edition
//         www.projectforge.org
//
// Copyright (C) 2001-2026 Micromata GmbH, Germany (www.micromata.com)
//
// ProjectForge is dual-licensed.
//
// This community edition is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License as published
// by the Free Software Foundation; version 3 of the License.
//
// This community edition is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General
// Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this program; if not, see http://www.gnu.org/licenses/.
//
/////////////////////////////////////////////////////////////////////////////

#pragma once

#include "abstract_base_object.hpp"
#include <string>
#include <optional>
#include <chrono>

namespace org::projectforge::model::rest {

/**
 * REST DTO for addresses.
 * Equivalent to AddressObject.java / AddressDO.
 */
class AddressObject : public AbstractBaseObject {
public:
    AddressObject() = default;

    // -- uid --
    std::optional<std::string> getUid() const { return uid_; }
    void setUid(std::optional<std::string> uid) { uid_ = std::move(uid); }

    // -- contactStatus --
    std::optional<std::string> getContactStatus() const { return contact_status_; }
    AddressObject& setContactStatus(std::optional<std::string> status) { contact_status_ = std::move(status); return *this; }

    // -- addressStatus --
    std::optional<std::string> getAddressStatus() const { return address_status_; }
    AddressObject& setAddressStatus(std::optional<std::string> status) { address_status_ = std::move(status); return *this; }

    // -- name --
    std::optional<std::string> getName() const { return name_; }
    AddressObject& setName(std::optional<std::string> name) { name_ = std::move(name); return *this; }

    // -- firstName --
    std::optional<std::string> getFirstName() const { return first_name_; }
    AddressObject& setFirstName(std::optional<std::string> firstName) { first_name_ = std::move(firstName); return *this; }

    // -- fullName (computed) --
    std::string getFullName() const;

    // -- form --
    std::optional<std::string> getForm() const { return form_; }
    AddressObject& setForm(std::optional<std::string> form) { form_ = std::move(form); return *this; }

    // -- title --
    std::optional<std::string> getTitle() const { return title_; }
    AddressObject& setTitle(std::optional<std::string> title) { title_ = std::move(title); return *this; }

    // -- positionText --
    std::optional<std::string> getPositionText() const { return position_text_; }
    void setPositionText(std::optional<std::string> text) { position_text_ = std::move(text); }

    // -- organization --
    std::optional<std::string> getOrganization() const { return organization_; }
    AddressObject& setOrganization(std::optional<std::string> org) { organization_ = std::move(org); return *this; }

    // -- division --
    std::optional<std::string> getDivision() const { return division_; }
    void setDivision(std::optional<std::string> division) { division_ = std::move(division); }

    // -- businessPhone --
    std::optional<std::string> getBusinessPhone() const { return business_phone_; }
    AddressObject& setBusinessPhone(std::optional<std::string> phone) { business_phone_ = std::move(phone); return *this; }

    // -- mobilePhone --
    std::optional<std::string> getMobilePhone() const { return mobile_phone_; }
    AddressObject& setMobilePhone(std::optional<std::string> phone) { mobile_phone_ = std::move(phone); return *this; }

    // -- fax --
    std::optional<std::string> getFax() const { return fax_; }
    void setFax(std::optional<std::string> fax) { fax_ = std::move(fax); }

    // -- addressText --
    std::optional<std::string> getAddressText() const { return address_text_; }
    void setAddressText(std::optional<std::string> text) { address_text_ = std::move(text); }

    // -- zipCode --
    std::optional<std::string> getZipCode() const { return zip_code_; }
    void setZipCode(std::optional<std::string> zip) { zip_code_ = std::move(zip); }

    // -- city --
    std::optional<std::string> getCity() const { return city_; }
    void setCity(std::optional<std::string> city) { city_ = std::move(city); }

    // -- country --
    std::optional<std::string> getCountry() const { return country_; }
    void setCountry(std::optional<std::string> country) { country_ = std::move(country); }

    // -- state --
    std::optional<std::string> getState() const { return state_; }
    void setState(std::optional<std::string> state) { state_ = std::move(state); }

    // -- postalAddressText --
    std::optional<std::string> getPostalAddressText() const { return postal_address_text_; }
    void setPostalAddressText(std::optional<std::string> text) { postal_address_text_ = std::move(text); }

    // -- postalZipCode --
    std::optional<std::string> getPostalZipCode() const { return postal_zip_code_; }
    void setPostalZipCode(std::optional<std::string> zip) { postal_zip_code_ = std::move(zip); }

    // -- postalCity --
    std::optional<std::string> getPostalCity() const { return postal_city_; }
    void setPostalCity(std::optional<std::string> city) { postal_city_ = std::move(city); }

    // -- postalCountry --
    std::optional<std::string> getPostalCountry() const { return postal_country_; }
    void setPostalCountry(std::optional<std::string> country) { postal_country_ = std::move(country); }

    // -- postalState --
    std::optional<std::string> getPostalState() const { return postal_state_; }
    void setPostalState(std::optional<std::string> state) { postal_state_ = std::move(state); }

    // -- email --
    std::optional<std::string> getEmail() const { return email_; }
    AddressObject& setEmail(std::optional<std::string> email) { email_ = std::move(email); return *this; }

    // -- website --
    std::optional<std::string> getWebsite() const { return website_; }
    void setWebsite(std::optional<std::string> website) { website_ = std::move(website); }

    // -- communicationLanguage (locale string) --
    std::optional<std::string> getCommunicationLanguage() const { return communication_language_; }
    void setCommunicationLanguage(std::optional<std::string> lang) { communication_language_ = std::move(lang); }

    // -- privatePhone --
    std::optional<std::string> getPrivatePhone() const { return private_phone_; }
    AddressObject& setPrivatePhone(std::optional<std::string> phone) { private_phone_ = std::move(phone); return *this; }

    // -- privateMobilePhone --
    std::optional<std::string> getPrivateMobilePhone() const { return private_mobile_phone_; }
    void setPrivateMobilePhone(std::optional<std::string> phone) { private_mobile_phone_ = std::move(phone); }

    // -- privateAddressText --
    std::optional<std::string> getPrivateAddressText() const { return private_address_text_; }
    void setPrivateAddressText(std::optional<std::string> text) { private_address_text_ = std::move(text); }

    // -- privateZipCode --
    std::optional<std::string> getPrivateZipCode() const { return private_zip_code_; }
    void setPrivateZipCode(std::optional<std::string> zip) { private_zip_code_ = std::move(zip); }

    // -- privateCity --
    std::optional<std::string> getPrivateCity() const { return private_city_; }
    void setPrivateCity(std::optional<std::string> city) { private_city_ = std::move(city); }

    // -- privateCountry --
    std::optional<std::string> getPrivateCountry() const { return private_country_; }
    void setPrivateCountry(std::optional<std::string> country) { private_country_ = std::move(country); }

    // -- privateState --
    std::optional<std::string> getPrivateState() const { return private_state_; }
    void setPrivateState(std::optional<std::string> state) { private_state_ = std::move(state); }

    // -- privateEmail --
    std::optional<std::string> getPrivateEmail() const { return private_email_; }
    AddressObject& setPrivateEmail(std::optional<std::string> email) { private_email_ = std::move(email); return *this; }

    // -- publicKey --
    std::optional<std::string> getPublicKey() const { return public_key_; }
    void setPublicKey(std::optional<std::string> key) { public_key_ = std::move(key); }

    // -- fingerprint --
    std::optional<std::string> getFingerprint() const { return fingerprint_; }
    void setFingerprint(std::optional<std::string> fp) { fingerprint_ = std::move(fp); }

    // -- comment --
    std::optional<std::string> getComment() const { return comment_; }
    AddressObject& setComment(std::optional<std::string> comment) { comment_ = std::move(comment); return *this; }

    // -- birthday --
    std::optional<std::chrono::system_clock::time_point> getBirthday() const { return birthday_; }
    void setBirthday(std::optional<std::chrono::system_clock::time_point> birthday) { birthday_ = birthday; }

    // -- image (Base64 data string) --
    std::optional<std::string> getImage() const { return image_; }
    void setImage(std::optional<std::string> image) { image_ = std::move(image); }

    // -- vCardData (Base64 data string) --
    std::optional<std::string> getVCardData() const { return vcard_data_; }
    void setVCardData(std::optional<std::string> data) { vcard_data_ = std::move(data); }

private:
    std::optional<std::string> uid_;
    std::optional<std::string> contact_status_;
    std::optional<std::string> address_status_;
    std::optional<std::string> name_;
    std::optional<std::string> first_name_;
    std::optional<std::string> form_;
    std::optional<std::string> title_;
    std::optional<std::string> position_text_;
    std::optional<std::string> organization_;
    std::optional<std::string> division_;
    std::optional<std::string> business_phone_;
    std::optional<std::string> mobile_phone_;
    std::optional<std::string> fax_;
    std::optional<std::string> address_text_;
    std::optional<std::string> zip_code_;
    std::optional<std::string> city_;
    std::optional<std::string> country_;
    std::optional<std::string> state_;
    std::optional<std::string> postal_address_text_;
    std::optional<std::string> postal_zip_code_;
    std::optional<std::string> postal_city_;
    std::optional<std::string> postal_country_;
    std::optional<std::string> postal_state_;
    std::optional<std::string> email_;
    std::optional<std::string> website_;
    std::optional<std::string> communication_language_;
    std::optional<std::string> private_phone_;
    std::optional<std::string> private_mobile_phone_;
    std::optional<std::string> private_address_text_;
    std::optional<std::string> private_zip_code_;
    std::optional<std::string> private_city_;
    std::optional<std::string> private_country_;
    std::optional<std::string> private_state_;
    std::optional<std::string> private_email_;
    std::optional<std::string> public_key_;
    std::optional<std::string> fingerprint_;
    std::optional<std::string> comment_;
    std::optional<std::chrono::system_clock::time_point> birthday_;
    std::optional<std::string> image_;
    std::optional<std::string> vcard_data_;
};

} // namespace org::projectforge::model::rest
