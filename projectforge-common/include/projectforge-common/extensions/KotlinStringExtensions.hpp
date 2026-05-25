/////////////////////////////////////////////////////////////////////////////
// (C) 2001-2026 Micromata GmbH - GPL v3
/////////////////////////////////////////////////////////////////////////////
#pragma once
#include <string>
#include <vector>
#include <optional>
namespace org::projectforge::common::extensions {
std::string substringBefore(const std::string& str, const std::string& delimiter);
std::string substringAfter(const std::string& str, const std::string& delimiter);
std::string substringBeforeLast(const std::string& str, const std::string& delimiter);
std::string substringAfterLast(const std::string& str, const std::string& delimiter);
bool containsIgnoreCase(const std::string& str, const std::string& search);
bool equalsIgnoreCase(const std::string& str, const std::string& other);
std::string replaceAll(const std::string& str, const std::string& oldStr, const std::string& newStr);
std::string removePrefix(const std::string& str, const std::string& prefix);
std::string removeSuffix(const std::string& str, const std::string& suffix);
std::vector<std::string> splitByChar(const std::string& str, char delimiter);
std::string trim(const std::string& str);
std::string toLowerCase(const std::string& str);
std::string toUpperCase(const std::string& str);
std::string capitalize(const std::string& str);
std::string decapitalize(const std::string& str);
bool isBlank(const std::string& str);
bool isNotBlank(const std::string& str);
std::string abbreviate(const std::string& str, int maxWidth);
std::string normalizeSpace(const std::string& str);
std::string stripAccents(const std::string& str);
}
