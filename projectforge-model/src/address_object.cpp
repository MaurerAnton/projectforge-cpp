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

#include "org/projectforge/model/rest/address_object.hpp"
#include <sstream>

namespace org::projectforge::model::rest {

std::string AddressObject::getFullName() const {
    // StringHelper.listToString(", ", name, firstName) equivalent
    if (name_.has_value() && first_name_.has_value()) {
        return *name_ + ", " + *first_name_;
    } else if (name_.has_value()) {
        return *name_;
    } else if (first_name_.has_value()) {
        return *first_name_;
    }
    return "";
}

} // namespace org::projectforge::model::rest
