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

#include <cstdint>
#include <string>
#include <optional>
#include <chrono>

namespace org::projectforge::model::rest {

/**
 * Base DTO with id, deleted flag, created and lastUpdate timestamps.
 * Equivalent to AbstractBaseObject.java / DefaultBaseDO.
 */
class AbstractBaseObject {
public:
    AbstractBaseObject() = default;
    virtual ~AbstractBaseObject() = default;

    // -- id --
    std::optional<int64_t> getId() const { return id_; }
    void setId(std::optional<int64_t> id) { id_ = id; }

    // -- deleted --
    bool isDeleted() const { return deleted_; }
    void setDeleted(bool deleted) { deleted_ = deleted; }

    // -- created --
    std::optional<std::chrono::system_clock::time_point> getCreated() const { return created_; }
    void setCreated(std::optional<std::chrono::system_clock::time_point> created) { created_ = created; }

    // -- lastUpdate --
    std::optional<std::chrono::system_clock::time_point> getLastUpdate() const { return last_update_; }
    void setLastUpdate(std::optional<std::chrono::system_clock::time_point> lastUpdate) { last_update_ = lastUpdate; }

protected:
    std::optional<int64_t> id_;
    bool deleted_ = false;
    std::optional<std::chrono::system_clock::time_point> created_;
    std::optional<std::chrono::system_clock::time_point> last_update_;
};

} // namespace org::projectforge::model::rest
