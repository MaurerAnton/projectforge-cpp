/////////////////////////////////////////////////////////////////////////////
// Project ProjectForge Community Edition — www.projectforge.org
// Copyright (C) 2001-2026 Micromata GmbH, Germany (www.micromata.com)
// ProjectForge is dual-licensed (GPL v3).
/////////////////////////////////////////////////////////////////////////////
#include "org/projectforge/common/DateHelper.hpp"
#include "org/projectforge/common/StringHelper.hpp"
#include <algorithm>
#include <cmath>
#include <regex>
#include <array>

namespace org::projectforge::common {

DateHelper::TimePoint DateHelper::now() { return std::chrono::system_clock::now(); }

DateHelper::TimePoint DateHelper::today() { return beginOfDay(now()); }

DateHelper::TimePoint DateHelper::beginOfDay(const TimePoint& date) {
    auto tt = std::chrono::system_clock::to_time_t(date);
    std::tm tm = *std::localtime(&tt);
    tm.tm_hour = 0; tm.tm_min = 0; tm.tm_sec = 0;
    return std::chrono::system_clock::from_time_t(std::mktime(&tm));
}

DateHelper::TimePoint DateHelper::endOfDay(const TimePoint& date) {
    auto tt = std::chrono::system_clock::to_time_t(date);
    std::tm tm = *std::localtime(&tt);
    tm.tm_hour = 23; tm.tm_min = 59; tm.tm_sec = 59;
    return std::chrono::system_clock::from_time_t(std::mktime(&tm));
}

std::string DateHelper::formatDate(const TimePoint& date, DateFormatType type) {
    auto tt = std::chrono::system_clock::to_time_t(date);
    std::tm tm = *std::localtime(&tt);
    std::ostringstream ss;
    switch (type) {
        case DateFormatType::DATE:
            ss << std::put_time(&tm, "%Y-%m-%d"); break;
        case DateFormatType::DATE_TIME_SECONDS:
            ss << std::put_time(&tm, "%Y-%m-%d %H:%M:%S"); break;
        case DateFormatType::DATE_TIME_MILLIS:
            ss << std::put_time(&tm, "%Y-%m-%d %H:%M:%S.") << std::setfill('0') << std::setw(3)
               << std::chrono::duration_cast<std::chrono::milliseconds>(date.time_since_epoch()).count() % 1000;
            break;
        case DateFormatType::DATE_TIME_MINUTES:
            ss << std::put_time(&tm, "%Y-%m-%d %H:%M"); break;
        case DateFormatType::ISO_DATE:
            ss << std::put_time(&tm, "%Y-%m-%d"); break;
        case DateFormatType::ISO_DATE_TIME:
            ss << std::put_time(&tm, "%Y-%m-%dT%H:%M:%S"); break;
        case DateFormatType::TIME_SECONDS:
            ss << std::put_time(&tm, "%H:%M:%S"); break;
        case DateFormatType::TIME_MINUTES:
            ss << std::put_time(&tm, "%H:%M"); break;
        case DateFormatType::GERMAN_DATE:
            ss << std::put_time(&tm, "%d.%m.%Y"); break;
        case DateFormatType::GERMAN_DATE_TIME:
            ss << std::put_time(&tm, "%d.%m.%Y %H:%M"); break;
        case DateFormatType::DATE_SHORT:
            ss << std::put_time(&tm, "%y-%m-%d"); break;
        case DateFormatType::DATE_TIME_SHORT:
            ss << std::put_time(&tm, "%y-%m-%d %H:%M"); break;
        case DateFormatType::TIMESTAMP:
            ss << std::put_time(&tm, "%Y%m%d%H%M%S"); break;
        case DateFormatType::DATE_ISO_FORMAT:
            ss << std::put_time(&tm, "%Y-%m-%d"); break;
        case DateFormatType::EXCEL_DATE: {
            int days = static_cast<int>(std::chrono::duration_cast<std::chrono::hours>(
                date - TimePoint{std::chrono::days(25569)}).count() / 24);
            ss << days; break;
        }
        case DateFormatType::YEAR_MONTH:
            ss << std::put_time(&tm, "%Y-%m"); break;
    }
    return ss.str();
}

std::string DateHelper::formatDate(const std::optional<TimePoint>& date, DateFormatType type) {
    if (!date.has_value()) return "";
    return formatDate(*date, type);
}

std::optional<DateHelper::TimePoint> DateHelper::parseDate(const std::string& str, DateFormatType type) {
    if (str.empty()) return std::nullopt;
    std::tm tm = {};
    std::istringstream ss(str);
    switch (type) {
        case DateFormatType::DATE:
        case DateFormatType::ISO_DATE:
        case DateFormatType::DATE_ISO_FORMAT:
            ss >> std::get_time(&tm, "%Y-%m-%d"); break;
        case DateFormatType::DATE_TIME_SECONDS:
            ss >> std::get_time(&tm, "%Y-%m-%d %H:%M:%S"); break;
        case DateFormatType::DATE_TIME_MINUTES:
            ss >> std::get_time(&tm, "%Y-%m-%d %H:%M"); break;
        case DateFormatType::ISO_DATE_TIME:
            ss >> std::get_time(&tm, "%Y-%m-%dT%H:%M:%S"); break;
        case DateFormatType::GERMAN_DATE:
            ss >> std::get_time(&tm, "%d.%m.%Y"); break;
        case DateFormatType::GERMAN_DATE_TIME:
            ss >> std::get_time(&tm, "%d.%m.%Y %H:%M"); break;
        default: return std::nullopt;
    }
    if (ss.fail()) return std::nullopt;
    return std::chrono::system_clock::from_time_t(std::mktime(&tm));
}

int DateHelper::getYear(const TimePoint& date) {
    auto tt = std::chrono::system_clock::to_time_t(date);
    return std::localtime(&tt)->tm_year + 1900;
}

int DateHelper::getMonth(const TimePoint& date) {
    auto tt = std::chrono::system_clock::to_time_t(date);
    return std::localtime(&tt)->tm_mon + 1;
}

int DateHelper::getDay(const TimePoint& date) {
    auto tt = std::chrono::system_clock::to_time_t(date);
    return std::localtime(&tt)->tm_mday;
}

int DateHelper::getHour(const TimePoint& date) {
    auto tt = std::chrono::system_clock::to_time_t(date);
    return std::localtime(&tt)->tm_hour;
}

int DateHelper::getMinute(const TimePoint& date) {
    auto tt = std::chrono::system_clock::to_time_t(date);
    return std::localtime(&tt)->tm_min;
}

int DateHelper::getSecond(const TimePoint& date) {
    auto tt = std::chrono::system_clock::to_time_t(date);
    return std::localtime(&tt)->tm_sec;
}

int DateHelper::getDayOfWeek(const TimePoint& date) {
    auto tt = std::chrono::system_clock::to_time_t(date);
    return std::localtime(&tt)->tm_wday;
}

int DateHelper::getDayOfYear(const TimePoint& date) {
    auto tt = std::chrono::system_clock::to_time_t(date);
    return std::localtime(&tt)->tm_yday + 1;
}

int DateHelper::getWeekOfYear(const TimePoint& date) {
    auto tt = std::chrono::system_clock::to_time_t(date);
    std::tm* tm = std::localtime(&tt);
    char buf[3];
    std::strftime(buf, sizeof(buf), "%V", tm);
    return std::stoi(buf);
}

DateHelper::TimePoint DateHelper::addDays(const TimePoint& date, int days) {
    return date + std::chrono::hours(24 * days);
}

DateHelper::TimePoint DateHelper::addMonths(const TimePoint& date, int months) {
    auto tt = std::chrono::system_clock::to_time_t(date);
    std::tm tm = *std::localtime(&tt);
    tm.tm_mon += months;
    std::mktime(&tm);
    return std::chrono::system_clock::from_time_t(std::mktime(&tm));
}

DateHelper::TimePoint DateHelper::addYears(const TimePoint& date, int years) {
    auto tt = std::chrono::system_clock::to_time_t(date);
    std::tm tm = *std::localtime(&tt);
    tm.tm_year += years;
    return std::chrono::system_clock::from_time_t(std::mktime(&tm));
}

DateHelper::TimePoint DateHelper::addHours(const TimePoint& date, int hours) {
    return date + std::chrono::hours(hours);
}

DateHelper::TimePoint DateHelper::addMinutes(const TimePoint& date, int minutes) {
    return date + std::chrono::minutes(minutes);
}

DateHelper::TimePoint DateHelper::addSeconds(const TimePoint& date, int64_t seconds) {
    return date + std::chrono::seconds(seconds);
}

DateHelper::TimePoint DateHelper::addWeeks(const TimePoint& date, int weeks) {
    return addDays(date, weeks * 7);
}

int64_t DateHelper::daysBetween(const TimePoint& start, const TimePoint& end) {
    return std::chrono::duration_cast<std::chrono::hours>(end - start).count() / 24;
}

int64_t DateHelper::hoursBetween(const TimePoint& start, const TimePoint& end) {
    return std::chrono::duration_cast<std::chrono::hours>(end - start).count();
}

int64_t DateHelper::minutesBetween(const TimePoint& start, const TimePoint& end) {
    return std::chrono::duration_cast<std::chrono::minutes>(end - start).count();
}

int64_t DateHelper::secondsBetween(const TimePoint& start, const TimePoint& end) {
    return std::chrono::duration_cast<std::chrono::seconds>(end - start).count();
}

DateHelper::TimePoint DateHelper::getFirstDayOfMonth(const TimePoint& date) {
    auto tt = std::chrono::system_clock::to_time_t(date);
    std::tm tm = *std::localtime(&tt);
    tm.tm_mday = 1; tm.tm_hour = 0; tm.tm_min = 0; tm.tm_sec = 0;
    return std::chrono::system_clock::from_time_t(std::mktime(&tm));
}

DateHelper::TimePoint DateHelper::getLastDayOfMonth(const TimePoint& date) {
    auto first = getFirstDayOfMonth(date);
    return addSeconds(addMonths(first, 1), -1);
}

DateHelper::TimePoint DateHelper::getFirstDayOfYear(const TimePoint& date) {
    auto tt = std::chrono::system_clock::to_time_t(date);
    std::tm tm = *std::localtime(&tt);
    tm.tm_mday = 1; tm.tm_mon = 0; tm.tm_hour = 0; tm.tm_min = 0; tm.tm_sec = 0;
    return std::chrono::system_clock::from_time_t(std::mktime(&tm));
}

DateHelper::TimePoint DateHelper::getLastDayOfYear(const TimePoint& date) {
    auto tt = std::chrono::system_clock::to_time_t(date);
    std::tm tm = {0};
    tm.tm_year = getYear(date) - 1900; tm.tm_mon = 11; tm.tm_mday = 31;
    tm.tm_hour = 23; tm.tm_min = 59; tm.tm_sec = 59;
    return std::chrono::system_clock::from_time_t(std::mktime(&tm));
}

DateHelper::TimePoint DateHelper::getFirstDayOfWeek(const TimePoint& date) {
    int dow = getDayOfWeek(date);
    int offset = (dow == 0) ? 6 : dow - 1; // Monday = 0
    return beginOfDay(addDays(date, -offset));
}

bool DateHelper::isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int DateHelper::daysInMonth(int year, int month) {
    static const int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month < 1 || month > 12) return 0;
    if (month == 2 && isLeapYear(year)) return 29;
    return days[month - 1];
}

