// ProjectForge C++ port — GPL v3 — www.projectforge.org
#pragma once

#include <drogon/HttpRequest.h>
#include <nlohmann/json.hpp>
#include <string>
#include <vector>
#include <map>
#include <optional>
#include <cstdint>
#include <algorithm>

namespace org::projectforge::rest {

using json = nlohmann::json;

class RequestParamsDef {
public:
    // Extract and validate standard request parameters
    struct RequestParams {
        std::optional<int64_t> id;
        std::string searchQuery;
        std::string sortField;
        std::string sortDirection = "asc";
        size_t page = 1;
        size_t pageSize = 25;
        std::string dateFrom;
        std::string dateTo;
        std::string fields;      // sparse fieldsets
        std::string expand;      // related resources to expand
        std::string format;      // response format: json, csv, xml, pdf
        std::map<std::string, std::string> customFilters;

        static RequestParams fromRequest(const drogon::HttpRequestPtr& req) {
            RequestParams p;
            // Extract path ID if present
            auto path = req->getPath();
            auto segments = splitPath(path);
            for (size_t i = 0; i < segments.size(); ++i) {
                if (isNumeric(segments[i])) {
                    p.id = std::stoll(segments[i]);
                    break;
                }
            }

            // Query parameters
            auto& query = req->getParameters();
            if (!query["page"].empty()) {
                try { p.page = std::max<size_t>(1, std::stoull(query["page"])); }
                catch (...) { p.page = 1; }
            }
            if (!query["pageSize"].empty()) {
                try { p.pageSize = std::clamp<size_t>(std::stoull(query["pageSize"]), 1, 500); }
                catch (...) { p.pageSize = 25; }
            }
            if (!query["search"].empty()) p.searchQuery = query["search"];
            else if (!query["query"].empty()) p.searchQuery = query["query"];
            if (!query["sort"].empty()) {
                std::string s = query["sort"];
                if (!s.empty() && s[0] == '-') {
                    p.sortField = s.substr(1);
                    p.sortDirection = "desc";
                } else {
                    p.sortField = s;
                }
            }
            if (!query["sortDirection"].empty()) {
                p.sortDirection = (query["sortDirection"] == "desc") ? "desc" : "asc";
            }
            if (!query["dateFrom"].empty()) p.dateFrom = query["dateFrom"];
            if (!query["dateTo"].empty()) p.dateTo = query["dateTo"];
            if (!query["fields"].empty()) p.fields = query["fields"];
            if (!query["expand"].empty()) p.expand = query["expand"];
            if (!query["format"].empty()) p.format = query["format"];

            // Custom filters - any unknown query params
            static const std::set<std::string> known = {
                "page", "pageSize", "search", "query", "sort", "sortDirection",
                "dateFrom", "dateTo", "fields", "expand", "format", "access_token"
            };
            for (auto& [k, v] : query) {
                if (known.find(k) == known.end()) {
                    p.customFilters[k] = v;
                }
            }
            return p;
        }

        json toJson() const {
            json j;
            if (id) j["id"] = *id;
            if (!searchQuery.empty()) j["search"] = searchQuery;
            if (!sortField.empty()) j["sort"] = sortField;
            j["sortDirection"] = sortDirection;
            j["page"] = page;
            j["pageSize"] = pageSize;
            if (!dateFrom.empty()) j["dateFrom"] = dateFrom;
            if (!dateTo.empty()) j["dateTo"] = dateTo;
            if (!fields.empty()) j["fields"] = fields;
            if (!expand.empty()) j["expand"] = expand;
            if (!format.empty()) j["format"] = format;
            for (auto& [k, v] : customFilters) j[k] = v;
            return j;
        }

    private:
        static std::vector<std::string> splitPath(const std::string& path) {
            std::vector<std::string> segs;
            size_t start = 0;
            while (start < path.size()) {
                size_t end = path.find('/', start);
                if (end == std::string::npos) end = path.size();
                if (end > start) segs.push_back(path.substr(start, end - start));
                start = end + 1;
            }
            return segs;
        }

        static bool isNumeric(const std::string& s) {
            if (s.empty()) return false;
            for (size_t i = (s[0] == '-' ? 1 : 0); i < s.size(); ++i) {
                if (!std::isdigit(s[i])) return false;
            }
            return true;
        }
    };

