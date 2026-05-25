/////////////////////////////////////////////////////////////////////////////
// Project ProjectForge Community Edition — www.projectforge.org
// Copyright (C) 2001-2026 Micromata GmbH, Germany (www.micromata.com)
// ProjectForge is dual-licensed (GPL v3).
/////////////////////////////////////////////////////////////////////////////
#include "org/projectforge/common/StringHelper.hpp"
#include <spdlog/spdlog.h>
#include <algorithm>
#include <cctype>
#include <cwctype>

namespace org::projectforge::common {

std::regex StringHelper::emailRegex(StringHelper::EMAIL_REGEX);

bool StringHelper::append(std::ostringstream& buf, bool first, const std::string& str, const std::string& delimiter) {
    if (str.empty()) return first;
    if (!first) buf << delimiter;
    buf << str;
    return false;
}

bool StringHelper::append(std::string& buf, bool first, const std::string& str, const std::string& delimiter) {
    if (str.empty()) return first;
    if (!first) buf += delimiter;
    buf += str;
    return false;
}

int StringHelper::compareTo(const std::string* s1, const std::string* s2) {
    if (s1 == nullptr) return (s2 == nullptr) ? 0 : -1;
    if (s2 == nullptr) return 1;
    return s1->compare(*s2);
}

int StringHelper::compareTo(const std::optional<std::string>& s1, const std::optional<std::string>& s2) {
    if (!s1.has_value()) return s2.has_value() ? -1 : 0;
    if (!s2.has_value()) return 1;
    return s1->compare(*s2);
}

bool StringHelper::isIn(const std::string& str, const std::vector<std::string>& fields) {
    if (str.empty()) return false;
    return std::find(fields.begin(), fields.end(), str) != fields.end();
}

bool StringHelper::isIn(const std::string* str, const std::vector<std::string>& fields) {
    if (str == nullptr || str->empty()) return false;
    return std::find(fields.begin(), fields.end(), *str) != fields.end();
}

bool StringHelper::endsWith(const std::string* str, const std::vector<std::string>& suffixes) {
    if (str == nullptr) return false;
    return endsWith(*str, suffixes);
}

bool StringHelper::endsWith(const std::string& str, const std::vector<std::string>& suffixes) {
    for (const auto& suffix : suffixes) {
        if (str.size() >= suffix.size() && str.compare(str.size() - suffix.size(), suffix.size(), suffix) == 0) {
            return true;
        }
    }
    return false;
}

bool StringHelper::startsWith(const std::string* str, const std::vector<std::string>& prefixes) {
    if (str == nullptr) return false;
    return startsWith(*str, prefixes);
}

bool StringHelper::startsWith(const std::string& str, const std::vector<std::string>& prefixes) {
    for (const auto& prefix : prefixes) {
        if (str.size() >= prefix.size() && str.compare(0, prefix.size(), prefix) == 0) {
            return true;
        }
    }
    return false;
}

std::string StringHelper::listToString(const std::vector<std::string>& list, const std::string& delimiter, bool sort) {
    auto sorted = list;
    if (sort) std::sort(sorted.begin(), sorted.end());
    return colToString(sorted, delimiter);
}

std::string StringHelper::colToString(const std::vector<std::string>& col, const std::string& delimiter) {
    std::ostringstream buf;
    bool first = true;
    for (const auto& item : col) {
        first = append(buf, first, item, delimiter);
    }
    return buf.str();
}

std::string StringHelper::listToString(const std::string& delimiter, const std::vector<std::string>& strings) {
    std::ostringstream buf;
    return listToString(buf, delimiter, strings);
}

std::string StringHelper::listToString(std::ostringstream& buf, const std::string& delimiter, const std::vector<std::string>& strings) {
    bool first = true;
    for (const auto& s : strings) {
        if (s.empty()) continue;
        first = append(buf, first, s, delimiter);
    }
    return buf.str();
}

std::string StringHelper::capitalize(const std::string& str) {
    if (str.empty()) return str;
    std::string result = str;
    result[0] = static_cast<char>(std::toupper(static_cast<unsigned char>(result[0])));
    return result;
}

std::string StringHelper::capitalizeEnding(const std::string& str, const std::string& ending) {
    if (str.size() < ending.size()) return str;
    std::string result = str;
    size_t pos = result.size() - ending.size();
    for (size_t i = 0; i < ending.size(); ++i) {
        result[pos + i] = static_cast<char>(std::toupper(static_cast<unsigned char>(ending[i])));
    }
    return result;
}

std::string StringHelper::substringBefore(const std::string& str, const std::string& separator) {
    size_t pos = str.find(separator);
    return (pos == std::string::npos) ? str : str.substr(0, pos);
}

std::string StringHelper::substringAfter(const std::string& str, const std::string& separator) {
    size_t pos = str.find(separator);
    return (pos == std::string::npos) ? "" : str.substr(pos + separator.size());
}

std::string StringHelper::substringBeforeLast(const std::string& str, const std::string& separator) {
    size_t pos = str.rfind(separator);
    return (pos == std::string::npos) ? str : str.substr(0, pos);
}

std::string StringHelper::substringAfterLast(const std::string& str, const std::string& separator) {
    size_t pos = str.rfind(separator);
    return (pos == std::string::npos) ? "" : str.substr(pos + separator.size());
}

std::string StringHelper::substringBetween(const std::string& str, const std::string& open, const std::string& close) {
    size_t start = str.find(open);
    if (start == std::string::npos) return "";
    start += open.size();
    size_t end = str.find(close, start);
    return (end == std::string::npos) ? "" : str.substr(start, end - start);
}

int StringHelper::countMatches(const std::string& str, const std::string& sub) {
    if (sub.empty()) return 0;
    int count = 0;
    size_t pos = 0;
    while ((pos = str.find(sub, pos)) != std::string::npos) {
        ++count;
        pos += sub.size();
    }
    return count;
}

std::string StringHelper::replace(const std::string& str, const std::string& search, const std::string& replacement) {
    if (search.empty()) return str;
    std::string result;
    result.reserve(str.size());
    size_t pos = 0, lastPos = 0;
    while ((pos = str.find(search, lastPos)) != std::string::npos) {
        result.append(str, lastPos, pos - lastPos);
        result.append(replacement);
        lastPos = pos + search.size();
    }
    result.append(str, lastPos, str.size() - lastPos);
    return result;
}

std::string StringHelper::escapeHtml(const std::string& str) {
    std::string result;
    result.reserve(str.size());
    for (char c : str) {
        switch (c) {
            case '&': result += "&amp;"; break;
            case '<': result += "&lt;"; break;
            case '>': result += "&gt;"; break;
            case '"': result += "&quot;"; break;
            case '\'': result += "&#39;"; break;
            default: result += c;
        }
    }
    return result;
}

std::string StringHelper::escapeXml(const std::string& str) {
    std::string result;
    result.reserve(str.size());
    for (char c : str) {
        switch (c) {
            case '&': result += "&amp;"; break;
            case '<': result += "&lt;"; break;
            case '>': result += "&gt;"; break;
            case '"': result += "&quot;"; break;
            default: result += c;
        }
    }
    return result;
}

std::string StringHelper::escapeJavaScript(const std::string& str) {
    std::string result;
    result.reserve(str.size());
    for (char c : str) {
        switch (c) {
            case '\\': result += "\\\\"; break;
            case '"': result += "\\\""; break;
            case '\'': result += "\\'"; break;
            case '\n': result += "\\n"; break;
            case '\r': result += "\\r"; break;
            case '\t': result += "\\t"; break;
            default: result += c;
        }
    }
    return result;
}

std::string StringHelper::trim(const std::string& str) {
    size_t start = 0;
    while (start < str.size() && std::isspace(static_cast<unsigned char>(str[start]))) ++start;
    size_t end = str.size();
    while (end > start && std::isspace(static_cast<unsigned char>(str[end - 1]))) --end;
    return str.substr(start, end - start);
}

static inline bool isWhitespaceAll(const std::string& str) {
    for (char c : str) if (!std::isspace(static_cast<unsigned char>(c))) return false;
    return true;
}

std::string StringHelper::trimLeft(const std::string& str) {
    size_t start = 0;
    while (start < str.size() && std::isspace(static_cast<unsigned char>(str[start]))) ++start;
    return str.substr(start);
}

std::string StringHelper::trimRight(const std::string& str) {
    size_t end = str.size();
    while (end > 0 && std::isspace(static_cast<unsigned char>(str[end - 1]))) --end;
    return str.substr(0, end);
}

std::string StringHelper::removeWhitespace(const std::string& str) {
    std::string result;
    result.reserve(str.size());
    for (char c : str) {
        if (!std::isspace(static_cast<unsigned char>(c))) result += c;
    }
    return result;
}

std::string StringHelper::abbreviate(const std::string& str, int maxWidth) {
    if (static_cast<int>(str.size()) <= maxWidth || maxWidth < 4) return str;
    return str.substr(0, maxWidth - 3) + "...";
}

std::string StringHelper::abbreviateMiddle(const std::string& str, const std::string& middle, int maxWidth) {
    if (static_cast<int>(str.size()) <= maxWidth) return str;
    int half = (maxWidth - static_cast<int>(middle.size())) / 2;
    return str.substr(0, half) + middle + str.substr(str.size() - half);
}

std::string StringHelper::getCommonPrefix(const std::string& a, const std::string& b) {
    size_t i = 0;
    while (i < a.size() && i < b.size() && a[i] == b[i]) ++i;
    return a.substr(0, i);
}

std::vector<std::string> StringHelper::split(const std::string& str, char delimiter) {
    std::vector<std::string> result;
    std::istringstream ss(str);
    std::string token;
    while (std::getline(ss, token, delimiter)) {
        result.push_back(token);
    }
    return result;
}

std::vector<std::string> StringHelper::split(const std::string& str, const std::string& delimiter) {
    std::vector<std::string> result;
    size_t pos = 0, lastPos = 0;
    while ((pos = str.find(delimiter, lastPos)) != std::string::npos) {
        result.push_back(str.substr(lastPos, pos - lastPos));
        lastPos = pos + delimiter.size();
    }
    result.push_back(str.substr(lastPos));
    return result;
}

std::string StringHelper::join(const std::vector<std::string>& parts, const std::string& delimiter) {
    std::ostringstream buf;
    for (size_t i = 0; i < parts.size(); ++i) {
        if (i > 0) buf << delimiter;
        buf << parts[i];
    }
    return buf.str();
}

bool StringHelper::isBlank(const std::string* str) {
    return str == nullptr || std::all_of(str->begin(), str->end(), [](unsigned char c){ return std::isspace(c); });
}

bool StringHelper::isBlank(const std::optional<std::string>& str) {
    return !str.has_value() || std::all_of(str->begin(), str->end(), [](unsigned char c){ return std::isspace(c); });
}

bool StringHelper::isBlank(const std::string& str) {
    return std::all_of(str.begin(), str.end(), [](unsigned char c){ return std::isspace(c); });
}

bool StringHelper::isNotBlank(const std::string* str) { return !isBlank(str); }
bool StringHelper::isNotBlank(const std::string& str) { return !isBlank(str); }

bool StringHelper::isEmpty(const std::string* str) { return str == nullptr || str->empty(); }
bool StringHelper::isEmpty(const std::string& str) { return str.empty(); }
bool StringHelper::isNotEmpty(const std::string* str) { return str != nullptr && !str->empty(); }
bool StringHelper::isNotEmpty(const std::string& str) { return !str.empty(); }

std::string StringHelper::defaultString(const std::string* str, const std::string& defaultStr) {
    return (str != nullptr) ? *str : defaultStr;
}

std::string StringHelper::toString(const void* obj) {
    if (obj == nullptr) return "null";
    std::ostringstream ss;
    ss << obj;
    return ss.str();
}

bool StringHelper::isValidEmail(const std::string& email) {
    return std::regex_match(email, emailRegex);
}

std::string StringHelper::format(const std::string& pattern, const std::vector<std::string>& args) {
    std::string result = pattern;
    for (size_t i = 0; i < args.size(); ++i) {
        std::string placeholder = "{" + std::to_string(i) + "}";
        result = replace(result, placeholder, args[i]);
    }
    return result;
}

bool StringHelper::equalsIgnoreCase(const std::string& a, const std::string& b) {
    if (a.size() != b.size()) return false;
    return std::equal(a.begin(), a.end(), b.begin(), [](char c1, char c2) {
        return std::tolower(static_cast<unsigned char>(c1)) == std::tolower(static_cast<unsigned char>(c2));
    });
}

bool StringHelper::containsIgnoreCase(const std::string& haystack, const std::string& needle) {
    auto it = std::search(haystack.begin(), haystack.end(), needle.begin(), needle.end(),
        [](char c1, char c2) { return std::tolower(c1) == std::tolower(c2); });
    return it != haystack.end();
}

bool StringHelper::startsWithIgnoreCase(const std::string& str, const std::string& prefix) {
    if (str.size() < prefix.size()) return false;
    return std::equal(prefix.begin(), prefix.end(), str.begin(),
        [](char c1, char c2) { return std::tolower(c1) == std::tolower(c2); });
}

bool StringHelper::endsWithIgnoreCase(const std::string& str, const std::string& suffix) {
    if (str.size() < suffix.size()) return false;
    return std::equal(suffix.begin(), suffix.end(), str.end() - static_cast<int>(suffix.size()),
        [](char c1, char c2) { return std::tolower(c1) == std::tolower(c2); });
}

std::string StringHelper::removeStart(const std::string& str, const std::string& remove) {
    if (str.size() >= remove.size() && str.compare(0, remove.size(), remove) == 0) {
        return str.substr(remove.size());
    }
    return str;
}

std::string StringHelper::removeStartIgnoreCase(const std::string& str, const std::string& remove) {
    if (str.size() >= remove.size() && startsWithIgnoreCase(str, remove)) {
        return str.substr(remove.size());
    }
    return str;
}

std::string StringHelper::removeEnd(const std::string& str, const std::string& remove) {
    if (str.size() >= remove.size() && str.compare(str.size() - remove.size(), remove.size(), remove) == 0) {
        return str.substr(0, str.size() - remove.size());
    }
    return str;
}

std::string StringHelper::removeEndIgnoreCase(const std::string& str, const std::string& remove) {
    if (str.size() >= remove.size() && endsWithIgnoreCase(str, remove)) {
        return str.substr(0, str.size() - remove.size());
    }
    return str;
}

std::string StringHelper::leftPad(const std::string& str, int size, char padChar) {
    if (static_cast<int>(str.size()) >= size) return str;
    return std::string(size - str.size(), padChar) + str;
}

std::string StringHelper::rightPad(const std::string& str, int size, char padChar) {
    if (static_cast<int>(str.size()) >= size) return str;
    return str + std::string(size - str.size(), padChar);
}

std::string StringHelper::repeat(const std::string& str, int repeat) {
    std::string result;
    result.reserve(str.size() * repeat);
    for (int i = 0; i < repeat; ++i) result += str;
    return result;
}

std::string StringHelper::reverse(const std::string& str) {
    return std::string(str.rbegin(), str.rend());
}

int StringHelper::getLevenshteinDistance(const std::string& s, const std::string& t) {
    int n = s.size(), m = t.size();
    if (n == 0) return m;
    if (m == 0) return n;
    std::vector<std::vector<int>> d(n + 1, std::vector<int>(m + 1));
    for (int i = 0; i <= n; ++i) d[i][0] = i;
    for (int j = 0; j <= m; ++j) d[0][j] = j;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int cost = (s[i-1] == t[j-1]) ? 0 : 1;
            d[i][j] = std::min({d[i-1][j] + 1, d[i][j-1] + 1, d[i-1][j-1] + cost});
        }
    }
    return d[n][m];
}

