#pragma once
// ProjectForge C++ Port - Data Table
// Feature-rich data table component with sorting, paging, selection,
// row expansion, and export support for server-side rendering.

#include <string>
#include <string_view>
#include <vector>
#include <functional>
#include <unordered_map>
#include <memory>
#include <algorithm>

namespace org::projectforge::wicket {

class DataTableColumn {
public:
    DataTableColumn(const std::string& property, const std::string& label)
        : property_(property), label_(label) {}

    void setSortable(bool sortable) { sortable_ = sortable; }
    bool isSortable() const { return sortable_; }
    const std::string& getProperty() const { return property_; }
    const std::string& getLabel() const { return label_; }
    void setWidth(const std::string& width) { width_ = width; }
    const std::string& getWidth() const { return width_; }
    void setCssClass(const std::string& cls) { cssClass_ = cls; }
    const std::string& getCssClass() const { return cssClass_; }
    void setAlign(const std::string& align) { align_ = align; }
    const std::string& getAlign() const { return align_; }

    std::string renderHeader(bool sorted = false, bool ascending = true) const {
        std::string html = "<th";
        if (!width_.empty()) html += " style=\"width:" + width_ + ";\"";
        if (!cssClass_.empty()) html += " class=\"" + cssClass_ + "\"";
        html += ">";
        html += "<a href=\"?sort=" + property_ + "&dir=" + (ascending ? "asc" : "desc") + "\"";
        if (sortable_) html += " class=\"sort-link\"";
        html += ">" + label_ + "</a>";
        if (sorted) {
            html += " <span class=\"sort-indicator\">" +
                std::string(ascending ? "&#9650;" : "&#9660;") + "</span>";
        }
        html += "</th>";
        return html;
    }

private:
    std::string property_;
    std::string label_;
    bool sortable_ = true;
    std::string width_;
    std::string cssClass_;
    std::string align_;
};

template<typename RowType>
class DataTable {
public:
    using CellRenderer = std::function<std::string(const RowType&, size_t rowIdx, size_t colIdx)>;
    using RowClassProvider = std::function<std::string(const RowType&, size_t idx)>;
    using SelectionHandler = std::function<void(const std::vector<size_t>&)>;
    using ExportHandler = std::function<std::string(const std::vector<RowType>&)>;

    DataTable(const std::string& id) : id_(id) {}
    virtual ~DataTable() = default;

    // Column management
    void addColumn(const DataTableColumn& col) { columns_.push_back(col); }
    void addColumn(DataTableColumn&& col) { columns_.push_back(std::move(col)); }
    const std::vector<DataTableColumn>& getColumns() const { return columns_; }

    // Data
    void setRows(const std::vector<RowType>& rows) { rows_ = rows; }
    void setRows(std::vector<RowType>&& rows) { rows_ = std::move(rows); }
    const std::vector<RowType>& getRows() const { return rows_; }
    size_t getRowCount() const { return rows_.size(); }

    // Cell renderer
    void setCellRenderer(CellRenderer renderer) { cellRenderer_ = std::move(renderer); }
    void setRowClassProvider(RowClassProvider provider) { rowClassProvider_ = std::move(provider); }

    // Sorting
    void sort(const std::string& property, bool ascending) {
        sortProperty_ = property;
        sortAscending_ = ascending;
        auto colIdx = getColumnIndex(property);
        std::sort(rows_.begin(), rows_.end(),
            [this, colIdx](const RowType& a, const RowType& b) {
                if (!cellRenderer_) return false;
                std::string va = cellRenderer_(a, 0, colIdx);
                std::string vb = cellRenderer_(b, 0, colIdx);
                return sortAscending_ ? va < vb : va > vb;
            });
    }

    const std::string& getSortProperty() const { return sortProperty_; }
    bool isSortAscending() const { return sortAscending_; }

    // Paging
    void setPageSize(size_t size) { pageSize_ = size; }
    size_t getPageSize() const { return pageSize_; }
    size_t getCurrentPage() const { return currentPage_; }
    void setCurrentPage(size_t page) { currentPage_ = page; }
    size_t getTotalPages() const {
        if (pageSize_ == 0 || rows_.empty()) return 1;
        return (rows_.size() + pageSize_ - 1) / pageSize_;
    }

