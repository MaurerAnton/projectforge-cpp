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

#include "abstract_base_object.hpp"
#include <string>
#include <optional>

namespace org::projectforge::model::rest {

/**
 * REST DTO for cost center (Kost2DO).
 * Equivalent to Cost2Object.java.
 */
class Cost2Object : public AbstractBaseObject {
public:
    Cost2Object() = default;

    // -- number --
    std::optional<std::string> getNumber() const { return number_; }
    void setNumber(std::optional<std::string> number) { number_ = std::move(number); }

    // -- type --
    std::optional<std::string> getType() const { return type_; }
    void setType(std::optional<std::string> type) { type_ = std::move(type); }

    // -- project --
    std::optional<std::string> getProject() const { return project_; }
    void setProject(std::optional<std::string> project) { project_ = std::move(project); }

    // -- customer --
    std::optional<std::string> getCustomer() const { return customer_; }
    void setCustomer(std::optional<std::string> customer) { customer_ = std::move(customer); }

    std::string toString() const;

private:
    std::optional<std::string> number_;
    std::optional<std::string> type_;
    std::optional<std::string> project_;
    std::optional<std::string> customer_;
};

} // namespace org::projectforge::model::rest
