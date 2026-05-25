/////////////////////////////////////////////////////////////////////////////
// (C) 2001-2026 Micromata GmbH - GPL v3
/////////////////////////////////////////////////////////////////////////////
#pragma once
#include <string>
#include <memory>
namespace org::projectforge::common::html {
class HtmlElement;
class HtmlDocument {
public:
    HtmlDocument();
    HtmlDocument& setTitle(const std::string& title);
    HtmlDocument& addHeadElement(std::shared_ptr<HtmlElement> elem);
    HtmlDocument& addBodyElement(std::shared_ptr<HtmlElement> elem);
    HtmlDocument& addCssLink(const std::string& href);
    HtmlDocument& addJsLink(const std::string& src);
    std::string toString() const;
private:
    std::string title_;
    std::vector<std::shared_ptr<HtmlElement>> headElements_;
    std::vector<std::shared_ptr<HtmlElement>> bodyElements_;
};
}
