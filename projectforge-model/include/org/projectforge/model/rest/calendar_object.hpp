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
 * REST DTO for TeamCalDO / calendar objects.
 * Equivalent to CalendarObject.java.
 */
class CalendarObject : public AbstractBaseObject {
public:
    CalendarObject() = default;

    // -- title --
    std::optional<std::string> getTitle() const { return title_; }
    CalendarObject& setTitle(std::optional<std::string> title) { title_ = std::move(title); return *this; }

    // -- owner --
    bool isOwner() const { return owner_; }
    CalendarObject& setOwner(bool owner) { owner_ = owner; return *this; }

    // -- fullAccess --
    bool isFullAccess() const { return full_access_; }
    CalendarObject& setFullAccess(bool access) { full_access_ = access; return *this; }

    // -- readonlyAccess --
    bool isReadonlyAccess() const { return readonly_access_; }
    CalendarObject& setReadonlyAccess(bool access) { readonly_access_ = access; return *this; }

    // -- minimalAccess --
    bool isMinimalAccess() const { return minimal_access_; }
    CalendarObject& setMinimalAccess(bool access) { minimal_access_ = access; return *this; }

    // -- description --
    std::optional<std::string> getDescription() const { return description_; }
    CalendarObject& setDescription(std::optional<std::string> desc) { description_ = std::move(desc); return *this; }

    // -- externalSubscription --
    bool isExternalSubscription() const { return external_subscription_; }
    CalendarObject& setExternalSubscription(bool ext) { external_subscription_ = ext; return *this; }

    std::string toString() const;

private:
    std::optional<std::string> title_;
    bool owner_ = false;
    bool full_access_ = false;
    bool readonly_access_ = false;
    bool minimal_access_ = false;
    std::optional<std::string> description_;
    bool external_subscription_ = false;
};

} // namespace org::projectforge::model::rest
