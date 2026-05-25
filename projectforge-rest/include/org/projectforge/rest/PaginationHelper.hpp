// ProjectForge C++ port — GPL v3 — www.projectforge.org
#pragma once

#include <string>
#include <vector>
#include <map>
#include <set>
#include <cstdint>
#include <optional>
#include <algorithm>
#include <nlohmann/json.hpp>

namespace org::projectforge::rest {

using json = nlohmann::json;

struct PaginationParams {
    size_t page = 1;
    size_t pageSize = 25;
    size_t offset() const { return (page > 0 ? page - 1 : 0) * pageSize; }

    static PaginationParams fromRequest(const json& queryParams) {
        PaginationParams p;
        if (queryParams.contains("page")) {
            auto val = queryParams["page"];
            if (val.is_number()) p.page = std::max<size_t>(1, val.get<size_t>());
            else if (val.is_string()) {
                try { p.page = std::max<size_t>(1, std::stoull(val.get<std::string>())); }
                catch (...) { p.page = 1; }
            }
        }
        if (queryParams.contains("pageSize")) {
            auto val = queryParams["pageSize"];
            size_t ps = 25;
            if (val.is_number()) ps = val.get<size_t>();
            else if (val.is_string()) {
                try { ps = std::stoull(val.get<std::string>()); }
                catch (...) { ps = 25; }
            }
            p.pageSize = std::min<size_t>(std::max<size_t>(1, ps), 500);
        }
        return p;
    }

    static PaginationParams fromMap(const std::map<std::string, std::string>& params) {
        PaginationParams p;
        auto it = params.find("page");
        if (it != params.end()) {
            try { p.page = std::max<size_t>(1, std::stoull(it->second)); }
            catch (...) { p.page = 1; }
        }
        it = params.find("pageSize");
        if (it != params.end()) {
            try {
                size_t ps = std::stoull(it->second);
                p.pageSize = std::min<size_t>(std::max<size_t>(1ul, ps), 500ul);
            } catch (...) { p.pageSize = 25; }
        }
        return p;
    }

    json toJson() const {
        return json{{"page", page}, {"pageSize", pageSize}};
    }
};

struct SortParams {
    std::string field;
    std::string direction = "asc"; // "asc" or "desc"

    bool isEmpty() const { return field.empty(); }
    bool isAscending() const { return direction == "asc"; }
    bool isDescending() const { return direction == "desc"; }

    static SortParams fromRequest(const json& queryParams) {
        SortParams s;
        if (queryParams.contains("sort")) {
            auto val = queryParams["sort"];
            if (val.is_string()) {
                std::string sortStr = val.get<std::string>();
                if (!sortStr.empty() && sortStr[0] == '-') {
                    s.field = sortStr.substr(1);
                    s.direction = "desc";
                } else {
                    s.field = sortStr;
                    s.direction = "asc";
                }
            }
        }
        if (queryParams.contains("sortDirection")) {
            auto val = queryParams["sortDirection"];
            if (val.is_string()) {
                std::string dir = val.get<std::string>();
                if (dir == "desc" || dir == "DESC") s.direction = "desc";
                else s.direction = "asc";
            }
        }
        return s;
    }

    static SortParams fromMap(const std::map<std::string, std::string>& params) {
        SortParams s;
        auto it = params.find("sort");
        if (it != params.end()) {
            if (!it->second.empty() && it->second[0] == '-') {
                s.field = it->second.substr(1);
                s.direction = "desc";
            } else {
                s.field = it->second;
                s.direction = "asc";
            }
        }
        it = params.find("sortDirection");
        if (it != params.end()) {
            if (it->second == "desc" || it->second == "DESC") s.direction = "desc";
            else s.direction = "asc";
        }
        return s;
    }

    json toJson() const {
        return json{{"field", field}, {"direction", direction}};
    }
};

struct FilterParams {
    std::string searchQuery;
    std::map<std::string, std::string> filters;
    std::string dateFrom;
    std::string dateTo;

    bool isEmpty() const {
        return searchQuery.empty() && filters.empty() && dateFrom.empty() && dateTo.empty();
    }

