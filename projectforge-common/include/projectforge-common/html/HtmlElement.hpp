/////////////////////////////////////////////////////////////////////////////
// (C) 2001-2026 Micromata GmbH - GPL v3
/////////////////////////////////////////////////////////////////////////////
#pragma once
#include <string>
#include <vector>
#include <map>
#include <memory>
namespace org::projectforge::common::html {
class HtmlElement {
public:
    explicit HtmlElement(const std::string& tag);
    virtual ~HtmlElement() = default;
    HtmlElement& addAttribute(const std::string& name, const std::string& value);
    HtmlElement& setClass(const std::string& cssClass);
    HtmlElement& setId(const std::string& id);
    HtmlElement& appendChild(std::shared_ptr<HtmlElement> child);
    const std::string& getTag() const { return tag_; }
    const std::map<std::string,std::string>& getAttributes() const { return attrs_; }
    const std::vector<std::shared_ptr<HtmlElement>>& getChildren() const { return children_; }
    virtual std::string toString() const;
protected:
    std::string tag_;
    std::map<std::string,std::string> attrs_;
    std::vector<std::shared_ptr<HtmlElement>> children_;
};
}
