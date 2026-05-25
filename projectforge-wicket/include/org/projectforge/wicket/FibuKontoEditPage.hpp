// ProjectForge C++ port — GPL v3
#pragma once
#include "org/projectforge/wicket/WicketModule.hpp"
#include <string>
#include <vector>
#include <map>

namespace org::projectforge::wicket {

class FibuKontoEditPage : public BaseEditPage {
public:
    FibuKontoEditPage(int64_t id = -1) : BaseEditPage("ProjectForge - Edit Account", "Edit Account"), entityId_(id) {
        buildForm();
    }
    
    void buildForm() {
        if (entityId_ >= 0) {
            loadEntity(entityId_);
        }
        addFields();
        addButton("submit", "Save");
        addButton("cancel", "Cancel");
    }
    
    void loadEntity(int64_t id) {
        // Load from DAO - placeholder for real implementation
    }
    
    void addFields() {
        for (const auto& field : getFieldNames()) {
            addTextField(field, field + "Label:", "");
        }
    }
    
    static std::vector<std::string> getFieldNames() {
        return { "number", "name", "description", "type", "active" };
    }
    
    std::string render() override {
        return BaseEditPage::render();
    }
    
private:
    int64_t entityId_;
};

} // namespace
