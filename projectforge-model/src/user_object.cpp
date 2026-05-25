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

#include "org/projectforge/model/rest/user_object.hpp"
#include <sstream>

namespace org::projectforge::model::rest {

std::string UserObject::toString() const {
    std::ostringstream oss;
    oss << "UserObject["
        << "id=" << (id_.has_value() ? std::to_string(id_.value()) : "null")
        << ",username=" << (username_.has_value() ? *username_ : "null")
        << ",firstName=" << (first_name_.has_value() ? *first_name_ : "null")
        << ",lastName=" << (last_name_.has_value() ? *last_name_ : "null")
        << ",email=" << (email_.has_value() ? *email_ : "null")
        << ",timeZone=" << (time_zone_.has_value() ? *time_zone_ : "null")
        << ",locale=" << (locale_.has_value() ? *locale_ : "null")
        // authenticationToken is excluded from toString (same as Java)
        << ",deleted=" << (deleted_ ? "true" : "false")
        << "]";
    return oss.str();
}

} // namespace org::projectforge::model::rest