int64_t DateHelper::toMillis(const TimePoint& date) {
    return std::chrono::duration_cast<std::chrono::milliseconds>(date.time_since_epoch()).count();
}

DateHelper::TimePoint DateHelper::fromMillis(int64_t millis) {
    return TimePoint(std::chrono::milliseconds(millis));
}

std::optional<DateHelper::TimePoint> DateHelper::parseIsoDate(const std::string& str) {
    return parseDate(str, DateFormatType::ISO_DATE_TIME);
}

std::string DateHelper::formatIsoDate(const TimePoint& date) {
    return formatDate(date, DateFormatType::ISO_DATE_TIME);
}

std::string DateHelper::formatGermanDate(const TimePoint& date) {
    return formatDate(date, DateFormatType::GERMAN_DATE);
}

std::optional<DateHelper::TimePoint> DateHelper::parseGermanDate(const std::string& str) {
    return parseDate(str, DateFormatType::GERMAN_DATE);
}

std::optional<DateHelper::TimePoint> DateHelper::parseGermanDateTime(const std::string& str) {
    return parseDate(str, DateFormatType::GERMAN_DATE_TIME);
}

static const char* DAY_NAMES[] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
static const char* DAY_NAMES_SHORT[] = {"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};
static const char* MONTH_NAMES[] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
static const char* MONTH_NAMES_SHORT[] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};

