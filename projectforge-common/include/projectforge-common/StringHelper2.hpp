/////////////////////////////////////////////////////////////////////////////
// (C) 2001-2026 Micromata GmbH - GPL v3
/////////////////////////////////////////////////////////////////////////////
#pragma once
#include <string>
namespace org::projectforge::common {
class StringHelper2 {
public:
    static std::string getWildCard(const std::vector<std::string>& strs);
    static std::string removeNonDigits(const std::string& str);
    static bool isIn(const std::string& str, const std::vector<std::string>& strings);
    static std::string listToString(const std::vector<std::string>& list, const std::string& delimiter, bool sort);
};
}
