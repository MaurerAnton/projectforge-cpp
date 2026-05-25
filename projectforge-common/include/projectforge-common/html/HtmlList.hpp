/////////////////////////////////////////////////////////////////////////////
// (C) 2001-2026 Micromata GmbH - GPL v3
/////////////////////////////////////////////////////////////////////////////
#pragma once
#include <string>
#include <vector>
#include <memory>
namespace org::projectforge::common::html {
class HtmlElement;
class HtmlList {
public:
    HtmlList(bool ordered = false);
    HtmlList& addItem(const std::string& content);
    std::shared_ptr<HtmlElement> build();
private:
    bool ordered_;
    std::vector<std::string> items_;
};
}
