// ProjectForge C++ port — GPL v3

#pragma once
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <spdlog/spdlog.h>
#include <nlohmann/json.hpp>
namespace com { namespace projectforge { namespace ui { namespace extended {
using json = nlohmann::json;
inline std::string esc(const std::string& s) { std::string r; for(char c:s){switch(c){case'&':r+="&amp;";break;case'<':r+="&lt;";break;case'>':r+="&gt;";break;case'"':r+="&quot;";break;default:r+=c;}}return r; }
inline std::string tag(const std::string& t,const std::string& c=""){ return"<"+t+">"+c+"</"+t+">"; }
class UIComponent1 {
public:
    UIComponent1(const std::string& id="comp1") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-1\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 1</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 1</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="1"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent2 {
public:
    UIComponent2(const std::string& id="comp2") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-2\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 2</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 2</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="2"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent3 {
public:
    UIComponent3(const std::string& id="comp3") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-3\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 3</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 3</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="3"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent4 {
public:
    UIComponent4(const std::string& id="comp4") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-4\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 4</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 4</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="4"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent5 {
public:
    UIComponent5(const std::string& id="comp5") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-5\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 5</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 5</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="5"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent6 {
public:
    UIComponent6(const std::string& id="comp6") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-6\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 6</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 6</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="6"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent7 {
public:
    UIComponent7(const std::string& id="comp7") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-7\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 7</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 7</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="7"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent8 {
public:
    UIComponent8(const std::string& id="comp8") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-8\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 8</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 8</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="8"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent9 {
public:
    UIComponent9(const std::string& id="comp9") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-9\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 9</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 9</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="9"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent10 {
public:
    UIComponent10(const std::string& id="comp10") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-10\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 10</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 10</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="10"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent11 {
public:
    UIComponent11(const std::string& id="comp11") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-11\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 11</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 11</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="11"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent12 {
public:
    UIComponent12(const std::string& id="comp12") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-12\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 12</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 12</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="12"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent13 {
public:
    UIComponent13(const std::string& id="comp13") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-13\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 13</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 13</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="13"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent14 {
public:
    UIComponent14(const std::string& id="comp14") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-14\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 14</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 14</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="14"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent15 {
public:
    UIComponent15(const std::string& id="comp15") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-15\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 15</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 15</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="15"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent16 {
public:
    UIComponent16(const std::string& id="comp16") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-16\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 16</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 16</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="16"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent17 {
public:
    UIComponent17(const std::string& id="comp17") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-17\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 17</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 17</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="17"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent18 {
public:
    UIComponent18(const std::string& id="comp18") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-18\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 18</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 18</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="18"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent19 {
public:
    UIComponent19(const std::string& id="comp19") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-19\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 19</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 19</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="19"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent20 {
public:
    UIComponent20(const std::string& id="comp20") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-20\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 20</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 20</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="20"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent21 {
public:
    UIComponent21(const std::string& id="comp21") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-21\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 21</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 21</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="21"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent22 {
public:
    UIComponent22(const std::string& id="comp22") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-22\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 22</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 22</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="22"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent23 {
public:
    UIComponent23(const std::string& id="comp23") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-23\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 23</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 23</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="23"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent24 {
public:
    UIComponent24(const std::string& id="comp24") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-24\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 24</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 24</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="24"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent25 {
public:
    UIComponent25(const std::string& id="comp25") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-25\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 25</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 25</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="25"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent26 {
public:
    UIComponent26(const std::string& id="comp26") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-26\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 26</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 26</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="26"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent27 {
public:
    UIComponent27(const std::string& id="comp27") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-27\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 27</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 27</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="27"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent28 {
public:
    UIComponent28(const std::string& id="comp28") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-28\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 28</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 28</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="28"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent29 {
public:
    UIComponent29(const std::string& id="comp29") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-29\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 29</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 29</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="29"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent30 {
public:
    UIComponent30(const std::string& id="comp30") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-30\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 30</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 30</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="30"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent31 {
public:
    UIComponent31(const std::string& id="comp31") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-31\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 31</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 31</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="31"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent32 {
public:
    UIComponent32(const std::string& id="comp32") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-32\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 32</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 32</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="32"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent33 {
public:
    UIComponent33(const std::string& id="comp33") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-33\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 33</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 33</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="33"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent34 {
public:
    UIComponent34(const std::string& id="comp34") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-34\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 34</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 34</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="34"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent35 {
public:
    UIComponent35(const std::string& id="comp35") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-35\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 35</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 35</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="35"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent36 {
public:
    UIComponent36(const std::string& id="comp36") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-36\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 36</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 36</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="36"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent37 {
public:
    UIComponent37(const std::string& id="comp37") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-37\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 37</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 37</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="37"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent38 {
public:
    UIComponent38(const std::string& id="comp38") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-38\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 38</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 38</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="38"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent39 {
public:
    UIComponent39(const std::string& id="comp39") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-39\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 39</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 39</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="39"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent40 {
public:
    UIComponent40(const std::string& id="comp40") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-40\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 40</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 40</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="40"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent41 {
public:
    UIComponent41(const std::string& id="comp41") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-41\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 41</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 41</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="41"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent42 {
public:
    UIComponent42(const std::string& id="comp42") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-42\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 42</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 42</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="42"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent43 {
public:
    UIComponent43(const std::string& id="comp43") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-43\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 43</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 43</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="43"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent44 {
public:
    UIComponent44(const std::string& id="comp44") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-44\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 44</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 44</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="44"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent45 {
public:
    UIComponent45(const std::string& id="comp45") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-45\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 45</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 45</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="45"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent46 {
public:
    UIComponent46(const std::string& id="comp46") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-46\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 46</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 46</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="46"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent47 {
public:
    UIComponent47(const std::string& id="comp47") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-47\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 47</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 47</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="47"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent48 {
public:
    UIComponent48(const std::string& id="comp48") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-48\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 48</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 48</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="48"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent49 {
public:
    UIComponent49(const std::string& id="comp49") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-49\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 49</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 49</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="49"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent50 {
public:
    UIComponent50(const std::string& id="comp50") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-50\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 50</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 50</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="50"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent51 {
public:
    UIComponent51(const std::string& id="comp51") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-51\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 51</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 51</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="51"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent52 {
public:
    UIComponent52(const std::string& id="comp52") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-52\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 52</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 52</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="52"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent53 {
public:
    UIComponent53(const std::string& id="comp53") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-53\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 53</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 53</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="53"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent54 {
public:
    UIComponent54(const std::string& id="comp54") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-54\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 54</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 54</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="54"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent55 {
public:
    UIComponent55(const std::string& id="comp55") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-55\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 55</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 55</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="55"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent56 {
public:
    UIComponent56(const std::string& id="comp56") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-56\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 56</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 56</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="56"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent57 {
public:
    UIComponent57(const std::string& id="comp57") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-57\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 57</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 57</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="57"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent58 {
public:
    UIComponent58(const std::string& id="comp58") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-58\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 58</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 58</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="58"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent59 {
public:
    UIComponent59(const std::string& id="comp59") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-59\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 59</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 59</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="59"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent60 {
public:
    UIComponent60(const std::string& id="comp60") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-60\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 60</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 60</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="60"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent61 {
public:
    UIComponent61(const std::string& id="comp61") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-61\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 61</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 61</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="61"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent62 {
public:
    UIComponent62(const std::string& id="comp62") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-62\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 62</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 62</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="62"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent63 {
public:
    UIComponent63(const std::string& id="comp63") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-63\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 63</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 63</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="63"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent64 {
public:
    UIComponent64(const std::string& id="comp64") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-64\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 64</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 64</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="64"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent65 {
public:
    UIComponent65(const std::string& id="comp65") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-65\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 65</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 65</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="65"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent66 {
public:
    UIComponent66(const std::string& id="comp66") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-66\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 66</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 66</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="66"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent67 {
public:
    UIComponent67(const std::string& id="comp67") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-67\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 67</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 67</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="67"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent68 {
public:
    UIComponent68(const std::string& id="comp68") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-68\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 68</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 68</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="68"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent69 {
public:
    UIComponent69(const std::string& id="comp69") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-69\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 69</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 69</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="69"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent70 {
public:
    UIComponent70(const std::string& id="comp70") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-70\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 70</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 70</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="70"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent71 {
public:
    UIComponent71(const std::string& id="comp71") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-71\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 71</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 71</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="71"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent72 {
public:
    UIComponent72(const std::string& id="comp72") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-72\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 72</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 72</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="72"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent73 {
public:
    UIComponent73(const std::string& id="comp73") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-73\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 73</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 73</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="73"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent74 {
public:
    UIComponent74(const std::string& id="comp74") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-74\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 74</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 74</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="74"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent75 {
public:
    UIComponent75(const std::string& id="comp75") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-75\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 75</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 75</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="75"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent76 {
public:
    UIComponent76(const std::string& id="comp76") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-76\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 76</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 76</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="76"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent77 {
public:
    UIComponent77(const std::string& id="comp77") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-77\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 77</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 77</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="77"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent78 {
public:
    UIComponent78(const std::string& id="comp78") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-78\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 78</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 78</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="78"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent79 {
public:
    UIComponent79(const std::string& id="comp79") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-79\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 79</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 79</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="79"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent80 {
public:
    UIComponent80(const std::string& id="comp80") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-80\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 80</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 80</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="80"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent81 {
public:
    UIComponent81(const std::string& id="comp81") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-81\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 81</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 81</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="81"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent82 {
public:
    UIComponent82(const std::string& id="comp82") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-82\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 82</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 82</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="82"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent83 {
public:
    UIComponent83(const std::string& id="comp83") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-83\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 83</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 83</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="83"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent84 {
public:
    UIComponent84(const std::string& id="comp84") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-84\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 84</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 84</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="84"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent85 {
public:
    UIComponent85(const std::string& id="comp85") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-85\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 85</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 85</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="85"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent86 {
public:
    UIComponent86(const std::string& id="comp86") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-86\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 86</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 86</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="86"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent87 {
public:
    UIComponent87(const std::string& id="comp87") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-87\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 87</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 87</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="87"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent88 {
public:
    UIComponent88(const std::string& id="comp88") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-88\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 88</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 88</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="88"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent89 {
public:
    UIComponent89(const std::string& id="comp89") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-89\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 89</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 89</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="89"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent90 {
public:
    UIComponent90(const std::string& id="comp90") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-90\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 90</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 90</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="90"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent91 {
public:
    UIComponent91(const std::string& id="comp91") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-91\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 91</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 91</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="91"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent92 {
public:
    UIComponent92(const std::string& id="comp92") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-92\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 92</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 92</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="92"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent93 {
public:
    UIComponent93(const std::string& id="comp93") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-93\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 93</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 93</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="93"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent94 {
public:
    UIComponent94(const std::string& id="comp94") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-94\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 94</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 94</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="94"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent95 {
public:
    UIComponent95(const std::string& id="comp95") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-95\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 95</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 95</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="95"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent96 {
public:
    UIComponent96(const std::string& id="comp96") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-96\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 96</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 96</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="96"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent97 {
public:
    UIComponent97(const std::string& id="comp97") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-97\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 97</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 97</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="97"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent98 {
public:
    UIComponent98(const std::string& id="comp98") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-98\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 98</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 98</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="98"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent99 {
public:
    UIComponent99(const std::string& id="comp99") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-99\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 99</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 99</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="99"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent100 {
public:
    UIComponent100(const std::string& id="comp100") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-100\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 100</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 100</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="100"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent101 {
public:
    UIComponent101(const std::string& id="comp101") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-101\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 101</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 101</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="101"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent102 {
public:
    UIComponent102(const std::string& id="comp102") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-102\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 102</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 102</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="102"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent103 {
public:
    UIComponent103(const std::string& id="comp103") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-103\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 103</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 103</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="103"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent104 {
public:
    UIComponent104(const std::string& id="comp104") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-104\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 104</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 104</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="104"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent105 {
public:
    UIComponent105(const std::string& id="comp105") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-105\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 105</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 105</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="105"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent106 {
public:
    UIComponent106(const std::string& id="comp106") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-106\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 106</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 106</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="106"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent107 {
public:
    UIComponent107(const std::string& id="comp107") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-107\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 107</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 107</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="107"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent108 {
public:
    UIComponent108(const std::string& id="comp108") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-108\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 108</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 108</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="108"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent109 {
public:
    UIComponent109(const std::string& id="comp109") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-109\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 109</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 109</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="109"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent110 {
public:
    UIComponent110(const std::string& id="comp110") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-110\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 110</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 110</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="110"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent111 {
public:
    UIComponent111(const std::string& id="comp111") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-111\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 111</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 111</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="111"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent112 {
public:
    UIComponent112(const std::string& id="comp112") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-112\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 112</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 112</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="112"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent113 {
public:
    UIComponent113(const std::string& id="comp113") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-113\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 113</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 113</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="113"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent114 {
public:
    UIComponent114(const std::string& id="comp114") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-114\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 114</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 114</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="114"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent115 {
public:
    UIComponent115(const std::string& id="comp115") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-115\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 115</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 115</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="115"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent116 {
public:
    UIComponent116(const std::string& id="comp116") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-116\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 116</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 116</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="116"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent117 {
public:
    UIComponent117(const std::string& id="comp117") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-117\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 117</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 117</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="117"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent118 {
public:
    UIComponent118(const std::string& id="comp118") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-118\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 118</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 118</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="118"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent119 {
public:
    UIComponent119(const std::string& id="comp119") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-119\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 119</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 119</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="119"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent120 {
public:
    UIComponent120(const std::string& id="comp120") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-120\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 120</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 120</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="120"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent121 {
public:
    UIComponent121(const std::string& id="comp121") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-121\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 121</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 121</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="121"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent122 {
public:
    UIComponent122(const std::string& id="comp122") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-122\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 122</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 122</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="122"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent123 {
public:
    UIComponent123(const std::string& id="comp123") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-123\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 123</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 123</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="123"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent124 {
public:
    UIComponent124(const std::string& id="comp124") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-124\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 124</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 124</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="124"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent125 {
public:
    UIComponent125(const std::string& id="comp125") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-125\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 125</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 125</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="125"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent126 {
public:
    UIComponent126(const std::string& id="comp126") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-126\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 126</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 126</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="126"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent127 {
public:
    UIComponent127(const std::string& id="comp127") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-127\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 127</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 127</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="127"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent128 {
public:
    UIComponent128(const std::string& id="comp128") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-128\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 128</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 128</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="128"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent129 {
public:
    UIComponent129(const std::string& id="comp129") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-129\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 129</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 129</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="129"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent130 {
public:
    UIComponent130(const std::string& id="comp130") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-130\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 130</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 130</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="130"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent131 {
public:
    UIComponent131(const std::string& id="comp131") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-131\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 131</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 131</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="131"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent132 {
public:
    UIComponent132(const std::string& id="comp132") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-132\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 132</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 132</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="132"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent133 {
public:
    UIComponent133(const std::string& id="comp133") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-133\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 133</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 133</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="133"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent134 {
public:
    UIComponent134(const std::string& id="comp134") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-134\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 134</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 134</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="134"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent135 {
public:
    UIComponent135(const std::string& id="comp135") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-135\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 135</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 135</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="135"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent136 {
public:
    UIComponent136(const std::string& id="comp136") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-136\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 136</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 136</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="136"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent137 {
public:
    UIComponent137(const std::string& id="comp137") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-137\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 137</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 137</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="137"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent138 {
public:
    UIComponent138(const std::string& id="comp138") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-138\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 138</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 138</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="138"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent139 {
public:
    UIComponent139(const std::string& id="comp139") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-139\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 139</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 139</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="139"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent140 {
public:
    UIComponent140(const std::string& id="comp140") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-140\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 140</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 140</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="140"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent141 {
public:
    UIComponent141(const std::string& id="comp141") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-141\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 141</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 141</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="141"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent142 {
public:
    UIComponent142(const std::string& id="comp142") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-142\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 142</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 142</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="142"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent143 {
public:
    UIComponent143(const std::string& id="comp143") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-143\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 143</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 143</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="143"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent144 {
public:
    UIComponent144(const std::string& id="comp144") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-144\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 144</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 144</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="144"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent145 {
public:
    UIComponent145(const std::string& id="comp145") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-145\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 145</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 145</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="145"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent146 {
public:
    UIComponent146(const std::string& id="comp146") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-146\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 146</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 146</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="146"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent147 {
public:
    UIComponent147(const std::string& id="comp147") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-147\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 147</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 147</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="147"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent148 {
public:
    UIComponent148(const std::string& id="comp148") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-148\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 148</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 148</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="148"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent149 {
public:
    UIComponent149(const std::string& id="comp149") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-149\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 149</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 149</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="149"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent150 {
public:
    UIComponent150(const std::string& id="comp150") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-150\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 150</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 150</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="150"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent151 {
public:
    UIComponent151(const std::string& id="comp151") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-151\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 151</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 151</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="151"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent152 {
public:
    UIComponent152(const std::string& id="comp152") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-152\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 152</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 152</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="152"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent153 {
public:
    UIComponent153(const std::string& id="comp153") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-153\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 153</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 153</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="153"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent154 {
public:
    UIComponent154(const std::string& id="comp154") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-154\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 154</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 154</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="154"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent155 {
public:
    UIComponent155(const std::string& id="comp155") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-155\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 155</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 155</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="155"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent156 {
public:
    UIComponent156(const std::string& id="comp156") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-156\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 156</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 156</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="156"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent157 {
public:
    UIComponent157(const std::string& id="comp157") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-157\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 157</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 157</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="157"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent158 {
public:
    UIComponent158(const std::string& id="comp158") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-158\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 158</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 158</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="158"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent159 {
public:
    UIComponent159(const std::string& id="comp159") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-159\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 159</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 159</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="159"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent160 {
public:
    UIComponent160(const std::string& id="comp160") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-160\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 160</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 160</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="160"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent161 {
public:
    UIComponent161(const std::string& id="comp161") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-161\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 161</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 161</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="161"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent162 {
public:
    UIComponent162(const std::string& id="comp162") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-162\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 162</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 162</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="162"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent163 {
public:
    UIComponent163(const std::string& id="comp163") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-163\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 163</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 163</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="163"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent164 {
public:
    UIComponent164(const std::string& id="comp164") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-164\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 164</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 164</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="164"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent165 {
public:
    UIComponent165(const std::string& id="comp165") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-165\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 165</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 165</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="165"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent166 {
public:
    UIComponent166(const std::string& id="comp166") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-166\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 166</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 166</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="166"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent167 {
public:
    UIComponent167(const std::string& id="comp167") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-167\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 167</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 167</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="167"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent168 {
public:
    UIComponent168(const std::string& id="comp168") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-168\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 168</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 168</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="168"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent169 {
public:
    UIComponent169(const std::string& id="comp169") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-169\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 169</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 169</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="169"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent170 {
public:
    UIComponent170(const std::string& id="comp170") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-170\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 170</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 170</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="170"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent171 {
public:
    UIComponent171(const std::string& id="comp171") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-171\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 171</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 171</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="171"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent172 {
public:
    UIComponent172(const std::string& id="comp172") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-172\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 172</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 172</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="172"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent173 {
public:
    UIComponent173(const std::string& id="comp173") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-173\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 173</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 173</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="173"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent174 {
public:
    UIComponent174(const std::string& id="comp174") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-174\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 174</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 174</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="174"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent175 {
public:
    UIComponent175(const std::string& id="comp175") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-175\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 175</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 175</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="175"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent176 {
public:
    UIComponent176(const std::string& id="comp176") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-176\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 176</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 176</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="176"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent177 {
public:
    UIComponent177(const std::string& id="comp177") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-177\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 177</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 177</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="177"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent178 {
public:
    UIComponent178(const std::string& id="comp178") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-178\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 178</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 178</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="178"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent179 {
public:
    UIComponent179(const std::string& id="comp179") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-179\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 179</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 179</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="179"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent180 {
public:
    UIComponent180(const std::string& id="comp180") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-180\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 180</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 180</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="180"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent181 {
public:
    UIComponent181(const std::string& id="comp181") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-181\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 181</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 181</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="181"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent182 {
public:
    UIComponent182(const std::string& id="comp182") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-182\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 182</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 182</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="182"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent183 {
public:
    UIComponent183(const std::string& id="comp183") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-183\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 183</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 183</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="183"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent184 {
public:
    UIComponent184(const std::string& id="comp184") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-184\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 184</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 184</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="184"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent185 {
public:
    UIComponent185(const std::string& id="comp185") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-185\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 185</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 185</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="185"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent186 {
public:
    UIComponent186(const std::string& id="comp186") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-186\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 186</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 186</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="186"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent187 {
public:
    UIComponent187(const std::string& id="comp187") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-187\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 187</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 187</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="187"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent188 {
public:
    UIComponent188(const std::string& id="comp188") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-188\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 188</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 188</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="188"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent189 {
public:
    UIComponent189(const std::string& id="comp189") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-189\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 189</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 189</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="189"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent190 {
public:
    UIComponent190(const std::string& id="comp190") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-190\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 190</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 190</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="190"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent191 {
public:
    UIComponent191(const std::string& id="comp191") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-191\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 191</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 191</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="191"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent192 {
public:
    UIComponent192(const std::string& id="comp192") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-192\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 192</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 192</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="192"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent193 {
public:
    UIComponent193(const std::string& id="comp193") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-193\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 193</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 193</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="193"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent194 {
public:
    UIComponent194(const std::string& id="comp194") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-194\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 194</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 194</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="194"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent195 {
public:
    UIComponent195(const std::string& id="comp195") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-195\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 195</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 195</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="195"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent196 {
public:
    UIComponent196(const std::string& id="comp196") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-196\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 196</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 196</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="196"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent197 {
public:
    UIComponent197(const std::string& id="comp197") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-197\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 197</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 197</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="197"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent198 {
public:
    UIComponent198(const std::string& id="comp198") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-198\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 198</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 198</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="198"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent199 {
public:
    UIComponent199(const std::string& id="comp199") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-199\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 199</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 199</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="199"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent200 {
public:
    UIComponent200(const std::string& id="comp200") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-200\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 200</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 200</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="200"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent201 {
public:
    UIComponent201(const std::string& id="comp201") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-201\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 201</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 201</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="201"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent202 {
public:
    UIComponent202(const std::string& id="comp202") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-202\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 202</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 202</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="202"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent203 {
public:
    UIComponent203(const std::string& id="comp203") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-203\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 203</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 203</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="203"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent204 {
public:
    UIComponent204(const std::string& id="comp204") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-204\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 204</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 204</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="204"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent205 {
public:
    UIComponent205(const std::string& id="comp205") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-205\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 205</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 205</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="205"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent206 {
public:
    UIComponent206(const std::string& id="comp206") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-206\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 206</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 206</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="206"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent207 {
public:
    UIComponent207(const std::string& id="comp207") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-207\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 207</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 207</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="207"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent208 {
public:
    UIComponent208(const std::string& id="comp208") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-208\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 208</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 208</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="208"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent209 {
public:
    UIComponent209(const std::string& id="comp209") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-209\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 209</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 209</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="209"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent210 {
public:
    UIComponent210(const std::string& id="comp210") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-210\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 210</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 210</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="210"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent211 {
public:
    UIComponent211(const std::string& id="comp211") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-211\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 211</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 211</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="211"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent212 {
public:
    UIComponent212(const std::string& id="comp212") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-212\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 212</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 212</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="212"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent213 {
public:
    UIComponent213(const std::string& id="comp213") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-213\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 213</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 213</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="213"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent214 {
public:
    UIComponent214(const std::string& id="comp214") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-214\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 214</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 214</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="214"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent215 {
public:
    UIComponent215(const std::string& id="comp215") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-215\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 215</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 215</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="215"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent216 {
public:
    UIComponent216(const std::string& id="comp216") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-216\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 216</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 216</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="216"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent217 {
public:
    UIComponent217(const std::string& id="comp217") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-217\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 217</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 217</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="217"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent218 {
public:
    UIComponent218(const std::string& id="comp218") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-218\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 218</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 218</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="218"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent219 {
public:
    UIComponent219(const std::string& id="comp219") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-219\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 219</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 219</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="219"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent220 {
public:
    UIComponent220(const std::string& id="comp220") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-220\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 220</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 220</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="220"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent221 {
public:
    UIComponent221(const std::string& id="comp221") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-221\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 221</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 221</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="221"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent222 {
public:
    UIComponent222(const std::string& id="comp222") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-222\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 222</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 222</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="222"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent223 {
public:
    UIComponent223(const std::string& id="comp223") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-223\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 223</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 223</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="223"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent224 {
public:
    UIComponent224(const std::string& id="comp224") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-224\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 224</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 224</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="224"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent225 {
public:
    UIComponent225(const std::string& id="comp225") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-225\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 225</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 225</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="225"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent226 {
public:
    UIComponent226(const std::string& id="comp226") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-226\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 226</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 226</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="226"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent227 {
public:
    UIComponent227(const std::string& id="comp227") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-227\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 227</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 227</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="227"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent228 {
public:
    UIComponent228(const std::string& id="comp228") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-228\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 228</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 228</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="228"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent229 {
public:
    UIComponent229(const std::string& id="comp229") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-229\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 229</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 229</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="229"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent230 {
public:
    UIComponent230(const std::string& id="comp230") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-230\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 230</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 230</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="230"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent231 {
public:
    UIComponent231(const std::string& id="comp231") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-231\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 231</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 231</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="231"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent232 {
public:
    UIComponent232(const std::string& id="comp232") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-232\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 232</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 232</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="232"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent233 {
public:
    UIComponent233(const std::string& id="comp233") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-233\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 233</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 233</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="233"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent234 {
public:
    UIComponent234(const std::string& id="comp234") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-234\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 234</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 234</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="234"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent235 {
public:
    UIComponent235(const std::string& id="comp235") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-235\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 235</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 235</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="235"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent236 {
public:
    UIComponent236(const std::string& id="comp236") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-236\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 236</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 236</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="236"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent237 {
public:
    UIComponent237(const std::string& id="comp237") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-237\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 237</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 237</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="237"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent238 {
public:
    UIComponent238(const std::string& id="comp238") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-238\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 238</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 238</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="238"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent239 {
public:
    UIComponent239(const std::string& id="comp239") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-239\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 239</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 239</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="239"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent240 {
public:
    UIComponent240(const std::string& id="comp240") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-240\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 240</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 240</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="240"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent241 {
public:
    UIComponent241(const std::string& id="comp241") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-241\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 241</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 241</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="241"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent242 {
public:
    UIComponent242(const std::string& id="comp242") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-242\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 242</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 242</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="242"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent243 {
public:
    UIComponent243(const std::string& id="comp243") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-243\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 243</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 243</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="243"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent244 {
public:
    UIComponent244(const std::string& id="comp244") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-244\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 244</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 244</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="244"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent245 {
public:
    UIComponent245(const std::string& id="comp245") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-245\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 245</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 245</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="245"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent246 {
public:
    UIComponent246(const std::string& id="comp246") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-246\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 246</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 246</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="246"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent247 {
public:
    UIComponent247(const std::string& id="comp247") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-247\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 247</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 247</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="247"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent248 {
public:
    UIComponent248(const std::string& id="comp248") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-248\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 248</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 248</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="248"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent249 {
public:
    UIComponent249(const std::string& id="comp249") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-249\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 249</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 249</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="249"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent250 {
public:
    UIComponent250(const std::string& id="comp250") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-250\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 250</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 250</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="250"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent251 {
public:
    UIComponent251(const std::string& id="comp251") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-251\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 251</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 251</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="251"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent252 {
public:
    UIComponent252(const std::string& id="comp252") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-252\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 252</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 252</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="252"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent253 {
public:
    UIComponent253(const std::string& id="comp253") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-253\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 253</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 253</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="253"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent254 {
public:
    UIComponent254(const std::string& id="comp254") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-254\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 254</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 254</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="254"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent255 {
public:
    UIComponent255(const std::string& id="comp255") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-255\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 255</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 255</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="255"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent256 {
public:
    UIComponent256(const std::string& id="comp256") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-256\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 256</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 256</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="256"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent257 {
public:
    UIComponent257(const std::string& id="comp257") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-257\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 257</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 257</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="257"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent258 {
public:
    UIComponent258(const std::string& id="comp258") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-258\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 258</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 258</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="258"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent259 {
public:
    UIComponent259(const std::string& id="comp259") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-259\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 259</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 259</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="259"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent260 {
public:
    UIComponent260(const std::string& id="comp260") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-260\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 260</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 260</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="260"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent261 {
public:
    UIComponent261(const std::string& id="comp261") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-261\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 261</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 261</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="261"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent262 {
public:
    UIComponent262(const std::string& id="comp262") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-262\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 262</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 262</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="262"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent263 {
public:
    UIComponent263(const std::string& id="comp263") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-263\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 263</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 263</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="263"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent264 {
public:
    UIComponent264(const std::string& id="comp264") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-264\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 264</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 264</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="264"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent265 {
public:
    UIComponent265(const std::string& id="comp265") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-265\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 265</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 265</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="265"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent266 {
public:
    UIComponent266(const std::string& id="comp266") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-266\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 266</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 266</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="266"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent267 {
public:
    UIComponent267(const std::string& id="comp267") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-267\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 267</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 267</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="267"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent268 {
public:
    UIComponent268(const std::string& id="comp268") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-268\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 268</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 268</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="268"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent269 {
public:
    UIComponent269(const std::string& id="comp269") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-269\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 269</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 269</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="269"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent270 {
public:
    UIComponent270(const std::string& id="comp270") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-270\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 270</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 270</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="270"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent271 {
public:
    UIComponent271(const std::string& id="comp271") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-271\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 271</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 271</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="271"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent272 {
public:
    UIComponent272(const std::string& id="comp272") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-272\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 272</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 272</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="272"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent273 {
public:
    UIComponent273(const std::string& id="comp273") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-273\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 273</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 273</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="273"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent274 {
public:
    UIComponent274(const std::string& id="comp274") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-274\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 274</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 274</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="274"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent275 {
public:
    UIComponent275(const std::string& id="comp275") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-275\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 275</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 275</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="275"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent276 {
public:
    UIComponent276(const std::string& id="comp276") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-276\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 276</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 276</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="276"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent277 {
public:
    UIComponent277(const std::string& id="comp277") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-277\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 277</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 277</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="277"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent278 {
public:
    UIComponent278(const std::string& id="comp278") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-278\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 278</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 278</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="278"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent279 {
public:
    UIComponent279(const std::string& id="comp279") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-279\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 279</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 279</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="279"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent280 {
public:
    UIComponent280(const std::string& id="comp280") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-280\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 280</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 280</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="280"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent281 {
public:
    UIComponent281(const std::string& id="comp281") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-281\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 281</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 281</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="281"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent282 {
public:
    UIComponent282(const std::string& id="comp282") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-282\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 282</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 282</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="282"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent283 {
public:
    UIComponent283(const std::string& id="comp283") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-283\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 283</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 283</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="283"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent284 {
public:
    UIComponent284(const std::string& id="comp284") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-284\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 284</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 284</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="284"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent285 {
public:
    UIComponent285(const std::string& id="comp285") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-285\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 285</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 285</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="285"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent286 {
public:
    UIComponent286(const std::string& id="comp286") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-286\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 286</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 286</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="286"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent287 {
public:
    UIComponent287(const std::string& id="comp287") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-287\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 287</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 287</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="287"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent288 {
public:
    UIComponent288(const std::string& id="comp288") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-288\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 288</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 288</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="288"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent289 {
public:
    UIComponent289(const std::string& id="comp289") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-289\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 289</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 289</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="289"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent290 {
public:
    UIComponent290(const std::string& id="comp290") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-290\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 290</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 290</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="290"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent291 {
public:
    UIComponent291(const std::string& id="comp291") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-291\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 291</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 291</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="291"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent292 {
public:
    UIComponent292(const std::string& id="comp292") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-292\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 292</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 292</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="292"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent293 {
public:
    UIComponent293(const std::string& id="comp293") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-293\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 293</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 293</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="293"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent294 {
public:
    UIComponent294(const std::string& id="comp294") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-294\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 294</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 294</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="294"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent295 {
public:
    UIComponent295(const std::string& id="comp295") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-295\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 295</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 295</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="295"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent296 {
public:
    UIComponent296(const std::string& id="comp296") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-296\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 296</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 296</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="296"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent297 {
public:
    UIComponent297(const std::string& id="comp297") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-297\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 297</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 297</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="297"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent298 {
public:
    UIComponent298(const std::string& id="comp298") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-298\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 298</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 298</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="298"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent299 {
public:
    UIComponent299(const std::string& id="comp299") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-299\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 299</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 299</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="299"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent300 {
public:
    UIComponent300(const std::string& id="comp300") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-300\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 300</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 300</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="300"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent301 {
public:
    UIComponent301(const std::string& id="comp301") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-301\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 301</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 301</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="301"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent302 {
public:
    UIComponent302(const std::string& id="comp302") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-302\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 302</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 302</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="302"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent303 {
public:
    UIComponent303(const std::string& id="comp303") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-303\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 303</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 303</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="303"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent304 {
public:
    UIComponent304(const std::string& id="comp304") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-304\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 304</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 304</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="304"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent305 {
public:
    UIComponent305(const std::string& id="comp305") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-305\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 305</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 305</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="305"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent306 {
public:
    UIComponent306(const std::string& id="comp306") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-306\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 306</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 306</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="306"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent307 {
public:
    UIComponent307(const std::string& id="comp307") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-307\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 307</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 307</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="307"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent308 {
public:
    UIComponent308(const std::string& id="comp308") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-308\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 308</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 308</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="308"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent309 {
public:
    UIComponent309(const std::string& id="comp309") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-309\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 309</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 309</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="309"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent310 {
public:
    UIComponent310(const std::string& id="comp310") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-310\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 310</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 310</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="310"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent311 {
public:
    UIComponent311(const std::string& id="comp311") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-311\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 311</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 311</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="311"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent312 {
public:
    UIComponent312(const std::string& id="comp312") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-312\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 312</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 312</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="312"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent313 {
public:
    UIComponent313(const std::string& id="comp313") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-313\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 313</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 313</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="313"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent314 {
public:
    UIComponent314(const std::string& id="comp314") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-314\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 314</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 314</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="314"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent315 {
public:
    UIComponent315(const std::string& id="comp315") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-315\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 315</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 315</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="315"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent316 {
public:
    UIComponent316(const std::string& id="comp316") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-316\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 316</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 316</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="316"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent317 {
public:
    UIComponent317(const std::string& id="comp317") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-317\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 317</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 317</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="317"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent318 {
public:
    UIComponent318(const std::string& id="comp318") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-318\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 318</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 318</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="318"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent319 {
public:
    UIComponent319(const std::string& id="comp319") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-319\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 319</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 319</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="319"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent320 {
public:
    UIComponent320(const std::string& id="comp320") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-320\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 320</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 320</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="320"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent321 {
public:
    UIComponent321(const std::string& id="comp321") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-321\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 321</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 321</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="321"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent322 {
public:
    UIComponent322(const std::string& id="comp322") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-322\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 322</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 322</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="322"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent323 {
public:
    UIComponent323(const std::string& id="comp323") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-323\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 323</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 323</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="323"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent324 {
public:
    UIComponent324(const std::string& id="comp324") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-324\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 324</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 324</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="324"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent325 {
public:
    UIComponent325(const std::string& id="comp325") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-325\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 325</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 325</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="325"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent326 {
public:
    UIComponent326(const std::string& id="comp326") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-326\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 326</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 326</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="326"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent327 {
public:
    UIComponent327(const std::string& id="comp327") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-327\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 327</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 327</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="327"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent328 {
public:
    UIComponent328(const std::string& id="comp328") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-328\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 328</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 328</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="328"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent329 {
public:
    UIComponent329(const std::string& id="comp329") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-329\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 329</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 329</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="329"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent330 {
public:
    UIComponent330(const std::string& id="comp330") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-330\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 330</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 330</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="330"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent331 {
public:
    UIComponent331(const std::string& id="comp331") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-331\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 331</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 331</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="331"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent332 {
public:
    UIComponent332(const std::string& id="comp332") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-332\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 332</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 332</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="332"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent333 {
public:
    UIComponent333(const std::string& id="comp333") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-333\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 333</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 333</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="333"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent334 {
public:
    UIComponent334(const std::string& id="comp334") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-334\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 334</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 334</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="334"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent335 {
public:
    UIComponent335(const std::string& id="comp335") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-335\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 335</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 335</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="335"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent336 {
public:
    UIComponent336(const std::string& id="comp336") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-336\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 336</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 336</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="336"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent337 {
public:
    UIComponent337(const std::string& id="comp337") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-337\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 337</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 337</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="337"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent338 {
public:
    UIComponent338(const std::string& id="comp338") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-338\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 338</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 338</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="338"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent339 {
public:
    UIComponent339(const std::string& id="comp339") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-339\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 339</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 339</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="339"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent340 {
public:
    UIComponent340(const std::string& id="comp340") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-340\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 340</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 340</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="340"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent341 {
public:
    UIComponent341(const std::string& id="comp341") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-341\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 341</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 341</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="341"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent342 {
public:
    UIComponent342(const std::string& id="comp342") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-342\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 342</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 342</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="342"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent343 {
public:
    UIComponent343(const std::string& id="comp343") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-343\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 343</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 343</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="343"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent344 {
public:
    UIComponent344(const std::string& id="comp344") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-344\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 344</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 344</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="344"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent345 {
public:
    UIComponent345(const std::string& id="comp345") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-345\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 345</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 345</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="345"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent346 {
public:
    UIComponent346(const std::string& id="comp346") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-346\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 346</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 346</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="346"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent347 {
public:
    UIComponent347(const std::string& id="comp347") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-347\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 347</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 347</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="347"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent348 {
public:
    UIComponent348(const std::string& id="comp348") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-348\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 348</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 348</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="348"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent349 {
public:
    UIComponent349(const std::string& id="comp349") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-349\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 349</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 349</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="349"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent350 {
public:
    UIComponent350(const std::string& id="comp350") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-350\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 350</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 350</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="350"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent351 {
public:
    UIComponent351(const std::string& id="comp351") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-351\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 351</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 351</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="351"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent352 {
public:
    UIComponent352(const std::string& id="comp352") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-352\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 352</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 352</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="352"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent353 {
public:
    UIComponent353(const std::string& id="comp353") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-353\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 353</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 353</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="353"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent354 {
public:
    UIComponent354(const std::string& id="comp354") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-354\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 354</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 354</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="354"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent355 {
public:
    UIComponent355(const std::string& id="comp355") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-355\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 355</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 355</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="355"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent356 {
public:
    UIComponent356(const std::string& id="comp356") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-356\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 356</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 356</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="356"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent357 {
public:
    UIComponent357(const std::string& id="comp357") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-357\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 357</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 357</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="357"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent358 {
public:
    UIComponent358(const std::string& id="comp358") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-358\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 358</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 358</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="358"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent359 {
public:
    UIComponent359(const std::string& id="comp359") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-359\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 359</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 359</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="359"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent360 {
public:
    UIComponent360(const std::string& id="comp360") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-360\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 360</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 360</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="360"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent361 {
public:
    UIComponent361(const std::string& id="comp361") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-361\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 361</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 361</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="361"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent362 {
public:
    UIComponent362(const std::string& id="comp362") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-362\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 362</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 362</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="362"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent363 {
public:
    UIComponent363(const std::string& id="comp363") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-363\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 363</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 363</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="363"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent364 {
public:
    UIComponent364(const std::string& id="comp364") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-364\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 364</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 364</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="364"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent365 {
public:
    UIComponent365(const std::string& id="comp365") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-365\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 365</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 365</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="365"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent366 {
public:
    UIComponent366(const std::string& id="comp366") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-366\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 366</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 366</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="366"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent367 {
public:
    UIComponent367(const std::string& id="comp367") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-367\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 367</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 367</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="367"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent368 {
public:
    UIComponent368(const std::string& id="comp368") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-368\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 368</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 368</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="368"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent369 {
public:
    UIComponent369(const std::string& id="comp369") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-369\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 369</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 369</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="369"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent370 {
public:
    UIComponent370(const std::string& id="comp370") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-370\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 370</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 370</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="370"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent371 {
public:
    UIComponent371(const std::string& id="comp371") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-371\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 371</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 371</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="371"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent372 {
public:
    UIComponent372(const std::string& id="comp372") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-372\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 372</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 372</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="372"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent373 {
public:
    UIComponent373(const std::string& id="comp373") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-373\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 373</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 373</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="373"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent374 {
public:
    UIComponent374(const std::string& id="comp374") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-374\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 374</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 374</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="374"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent375 {
public:
    UIComponent375(const std::string& id="comp375") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-375\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 375</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 375</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="375"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent376 {
public:
    UIComponent376(const std::string& id="comp376") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-376\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 376</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 376</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="376"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent377 {
public:
    UIComponent377(const std::string& id="comp377") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-377\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 377</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 377</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="377"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent378 {
public:
    UIComponent378(const std::string& id="comp378") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-378\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 378</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 378</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="378"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent379 {
public:
    UIComponent379(const std::string& id="comp379") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-379\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 379</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 379</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="379"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent380 {
public:
    UIComponent380(const std::string& id="comp380") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-380\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 380</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 380</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="380"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent381 {
public:
    UIComponent381(const std::string& id="comp381") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-381\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 381</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 381</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="381"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent382 {
public:
    UIComponent382(const std::string& id="comp382") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-382\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 382</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 382</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="382"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent383 {
public:
    UIComponent383(const std::string& id="comp383") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-383\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 383</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 383</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="383"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent384 {
public:
    UIComponent384(const std::string& id="comp384") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-384\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 384</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 384</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="384"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent385 {
public:
    UIComponent385(const std::string& id="comp385") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-385\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 385</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 385</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="385"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent386 {
public:
    UIComponent386(const std::string& id="comp386") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-386\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 386</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 386</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="386"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent387 {
public:
    UIComponent387(const std::string& id="comp387") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-387\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 387</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 387</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="387"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent388 {
public:
    UIComponent388(const std::string& id="comp388") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-388\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 388</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 388</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="388"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent389 {
public:
    UIComponent389(const std::string& id="comp389") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-389\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 389</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 389</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="389"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent390 {
public:
    UIComponent390(const std::string& id="comp390") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-390\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 390</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 390</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="390"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent391 {
public:
    UIComponent391(const std::string& id="comp391") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-391\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 391</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 391</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="391"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent392 {
public:
    UIComponent392(const std::string& id="comp392") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-392\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 392</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 392</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="392"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent393 {
public:
    UIComponent393(const std::string& id="comp393") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-393\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 393</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 393</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="393"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent394 {
public:
    UIComponent394(const std::string& id="comp394") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-394\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 394</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 394</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="394"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent395 {
public:
    UIComponent395(const std::string& id="comp395") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-395\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 395</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 395</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="395"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent396 {
public:
    UIComponent396(const std::string& id="comp396") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-396\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 396</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 396</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="396"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent397 {
public:
    UIComponent397(const std::string& id="comp397") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-397\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 397</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 397</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="397"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent398 {
public:
    UIComponent398(const std::string& id="comp398") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-398\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 398</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 398</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="398"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent399 {
public:
    UIComponent399(const std::string& id="comp399") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-399\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 399</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 399</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="399"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent400 {
public:
    UIComponent400(const std::string& id="comp400") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-400\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 400</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 400</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="400"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent401 {
public:
    UIComponent401(const std::string& id="comp401") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-401\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 401</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 401</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="401"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent402 {
public:
    UIComponent402(const std::string& id="comp402") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-402\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 402</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 402</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="402"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent403 {
public:
    UIComponent403(const std::string& id="comp403") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-403\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 403</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 403</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="403"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent404 {
public:
    UIComponent404(const std::string& id="comp404") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-404\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 404</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 404</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="404"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent405 {
public:
    UIComponent405(const std::string& id="comp405") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-405\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 405</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 405</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="405"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent406 {
public:
    UIComponent406(const std::string& id="comp406") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-406\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 406</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 406</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="406"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent407 {
public:
    UIComponent407(const std::string& id="comp407") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-407\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 407</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 407</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="407"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent408 {
public:
    UIComponent408(const std::string& id="comp408") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-408\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 408</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 408</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="408"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent409 {
public:
    UIComponent409(const std::string& id="comp409") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-409\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 409</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 409</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="409"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent410 {
public:
    UIComponent410(const std::string& id="comp410") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-410\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 410</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 410</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="410"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent411 {
public:
    UIComponent411(const std::string& id="comp411") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-411\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 411</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 411</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="411"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent412 {
public:
    UIComponent412(const std::string& id="comp412") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-412\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 412</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 412</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="412"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent413 {
public:
    UIComponent413(const std::string& id="comp413") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-413\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 413</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 413</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="413"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent414 {
public:
    UIComponent414(const std::string& id="comp414") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-414\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 414</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 414</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="414"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent415 {
public:
    UIComponent415(const std::string& id="comp415") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-415\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 415</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 415</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="415"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent416 {
public:
    UIComponent416(const std::string& id="comp416") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-416\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 416</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 416</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="416"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent417 {
public:
    UIComponent417(const std::string& id="comp417") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-417\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 417</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 417</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="417"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent418 {
public:
    UIComponent418(const std::string& id="comp418") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-418\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 418</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 418</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="418"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent419 {
public:
    UIComponent419(const std::string& id="comp419") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-419\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 419</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 419</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="419"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent420 {
public:
    UIComponent420(const std::string& id="comp420") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-420\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 420</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 420</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="420"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent421 {
public:
    UIComponent421(const std::string& id="comp421") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-421\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 421</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 421</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="421"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent422 {
public:
    UIComponent422(const std::string& id="comp422") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-422\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 422</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 422</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="422"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent423 {
public:
    UIComponent423(const std::string& id="comp423") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-423\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 423</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 423</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="423"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent424 {
public:
    UIComponent424(const std::string& id="comp424") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-424\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 424</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 424</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="424"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent425 {
public:
    UIComponent425(const std::string& id="comp425") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-425\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 425</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 425</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="425"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent426 {
public:
    UIComponent426(const std::string& id="comp426") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-426\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 426</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 426</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="426"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent427 {
public:
    UIComponent427(const std::string& id="comp427") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-427\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 427</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 427</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="427"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent428 {
public:
    UIComponent428(const std::string& id="comp428") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-428\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 428</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 428</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="428"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent429 {
public:
    UIComponent429(const std::string& id="comp429") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-429\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 429</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 429</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="429"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent430 {
public:
    UIComponent430(const std::string& id="comp430") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-430\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 430</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 430</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="430"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent431 {
public:
    UIComponent431(const std::string& id="comp431") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-431\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 431</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 431</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="431"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent432 {
public:
    UIComponent432(const std::string& id="comp432") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-432\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 432</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 432</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="432"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent433 {
public:
    UIComponent433(const std::string& id="comp433") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-433\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 433</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 433</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="433"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent434 {
public:
    UIComponent434(const std::string& id="comp434") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-434\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 434</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 434</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="434"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent435 {
public:
    UIComponent435(const std::string& id="comp435") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-435\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 435</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 435</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="435"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent436 {
public:
    UIComponent436(const std::string& id="comp436") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-436\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 436</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 436</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="436"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent437 {
public:
    UIComponent437(const std::string& id="comp437") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-437\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 437</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 437</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="437"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent438 {
public:
    UIComponent438(const std::string& id="comp438") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-438\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 438</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 438</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="438"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent439 {
public:
    UIComponent439(const std::string& id="comp439") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-439\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 439</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 439</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="439"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent440 {
public:
    UIComponent440(const std::string& id="comp440") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-440\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 440</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 440</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="440"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent441 {
public:
    UIComponent441(const std::string& id="comp441") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-441\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 441</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 441</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="441"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent442 {
public:
    UIComponent442(const std::string& id="comp442") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-442\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 442</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 442</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="442"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent443 {
public:
    UIComponent443(const std::string& id="comp443") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-443\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 443</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 443</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="443"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent444 {
public:
    UIComponent444(const std::string& id="comp444") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-444\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 444</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 444</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="444"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent445 {
public:
    UIComponent445(const std::string& id="comp445") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-445\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 445</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 445</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="445"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent446 {
public:
    UIComponent446(const std::string& id="comp446") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-446\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 446</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 446</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="446"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent447 {
public:
    UIComponent447(const std::string& id="comp447") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-447\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 447</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 447</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="447"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent448 {
public:
    UIComponent448(const std::string& id="comp448") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-448\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 448</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 448</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="448"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent449 {
public:
    UIComponent449(const std::string& id="comp449") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-449\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 449</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 449</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="449"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent450 {
public:
    UIComponent450(const std::string& id="comp450") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-450\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 450</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 450</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="450"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent451 {
public:
    UIComponent451(const std::string& id="comp451") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-451\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 451</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 451</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="451"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent452 {
public:
    UIComponent452(const std::string& id="comp452") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-452\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 452</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 452</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="452"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent453 {
public:
    UIComponent453(const std::string& id="comp453") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-453\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 453</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 453</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="453"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent454 {
public:
    UIComponent454(const std::string& id="comp454") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-454\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 454</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 454</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="454"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent455 {
public:
    UIComponent455(const std::string& id="comp455") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-455\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 455</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 455</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="455"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent456 {
public:
    UIComponent456(const std::string& id="comp456") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-456\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 456</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 456</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="456"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent457 {
public:
    UIComponent457(const std::string& id="comp457") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-457\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 457</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 457</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="457"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent458 {
public:
    UIComponent458(const std::string& id="comp458") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-458\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 458</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 458</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="458"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent459 {
public:
    UIComponent459(const std::string& id="comp459") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-459\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 459</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 459</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="459"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent460 {
public:
    UIComponent460(const std::string& id="comp460") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-460\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 460</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 460</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="460"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent461 {
public:
    UIComponent461(const std::string& id="comp461") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-461\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 461</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 461</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="461"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent462 {
public:
    UIComponent462(const std::string& id="comp462") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-462\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 462</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 462</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="462"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent463 {
public:
    UIComponent463(const std::string& id="comp463") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-463\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 463</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 463</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="463"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent464 {
public:
    UIComponent464(const std::string& id="comp464") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-464\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 464</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 464</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="464"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent465 {
public:
    UIComponent465(const std::string& id="comp465") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-465\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 465</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 465</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="465"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent466 {
public:
    UIComponent466(const std::string& id="comp466") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-466\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 466</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 466</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="466"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent467 {
public:
    UIComponent467(const std::string& id="comp467") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-467\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 467</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 467</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="467"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent468 {
public:
    UIComponent468(const std::string& id="comp468") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-468\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 468</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 468</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="468"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent469 {
public:
    UIComponent469(const std::string& id="comp469") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-469\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 469</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 469</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="469"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent470 {
public:
    UIComponent470(const std::string& id="comp470") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-470\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 470</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 470</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="470"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent471 {
public:
    UIComponent471(const std::string& id="comp471") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-471\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 471</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 471</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="471"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent472 {
public:
    UIComponent472(const std::string& id="comp472") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-472\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 472</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 472</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="472"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent473 {
public:
    UIComponent473(const std::string& id="comp473") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-473\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 473</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 473</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="473"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent474 {
public:
    UIComponent474(const std::string& id="comp474") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-474\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 474</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 474</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="474"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent475 {
public:
    UIComponent475(const std::string& id="comp475") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-475\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 475</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 475</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="475"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent476 {
public:
    UIComponent476(const std::string& id="comp476") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-476\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 476</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 476</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="476"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent477 {
public:
    UIComponent477(const std::string& id="comp477") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-477\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 477</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 477</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="477"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent478 {
public:
    UIComponent478(const std::string& id="comp478") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-478\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 478</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 478</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="478"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent479 {
public:
    UIComponent479(const std::string& id="comp479") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-479\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 479</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 479</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="479"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent480 {
public:
    UIComponent480(const std::string& id="comp480") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-480\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 480</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 480</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="480"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent481 {
public:
    UIComponent481(const std::string& id="comp481") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-481\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 481</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 481</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="481"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent482 {
public:
    UIComponent482(const std::string& id="comp482") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-482\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 482</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 482</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="482"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent483 {
public:
    UIComponent483(const std::string& id="comp483") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-483\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 483</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 483</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="483"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent484 {
public:
    UIComponent484(const std::string& id="comp484") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-484\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 484</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 484</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="484"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent485 {
public:
    UIComponent485(const std::string& id="comp485") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-485\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 485</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 485</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="485"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent486 {
public:
    UIComponent486(const std::string& id="comp486") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-486\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 486</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 486</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="486"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent487 {
public:
    UIComponent487(const std::string& id="comp487") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-487\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 487</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 487</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="487"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent488 {
public:
    UIComponent488(const std::string& id="comp488") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-488\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 488</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 488</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="488"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent489 {
public:
    UIComponent489(const std::string& id="comp489") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-489\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 489</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 489</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="489"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent490 {
public:
    UIComponent490(const std::string& id="comp490") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-490\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 490</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 490</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="490"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent491 {
public:
    UIComponent491(const std::string& id="comp491") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-491\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 491</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 491</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="491"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent492 {
public:
    UIComponent492(const std::string& id="comp492") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-492\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 492</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 492</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="492"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent493 {
public:
    UIComponent493(const std::string& id="comp493") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-493\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 493</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 493</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="493"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent494 {
public:
    UIComponent494(const std::string& id="comp494") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-494\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 494</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 494</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="494"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent495 {
public:
    UIComponent495(const std::string& id="comp495") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-495\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 495</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 495</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="495"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent496 {
public:
    UIComponent496(const std::string& id="comp496") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-496\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 496</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 496</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="496"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent497 {
public:
    UIComponent497(const std::string& id="comp497") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-497\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 497</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 497</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="497"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent498 {
public:
    UIComponent498(const std::string& id="comp498") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-498\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 498</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 498</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="498"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent499 {
public:
    UIComponent499(const std::string& id="comp499") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-499\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 499</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 499</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="499"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
class UIComponent500 {
public:
    UIComponent500(const std::string& id="comp500") : id_(id) {}
    std::string render(const json& data=json::object()) {
        std::ostringstream ss;
        ss << "<div class=\"component component-500\" id=\"" << esc(id_) << "\">";
        ss << "<div class=\"component-header\">Component 500</div>";
        ss << "<div class=\"component-body\">";
        if(data.contains("text")) ss << "<p>" << esc(data["text"]) << "</p>";
        else ss << "<p>Default content for component 500</p>";
        ss << "</div>";
        ss << "<div class=\"component-footer\">ID: " << esc(id_) << "</div>";
        ss << "</div>";
        return ss.str();
    }
    json toJson() const { json j; j["id"]=id_; j["type"]="500"; return j; }
    void setId(const std::string& id) { id_=id; }
    std::string getId() const { return id_; }
    void setVisible(bool v) { visible_=v; }
    bool isVisible() const { return visible_; }
    void setDisabled(bool d) { disabled_=d; }
    bool isDisabled() const { return disabled_; }
    void addCssClass(const std::string& c) { cssClasses_.push_back(c); }
    void setTooltip(const std::string& t) { tooltip_=t; }
    void setData(const json& d) { data_=d; }
    json getData() const { return data_; }
private:
    std::string id_,tooltip_;
    bool visible_=true,disabled_=false;
    std::vector<std::string> cssClasses_;
    json data_;
};
}}}} // namespace