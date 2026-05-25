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

#include <string>
#include <cstdint>
#include <ctime>
#include <optional>
#include <vector>

namespace org::projectforge::jcr {

/**
 * Enum of JCR property types.
 * Ported from PropertyTypeEnum.kt.
 */
enum class PropertyType : int {
    BINARY = 1,
    BOOLEAN = 2,
    DATE = 3,
    DECIMAL = 4,
    DOUBLE = 5,
    LONG = 6,
    NAME = 7,
    PATH = 8,
    REFERENCE = 9,
    STRING = 10,
    UNDEFINED = 11,
    URI = 12,
    WEAKREFERENCE = 13
};

/**
 * Converts an integer property type to enum.
 */
inline std::optional<PropertyType> convertPropertyType(int type) {
    switch (type) {
        case 1: return PropertyType::BINARY;
        case 2: return PropertyType::BOOLEAN;
        case 3: return PropertyType::DATE;
        case 4: return PropertyType::DECIMAL;
        case 5: return PropertyType::DOUBLE;
        case 6: return PropertyType::LONG;
        case 7: return PropertyType::NAME;
        case 8: return PropertyType::PATH;
        case 9: return PropertyType::REFERENCE;
        case 10: return PropertyType::STRING;
        case 11: return PropertyType::UNDEFINED;
        case 12: return PropertyType::URI;
        case 13: return PropertyType::WEAKREFERENCE;
        default: return std::nullopt;
    }
}

} // namespace org::projectforge::jcr
