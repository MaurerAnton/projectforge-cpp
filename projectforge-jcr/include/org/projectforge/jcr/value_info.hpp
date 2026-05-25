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

#include "property_type.hpp"
#include <string>
#include <optional>
#include <ctime>
#include <chrono>

namespace org::projectforge::jcr {

/**
 * Holds a typed JCR value.
 * Ported from ValueInfo.kt.
 */
class ValueInfo {
public:
    ValueInfo() = default;

    // -- type --
    std::optional<PropertyType> type;

    // -- typed values --
    std::optional<bool> boolean_value;
    std::optional<std::string> string_value;
    std::optional<std::chrono::system_clock::time_point> date_value;
    std::optional<double> decimal_value;
    std::optional<double> double_value;
    std::optional<int64_t> long_value;

    // Legacy aliases for compatibility
    std::optional<bool> boolean() const { return boolean_value; }
    std::optional<std::string> string() const { return string_value; }
    std::optional<std::chrono::system_clock::time_point> date() const { return date_value; }
    std::optional<double> decimal() const { return decimal_value; }
    std::optional<double> doubleVal() const { return double_value; }
    std::optional<int64_t> longVal() const { return long_value; }

    /**
     * String representation of the value, by type.
     */
    std::string toString() const;
};

} // namespace org::projectforge::jcr
