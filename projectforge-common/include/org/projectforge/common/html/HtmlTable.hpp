// ProjectForge C++ port — GPL v3 — www.projectforge.org
#pragma once
#include "HtmlElement.hpp"
#include <vector>
#include <string>

namespace org::projectforge::common::html {

class HtmlTable {
public:
    HtmlTable() : table_(HtmlElement::table()) {}

    HtmlTable& id(const std::string& id) { table_.id(id); return *this; }
    HtmlTable& cls(const std::string& c) { table_.cls(c); return *this; }
    HtmlTable& style(const std::string& s) { table_.style(s); return *this; }

    HtmlTable& addHeaderRow(const std::vector<std::string>& headers) {
        auto thead = HtmlElement("thead");
        auto tr = HtmlElement("tr");
        for (const auto& h : headers) tr.addChild(HtmlElement::th(h));
        thead.addChild(tr);
        table_.addChild(thead);
        return *this;
    }

    HtmlTable& addRow(const std::vector<HtmlElement>& cells) {
        auto tr = HtmlElement("tr");
        for (const auto& c : cells) tr.addChild(HtmlElement::td().addChild(c));
        table_.addChild(tr);
        return *this;
    }

    HtmlTable& addDataRow(const std::vector<std::string>& cells, const std::string& rowClass = "") {
        auto tr = HtmlElement("tr");
        if (!rowClass.empty()) tr.cls(rowClass);
        for (const auto& c : cells) tr.addChild(HtmlElement("td", c));
        table_.addChild(tr);
        return *this;
    }

    std::string render() const { return table_.render(); }

private:
    HtmlElement table_;
};
}