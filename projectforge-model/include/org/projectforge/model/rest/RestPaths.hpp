// ProjectForge C++ port — GPL v3 — www.projectforge.org
#pragma once
#include <string>

namespace org::projectforge::model::rest {

struct RestPaths {
    static constexpr const char* API_PREFIX = "/api/v1";
    static constexpr const char* USERS = "/api/v1/users";
    static constexpr const char* TASKS = "/api/v1/tasks";
    static constexpr const char* TIMESHEETS = "/api/v1/timesheets";
    static constexpr const char* ADDRESSES = "/api/v1/addresses";
    static constexpr const char* CALENDARS = "/api/v1/calendars";
    static constexpr const char* FIBU = "/api/v1/fibu";
    static constexpr const char* RECHNUNG = "/api/v1/rechnung";
    static constexpr const char* KONTO = "/api/v1/konto";
    static constexpr const char* AUTH = "/api/v1/auth";
    static constexpr const char* LOGIN = "/api/v1/auth/login";
    static constexpr const char* LOGOUT = "/api/v1/auth/logout";
    static constexpr const char* CHANGE_PASSWORD = "/api/v1/auth/changePassword";
    static constexpr const char* HR_PLANNING = "/api/v1/hrplanning";
    static constexpr const char* VACATION = "/api/v1/vacation";
    static constexpr const char* MENU = "/api/v1/menu";
    static constexpr const char* INDEX = "/api/v1/index";
};
}