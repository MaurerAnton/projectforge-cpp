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

#include "org/projectforge/model/rest/cost2_object.hpp"
#include <sstream>

namespace org::projectforge::model::rest {

std::string Cost2Object::toString() const {
    std::ostringstream oss;
    oss << "Cost2Object["
        << "id=" << (id_.has_value() ? std::to_string(id_.value()) : "null")
        << ",number=" << (number_.has_value() ? *number_ : "null")
        << ",type=" << (type_.has_value() ? *type_ : "null")
        << ",project=" << (project_.has_value() ? *project_ : "null")
        << ",customer=" << (customer_.has_value() ? *customer_ : "null")
        << ",deleted=" << (deleted_ ? "true" : "false")
        << "]";
    return oss.str();
}

} // namespace org::projectforge::model::rest
