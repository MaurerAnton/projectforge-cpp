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
#include <chrono>
#include <memory>

namespace org::projectforge::model::rest {

// Forward declarations
class TaskObject;
class UserObject;
class Cost2Object;

/**
 * REST DTO for ProjectForge timesheets.
 * Equivalent to TimesheetObject.java / TimesheetDO.
 */
class TimesheetObject : public AbstractBaseObject {
public:
    TimesheetObject() = default;

    // -- task --
    std::shared_ptr<TaskObject> getTask() const { return task_; }
    void setTask(std::shared_ptr<TaskObject> task) { task_ = std::move(task); }

    // -- user --
    std::shared_ptr<UserObject> getUser() const { return user_; }
    void setUser(std::shared_ptr<UserObject> user) { user_ = std::move(user); }

    // -- timeZone --
    std::optional<std::string> getTimeZone() const { return time_zone_; }
    void setTimeZone(std::optional<std::string> timeZone) { time_zone_ = std::move(timeZone); }

    // -- startTime --
    std::optional<std::chrono::system_clock::time_point> getStartTime() const { return start_time_; }
    void setStartTime(std::optional<std::chrono::system_clock::time_point> startTime) { start_time_ = startTime; }

    // -- stopTime --
    std::optional<std::chrono::system_clock::time_point> getStopTime() const { return stop_time_; }
    void setStopTime(std::optional<std::chrono::system_clock::time_point> stopTime) { stop_time_ = stopTime; }

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
    std::shared_ptr<TaskObject> task_;
    std::shared_ptr<UserObject> user_;
    std::optional<std::string> time_zone_;
    std::optional<std::chrono::system_clock::time_point> start_time_;
    std::optional<std::chrono::system_clock::time_point> stop_time_;
    std::optional<std::string> location_;
    std::optional<std::string> description_;
    std::shared_ptr<Cost2Object> cost2_;
};

} // namespace org::projectforge::model::rest
