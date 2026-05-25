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

namespace org::projectforge::common {

/**
 * Some helper methods for canonical file paths.
 */
class CanonicalFileUtils {
public:
    /**
     * Returns the canonical (or absolute if canonical fails) path of the given file.
     */
    static std::string absolutePath(const std::string& path);

    /**
     * Returns the canonical (or absolute if canonical fails) path of the given file.
     */
    static std::string absolute(const std::string& path);

private:
    CanonicalFileUtils() = delete;
};

} // namespace org::projectforge::common
