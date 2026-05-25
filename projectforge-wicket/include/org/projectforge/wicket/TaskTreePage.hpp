// ProjectForge C++ port — GPL v3
#pragma once
#include "org/projectforge/wicket/WicketModule.hpp"
#include <vector>
#include <map>

namespace org::projectforge::wicket {

struct TreeNode {
    int64_t id;
    std::string label;
    std::vector<TreeNode> children;
    bool expanded = false;
    std::string icon;
    nlohmann::json toJson() const {
        nlohmann::json j; j["id"]=id; j["label"]=label; j["expanded"]=expanded;
        if(!icon.empty())j["icon"]=icon;
        if(!children.empty()){nlohmann::json c=nlohmann::json::array();for(auto&ch:children)c.push_back(ch.toJson());j["children"]=c;}
        return j;
    }
};

class TaskTreePage : public BasePage {
public:
    TaskTreePage() : BasePage("ProjectForge - Task Tree", "Task Tree") {
        treeRoot_ = buildTree();
    }
    
    TreeNode buildTree() {
        TreeNode root; root.id=0; root.label="Root"; root.expanded=true;
        return root;
    }
    
    std::string render() override {
        addComponent(std::make_shared<Label>("treeView", "Tree: Task Tree"));
        return BasePage::render();
    }
private:
    TreeNode treeRoot_;
};

} // namespace
