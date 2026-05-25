/////////////////////////////////////////////////////////////////////////////
// Project ProjectForge Community Edition — www.projectforge.org
// Copyright (C) 2001-2026 Micromata GmbH, Germany (www.micromata.com)
// ProjectForge is dual-licensed (GPL v3).
/////////////////////////////////////////////////////////////////////////////
#pragma once

#include <string>
#include <chrono>
#include <optional>
#include <vector>
#include <ctime>
#include <sstream>
#include <iomanip>

namespace org::projectforge::common {

enum class DateFormatType {
    DATE,
    DATE_TIME_SECONDS,
    DATE_TIME_MILLIS,
    DATE_TIME_MINUTES,
    ISO_DATE,
    ISO_DATE_TIME,
    TIME_SECONDS,
    TIME_MINUTES,
    GERMAN_DATE,
    GERMAN_DATE_TIME,
    DATE_SHORT,
    DATE_TIME_SHORT,
    TIMESTAMP,
    DATE_ISO_FORMAT,
    EXCEL_DATE,
    YEAR_MONTH
};

enum class DatePrecision {
    SECOND,
    MINUTE,
    HOUR,
    DAY,
    WEEK,
    MONTH,
    YEAR
};

class DateHelper {
public:
    using TimePoint = std::chrono::system_clock::time_point;

    /** Parse date from various formats */
    static std::optional<TimePoint> parseDate(const std::string& str, DateFormatType formatType);

    /** Format date to string */
    static std::string formatDate(const TimePoint& date, DateFormatType formatType);
    static std::string formatDate(const std::optional<TimePoint>& date, DateFormatType formatType);

    /** Get current date/time */
    static TimePoint now();
    static TimePoint today(); // Start of day
    static TimePoint beginOfDay(const TimePoint& date);
    static TimePoint endOfDay(const TimePoint& date);

    /** Date arithmetic */
    static TimePoint addDays(const TimePoint& date, int days);
    static TimePoint addMonths(const TimePoint& date, int months);
    static TimePoint addYears(const TimePoint& date, int years);
    static TimePoint addHours(const TimePoint& date, int hours);
    static TimePoint addMinutes(const TimePoint& date, int minutes);
    static TimePoint addSeconds(const TimePoint& date, int64_t seconds);
    static TimePoint addWeeks(const TimePoint& date, int weeks);

    /** Date difference */
    static int64_t daysBetween(const TimePoint& start, const TimePoint& end);
    static int64_t hoursBetween(const TimePoint& start, const TimePoint& end);
    static int64_t minutesBetween(const TimePoint& start, const TimePoint& end);
    static int64_t secondsBetween(const TimePoint& start, const TimePoint& end);

    /** Get date components */
    static int getYear(const TimePoint& date);
    static int getMonth(const TimePoint& date); // 1-12
    static int getDay(const TimePoint& date);
    static int getHour(const TimePoint& date);
    static int getMinute(const TimePoint& date);
    static int getSecond(const TimePoint& date);
    static int getDayOfWeek(const TimePoint& date); // Sun=0..Sat=6
    static int getDayOfYear(const TimePoint& date);
    static int getWeekOfYear(const TimePoint& date);

    /** Get first/last day of month */
    static TimePoint getFirstDayOfMonth(const TimePoint& date);
    static TimePoint getLastDayOfMonth(const TimePoint& date);

    /** Get first/last day of year */
    static TimePoint getFirstDayOfYear(const TimePoint& date);
    static TimePoint getLastDayOfYear(const TimePoint& date);

    /** Get first day of week (monday) */
    static TimePoint getFirstDayOfWeek(const TimePoint& date);

    /** Is leap year */
    static bool isLeapYear(int year);

    /** Days in month */
    static int daysInMonth(int year, int month);

    /** Millisecond timestamp */
    static int64_t toMillis(const TimePoint& date);
    static TimePoint fromMillis(int64_t millis);

    /** Parse ISO 8601 date */
    static std::optional<TimePoint> parseIsoDate(const std::string& str);

    /** Format as ISO 8601 */
    static std::string formatIsoDate(const TimePoint& date);

    /** German date format (dd.MM.yyyy) */
    static std::string formatGermanDate(const TimePoint& date);

    /** Parsing helpers */
    static std::optional<TimePoint> parseGermanDate(const std::string& str);
    static std::optional<TimePoint> parseGermanDateTime(const std::string& str);

    /** Day names */
    static std::string getDayName(int dayOfWeek, bool shortName = false);
    static std::string getMonthName(int month, bool shortName = false);

    /** Quarter helpers */
    static int getQuarter(const TimePoint& date);
    static TimePoint getFirstDayOfQuarter(const TimePoint& date);
    static TimePoint getLastDayOfQuarter(const TimePoint& date);

    /** Working days between dates */
    static int64_t workingDaysBetween(const TimePoint& start, const TimePoint& end, const std::vector<int>& holidays = {});

    /** Is weekend */
    static bool isWeekend(const TimePoint& date);

    /** Min/max of dates */
    static TimePoint minDate(const TimePoint& a, const TimePoint& b);
    static TimePoint maxDate(const TimePoint& a, const TimePoint& b);

    /** Ensure mid range (clamp) */
    static TimePoint ensureMidRange(const TimePoint& date);

    /** Get age from birth date */
    static int getAge(const TimePoint& birthDate, const TimePoint& referenceDate);

    /** Duration string (e.g. "2h 30min") */
    static std::string formatDuration(int64_t seconds);
    static std::string formatDurationShort(int64_t seconds);

    /** Format relative time */
    static std::string formatRelativeTime(const TimePoint& date);
    static std::string formatElapsed(const TimePoint& start, const TimePoint& end);

    /** Human readable time span */
    static std::string humanReadableDuration(int64_t millis);
};

} // namespace org::projectforge::common