    static FilterParams fromRequest(const json& queryParams) {
        FilterParams f;
        if (queryParams.contains("search") && queryParams["search"].is_string()) {
            f.searchQuery = queryParams["search"].get<std::string>();
        }
        if (queryParams.contains("query") && queryParams["query"].is_string()) {
            f.searchQuery = queryParams["query"].get<std::string>();
        }
        if (queryParams.contains("dateFrom") && queryParams["dateFrom"].is_string()) {
            f.dateFrom = queryParams["dateFrom"].get<std::string>();
        }
        if (queryParams.contains("dateTo") && queryParams["dateTo"].is_string()) {
            f.dateTo = queryParams["dateTo"].get<std::string>();
        }
        // Extract dynamic filters (anything that isn't a known param)
        static const std::set<std::string> knownParams = {
            "page", "pageSize", "sort", "sortDirection", "search", "query",
            "dateFrom", "dateTo", "format", "fields", "expand"
        };
        for (auto& [key, val] : queryParams.items()) {
            if (knownParams.count(key) == 0 && val.is_string()) {
                f.filters[key] = val.get<std::string>();
            }
        }
        return f;
    }

    static FilterParams fromMap(const std::map<std::string, std::string>& params) {
        FilterParams f;
        auto it = params.find("search");
        if (it != params.end()) f.searchQuery = it->second;
        else {
            it = params.find("query");
            if (it != params.end()) f.searchQuery = it->second;
        }
        it = params.find("dateFrom");
        if (it != params.end()) f.dateFrom = it->second;
        it = params.find("dateTo");
        if (it != params.end()) f.dateTo = it->second;
        static const std::set<std::string> knownParams = {
            "page", "pageSize", "sort", "sortDirection", "search", "query",
            "dateFrom", "dateTo", "format", "fields", "expand"
        };
        for (auto& [k, v] : params) {
            if (knownParams.count(k) == 0) f.filters[k] = v;
        }
        return f;
    }

    std::string getFilter(const std::string& key, const std::string& defaultValue = "") const {
        auto it = filters.find(key);
        return it != filters.end() ? it->second : defaultValue;
    }

    bool hasFilter(const std::string& key) const {
        return filters.find(key) != filters.end();
    }

    json toJson() const {
        json j;
        if (!searchQuery.empty()) j["search"] = searchQuery;
        if (!dateFrom.empty()) j["dateFrom"] = dateFrom;
        if (!dateTo.empty()) j["dateTo"] = dateTo;
        for (auto& [k, v] : filters) j[k] = v;
        return j;
    }
};

struct PagedResponse {
    json data;
    size_t total = 0;
    size_t page = 1;
    size_t pageSize = 25;
    size_t totalPages = 0;
    bool hasNext = false;
    bool hasPrevious = false;
    std::string sortField;
    std::string sortDirection;
    json appliedFilters;

    json toJson() const {
        json j;
        j["data"] = data;
        j["pagination"] = {
            {"page", page},
            {"pageSize", pageSize},
            {"total", total},
            {"totalPages", totalPages},
            {"hasNext", hasNext},
            {"hasPrevious", hasPrevious}
        };
        if (!sortField.empty()) {
            j["sort"] = {{"field", sortField}, {"direction", sortDirection}};
        }
        if (!appliedFilters.empty()) {
            j["filters"] = appliedFilters;
        }
        return j;
    }

    static PagedResponse fromResults(const json& results, size_t total,
                                     const PaginationParams& pagination,
                                     const SortParams& sort = {},
                                     const FilterParams& filter = {}) {
        PagedResponse resp;
        resp.data = results;
        resp.total = total;
        resp.page = pagination.page;
        resp.pageSize = pagination.pageSize;
        resp.totalPages = pagination.pageSize > 0
            ? (total + pagination.pageSize - 1) / pagination.pageSize : 0;
        resp.hasNext = pagination.page < resp.totalPages;
        resp.hasPrevious = pagination.page > 1;
        if (!sort.isEmpty()) {
            resp.sortField = sort.field;
            resp.sortDirection = sort.direction;
        }
        if (!filter.isEmpty()) {
            resp.appliedFilters = filter.toJson();
        }
        return resp;
    }
};

} // namespace org::projectforge::rest
