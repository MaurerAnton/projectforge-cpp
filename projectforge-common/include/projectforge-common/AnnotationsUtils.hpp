/////////////////////////////////////////////////////////////////////////////
// (C) 2001-2026 Micromata GmbH - GPL v3
/////////////////////////////////////////////////////////////////////////////
#pragma once
#include <string>
#include <map>
#include <optional>
namespace org::projectforge::common {
class AnnotationsUtils {
public:
    static std::optional<std::string> getAnnotationValue(const std::string& className, const std::string& fieldName, const std::string& annotation);
    static std::map<std::string,std::string> getAnnotationValues(const std::string& className, const std::string& annotation);
};
}
