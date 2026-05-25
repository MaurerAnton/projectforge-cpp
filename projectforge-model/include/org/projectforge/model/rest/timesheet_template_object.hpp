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
#include <optional>
#include <memory>

namespace org::projectforge::model::rest {

// Forward declarations
class TaskObject;
class UserObject;
class Cost2Object;

/**
 * Stores a user preference for adding new timesheets (template pre-filling).
 * Equivalent to TimesheetTemplateObject.java.
 */
class TimesheetTemplateObject {
public:
    TimesheetTemplateObject() = default;

    // -- name --
    std::optional<std::string> getName() const { return name_; }
    void setName(std::optional<std::string> name) { name_ = std::move(name); }

    // -- task --
    std::shared_ptr<TaskObject> getTask() const { return task_; }
    void setTask(std::shared_ptr<TaskObject> task) { task_ = std::move(task); }

    // -- user --
    std::shared_ptr<UserObject> getUser() const { return user_; }
    void setUser(std::shared_ptr<UserObject> user) { user_ = std::move(user); }

    // -- location --
    std::optional<std::string> getLocation() const { return location_; }
    void setLocation(std::optional<std::string> location) { location_ = std::move(location); }

    // -- description --
    std::optional<std::string> getDescription() const { return description_; }
    void setDescription(std::optional<std::string> description) { description_ = std::move(description); }

    // -- cost2 --
    std::shared_ptr<Cost2Object> getCost2() const { return cost2_; }
    void setCost2(std::shared_ptr<Cost2Object> cost2) { cost2_ = std::move(cost2); }

    std::string toString() const;

private:
    std::optional<std::string> name_;
    std::shared_ptr<TaskObject> task_;
    std::shared_ptr<UserObject> user_;
    std::optional<std::string> location_;
    std::optional<std::string> description_;
    std::shared_ptr<Cost2Object> cost2_;
};

} // namespace org::projectforge::model::rest
