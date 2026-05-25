/////////////////////////////////////////////////////////////////////////////
// (C) 2001-2026 Micromata GmbH - GPL v3
/////////////////////////////////////////////////////////////////////////////
#pragma once
#include <string>
#include <vector>
namespace org::projectforge::common::html {
class CssClass {
public:
    CssClass& add(const std::string& cssClass);
    CssClass& addIf(bool condition, const std::string& cssClass);
    std::string toString() const;
    bool isEmpty() const { return classes_.empty(); }
private:
    std::vector<std::string> classes_;
};
}
