/////////////////////////////////////////////////////////////////////////////
// (C) 2001-2026 Micromata GmbH - GPL v3
/////////////////////////////////////////////////////////////////////////////
#pragma once
#include <string>
#include <vector>
#include <memory>
namespace org::projectforge::common::html {
class HtmlElement;
class HtmlTable {
public:
    HtmlTable();
    HtmlTable& setCaption(const std::string& caption);
    HtmlTable& addHeaderCell(const std::string& content);
    HtmlTable& addHeaderCells(const std::vector<std::string>& headers);
    HtmlTable& addCell(const std::string& content);
    HtmlTable& newRow();
    std::shared_ptr<HtmlElement> build();
private:
    std::string caption_;
    std::vector<std::string> headers_;
    std::vector<std::vector<std::string>> rows_;
    std::vector<std::string> currentRow_;
};
}
