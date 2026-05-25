#pragma once
// ProjectForge C++ Port - Base List Page
// Provides list/table-based entity browsing with sorting, paging,
// filtering, and action column support for server-side rendering.

#include "BasePage.hpp"
#include "TemplateEngine.hpp"
#include <string>
#include <string_view>
#include <vector>
#include <unordered_map>
#include <functional>
#include <memory>
#include <algorithm>
#include <sstream>

namespace org::projectforge::wicket {

template<typename EntityType>
class BaseListPage : public BasePage {
public:
    using ColumnRenderer = std::function<std::string(const EntityType&, size_t idx)>;
    using ActionRenderer = std::function<std::string(const EntityType&)>;
    using FilterFunc = std::function<bool(const EntityType&, const std::string&)>;

    struct Column {
        std::string id;
        std::string label;
        std::string sortProperty;
        bool sortable = true;
        ColumnRenderer renderer;
    };

    BaseListPage() {
        templateEngine_.loadTemplate("list", TemplateEngine::defaultListPageTemplate());
        BasePage::setTitle("List");
    }

    explicit BaseListPage(const std::string& title) {
        templateEngine_.loadTemplate("list", TemplateEngine::defaultListPageTemplate());
        BasePage::setTitle(title);
    }
    virtual ~BaseListPage() = default;

    // Column management
    void addColumn(const std::string& id, const std::string& label,
                   ColumnRenderer renderer, bool sortable = true) {
        columns_.push_back({id, label, id, sortable, std::move(renderer)});
    }

    void addColumn(Column&& col) {
        columns_.push_back(std::move(col));
    }

    // Data management
    void setData(const std::vector<EntityType>& data) {
        allData_ = data;
        filteredData_ = data;
        updatePage();
    }

    void setData(std::vector<EntityType>&& data) {
        allData_ = std::move(data);
        filteredData_ = allData_;
        updatePage();
    }

    // Sorting
    void setSortColumn(const std::string& colId, bool ascending = true) {
        sortColumn_ = colId;
        sortAscending_ = ascending;
        sortData();
        updatePage();
    }

    // Paging
    void setPageSize(size_t size) { pageSize_ = size; updatePage(); }
    size_t getPageSize() const { return pageSize_; }
    void setCurrentPage(size_t page) {
        currentPage_ = std::max(size_t(0), std::min(page, getTotalPages() - 1));
    }
    size_t getCurrentPage() const { return currentPage_; }
    size_t getTotalPages() const {
        if (pageSize_ == 0 || filteredData_.empty()) return 1;
        return (filteredData_.size() + pageSize_ - 1) / pageSize_;
    }
    size_t getTotalRows() const { return filteredData_.size(); }

    // Search/filter
    void setSearchFilter(const std::string& filter) {
        searchFilter_ = filter;
        applySearchFilter();
        updatePage();
    }
    const std::string& getSearchFilter() const { return searchFilter_; }

    void addFilterField(const std::string& fieldName, FilterFunc filterFunc) {
        filterFields_[fieldName] = std::move(filterFunc);
    }

    // Actions
    void setEditUrl(const std::string& url) { editUrl_ = url; }
    void setNewUrl(const std::string& url) { newUrl_ = url; }
    void setViewUrl(const std::string& url) { viewUrl_ = url; }

    // New entity URL
    void setNewEntityUrl(const std::string& url) { newEntityUrl_ = url; }
    const std::string& getNewEntityUrl() const { return newEntityUrl_; }

    // Get current page data
    std::vector<EntityType> getCurrentPageData() const {
        std::vector<EntityType> page;
        size_t start = currentPage_ * pageSize_;
        size_t end = std::min(start + pageSize_, filteredData_.size());
        for (size_t i = start; i < end; ++i) {
            page.push_back(filteredData_[i]);
        }
        return page;
    }

