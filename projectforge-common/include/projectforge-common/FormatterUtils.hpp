/////////////////////////////////////////////////////////////////////////////
// (C) 2001-2026 Micromata GmbH - GPL v3
/////////////////////////////////////////////////////////////////////////////
#pragma once
#include <string>
#include <map>
namespace org::projectforge::common {
class FormatterUtils {
public:
    static std::string formatMessage(const std::string& pattern, const std::map<std::string,std::string>& params);
    static std::string escapeHtml(const std::string& input);
    static std::string escapeXml(const std::string& input);
};
}
