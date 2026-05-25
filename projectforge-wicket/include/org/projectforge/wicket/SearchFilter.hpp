#pragma once
// ProjectForge C++ Port - Search Filter
// Advanced search/filter component with full-text search, field-specific
// filters, date ranges, and saved search support.

#include <string>
#include <string_view>
#include <vector>
#include <functional>
#include <unordered_map>
#include <sstream>
#include <algorithm>

namespace org::projectforge::wicket {

class SearchFilter {
public:
    struct FilterField {
        std::string name;
        std::string label;
        std::string type; // "text", "select", "date-range", "number-range", "checkbox"
        std::vector<std::pair<std::string, std::string>> options; // for select type
        std::string value;
    };

    SearchFilter(const std::string& id) : id_(id) {}
    virtual ~SearchFilter() = default;

    void addField(const std::string& name, const std::string& label,
                  const std::string& type = "text") {
        fields_.push_back({name, label, type, {}, ""});
    }

    void addSelectField(const std::string& name, const std::string& label,
                        const std::vector<std::pair<std::string, std::string>>& options) {
        FilterField field{name, label, "select", options, ""};
        fields_.push_back(std::move(field));
    }

    void addDateRangeField(const std::string& name, const std::string& label) {
        fields_.push_back({name, label, "date-range", {}, ""});
    }

    void setQuickSearchPlaceholder(const std::string& ph) { quickSearchPlaceholder_ = ph; }
    void setQuickSearchValue(const std::string& val) { quickSearchValue_ = val; }
    const std::string& getQuickSearchValue() const { return quickSearchValue_; }

    void setAdvancedSearchVisible(bool visible) { advancedVisible_ = visible; }
    bool isAdvancedSearchVisible() const { return advancedVisible_; }

    void setValue(const std::string& name, const std::string& value) {
        for (auto& f : fields_) {
            if (f.name == name) {
                f.value = value;
                return;
            }
        }
    }

    std::string getValue(const std::string& name) const {
        for (const auto& f : fields_) {
            if (f.name == name) return f.value;
        }
        return "";
    }

    // Collect all search parameters into a map
    std::unordered_map<std::string, std::string> getSearchParams() const {
        std::unordered_map<std::string, std::string> params;
        if (!quickSearchValue_.empty()) {
            params["q"] = quickSearchValue_;
        }
        for (const auto& f : fields_) {
            if (!f.value.empty()) {
                params[f.name] = f.value;
            }
        }
        return params;
    }

    // Clear all values
    void clear() {
        quickSearchValue_.clear();
        for (auto& f : fields_) {
            f.value.clear();
        }
    }

    // Check if any filter is active
    bool isActive() const {
        if (!quickSearchValue_.empty()) return true;
        for (const auto& f : fields_) {
            if (!f.value.empty()) return true;
        }
        return false;
    }

