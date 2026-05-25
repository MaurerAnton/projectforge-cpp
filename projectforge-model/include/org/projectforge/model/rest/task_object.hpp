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
#include <vector>
#include <memory>
#include <set>

namespace org::projectforge::model::rest {

// Forward declaration
class TaskObject;

/**
 * Enum representing task priority (mirrors org.projectforge.common.i18n.Priority).
 */
enum class Priority {
    NONE = 0,
    LOW = 1,
    MEDIUM = 2,
    HIGH = 3,
    URGENT = 4
};

/**
 * Enum representing task status (mirrors org.projectforge.common.task.TaskStatus).
 */
enum class TaskStatus {
    NONE = 0,
    OPEN = 1,
    IN_PROGRESS = 2,
    CLOSED = 3
};

/**
 * Enum representing timesheet booking status (mirrors org.projectforge.common.task.TimesheetBookingStatus).
 */
enum class TimesheetBookingStatus {
    NONE = 0,
    BOOKABLE = 1,
    NOT_BOOKABLE = 2,
    ONLY_LEAFS = 3
};

/**
 * REST DTO for ProjectForge tasks.
 * Equivalent to TaskObject.java / TaskDO.
 */
class TaskObject : public AbstractBaseObject {
public:
    TaskObject() = default;

    // -- description --
    std::optional<std::string> getDescription() const { return description_; }
    void setDescription(std::optional<std::string> description) { description_ = std::move(description); }

    // -- title --
    std::optional<std::string> getTitle() const { return title_; }
    void setTitle(std::optional<std::string> title) { title_ = std::move(title); }

    // -- shortDescription --
    std::optional<std::string> getShortDescription() const { return short_description_; }
    void setShortDescription(std::optional<std::string> shortDesc) { short_description_ = std::move(shortDesc); }

    // -- reference --
    std::optional<std::string> getReference() const { return reference_; }
    void setReference(std::optional<std::string> reference) { reference_ = std::move(reference); }

    // -- maxHours --
    std::optional<int32_t> getMaxHours() const { return max_hours_; }
    void setMaxHours(std::optional<int32_t> maxHours) { max_hours_ = maxHours; }

    // -- parentTaskId --
    std::optional<int64_t> getParentTaskId() const { return parent_task_id_; }
    void setParentTaskId(std::optional<int64_t> parentTaskId) { parent_task_id_ = parentTaskId; }

    // -- priority --
    std::optional<Priority> getPriority() const { return priority_; }
    void setPriority(std::optional<Priority> priority) { priority_ = priority; }

    // -- status --
    std::optional<TaskStatus> getStatus() const { return status_; }
    void setStatus(std::optional<TaskStatus> status) { status_ = status; }

    // -- timesheetBookingStatus --
    std::optional<TimesheetBookingStatus> getTimesheetBookingStatus() const { return timesheet_booking_status_; }
    void setTimesheetBookingStatus(std::optional<TimesheetBookingStatus> status) {
        timesheet_booking_status_ = status;
    }

    // -- bookableForTimesheets --
    bool isBookableForTimesheets() const { return bookable_for_timesheets_; }
    void setBookableForTimesheets(bool bookable) { bookable_for_timesheets_ = bookable; }

    // -- children --
    const std::vector<std::shared_ptr<TaskObject>>& getChildren() const { return children_; }
    void add(const std::shared_ptr<TaskObject>& child);

    // Comparison operators and hash
    bool operator==(const TaskObject& other) const;
    bool operator<(const TaskObject& other) const;

    std::string toString() const;

private:
    std::optional<std::string> description_;
    std::optional<std::string> title_;
    std::optional<std::string> short_description_;
    std::optional<std::string> reference_;
    std::optional<int32_t> max_hours_;
    std::optional<int64_t> parent_task_id_;
    std::optional<Priority> priority_;
    std::optional<TaskStatus> status_;
    std::optional<TimesheetBookingStatus> timesheet_booking_status_;
    bool bookable_for_timesheets_ = false;
    std::vector<std::shared_ptr<TaskObject>> children_;
};

} // namespace org::projectforge::model::rest

// Hash specialization for TaskObject (using id)
namespace std {
    template<>
    struct hash<org::projectforge::model::rest::TaskObject> {
        std::size_t operator()(const org::projectforge::model::rest::TaskObject& obj) const {
            auto id = obj.getId();
            return id.has_value() ? std::hash<int64_t>{}(id.value()) : 0;
        }
    };
}