bool StringHelper::wildcardMatch(const std::string& text, const std::string& pattern) {
    std::string regexPattern;
    for (char c : pattern) {
        switch (c) {
            case '*': regexPattern += ".*"; break;
            case '?': regexPattern += '.'; break;
            case '.': case '+': case '^': case '$': case '(': case ')': case '[': case ']': case '{': case '}': case '|': case '\\':
                regexPattern += '\\'; regexPattern += c; break;
            default: regexPattern += c;
        }
    }
    try {
        std::regex re(regexPattern);
        return std::regex_match(text, re);
    } catch (...) {
        return false;
    }
}

std::string StringHelper::soundex(const std::string& str) {
    if (str.empty()) return "";
    std::string result;
    result += static_cast<char>(std::toupper(str[0]));
    for (size_t i = 1; i < str.size() && result.size() < 4; ++i) {
        char c = static_cast<char>(std::toupper(str[i]));
        switch (c) {
            case 'B': case 'F': case 'P': case 'V':
                if (result.back() != '1') result += '1'; break;
            case 'C': case 'G': case 'J': case 'K': case 'Q': case 'S': case 'X': case 'Z':
                if (result.back() != '2') result += '2'; break;
            case 'D': case 'T':
                if (result.back() != '3') result += '3'; break;
            case 'L':
                if (result.back() != '4') result += '4'; break;
            case 'M': case 'N':
                if (result.back() != '5') result += '5'; break;
            case 'R':
                if (result.back() != '6') result += '6'; break;
        }
    }
    while (result.size() < 4) result += '0';
    return result;
}

std::string StringHelper::camelToUnderscore(const std::string& str) {
    std::string result;
    for (size_t i = 0; i < str.size(); ++i) {
        if (std::isupper(str[i])) {
            if (i > 0) result += '_';
            result += static_cast<char>(std::tolower(str[i]));
        } else {
            result += str[i];
        }
    }
    return result;
}

std::string StringHelper::underscoreToCamel(const std::string& str) {
    std::string result;
    bool capitalize = false;
    for (char c : str) {
        if (c == '_') {
            capitalize = true;
        } else {
            result += capitalize ? static_cast<char>(std::toupper(c)) : c;
            capitalize = false;
        }
    }
    return result;
}

std::string StringHelper::escapeRegex(const std::string& str) {
    static const std::string special = ".^$|()[]{}*+?\\";
    std::string result;
    result.reserve(str.size());
    for (char c : str) {
        if (special.find(c) != std::string::npos) result += '\\';
        result += c;
    }
    return result;
}

} // namespace org::projectforge::common
