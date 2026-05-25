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
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>

namespace org::projectforge::model::rest {

/**
 * Date/time serialization helpers.
 * Formats dates as "yyyy-MM-dd HH:mm:ss" (ISO-like, space-separated).
 * Equivalent to CustomerDateAndTimeSerialize.java and CustomerDateAndTimeDeserialize.java.
 */
class DateTimeSerialization {
public:
    static constexpr const char* DATE_TIME_FORMAT = "%Y-%m-%d %H:%M:%S";

    /**
     * Serialize a time_point to a date-time string.
     * If the value cannot be formatted, returns an empty string (handled gracefully).
     */
    static std::string serialize(const std::optional<std::chrono::system_clock::time_point>& value) {
        if (!value.has_value()) {
            return "";
        }
        try {
            auto time_t_val = std::chrono::system_clock::to_time_t(value.value());
            std::tm tm_val;
            gmtime_r(&time_t_val, &tm_val); // UTC

            std::ostringstream oss;
            oss << std::put_time(&tm_val, DATE_TIME_FORMAT);
            return oss.str();
        } catch (...) {
            // Fallback: return ISO 8601-like string
            return "";
        }
    }

    /**
     * Deserialize a date-time string to a time_point.
     * Tries the primary format first; falls back to ISO 8601 parsing.
     */
    static std::optional<std::chrono::system_clock::time_point> deserialize(const std::string& str) {
        if (str.empty()) {
            return std::nullopt;
        }
        std::string trimmed = str;
        // trim
        size_t start = trimmed.find_first_not_of(" \t\n\r");
        size_t end = trimmed.find_last_not_of(" \t\n\r");
        if (start == std::string::npos) return std::nullopt;
        trimmed = trimmed.substr(start, end - start + 1);

        // Try primary format: "yyyy-MM-dd HH:mm:ss"
        std::tm tm_val = {};
        std::istringstream iss(trimmed);
        iss >> std::get_time(&tm_val, DATE_TIME_FORMAT);
        if (!iss.fail()) {
            auto tp = std::chrono::system_clock::from_time_t(timegm(&tm_val));
            return tp;
        }

        // Fallback: try ISO 8601 "yyyy-MM-ddTHH:mm:ss" or "yyyy-MM-ddTHH:mm:ss.SSSZ"
        // Simple fallback by replacing 'T' with space and retrying
        std::string fallback = trimmed;
        size_t t_pos = fallback.find('T');
        if (t_pos != std::string::npos) {
            fallback[t_pos] = ' ';
            // Strip timezone suffix if present
            size_t z_pos = fallback.find_first_of("Z+-", t_pos);
            if (z_pos != std::string::npos && z_pos > t_pos) {
                fallback = fallback.substr(0, z_pos);
            }
            // Strip milliseconds if present
            size_t dot_pos = fallback.find('.', t_pos);
            if (dot_pos != std::string::npos) {
                fallback = fallback.substr(0, dot_pos);
            }
            std::istringstream iss2(fallback);
            std::tm tm2 = {};
            iss2 >> std::get_time(&tm2, DATE_TIME_FORMAT);
            if (!iss2.fail()) {
                return std::chrono::system_clock::from_time_t(timegm(&tm2));
            }
        }

        return std::nullopt;
    }

private:
    DateTimeSerialization() = default;
};

} // namespace org::projectforge::model::rest
