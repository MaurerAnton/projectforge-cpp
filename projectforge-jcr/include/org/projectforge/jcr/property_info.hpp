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

#include "value_info.hpp"
#include <string>
#include <optional>
#include <vector>
#include <memory>

namespace org::projectforge::jcr {

/**
 * Holds information about a JCR property.
 * Ported from PropertyInfo.kt.
 */
class PropertyInfo {
public:
    PropertyInfo() = default;

    // -- name --
    std::optional<std::string> name;

    // -- single value --
    std::shared_ptr<ValueInfo> value;

    // -- multi-valued --
    std::vector<std::shared_ptr<ValueInfo>> values;

    /**
     * Add this property to a node represented as a JSON object.
     */
    // addToNode is implemented for JSON-based node storage
};

} // namespace org::projectforge::jcr
