// ProjectForge C++ port — GPL v3 — www.projectforge.org
#pragma once
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <functional>
#include <memory>
#include <nlohmann/json.hpp>

namespace org::projectforge::wicket {

// Base component class for all Wicket-like components
class Component {
public:
    Component(const std::string& id) : id_(id) {}
    virtual ~Component() = default;
    virtual std::string render() = 0;
    const std::string& getId() const { return id_; }
    void setVisible(bool v) { visible_ = v; }
    bool isVisible() const { return visible_; }
    void addCssClass(const std::string& cls) { cssClasses_.push_back(cls); }
protected:
    std::string id_;
    bool visible_ = true;
    std::vector<std::string> cssClasses_;
};

// Label component
class Label : public Component {
public:
    Label(const std::string& id, const std::string& text) : Component(id), text_(text) {}
    std::string render() override {
        if (!visible_) return "";
        return "<span id=\"" + id_ + "\">" + escape(text_) + "</span>";
    }
    void setText(const std::string& t) { text_ = t; }
private:
    std::string text_;
    static std::string escape(const std::string& s) {
        std::string r;
        for(char c:s) {
            switch(c) {
                case '&': r+="&amp;"; break;
                case '<': r+="&lt;"; break;
                case '>': r+="&gt;"; break;
                case '"': r+="&quot;"; break;
                default: r+=c;
            }
        }
        return r;
    }
};

// TextField component
class TextField : public Component {
public:
    TextField(const std::string& id, const std::string& value="") : Component(id), value_(value) {}
    std::string render() override {
        if(!visible_) return "";
        return "<input type=\"text\" id=\""+id_+"\" name=\""+id_+"\" value=\""+escape(value_)+"\">";
    }
    void setValue(const std::string& v) { value_ = v; }
    std::string getValue() const { return value_; }
private:
    std::string value_;
    static std::string escape(const std::string& s) {
        std::string r;
        for(char c:s) { if(c=='"') r+="&quot;"; else if(c=='<') r+="&lt;"; else r+=c; }
        return r;
    }
};

// DropDownChoice
class DropDownChoice : public Component {
public:
    DropDownChoice(const std::string& id) : Component(id) {}
    void addChoice(const std::string& value, const std::string& label) { choices_[value]=label; }
    void setSelected(const std::string& v) { selected_=v; }
    std::string render() override {
        if(!visible_) return "";
        std::ostringstream ss;
        ss<<"<select id=\""<<id_<<"\" name=\""<<id_<<"\">";
        for(auto&[v,l]:choices_) {
            ss<<"<option value=\""<<v<<"\"";
            if(v==selected_) ss<<" selected";
            ss<<">"<<l<<"</option>";
        }
        ss<<"</select>";
        return ss.str();
    }
private:
    std::map<std::string,std::string> choices_;
    std::string selected_;
};

// CheckBox
class CheckBox : public Component {
public:
    CheckBox(const std::string& id, bool checked=false) : Component(id), checked_(checked) {}
    std::string render() override {
        if(!visible_) return "";
        return "<input type=\"checkbox\" id=\""+id_+"\" name=\""+id_+"\""+(checked_?" checked":"")+">";
    }
    void setChecked(bool c) { checked_=c; }
    bool isChecked() const { return checked_; }
private:
    bool checked_ = false;
};

// Button
class Button : public Component {
public:
    Button(const std::string& id, const std::string& label) : Component(id), label_(label) {}
    std::string render() override {
        if(!visible_) return "";
        return "<button type=\"button\" id=\""+id_+"\">"+label_+"</button>";
    }
private:
    std::string label_;
};

// DataTable
class DataTable : public Component {
public:
    DataTable(const std::string& id) : Component(id) {}
    void addColumn(const std::string& header) { headers_.push_back(header); }
    void addRow(const std::vector<std::string>& cells) { rows_.push_back(cells); }
    std::string render() override {
        if(!visible_) return "";
        std::ostringstream ss;
        ss<<"<table id=\""<<id_<<"\" class=\"data-table\"><thead><tr>";
        for(auto& h:headers_) ss<<"<th>"<<h<<"</th>";
        ss<<"</tr></thead><tbody>";
        for(auto& row:rows_) {
            ss<<"<tr>";
            for(auto& cell:row) ss<<"<td>"<<cell<<"</td>";
            ss<<"</tr>";
        }
        ss<<"</tbody></table>";
        return ss.str();
    }
private:
    std::vector<std::string> headers_;
    std::vector<std::vector<std::string>> rows_;
};

// Navigation panel
class PagingNavigator : public Component {
public:
    PagingNavigator(const std::string& id, int currentPage, int totalPages) : Component(id), page_(currentPage), total_(totalPages) {}
    std::string render() override {
        if(!visible_ || total_<=1) return "";
        std::ostringstream ss;
        ss<<"<nav class=\"pagination\">";
        if(page_>0) ss<<"<a href=\"?page="<<(page_-1)<<"\">&laquo; Prev</a>";
        for(int i=0;i<total_&&i<10;++i) {
            if(i==page_) ss<<"<span class=\"current\">"<<(i+1)<<"</span>";
            else ss<<"<a href=\"?page="<<i<<"\">"<<(i+1)<<"</a>";
        }
        if(page_<total_-1) ss<<"<a href=\"?page="<<(page_+1)<<"\">Next &raquo;</a>";
        ss<<"</nav>";
        return ss.str();
    }
private:
    int page_, total_;
};

// Feedback panel for messages
class FeedbackPanel : public Component {
public:
    FeedbackPanel(const std::string& id) : Component(id) {}
    void info(const std::string& msg) { messages_.push_back({"info",msg}); }
    void warn(const std::string& msg) { messages_.push_back({"warning",msg}); }
    void error(const std::string& msg) { messages_.push_back({"error",msg}); }
    void success(const std::string& msg) { messages_.push_back({"success",msg}); }
    std::string render() override {
        std::ostringstream ss;
        for(auto&[type,msg]:messages_) ss<<"<div class=\"alert alert-"<<type<<"\">"<<msg<<"</div>";
        messages_.clear();
        return ss.str();
    }
private:
    std::vector<std::pair<std::string,std::string>> messages_;
};

// Form component
class Form : public Component {
public:
    Form(const std::string& id) : Component(id) {}
    void addComponent(std::shared_ptr<Component> c) { children_.push_back(c); }
    void onSubmit(std::function<void()> handler) { onSubmit_ = handler; }
    std::string render() override {
        std::ostringstream ss;
        ss<<"<form id=\""<<id_<<"\" method=\"post\">";
        for(auto& c:children_) ss<<c->render();
        ss<<"<button type=\"submit\">Submit</button>";
        ss<<"</form>";
        return ss.str();
    }
private:
    std::vector<std::shared_ptr<Component>> children_;
    std::function<void()> onSubmit_;
};

// Base page with layout
class BasePage {
public:
    BasePage(const std::string& title="ProjectForge", const std::string& pageTitle="") : title_(title), pageTitle_(pageTitle) {}
    virtual ~BasePage() = default;
    void addComponent(std::shared_ptr<Component> c) { components_.push_back(c); }
    FeedbackPanel& feedback() { return feedback_; }
    virtual std::string render() {
        std::ostringstream ss;
        ss<<"<!DOCTYPE html><html><head><meta charset=\"utf-8\">";
        ss<<"<meta name=\"viewport\" content=\"width=device-width,initial-scale=1\">";
        ss<<"<title>"<<title_<<"</title>";
        ss<<"<link rel=\"stylesheet\" href=\"/css/projectforge.css\">";
        ss<<"</head><body>";
        ss<<"<header><h1>ProjectForge</h1>";
        ss<<"<nav><a href=\"/timesheet\">Timesheet</a> ";
        ss<<"<a href=\"/tasks\">Tasks</a> <a href=\"/addresses\">Addresses</a> ";
        ss<<"<a href=\"/fibu\">Finance</a> </nav></header>";
        ss<<"<main>";
        if(!pageTitle_.empty()) ss<<"<h2>"<<pageTitle_<<"</h2>";
        ss<<feedback_.render();
        for(auto& c:components_) ss<<c->render();
        ss<<"</main><footer>ProjectForge C++ v8.2.0</footer>";
        ss<<"<script src=\"/js/projectforge.js\"></script>";
        ss<<"</body></html>";
        return ss.str();
    }
protected:
    std::string title_, pageTitle_;
    std::vector<std::shared_ptr<Component>> components_;
    FeedbackPanel feedback_{"feedback"};
};

// ListPage with DataTable
class BaseListPage : public BasePage {
public:
    BaseListPage(const std::string& title, const std::string& pageTitle) : BasePage(title, pageTitle) {
        table_ = std::make_shared<DataTable>("dataTable");
    }
    void addColumn(const std::string& h) { table_->addColumn(h); }
    void addRow(const std::vector<std::string>& r) { table_->addRow(r); }
    void setPagination(int page, int total) {
        pager_ = std::make_shared<PagingNavigator>("pager", page, total);
    }
    std::string render() override {
        addComponent(table_);
        if(pager_) addComponent(pager_);
        return BasePage::render();
    }
private:
    std::shared_ptr<DataTable> table_;
    std::shared_ptr<PagingNavigator> pager_;
};

// EditPage with Form
class BaseEditPage : public BasePage {
public:
    BaseEditPage(const std::string& title, const std::string& pageTitle) : BasePage(title, pageTitle) {
        form_ = std::make_shared<Form>("editForm");
    }
    template<typename T>
    void addField(const std::string& id, const std::string& label, const T& value);
    void addTextField(const std::string& id, const std::string& label, const std::string& value="") {
        form_->addComponent(std::make_shared<Label>(id+"Label",label));
        form_->addComponent(std::make_shared<TextField>(id, value));
    }
    void addDropDown(const std::string& id, const std::string& label, const std::map<std::string,std::string>& choices, const std::string& selected="") {
        form_->addComponent(std::make_shared<Label>(id+"Label",label));
        auto dd = std::make_shared<DropDownChoice>(id);
        for(auto&[v,l]:choices) dd->addChoice(v,l);
        if(!selected.empty()) dd->setSelected(selected);
        form_->addComponent(dd);
    }
    void addCheckBox(const std::string& id, const std::string& label, bool checked=false) {
        form_->addComponent(std::make_shared<Label>(id+"Label",label));
        form_->addComponent(std::make_shared<CheckBox>(id, checked));
    }
    void addButton(const std::string& id, const std::string& label) {
        form_->addComponent(std::make_shared<Button>(id, label));
    }
    std::string render() override {
        addComponent(form_);
        return BasePage::render();
    }
protected:
    std::shared_ptr<Form> form_;
};

} // namespace
