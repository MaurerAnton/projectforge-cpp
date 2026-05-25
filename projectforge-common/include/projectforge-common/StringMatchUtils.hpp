/////////////////////////////////////////////////////////////////////////////
// (C) 2001-2026 Micromata GmbH - GPL v3
/////////////////////////////////////////////////////////////////////////////
#pragma once
#include <string>
#include <vector>
namespace org::projectforge::common {
class StringMatchUtils {
public:
    static bool wildcardMatch(const std::string& text, const std::string& pattern);
    static bool containsAny(const std::string& text, const std::vector<std::string>& searches);
    static int levenshteinDistance(const std::string& s1, const std::string& s2);
    static std::string normalizeForSearch(const std::string& str);
};
}
