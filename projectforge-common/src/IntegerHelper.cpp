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

#include "projectforge-common/IntegerHelper.hpp"
#include <spdlog/spdlog.h>
#include <algorithm>
#include <cctype>

namespace org::projectforge::common {

std::optional<int> IntegerHelper::parseInteger(const std::string& value) {
    std::string trimmed = value;
    // Trim leading and trailing whitespace
    trimmed.erase(trimmed.begin(), std::find_if(trimmed.begin(), trimmed.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
    trimmed.erase(std::find_if(trimmed.rbegin(), trimmed.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), trimmed.end());

    if (trimmed.empty()) {
        return std::nullopt;
    }
    try {
        return std::stoi(trimmed);
    } catch (const std::invalid_argument&) {
        auto log = spdlog::get("projectforge");
        if (log) {
            log->warn("Can't parse integer: '{}'.", trimmed);
        }
        return std::nullopt;
    } catch (const std::out_of_range&) {
        auto log = spdlog::get("projectforge");
        if (log) {
            log->warn("Can't parse integer: '{}'.", trimmed);
        }
        return std::nullopt;
    }
}

} // namespace org::projectforge::common
