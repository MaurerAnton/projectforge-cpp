/////////////////////////////////////////////////////////////////////////////
// (C) 2001-2026 Micromata GmbH - GPL v3
/////////////////////////////////////////////////////////////////////////////
#pragma once
#include <string>
#include <map>
#include <any>
#include <optional>
namespace org::projectforge::common {
class PropertyUtils {
public:
    static std::optional<std::any> getProperty(const std::any& bean, const std::string& property);
    static void setProperty(const std::any& bean, const std::string& property, const std::any& value);
};
}
