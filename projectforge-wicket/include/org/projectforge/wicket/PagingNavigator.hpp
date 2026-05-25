#pragma once
// ProjectForge C++ Port - Paging Navigator
// Navigation component for paginated lists with configurable page sizes,
// first/last/prev/next controls, and page number windowing.

#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

namespace org::projectforge::wicket {

struct PageLink {
    std::string label;
    size_t page;
    bool enabled;
    bool isCurrent;
};

class PagingNavigator {
public:
    PagingNavigator(const std::string& id, size_t totalItems, size_t itemsPerPage = 20)
        : id_(id), totalItems_(totalItems), itemsPerPage_(itemsPerPage) {
        calculateTotalPages();
    }

    void setCurrentPage(size_t page) { currentPage_ = std::max(size_t(0), page); }
    size_t getCurrentPage() const { return currentPage_; }
    size_t getTotalPages() const { return totalPages_; }
    size_t getTotalItems() const { return totalItems_; }
    void setItemsPerPage(size_t n) {
        itemsPerPage_ = n;
        calculateTotalPages();
    }
    size_t getItemsPerPage() const { return itemsPerPage_; }

    void setPageParamName(const std::string& name) { pageParamName_ = name; }
    const std::string& getPageParamName() const { return pageParamName_; }

    std::vector<PageLink> getPageLinks(size_t windowSize = 5) const {
        std::vector<PageLink> links;

        // First
        links.push_back({"First", 0, currentPage_ > 0, false});

        // Prev
        links.push_back({"Prev", currentPage_ > 0 ? currentPage_ - 1 : 0,
                         currentPage_ > 0, false});

        // Calculate window
        size_t halfWindow = windowSize / 2;
        size_t startPage;
        if (currentPage_ < halfWindow) {
            startPage = 0;
        } else if (currentPage_ + halfWindow >= totalPages_) {
            startPage = totalPages_ > windowSize ? totalPages_ - windowSize : 0;
        } else {
            startPage = currentPage_ - halfWindow;
        }
        size_t endPage = std::min(startPage + windowSize, totalPages_);

        for (size_t p = startPage; p < endPage; ++p) {
            links.push_back({std::to_string(p + 1), p, true, p == currentPage_});
        }

        // Next
        links.push_back({"Next", std::min(currentPage_ + 1, totalPages_ > 0 ? totalPages_ - 1 : 0),
                         currentPage_ + 1 < totalPages_, false});

        // Last
        links.push_back({"Last", totalPages_ > 0 ? totalPages_ - 1 : 0,
                         currentPage_ + 1 < totalPages_, false});

        return links;
    }

    std::string render() const {
        std::string html;
        html += "<div id=\"" + id_ + "\" class=\"pf-paging-navigator\">";
        html += "<div class=\"pf-page-size-selector\">";
        html += "<select name=\"pageSize\" class=\"pf-page-size-select\" onchange=\"changePageSize(this.value)\">";
        for (int size : {10, 20, 50, 100}) {
            html += "<option value=\"" + std::to_string(size) + "\"" +
                (static_cast<int>(itemsPerPage_) == size ? " selected" : "") + ">" +
                std::to_string(size) + " per page</option>";
        }
        html += "</select></div>";

        if (totalPages_ > 1) {
            html += "<nav class=\"pf-pagination\">";
            html += "<ul class=\"pagination\">";

            auto links = getPageLinks(7);
            for (const auto& link : links) {
                html += "<li class=\"page-item";
                if (!link.enabled) html += " disabled";
                if (link.isCurrent) html += " active";
                html += "\">";

                if (link.enabled && !link.isCurrent) {
                    html += "<a class=\"page-link\" href=\"?" + pageParamName_ + "=" +
                        std::to_string(link.page) + "\">" + link.label + "</a>";
                } else {
                    html += "<span class=\"page-link\">" + link.label + "</span>";
                }
                html += "</li>";
            }

            html += "</ul>";
            html += "</nav>";
        }

        html += "<div class=\"pf-page-info\">";
        if (totalItems_ == 0) {
            html += "No items";
        } else {
            size_t first = currentPage_ * itemsPerPage_ + 1;
            size_t last = std::min(first + itemsPerPage_ - 1, totalItems_);
            html += std::to_string(first) + "-" + std::to_string(last) +
                " of " + std::to_string(totalItems_);
        }
        html += "</div>";

        html += "</div>";
        return html;
    }

    std::string renderCompact() const {
        if (totalPages_ <= 1) return "";

        std::string html = "<div class=\"pf-paging-compact\">";
        if (currentPage_ > 0) {
            html += "<a href=\"?" + pageParamName_ + "=" + std::to_string(currentPage_ - 1) +
                "\" class=\"btn btn-sm\">&laquo; Prev</a> ";
        }
        html += "<span>Page " + std::to_string(currentPage_ + 1) +
            " / " + std::to_string(totalPages_) + "</span>";
        if (currentPage_ + 1 < totalPages_) {
            html += " <a href=\"?" + pageParamName_ + "=" + std::to_string(currentPage_ + 1) +
                "\" class=\"btn btn-sm\">Next &raquo;</a>";
        }
        html += "</div>";
        return html;
    }

    size_t getStartIndex() const { return currentPage_ * itemsPerPage_; }
    size_t getEndIndex() const {
        return std::min((currentPage_ + 1) * itemsPerPage_, totalItems_);
    }

private:
    void calculateTotalPages() {
        if (itemsPerPage_ == 0) {
            totalPages_ = 1;
        } else {
            totalPages_ = (totalItems_ + itemsPerPage_ - 1) / itemsPerPage_;
        }
        if (totalPages_ == 0) totalPages_ = 1;
    }

    std::string id_;
    size_t totalItems_;
    size_t itemsPerPage_;
    size_t totalPages_ = 1;
    size_t currentPage_ = 0;
    std::string pageParamName_ = "page";
};

} // namespace org::projectforge::wicket
