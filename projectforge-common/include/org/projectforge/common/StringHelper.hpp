/////////////////////////////////////////////////////////////////////////////
// Project ProjectForge Community Edition — www.projectforge.org
// Copyright (C) 2001-2026 Micromata GmbH, Germany (www.micromata.com)
// ProjectForge is dual-licensed (GPL v3).
/////////////////////////////////////////////////////////////////////////////
#pragma once

#include <string>
#include <string_view>
#include <vector>
#include <sstream>
#include <algorithm>
#include <regex>
#include <optional>
#include <cctype>

namespace org::projectforge::common {

class StringHelper {
public:
    static constexpr const char* EMAIL_REGEX = R"(^[a-zA-Z0-9_+&*-]+(?:\.[a-zA-Z0-9_+&*-]+)*@(?:[a-zA-Z0-9-]+\.)+[a-zA-Z]{2,7}$)";

    /** Build delimited strings. Returns false once first item appended. */
    static bool append(std::ostringstream& buf, bool first, const std::string& str, const std::string& delimiter);
    static bool append(std::string& buf, bool first, const std::string& str, const std::string& delimiter);

    /** Null-safe comparison (null < non-null) */
    static int compareTo(const std::string* s1, const std::string* s2);
    static int compareTo(const std::string& s1, const std::string& s2) { return s1.compare(s2); }

    /** Null-safe compare with optional */
    static int compareTo(const std::optional<std::string>& s1, const std::optional<std::string>& s2);

    /** Check if string is in list */
    static bool isIn(const std::string& str, const std::vector<std::string>& fields);
    static bool isIn(const std::string* str, const std::vector<std::string>& fields);

    /** Null-safe version of endsWith */
    static bool endsWith(const std::string* str, const std::vector<std::string>& suffixes);
    static bool endsWith(const std::string& str, const std::vector<std::string>& suffixes);

    /** Null-safe version of startsWith */
    static bool startsWith(const std::string* str, const std::vector<std::string>& prefixes);
    static bool startsWith(const std::string& str, const std::vector<std::string>& prefixes);

    /** Join list to string with delimiter, optionally sorted */
    static std::string listToString(const std::vector<std::string>& list, const std::string& delimiter, bool sort);

    /** Join collection to string with delimiter */
    static std::string colToString(const std::vector<std::string>& col, const std::string& delimiter);

    /** Join collection of objects via toString() */
    template<typename T>
    static std::string objectColToString(const std::vector<T>& col, const std::string& delimiter) {
        std::ostringstream buf;
        bool first = true;
        for (const auto& item : col) {
            std::ostringstream ss;
            ss << item;
            first = append(buf, first, ss.str(), delimiter);
        }
        return buf.str();
    }

    /** Join varargs to string */
    static std::string listToString(const std::string& delimiter, const std::vector<std::string>& strings);
    static std::string listToString(std::ostringstream& buf, const std::string& delimiter, const std::vector<std::string>& strings);

    /** Capitalize first letter */
    static std::string capitalize(const std::string& str);
    static std::string capitalizeEnding(const std::string& str, const std::string& ending);

    /** Get substring before/after separator */
    static std::string substringBefore(const std::string& str, const std::string& separator);
    static std::string substringAfter(const std::string& str, const std::string& separator);
    static std::string substringBeforeLast(const std::string& str, const std::string& separator);
    static std::string substringAfterLast(const std::string& str, const std::string& separator);

    /** Get string between markers */
    static std::string substringBetween(const std::string& str, const std::string& open, const std::string& close);

    /** Count occurrences */
    static int countMatches(const std::string& str, const std::string& sub);

    /** Replace all occurrences */
    static std::string replace(const std::string& str, const std::string& search, const std::string& replacement);

    /** HTML escaping */
    static std::string escapeHtml(const std::string& str);
    static std::string escapeXml(const std::string& str);

    /** JavaScript escaping */
    static std::string escapeJavaScript(const std::string& str);

    /** Trim whitespace */
    static std::string trim(const std::string& str);
    static std::string trimLeft(const std::string& str);
    static std::string trimRight(const std::string& str);

    /** Remove all whitespace */
    static std::string removeWhitespace(const std::string& str);

    /** Abbreviate string to max width */
    static std::string abbreviate(const std::string& str, int maxWidth);
    static std::string abbreviateMiddle(const std::string& str, const std::string& middle, int maxWidth);

    /** Get common prefix of two strings */
    static std::string getCommonPrefix(const std::string& a, const std::string& b);

    /** Split string by delimiter */
    static std::vector<std::string> split(const std::string& str, char delimiter);
    static std::vector<std::string> split(const std::string& str, const std::string& delimiter);

    /** Join with delimiter */
    static std::string join(const std::vector<std::string>& parts, const std::string& delimiter);

    /** Is blank (null or whitespace) */
    static bool isBlank(const std::string* str);
    static bool isBlank(const std::optional<std::string>& str);
    static bool isBlank(const std::string& str);
    static bool isNotBlank(const std::string* str);
    static bool isNotBlank(const std::string& str);

    /** Is empty (null or length 0) */
    static bool isEmpty(const std::string* str);
    static bool isEmpty(const std::string& str);
    static bool isNotEmpty(const std::string* str);
    static bool isNotEmpty(const std::string& str);

    /** Default string if null */
    static std::string defaultString(const std::string* str, const std::string& defaultStr = "");

    /** Null-safe toString */
    static std::string toString(const void* obj);

    /** Valid email check */
    static bool isValidEmail(const std::string& email);

    /** Format string using {0}, {1} placeholders */
    static std::string format(const std::string& pattern, const std::vector<std::string>& args);

    /** Check if strings are equal ignoring case */
    static bool equalsIgnoreCase(const std::string& a, const std::string& b);

    /** Check if string contains another (ignoring case) */
    static bool containsIgnoreCase(const std::string& haystack, const std::string& needle);

    /** Check if string starts with prefix (ignoring case) */
    static bool startsWithIgnoreCase(const std::string& str, const std::string& prefix);

    /** Check if string ends with suffix (ignoring case) */
    static bool endsWithIgnoreCase(const std::string& str, const std::string& suffix);

    /** Remove start from string if present */
    static std::string removeStart(const std::string& str, const std::string& remove);
    static std::string removeStartIgnoreCase(const std::string& str, const std::string& remove);

    /** Remove end from string if present */
    static std::string removeEnd(const std::string& str, const std::string& remove);
    static std::string removeEndIgnoreCase(const std::string& str, const std::string& remove);

    /** Left pad / right pad */
    static std::string leftPad(const std::string& str, int size, char padChar = ' ');
    static std::string rightPad(const std::string& str, int size, char padChar = ' ');

    /** Repeat string n times */
    static std::string repeat(const std::string& str, int repeat);

    /** Reverse string */
    static std::string reverse(const std::string& str);

    /** Get Levenshtein distance for fuzzy matching */
    static int getLevenshteinDistance(const std::string& s, const std::string& t);

    /** Check for wildcard match */
    static bool wildcardMatch(const std::string& text, const std::string& pattern);

    /** Soundex for phonetic matching */
    static std::string soundex(const std::string& str);

    /** Convert to underscore_case from CamelCase */
    static std::string camelToUnderscore(const std::string& str);

    /** Convert to CamelCase from underscore_case */
    static std::string underscoreToCamel(const std::string& str);

    /** Escape for regex */
    static std::string escapeRegex(const std::string& str);

private:
    static std::regex emailRegex;
};

} // namespace org::projectforge::common