    // Render HTML
    std::string render() const {
        std::string html;
        html += "<div id=\"" + id_ + "\" class=\"pf-search-filter\">";

        // Quick search
        html += "<div class=\"pf-quick-search\">";
        html += "<form method=\"get\" class=\"search-form\">";
        html += "<div class=\"search-input-group\">";
        html += "<input type=\"text\" name=\"q\" value=\"" +
            escapeHtml(quickSearchValue_) + "\" placeholder=\"" +
            escapeHtml(quickSearchPlaceholder_.empty() ? "Search..." : quickSearchPlaceholder_) +
            "\" class=\"pf-search-input\">";
        html += "<button type=\"submit\" class=\"btn btn-search\">" +
            std::string("<i class=\"fa fa-search\"></i>") + "</button>";
        if (isActive()) {
            html += "<a href=\"?\" class=\"btn btn-clear\" title=\"Clear all filters\">" +
                std::string("<i class=\"fa fa-times\"></i>") + "</a>";
        }
        html += "</div>";

        // Advanced toggle
        if (!fields_.empty()) {
            html += "<button type=\"button\" class=\"btn btn-advanced-toggle\" " +
                std::string("onclick=\"toggleAdvancedSearch()\">") +
                (advancedVisible_ ? "Hide Advanced" : "Advanced") + "</button>";
        }
        html += "</form>";
        html += "</div>";

        // Advanced search panel
        if (!fields_.empty()) {
            html += "<div class=\"pf-advanced-search\" style=\"display:" +
                std::string(advancedVisible_ ? "block" : "none") + ";\">";
            html += "<div class=\"advanced-search-fields\">";

            for (const auto& field : fields_) {
                html += "<div class=\"filter-field\">";
                html += "<label for=\"filter_" + field.name + "\">" +
                    escapeHtml(field.label) + "</label>";

                if (field.type == "text") {
                    html += "<input type=\"text\" id=\"filter_" + field.name +
                        "\" name=\"" + field.name + "\" value=\"" +
                        escapeHtml(field.value) + "\" class=\"pf-input pf-filter-input\">";
                } else if (field.type == "select") {
                    html += "<select id=\"filter_" + field.name +
                        "\" name=\"" + field.name + "\" class=\"pf-select\">";
                    html += "<option value=\"\">-- Any --</option>";
                    for (const auto& [val, label] : field.options) {
                        html += "<option value=\"" + escapeHtml(val) + "\"" +
                            (val == field.value ? " selected" : "") + ">" +
                            escapeHtml(label) + "</option>";
                    }
                    html += "</select>";
                } else if (field.type == "date-range") {
                    html += "<input type=\"date\" id=\"filter_" + field.name + "_from\" " +
                        std::string("name=\"") + field.name + "_from\" placeholder=\"From\" " +
                        "class=\"pf-input pf-filter-input pf-date-range\">";
                    html += "<span class=\"range-separator\">to</span>";
                    html += "<input type=\"date\" id=\"filter_" + field.name + "_to\" " +
                        std::string("name=\"") + field.name + "_to\" placeholder=\"To\" " +
                        "class=\"pf-input pf-filter-input pf-date-range\">";
                } else if (field.type == "number-range") {
                    html += "<input type=\"number\" id=\"filter_" + field.name + "_from\" " +
                        std::string("name=\"") + field.name + "_from\" placeholder=\"Min\" " +
                        "class=\"pf-input pf-filter-input pf-number-range\">";
                    html += "<span class=\"range-separator\">to</span>";
                    html += "<input type=\"number\" id=\"filter_" + field.name + "_to\" " +
                        std::string("name=\"") + field.name + "_to\" placeholder=\"Max\" " +
                        "class=\"pf-input pf-filter-input pf-number-range\">";
                } else if (field.type == "checkbox") {
                    html += "<input type=\"checkbox\" id=\"filter_" + field.name +
                        "\" name=\"" + field.name + "\" value=\"true\" " +
                        (field.value == "true" ? "checked" : "") + " class=\"pf-checkbox\">";
                }

                html += "</div>";
            }

            html += "<div class=\"advanced-search-actions\">";
            html += "<button type=\"submit\" class=\"btn btn-primary btn-sm\">Apply Filters</button>";
            html += "<button type=\"button\" class=\"btn btn-secondary btn-sm\" " +
                std::string("onclick=\"clearFilters()\">Clear</button>");
            html += "</div>";

            html += "</div>";
            html += "</div>";
        }

        // Active filter badges
        if (isActive()) {
            html += "<div class=\"pf-active-filters\">";
            if (!quickSearchValue_.empty()) {
                html += "<span class=\"filter-badge\">Search: " +
                    escapeHtml(quickSearchValue_) +
                    " <a href=\"?\" class=\"remove-filter\" data-field=\"q\">&times;</a></span>";
            }
            for (const auto& field : fields_) {
                if (!field.value.empty()) {
                    html += "<span class=\"filter-badge\">" +
                        escapeHtml(field.label) + ": " + escapeHtml(field.value) +
                        " <a href=\"?\" class=\"remove-filter\" data-field=\"" +
                        field.name + "\">&times;</a></span>";
                }
            }
            html += "</div>";
        }

        html += "</div>";
        return html;
    }

    std::string renderCompact() const {
        std::string html;
        html += "<div id=\"" + id_ + "\" class=\"pf-search-filter-compact\">";
        html += "<form method=\"get\">";
        html += "<input type=\"text\" name=\"q\" value=\"" + escapeHtml(quickSearchValue_) +
            "\" placeholder=\"Search...\" class=\"pf-search-input\">";
        html += "<button type=\"submit\" class=\"btn btn-search\">Go</button>";
        html += "</form>";
        html += "</div>";
        return html;
    }

private:
    std::string escapeHtml(const std::string& input) const {
        std::string result;
        for (char c : input) {
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

    std::string id_;
    std::string quickSearchPlaceholder_;
    std::string quickSearchValue_;
    std::vector<FilterField> fields_;
    bool advancedVisible_ = false;
};

} // namespace org::projectforge::wicket