std::string DateHelper::getDayName(int dow, bool shortName) {
    if (dow < 0 || dow > 6) return "";
    return shortName ? DAY_NAMES_SHORT[dow] : DAY_NAMES[dow];
}

std::string DateHelper::getMonthName(int month, bool shortName) {
    if (month < 1 || month > 12) return "";
    return shortName ? MONTH_NAMES_SHORT[month-1] : MONTH_NAMES[month-1];
}

int DateHelper::getQuarter(const TimePoint& date) {
    return (getMonth(date) + 2) / 3;
}

DateHelper::TimePoint DateHelper::getFirstDayOfQuarter(const TimePoint& date) {
    int q = getQuarter(date);
    auto tt = std::chrono::system_clock::to_time_t(date);
    std::tm tm = *std::localtime(&tt);
    tm.tm_mon = (q - 1) * 3; tm.tm_mday = 1; tm.tm_hour = 0; tm.tm_min = 0; tm.tm_sec = 0;
    return std::chrono::system_clock::from_time_t(std::mktime(&tm));
}

DateHelper::TimePoint DateHelper::getLastDayOfQuarter(const TimePoint& date) {
    auto first = getFirstDayOfQuarter(date);
    return addSeconds(addMonths(first, 3), -1);
}

int64_t DateHelper::workingDaysBetween(const TimePoint& start, const TimePoint& end, const std::vector<int>& holidays) {
    int64_t days = 0;
    auto current = beginOfDay(start);
    auto endDay = beginOfDay(end);
    while (current < endDay) {
        int dow = getDayOfWeek(current);
        if (dow != 0 && dow != 6) {
            int yday = getDayOfYear(current);
            if (std::find(holidays.begin(), holidays.end(), yday) == holidays.end()) {
                ++days;
            }
        }
        current = addDays(current, 1);
    }
    return days;
}

