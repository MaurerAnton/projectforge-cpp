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

namespace org::projectforge::model::rest {

/**
 * REST path constants used by the ProjectForge API.
 * Equivalent to RestPaths.java.
 */
class RestPaths {
public:
    static constexpr const char* REST = "rs";
    static constexpr const char* REST_PUBLIC = "rsPublic";
    static constexpr const char* REST_EXCEL_SUB_PATH = "exportAsExcel";
    static constexpr const char* REST_START_MULTI_SELECTION = "startMultiSelection";
    static constexpr const char* TASK = "task";
    static constexpr const char* TIMESHEET_TEMPLATE = "timesheetTemplate";
    static constexpr const char* LIST = "list";
    static constexpr const char* CANCEL = "cancel";
    static constexpr const char* CANCEL_MULTI_SELECTION = "cancelMultiSelection";
    static constexpr const char* EDIT = "edit";
    static constexpr const char* SAVE = "save";
    static constexpr const char* UPDATE = "update";
    static constexpr const char* SAVE_OR_UPDATE = "saveorupdate";
    static constexpr const char* DELETE = "delete";
    static constexpr const char* MARK_AS_DELETED = "markAsDeleted";
    static constexpr const char* FORCE_DELETE = "forceDelete";
    static constexpr const char* UNDELETE = "undelete";
    static constexpr const char* CLONE = "clone";
    static constexpr const char* SET_COLUMN_STATES = "setColumnStates";
    static constexpr const char* WATCH_FIELDS = "watchFields";
    static constexpr const char* FILTER_RESET = "filterReset";

private:
    RestPaths() = default;
};

} // namespace org::projectforge::model::rest
