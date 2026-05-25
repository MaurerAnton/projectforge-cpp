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

#include <stdexcept>
#include <string>

namespace org::projectforge::common {

/**
 * All ProjectForge specific exception should be derived from this class.
 *
 * @author Kai Reinhard (k.reinhard@micromata.de)
 */
class ProjectForgeException : public std::runtime_error {
public:
    explicit ProjectForgeException(const std::string& message)
        : std::runtime_error(message) {}

    explicit ProjectForgeException(const char* message)
        : std::runtime_error(message) {}
};

} // namespace org::projectforge::common
