// ProjectForge C++ port — GPL v3 — www.projectforge.org
#pragma once
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <optional>

namespace org::projectforge::common::html {

class HtmlElement {
public:
    HtmlElement(const std::string& tag = "div") : tag_(tag) {}
    HtmlElement(const std::string& tag, const std::string& text) : tag_(tag), text_(text) {}

    HtmlElement& id(const std::string& id) { attrs_["id"] = id; return *this; }
    HtmlElement& cls(const std::string& c) { attrs_["class"] = attrs_["class"] + " " + c; return *this; }
    HtmlElement& attr(const std::string& k, const std::string& v) { attrs_[k] = v; return *this; }
    HtmlElement& text(const std::string& t) { text_ = t; return *this; }
    HtmlElement& style(const std::string& s) { attrs_["style"] = s; return *this; }
    HtmlElement& href(const std::string& h) { attrs_["href"] = h; return *this; }
    HtmlElement& src(const std::string& s) { attrs_["src"] = s; return *this; }
    HtmlElement& title(const std::string& t) { attrs_["title"] = t; return *this; }
    HtmlElement& name(const std::string& n) { attrs_["name"] = n; return *this; }
    HtmlElement& value(const std::string& v) { attrs_["value"] = v; return *this; }
    HtmlElement& type(const std::string& t) { attrs_["type"] = t; return *this; }
    HtmlElement& placeholder(const std::string& p) { attrs_["placeholder"] = p; return *this; }
    HtmlElement& disabled(bool d = true) { if(d) attrs_["disabled"] = "disabled"; return *this; }
    HtmlElement& checked(bool c = true) { if(c) attrs_["checked"] = "checked"; return *this; }
    HtmlElement& selected(bool s = true) { if(s) attrs_["selected"] = "selected"; return *this; }
    HtmlElement& readonly(bool r = true) { if(r) attrs_["readonly"] = "readonly"; return *this; }

    HtmlElement& addChild(const HtmlElement& child) { children_.push_back(child); return *this; }

    std::string render() const {
        std::ostringstream ss;
        renderTo(ss, 0);
        return ss.str();
    }

    void renderTo(std::ostringstream& ss, int indent = 0) const {
        std::string pad(indent * 2, ' ');
        ss << pad << "<" << tag_;
        for (const auto& [k, v] : attrs_) {
            if (!v.empty()) ss << " " << k << "=\"" << v << "\"";
        }
        if (children_.empty() && text_.empty() && !isVoidElement()) {
            ss << "></" << tag_ << ">";
        } else if (children_.empty() && text_.empty()) {
            ss << " />";
        } else {
            ss << ">";
            if (!text_.empty()) ss << text_;
            if (!children_.empty()) {
                ss << "\n";
                for (const auto& c : children_) c.renderTo(ss, indent + 1);
                ss << pad;
            }
            ss << "</" << tag_ << ">";
        }
    }

    const std::string& getTag() const { return tag_; }
    const std::string& getText() const { return text_; }
    const std::vector<HtmlElement>& getChildren() const { return children_; }
    const std::map<std::string, std::string>& getAttributes() const { return attrs_; }

    static HtmlElement div() { return HtmlElement("div"); }
    static HtmlElement span() { return HtmlElement("span"); }
    static HtmlElement p(const std::string& text = "") { return HtmlElement("p", text); }
    static HtmlElement a(const std::string& href, const std::string& text = "") { return HtmlElement("a", text).href(href); }
    static HtmlElement img(const std::string& src) { return HtmlElement("img").src(src); }
    static HtmlElement input(const std::string& type = "text") { return HtmlElement("input").type(type); }
    static HtmlElement button(const std::string& text = "") { return HtmlElement("button", text); }
    static HtmlElement h1(const std::string& text = "") { return HtmlElement("h1", text); }
    static HtmlElement h2(const std::string& text = "") { return HtmlElement("h2", text); }
    static HtmlElement h3(const std::string& text = "") { return HtmlElement("h3", text); }
    static HtmlElement h4(const std::string& text = "") { return HtmlElement("h4", text); }
    static HtmlElement h5(const std::string& text = "") { return HtmlElement("h5", text); }
    static HtmlElement h6(const std::string& text = "") { return HtmlElement("h6", text); }
    static HtmlElement ul() { return HtmlElement("ul"); }
    static HtmlElement ol() { return HtmlElement("ol"); }
    static HtmlElement li(const std::string& text = "") { return HtmlElement("li", text); }
    static HtmlElement form(const std::string& action = "") { return HtmlElement("form").attr("action", action).attr("method", "post"); }
    static HtmlElement table() { return HtmlElement("table"); }
    static HtmlElement tr() { return HtmlElement("tr"); }
    static HtmlElement td(const std::string& text = "") { return HtmlElement("td", text); }
    static HtmlElement th(const std::string& text = "") { return HtmlElement("th", text); }
    static HtmlElement label(const std::string& text = "") { return HtmlElement("label", text); }
    static HtmlElement select(const std::string& name = "") { return HtmlElement("select").name(name); }
    static HtmlElement option(const std::string& value, const std::string& text = "") { return HtmlElement("option", text).value(value); }
    static HtmlElement textarea(const std::string& name = "") { return HtmlElement("textarea").name(name); }
    static HtmlElement br() { return HtmlElement("br"); }
    static HtmlElement hr() { return HtmlElement("hr"); }
    static HtmlElement script() { return HtmlElement("script"); }
    static HtmlElement link() { return HtmlElement("link"); }
    static HtmlElement meta() { return HtmlElement("meta"); }
    static HtmlElement nav() { return HtmlElement("nav"); }
    static HtmlElement header() { return HtmlElement("header"); }
    static HtmlElement footer() { return HtmlElement("footer"); }
    static HtmlElement section() { return HtmlElement("section"); }
    static HtmlElement article() { return HtmlElement("article"); }
    static HtmlElement aside() { return HtmlElement("aside"); }
    static HtmlElement main() { return HtmlElement("main"); }

private:
    std::string tag_, text_;
    std::map<std::string, std::string> attrs_;
    std::vector<HtmlElement> children_;

    bool isVoidElement() const {
        static const std::vector<std::string> voids = {"br","hr","img","input","meta","link"};
        return std::find(voids.begin(), voids.end(), tag_) != voids.end();
    }
};
}