    // Render
    std::string render() override {
        onBeforeRender();

        // Build table headers
        std::string headersHtml;
        for (const auto& col : columns_) {
            headersHtml += "<th";
            if (col.sortable) {
                headersHtml += " class=\"sortable\" data-sort=\"" + col.sortProperty + "\"";
                if (col.sortProperty == sortColumn_) {
                    headersHtml += " data-dir=\"" + std::string(sortAscending_ ? "asc" : "desc") + "\"";
                }
                headersHtml += " onclick=\"sortBy('" + col.sortProperty + "')\"";
            }
            headersHtml += ">" + TemplateContext::escape(col.label, EscapeMode::HTML);
            if (col.sortable && col.sortProperty == sortColumn_) {
                headersHtml += " <span class=\"sort-icon\">" +
                    std::string(sortAscending_ ? "&#9650;" : "&#9660;") + "</span>";
            }
            headersHtml += "</th>";
        }
        // Action column
        if (!editUrl_.empty() || !viewUrl_.empty()) {
            headersHtml += "<th class=\"actions\">Actions</th>";
        }

        // Build table rows
        auto pageData = getCurrentPageData();
        std::string rowsData;
        for (size_t i = 0; i < pageData.size(); ++i) {
            std::string rowHtml;
            for (const auto& col : columns_) {
                rowHtml += "<td>" + col.renderer(pageData[i], i) + "</td>";
            }
            if (!editUrl_.empty() || !viewUrl_.empty()) {
                rowHtml += "<td class=\"actions\">";
                if (!viewUrl_.empty()) {
                    rowHtml += "<a href=\"" + viewUrl_ + "\" class=\"btn btn-sm btn-info\">View</a> ";
                }
                if (!editUrl_.empty()) {
                    rowHtml += "<a href=\"" + editUrl_ + "\" class=\"btn btn-sm btn-primary\">Edit</a>";
                }
                rowHtml += "</td>";
            }
            rowsData += rowHtml + "\n";
        }

        // Build template context
        TemplateContext listCtx;
        listCtx.set("newUrl", newEntityUrl_);
        listCtx.setEscaped("tableHeaders", headersHtml, EscapeMode::HTML);
        listCtx.set("rows", rowsData);

        size_t start = currentPage_ * pageSize_ + 1;
        size_t end = std::min(start + pageSize_ - 1, filteredData_.size());
        if (filteredData_.empty()) end = 0;
        listCtx.setInt("firstRow", static_cast<int>(filteredData_.empty() ? 0 : start));
        listCtx.setInt("lastRow", static_cast<int>(end));
        listCtx.setInt("totalRows", static_cast<int>(filteredData_.size()));

        // Search filter component
        std::string searchHtml = renderSearchFilter();
        templateEngine_.registerComponent("searchFilter", [searchHtml](const TemplateContext&) {
            return searchHtml;
        });

        // Paging navigator component
        std::string pagingHtml = renderPagingNavigator();
        templateEngine_.registerComponent("pagingNavigator", [pagingHtml](const TemplateContext&) {
            return pagingHtml;
        });

        setContent(templateEngine_.render("list", listCtx));
        TemplateContext pageCtx = buildPageContext();
        std::string result = templateEngine_.render("page", pageCtx);
        onAfterRender();
        return result;
    }

    const std::vector<Column>& getColumns() const { return columns_; }

protected:
    std::string renderSearchFilter() const {
        std::string html = "<div class=\"pf-search-filter\">";
        html += "<form method=\"get\" class=\"search-form\">";
        html += "<input type=\"text\" name=\"search\" value=\"" +
            TemplateContext::escape(searchFilter_, EscapeMode::HTML) +
            "\" placeholder=\"Search...\" class=\"pf-search-input\">";
        html += "<button type=\"submit\" class=\"btn btn-sm\">Search</button>";
        if (!searchFilter_.empty()) {
            html += "<a href=\"?\" class=\"btn btn-sm btn-secondary\">Clear</a>";
        }
        html += "</form>";
        html += "</div>";
        return html;
    }