    // Parse JSON body and validate required fields
    static std::optional<json> parseBody(const drogon::HttpRequestPtr& req) {
        try {
            auto& body = req->getBody();
            if (body.empty()) return json::object();
            return json::parse(body);
        } catch (const std::exception& e) {
            return std::nullopt;
        }
    }

    static std::optional<json> parseBody(const drogon::HttpRequestPtr& req, std::string& errorMsg) {
        try {
            auto& body = req->getBody();
            if (body.empty()) {
                errorMsg = "Empty request body";
                return std::nullopt;
            }
            return json::parse(body);
        } catch (const json::parse_error& e) {
            errorMsg = std::string("Invalid JSON: ") + e.what();
            return std::nullopt;
        }
    }

    // Validate required fields in JSON body
    static bool validateRequired(const json& body, const std::vector<std::string>& fields,
                                 std::vector<std::string>& missingFields) {
        for (auto& f : fields) {
            if (!body.contains(f) || body[f].is_null()) {
                missingFields.push_back(f);
            }
        }
        return missingFields.empty();
    }

    // Extract string param safely
    static std::string getString(const json& obj, const std::string& key,
                                 const std::string& defaultValue = "") {
        if (obj.contains(key) && obj[key].is_string()) {
            return obj[key].get<std::string>();
        }
        return defaultValue;
    }

    static std::optional<std::string> getOptionalString(const json& obj, const std::string& key) {
        if (obj.contains(key) && obj[key].is_string()) {
            return obj[key].get<std::string>();
        }
        return std::nullopt;
    }

    static int64_t getInt64(const json& obj, const std::string& key, int64_t defaultValue = 0) {
        if (obj.contains(key)) {
            auto& val = obj[key];
            if (val.is_number_integer()) return val.get<int64_t>();
            if (val.is_number_float()) return static_cast<int64_t>(val.get<double>());
            if (val.is_string()) {
                try { return std::stoll(val.get<std::string>()); }
                catch (...) { return defaultValue; }
            }
        }
        return defaultValue;
    }

    static int32_t getInt32(const json& obj, const std::string& key, int32_t defaultValue = 0) {
        if (obj.contains(key)) {
            auto& val = obj[key];
            if (val.is_number_integer()) return val.get<int32_t>();
            if (val.is_string()) {
                try { return std::stoi(val.get<std::string>()); }
                catch (...) { return defaultValue; }
            }
        }
        return defaultValue;
    }

    static double getDouble(const json& obj, const std::string& key, double defaultValue = 0.0) {
        if (obj.contains(key)) {
            auto& val = obj[key];
            if (val.is_number()) return val.get<double>();
            if (val.is_string()) {
                try { return std::stod(val.get<std::string>()); }
                catch (...) { return defaultValue; }
            }
        }
        return defaultValue;
    }

    static bool getBool(const json& obj, const std::string& key, bool defaultValue = false) {
        if (obj.contains(key) && obj[key].is_boolean()) {
            return obj[key].get<bool>();
        }
        return defaultValue;
    }

    static std::vector<int64_t> getInt64Array(const json& obj, const std::string& key) {
        std::vector<int64_t> result;
        if (obj.contains(key) && obj[key].is_array()) {
            for (auto& v : obj[key]) {
                if (v.is_number_integer()) result.push_back(v.get<int64_t>());
            }
        }
        return result;
    }

    static std::vector<std::string> getStringArray(const json& obj, const std::string& key) {
        std::vector<std::string> result;
        if (obj.contains(key) && obj[key].is_array()) {
            for (auto& v : obj[key]) {
                if (v.is_string()) result.push_back(v.get<std::string>());
            }
        }
        return result;
    }

    // Validate email format
    static bool isValidEmail(const std::string& email) {
        const std::regex pattern(R"(^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$)");
        return std::regex_match(email, pattern);
    }

    // Sanitize string input
    static std::string sanitize(const std::string& input, size_t maxLen = 1024) {
        std::string result;
        for (char c : input) {
            if (c == '<' || c == '>') continue;
            result += c;
            if (result.size() >= maxLen) break;
        }
        return result;
    }
};

} // namespace org::projectforge::rest
