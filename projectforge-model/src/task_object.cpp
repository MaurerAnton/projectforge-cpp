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

#include "org/projectforge/model/rest/task_object.hpp"
#include <sstream>
#include <algorithm>
#include <cctype>

namespace org::projectforge::model::rest {

void TaskObject::add(const std::shared_ptr<TaskObject>& child) {
    children_.push_back(child);
    // Sort by title (case-insensitive) matching TreeSet behavior
    std::sort(children_.begin(), children_.end(),
        [](const std::shared_ptr<TaskObject>& a, const std::shared_ptr<TaskObject>& b) {
            return *a < *b;
        });
}

bool TaskObject::operator==(const TaskObject& other) const {
    if (!id_.has_value() || !other.id_.has_value()) {
        return this == &other; // fallback to pointer comparison
    }
    return id_.value() == other.id_.value();
}

bool TaskObject::operator<(const TaskObject& other) const {
    std::string title1 = title_.has_value() ? *title_ : "";
    std::string title2 = other.title_.has_value() ? *other.title_ : "";
    // Case-insensitive comparison
    std::transform(title1.begin(), title1.end(), title1.begin(),
        [](unsigned char c) { return std::tolower(c); });
    std::transform(title2.begin(), title2.end(), title2.begin(),
        [](unsigned char c) { return std::tolower(c); });
    return title1 < title2;
}

std::string TaskObject::toString() const {
    std::ostringstream oss;
    oss << "TaskObject["
        << "id=" << (id_.has_value() ? std::to_string(id_.value()) : "null")
        << ",title=" << (title_.has_value() ? *title_ : "null")
        << ",description=" << (description_.has_value() ? *description_ : "null")
        << ",parentTaskId=" << (parent_task_id_.has_value() ? std::to_string(parent_task_id_.value()) : "null")
        << ",deleted=" << (deleted_ ? "true" : "false")
        << "]";
    return oss.str();
}

} // namespace org::projectforge::model::rest