    // Selection
    void setSelectable(bool selectable) { selectable_ = selectable; }
    bool isSelectable() const { return selectable_; }
    void setSelectionHandler(SelectionHandler handler) { selectionHandler_ = std::move(handler); }
    const std::vector<size_t>& getSelectedIndices() const { return selectedIndices_; }
    void toggleSelection(size_t idx) {
        auto it = std::find(selectedIndices_.begin(), selectedIndices_.end(), idx);
        if (it != selectedIndices_.end()) {
            selectedIndices_.erase(it);
        } else {
            selectedIndices_.push_back(idx);
        }
    }
    void selectAll() {
        selectedIndices_.clear();
        size_t start = currentPage_ * pageSize_;
        size_t end = std::min(start + pageSize_, rows_.size());
        for (size_t i = start; i < end; ++i) {
            selectedIndices_.push_back(i);
        }
    }
    void clearSelection() { selectedIndices_.clear(); }

    // Expandable rows
    void setExpandable(bool expandable) { expandable_ = expandable; }
    using ExpandedRowRenderer = std::function<std::string(const RowType&)>;
    void setExpandedRowRenderer(ExpandedRowRenderer renderer) { expandedRowRenderer_ = std::move(renderer); }

    // Export
    void setExportHandler(ExportHandler handler) { exportHandler_ = std::move(handler); }
    std::string exportData() const {
        if (exportHandler_) return exportHandler_(rows_);
        return "";
    }

    // Rendering
    std::string render() {
        std::string html;
        html += "<div id=\"" + id_ + "\" class=\"pf-data-table-container\">";

        // Table info bar
        html += renderInfoBar();

        // Main table
        html += "<table class=\"pf-data-table\">";
        html += renderHeader();
        html += renderBody();
        html += "</table>";

        // Footer with paging
        html += renderFooter();

        html += "</div>";
        return html;
    }

    std::string renderHeader() {
        std::string html = "<thead><tr>";
        if (selectable_) {
            html += "<th class=\"col-select\"><input type=\"checkbox\" class=\"select-all\" " +
                std::string(selectedIndices_.size() == rows_.size() ? "checked" : "") + "></th>";
        }
        if (expandable_) {
            html += "<th class=\"col-expand\"></th>";
        }
        for (size_t i = 0; i < columns_.size(); ++i) {
            bool sorted = columns_[i].getProperty() == sortProperty_;
            html += columns_[i].renderHeader(sorted, sortAscending_);
        }
        html += "</tr></thead>";
        return html;
    }

    std::string renderBody() {
        std::string html = "<tbody>";
        size_t start = currentPage_ * pageSize_;
        size_t end = std::min(start + pageSize_, rows_.size());

        for (size_t i = start; i < end; ++i) {
            const RowType& row = rows_[i];

            std::string rowClass = rowClassProvider_ ? rowClassProvider_(row, i) : "";
            bool selected = std::find(selectedIndices_.begin(), selectedIndices_.end(), i) != selectedIndices_.end();
            if (selected) rowClass += " selected";

            html += "<tr class=\"" + rowClass + "\">";

            if (selectable_) {
                html += "<td class=\"col-select\"><input type=\"checkbox\" class=\"row-select\" " +
                    std::string(selected ? "checked" : "") + " data-row-idx=\"" + std::to_string(i) + "\"></td>";
            }

            if (expandable_) {
                html += "<td class=\"col-expand\"><button class=\"btn-expand\" data-row-idx=\"" +
                    std::to_string(i) + "\">+</button></td>";
            }

            for (size_t j = 0; j < columns_.size(); ++j) {
                html += "<td";
                if (!columns_[j].getAlign().empty())
                    html += " style=\"text-align:" + columns_[j].getAlign() + ";\"";
                if (!columns_[j].getCssClass().empty())
                    html += " class=\"" + columns_[j].getCssClass() + "\"";
                html += ">";
                if (cellRenderer_) {
                    html += cellRenderer_(row, i, j);
                } else {
                    html += "&nbsp;";
                }
                html += "</td>";
            }

            html += "</tr>";

            // Expanded row content
            if (expandable_ && expandedRowRenderer_) {
                html += "<tr class=\"expanded-row\" data-row-idx=\"" + std::to_string(i) +
                    "\" style=\"display:none;\"><td colspan=\"" +
                    std::to_string(columns_.size() + (selectable_ ? 1 : 0) + (expandable_ ? 1 : 0)) + "\">";
                html += expandedRowRenderer_(row);
                html += "</td></tr>";
            }
        }

        html += "</tbody>";
        return html;
    }