    std::string renderPagingNavigator() const {
        size_t totalPages = getTotalPages();
        if (totalPages <= 1) return "";

        std::string html = "<div class=\"pf-paging-navigator\">";
        html += "<ul class=\"pagination\">";

        // Previous
        if (currentPage_ > 0) {
            html += "<li class=\"page-item\"><a class=\"page-link\" href=\"?page=" +
                std::to_string(currentPage_ - 1) + "\">&laquo; Prev</a></li>";
        } else {
            html += "<li class=\"page-item disabled\"><span class=\"page-link\">&laquo; Prev</span></li>";
        }

        // Page numbers
        size_t startPage = std::max(size_t(0), currentPage_ > 3 ? currentPage_ - 3 : 0);
        size_t endPage = std::min(totalPages, currentPage_ + 4);

        for (size_t p = startPage; p < endPage; ++p) {
            if (p == currentPage_) {
                html += "<li class=\"page-item active\"><span class=\"page-link\">" +
                    std::to_string(p + 1) + "</span></li>";
            } else {
                html += "<li class=\"page-item\"><a class=\"page-link\" href=\"?page=" +
                    std::to_string(p) + "\">" + std::to_string(p + 1) + "</a></li>";
            }
        }

        // Next
        if (currentPage_ + 1 < totalPages) {
            html += "<li class=\"page-item\"><a class=\"page-link\" href=\"?page=" +
                std::to_string(currentPage_ + 1) + "\">Next &raquo;</a></li>";
        } else {
            html += "<li class=\"page-item disabled\"><span class=\"page-link\">Next &raquo;</span></li>";
        }

        html += "</ul>";
        html += "<span class=\"page-info\">Page " + std::to_string(currentPage_ + 1) +
            " of " + std::to_string(totalPages) + "</span>";
        html += "</div>";
        return html;
    }

    void sortData() {
        std::sort(filteredData_.begin(), filteredData_.end(),
            [this](const EntityType& a, const EntityType& b) {
                // Use column renderer for comparison
                auto colIt = std::find_if(columns_.begin(), columns_.end(),
                    [this](const Column& c) { return c.sortProperty == sortColumn_; });
                if (colIt != columns_.end()) {
                    std::string valA = colIt->renderer(a, 0);
                    std::string valB = colIt->renderer(b, 0);
                    // Strip HTML tags for sorting
                    auto stripHtml = [](std::string s) {
                        std::string r;
                        bool inTag = false;
                        for (char c : s) {
                            if (c == '<') inTag = true;
                            else if (c == '>') inTag = false;
                            else if (!inTag) r += c;
                        }
                        return r;
                    };
                    valA = stripHtml(valA);
                    valB = stripHtml(valB);
                    return sortAscending_ ? valA < valB : valA > valB;
                }
                return false;
            });
    }

    void applySearchFilter() {
        if (searchFilter_.empty()) {
            filteredData_ = allData_;
            return;
        }
        filteredData_.clear();
        std::string lowerFilter = searchFilter_;
        std::transform(lowerFilter.begin(), lowerFilter.end(), lowerFilter.begin(), ::tolower);

        for (const auto& entity : allData_) {
            bool matches = false;
            // Check all columns
            for (const auto& col : columns_) {
                std::string val = col.renderer(entity, 0);
                // Strip HTML
                std::string plain;
                bool inTag = false;
                for (char c : val) {
                    if (c == '<') inTag = true;
                    else if (c == '>') inTag = false;
                    else if (!inTag) plain += static_cast<char>(::tolower(c));
                }
                if (plain.find(lowerFilter) != std::string::npos) {
                    matches = true;
                    break;
                }
            }
            // Check filter fields
            if (!matches) {
                for (const auto& [fieldName, filterFn] : filterFields_) {
                    if (filterFn(entity, searchFilter_)) {
                        matches = true;
                        break;
                    }
                }
            }
            if (matches) {
                filteredData_.push_back(entity);
            }
        }
    }

    void updatePage() {
        if (currentPage_ >= getTotalPages()) {
            currentPage_ = std::max(size_t(0), getTotalPages() - 1);
        }
    }

    std::vector<Column> columns_;
    std::vector<EntityType> allData_;
    std::vector<EntityType> filteredData_;
    std::string sortColumn_;
    bool sortAscending_ = true;
    size_t currentPage_ = 0;
    size_t pageSize_ = 20;
    std::string searchFilter_;
    std::string editUrl_;
    std::string viewUrl_;
    std::string newUrl_;
    std::string newEntityUrl_ = "#";
    std::unordered_map<std::string, FilterFunc> filterFields_;
};

} // namespace org::projectforge::wicket
