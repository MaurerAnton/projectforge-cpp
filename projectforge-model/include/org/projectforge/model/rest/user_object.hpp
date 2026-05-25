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

namespace org::projectforge::model::rest {

/**
 * REST DTO for ProjectForge users.
 * Equivalent to UserObject.java / PFUserDO.
 */
class UserObject : public AbstractBaseObject {
public:
    UserObject() = default;

    // -- username --
    std::optional<std::string> getUsername() const { return username_; }
    void setUsername(std::optional<std::string> username) { username_ = std::move(username); }

    // -- firstName --
    std::optional<std::string> getFirstName() const { return first_name_; }
    void setFirstName(std::optional<std::string> firstName) { first_name_ = std::move(firstName); }

    // -- lastName --
    std::optional<std::string> getLastName() const { return last_name_; }
    void setLastName(std::optional<std::string> lastName) { last_name_ = std::move(lastName); }

    // -- email --
    std::optional<std::string> getEmail() const { return email_; }
    void setEmail(std::optional<std::string> email) { email_ = std::move(email); }

    // -- authenticationToken --
    std::optional<std::string> getAuthenticationToken() const { return auth_token_; }
    void setAuthenticationToken(std::optional<std::string> token) { auth_token_ = std::move(token); }

    // -- timeZone --
    std::optional<std::string> getTimeZone() const { return time_zone_; }
    UserObject& setTimeZone(std::optional<std::string> timeZone) {
        time_zone_ = std::move(timeZone);
        return *this;
    }

    // -- locale --
    std::optional<std::string> getLocale() const { return locale_; }
    UserObject& setLocale(std::optional<std::string> locale) {
        locale_ = std::move(locale);
        return *this;
    }

    // Returns a string representation excluding authenticationToken.
    std::string toString() const;

private:
    std::optional<std::string> username_;
    std::optional<std::string> first_name_;
    std::optional<std::string> last_name_;
    std::optional<std::string> email_;
    std::optional<std::string> auth_token_;
    std::optional<std::string> time_zone_;
    std::optional<std::string> locale_;
};

} // namespace org::projectforge::model::rest