bool DateHelper::isWeekend(const TimePoint& date) {
    int dow = getDayOfWeek(date);
    return dow == 0 || dow == 6;
}

DateHelper::TimePoint DateHelper::minDate(const TimePoint& a, const TimePoint& b) {
    return (a < b) ? a : b;
}

DateHelper::TimePoint DateHelper::maxDate(const TimePoint& a, const TimePoint& b) {
    return (a < b) ? b : a;
}

DateHelper::TimePoint DateHelper::ensureMidRange(const TimePoint& date) {
    using namespace std::chrono;
    auto now = system_clock::now();
    auto minDate = now - hours(24 * 365 * 100);
    auto maxDate = now + hours(24 * 365 * 100);
    if (date < minDate) return minDate;
    if (date > maxDate) return maxDate;
    return date;
}

int DateHelper::getAge(const TimePoint& birthDate, const TimePoint& reference) {
    int age = getYear(reference) - getYear(birthDate);
    auto bday = getFirstDayOfMonth(birthDate);
    bday = std::chrono::system_clock::from_time_t(
        std::mktime(new std::tm{0,0,0,getDay(birthDate),getMonth(birthDate)-1,getYear(reference)-1900}));
    if (reference < bday) --age;
    return age;
}

std::string DateHelper::formatDuration(int64_t seconds) {
    if (seconds < 0) return "0s";
    int64_t h = seconds / 3600;
    int64_t m = (seconds % 3600) / 60;
    int64_t s = seconds % 60;
    std::ostringstream ss;
    if (h > 0) ss << h << "h ";
    if (m > 0 || h > 0) ss << m << "min ";
    ss << s << "s";
    return ss.str();
}

std::string DateHelper::formatDurationShort(int64_t seconds) {
    if (seconds < 0) return "0:00";
    int64_t h = seconds / 3600;
    int64_t m = (seconds % 3600) / 60;
    std::ostringstream ss;
    ss << h << ":" << std::setfill('0') << std::setw(2) << m;
    return ss.str();
}

std::string DateHelper::formatRelativeTime(const TimePoint& date) {
    int64_t diff = secondsBetween(date, now());
    if (diff < 60) return "just now";
    if (diff < 3600) return std::to_string(diff / 60) + " minutes ago";
    if (diff < 86400) return std::to_string(diff / 3600) + " hours ago";
    if (diff < 2592000) return std::to_string(diff / 86400) + " days ago";
    return formatGermanDate(date);
}

std::string DateHelper::formatElapsed(const TimePoint& start, const TimePoint& end) {
    return formatDuration(secondsBetween(start, end));
}

std::string DateHelper::humanReadableDuration(int64_t millis) {
    if (millis < 1000) return std::to_string(millis) + "ms";
    if (millis < 60000) return std::to_string(millis / 1000) + "s";
    if (millis < 3600000) return std::to_string(millis / 60000) + "min";
    if (millis < 86400000) return std::to_string(millis / 3600000) + "h";
    return std::to_string(millis / 86400000) + " days";
}

} // namespace org::projectforge::common
