// ProjectForge C++ port — GPL v3 — www.projectforge.org
#pragma once
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>
#include <regex>

namespace org::projectforge::web {

class WebUtils {
public:
    static std::string escapeHtml(const std::string& s) {
        std::string r;
        for (char c : s) {
            switch (c) {
                case '&': r += "&amp;"; break;
                case '<': r += "&lt;"; break;
                case '>': r += "&gt;"; break;
                case '"': r += "&quot;"; break;
                case '\'': r += "&#39;"; break;
                default: r += c;
            }
        }
        return r;
    }

    static std::string escapeJavaScript(const std::string& s) {
        std::string r;
        for (char c : s) {
            switch (c) {
                case '\\': r += "\\\\"; break;
                case '\'': r += "\\'"; break;
                case '"': r += "\\\""; break;
                case '\n': r += "\\n"; break;
                case '\r': r += "\\r"; break;
                default: r += c;
            }
        }
        return r;
    }

    static std::string urlEncode(const std::string& s) {
        std::ostringstream ss;
        for (unsigned char c : s) {
            if (std::isalnum(c) || c=='-'||c=='_'||c=='.'||c=='~') ss << c;
            else ss << '%' << std::uppercase << std::hex << std::setw(2) << std::setfill('0') << (int)c;
        }
        return ss.str();
    }

    static std::string urlDecode(const std::string& s) {
        std::string r;
        for (size_t i=0; i<s.size(); ++i) {
            if (s[i]=='%' && i+2<s.size()) {
                int val;
                std::istringstream ss(s.substr(i+1, 2));
                ss >> std::hex >> val;
                r += static_cast<char>(val);
                i += 2;
            } else if (s[i]=='+') {
                r += ' ';
            } else {
                r += s[i];
            }
        }
        return r;
    }

    static std::map<std::string, std::string> parseQueryString(const std::string& query) {
        std::map<std::string, std::string> result;
        std::istringstream ss(query);
        std::string pair;
        while (std::getline(ss, pair, '&')) {
            auto pos = pair.find('=');
            if (pos != std::string::npos) {
                result[urlDecode(pair.substr(0, pos))] = urlDecode(pair.substr(pos+1));
            }
        }
        return result;
    }

    static std::string buildUrl(const std::string& baseUrl, const std::map<std::string, std::string>& params) {
        std::ostringstream ss;
        ss << baseUrl;
        bool first = true;
        for (auto& [k, v] : params) {
            ss << (first ? '?' : '&') << urlEncode(k) << '=' << urlEncode(v);
            first = false;
        }
        return ss.str();
    }

    static std::string getClientIp(const std::string& xForwardedFor, const std::string& remoteAddr) {
        if (!xForwardedFor.empty()) {
            auto pos = xForwardedFor.find(',');
            return pos != std::string::npos ? xForwardedFor.substr(0, pos) : xForwardedFor;
        }
        return remoteAddr;
    }

    static bool isValidUrl(const std::string& url) {
        static std::regex urlRe(R"(https?://[\w./\-_?#=&\+\%]+)", std::regex::icase);
        return std::regex_match(url, urlRe);
    }

    static std::string sanitizeFilename(const std::string& filename) {
        std::string result;
        for (char c : filename) {
            if (std::isalnum(c) || c=='-'||c=='_'||c=='.') result += c;
            else result += '_';
        }
        return result;
    }
};

} // namespace
