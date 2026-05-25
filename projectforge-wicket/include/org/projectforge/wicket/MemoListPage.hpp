// ProjectForge C++ port — GPL v3
#pragma once
#include "org/projectforge/wicket/WicketModule.hpp"
#include <string>
#include <vector>

namespace org::projectforge::wicket {

class MemoListPage : public BaseListPage {
public:
    MemoListPage() : BaseListPage("ProjectForge - Memos", "Memos") {
        for (auto& col : getColumns()) addColumn(col);
        setPagination(0, 1);
    }
    
    void loadData() {
        addRow({}); // Placeholder - real impl loads from DAO
    }
    
    static std::vector<std::string> getColumns() {
        return { "Title", "Owner", "Updated", "Actions" };
    }
    
    std::string render() override {
        loadData();
        return BaseListPage::render();
    }
};

} // namespace