    std::string renderInfoBar() {
        std::string html = "<div class=\"pf-table-info\">";
        size_t start = currentPage_ * pageSize_ + 1;
        size_t end = std::min(start + pageSize_ - 1, rows_.size());
        if (rows_.empty()) {
            html += "<span>No entries found</span>";
        } else {
            html += "<span>Showing " + std::to_string(start) + " to " +
                std::to_string(end) + " of " + std::to_string(rows_.size()) + " entries</span>";
        }

        if (selectable_ && !selectedIndices_.empty()) {
            html += "<span class=\"selection-info\">" + std::to_string(selectedIndices_.size()) +
                " selected</span>";
        }

        if (exportHandler_) {
            html += "<button class=\"btn btn-sm btn-export\" onclick=\"exportTable()\">Export CSV</button>";
        }

        html += "</div>";
        return html;
    }

    std::string renderFooter() {
        std::string html = "<div class=\"pf-table-footer\">";
        size_t totalPages = getTotalPages();

        if (totalPages > 1) {
            html += "<div class=\"pf-pagination\">";
            html += "<ul class=\"pagination-list\">";

            // First
            if (currentPage_ > 0) {
                html += "<li><a href=\"?page=0\">First</a></li>";
            } else {
                html += "<li class=\"disabled\"><span>First</span></li>";
            }

            // Prev
            if (currentPage_ > 0) {
                html += "<li><a href=\"?page=" + std::to_string(currentPage_ - 1) + "\">Prev</a></li>";
            } else {
                html += "<li class=\"disabled\"><span>Prev</span></li>";
            }

            // Page numbers
            size_t windowStart = std::max(size_t(0), currentPage_ > 2 ? currentPage_ - 2 : 0);
            size_t windowEnd = std::min(totalPages, windowStart + 5);
            if (windowEnd - windowStart < 5 && windowStart > 0) {
                windowStart = std::max(size_t(0), windowEnd - 5);
            }

            for (size_t p = windowStart; p < windowEnd; ++p) {
                if (p == currentPage_) {
                    html += "<li class=\"active\"><span>" + std::to_string(p + 1) + "</span></li>";
                } else {
                    html += "<li><a href=\"?page=" + std::to_string(p) + "\">" +
                        std::to_string(p + 1) + "</a></li>";
                }
            }

            // Next
            if (currentPage_ + 1 < totalPages) {
                html += "<li><a href=\"?page=" + std::to_string(currentPage_ + 1) + "\">Next</a></li>";
            } else {
                html += "<li class=\"disabled\"><span>Next</span></li>";
            }

            // Last
            if (currentPage_ + 1 < totalPages) {
                html += "<li><a href=\"?page=" + std::to_string(totalPages - 1) + "\">Last</a></li>";
            } else {
                html += "<li class=\"disabled\"><span>Last</span></li>";
            }

            html += "</ul>";
            html += "</div>";
        }

        html += "</div>";
        return html;
    }

private:
    size_t getColumnIndex(const std::string& property) const {
        for (size_t i = 0; i < columns_.size(); ++i) {
            if (columns_[i].getProperty() == property) return i;
        }
        return 0;
    }

    std::string id_;
    std::vector<DataTableColumn> columns_;
    std::vector<RowType> rows_;
    CellRenderer cellRenderer_;
    RowClassProvider rowClassProvider_;
    std::string sortProperty_;
    bool sortAscending_ = true;
    size_t pageSize_ = 25;
    size_t currentPage_ = 0;
    bool selectable_ = false;
    std::vector<size_t> selectedIndices_;
    SelectionHandler selectionHandler_;
    bool expandable_ = false;
    ExpandedRowRenderer expandedRowRenderer_;
    ExportHandler exportHandler_;
};

} // namespace org::projectforge::wicket
