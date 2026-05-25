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

#include "value_info.hpp"
#include <sstream>
#include <iomanip>

namespace org::projectforge::jcr {

std::string ValueInfo::toString() const {
    if (!type.has_value()) return "null";

    switch (type.value()) {
        case PropertyType::BOOLEAN:
            return boolean_value.has_value() ? (boolean_value.value() ? "true" : "false") : "null";
        case PropertyType::DATE:
            if (date_value.has_value()) {
                auto t = std::chrono::system_clock::to_time_t(date_value.value());
                std::ostringstream oss;
                oss << std::put_time(std::gmtime(&t), "%Y-%m-%dT%H:%M:%S");
                return oss.str();
            }
            return "null";
        case PropertyType::DECIMAL:
            return decimal_value.has_value() ? std::to_string(decimal_value.value()) : "null";
        case PropertyType::DOUBLE:
            return double_value.has_value() ? std::to_string(double_value.value()) : "null";
        case PropertyType::LONG:
            return long_value.has_value() ? std::to_string(long_value.value()) : "null";
        case PropertyType::BINARY:
            return "<binary>";
        case PropertyType::STRING:
        default:
            return string_value.has_value() ? string_value.value() : "null";
    }
}

} // namespace org::projectforge::jcr
