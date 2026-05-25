// ProjectForge C++ port — GPL v3 — www.projectforge.org
#pragma once
#include "HtmlElement.hpp"
#include <string>
#include <vector>

namespace org::projectforge::common::html {

class CssClass {
public:
    static HtmlElement& primary(HtmlElement& e) { return e.cls("primary"); }
    static HtmlElement& secondary(HtmlElement& e) { return e.cls("secondary"); }
    static HtmlElement& success(HtmlElement& e) { return e.cls("success"); }
    static HtmlElement& danger(HtmlElement& e) { return e.cls("danger"); }
    static HtmlElement& warning(HtmlElement& e) { return e.cls("warning"); }
    static HtmlElement& info(HtmlElement& e) { return e.cls("info"); }
    static HtmlElement& active(HtmlElement& e) { return e.cls("active"); }
    static HtmlElement& hidden(HtmlElement& e) { return e.cls("hidden"); }
    static HtmlElement& textCenter(HtmlElement& e) { return e.cls("text-center"); }
    static HtmlElement& textRight(HtmlElement& e) { return e.cls("text-right"); }
};

class HtmlDocument {
public:
    HtmlDocument(const std::string& title = "ProjectForge") : title_(title) {}

    void setTitle(const std::string& t) { title_ = t; }
    void addStylesheet(const std::string& href) { stylesheets_.push_back(href); }
    void addScript(const std::string& src) { scripts_.push_back(src); }
    void setBody(HtmlElement body) { body_ = std::move(body); }
    HtmlElement& body() { return body_; }

    std::string render() const {
        std::ostringstream ss;
        ss << "<!DOCTYPE html>\n<html>\n<head>\n";
        ss << "<meta charset=\"utf-8\">\n";
        ss << "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">\n";
        ss << "<title>" << title_ << "</title>\n";
        for (const auto& css : stylesheets_) ss << "<link rel=\"stylesheet\" href=\"" << css << "\">\n";
        ss << "</head>\n<body>\n";
        ss << body_.render();
        ss << "\n";
        for (const auto& js : scripts_) ss << "<script src=\"" << js << "\"></script>\n";
        ss << "</body>\n</html>";
        return ss.str();
    }

private:
    std::string title_;
    std::vector<std::string> stylesheets_, scripts_;
    HtmlElement body_{"body"};
};
}