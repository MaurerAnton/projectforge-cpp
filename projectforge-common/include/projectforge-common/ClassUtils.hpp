/////////////////////////////////////////////////////////////////////////////
// (C) 2001-2026 Micromata GmbH - GPL v3
/////////////////////////////////////////////////////////////////////////////
#pragma once
#include <string>
namespace org::projectforge::common {
class ClassUtils {
public:
    static std::string getShortClassName(const std::string& fullClassName);
    static std::string getPackageName(const std::string& fullClassName);
    static std::string getSimpleName(const std::string& fullClassName);
    static bool isAssignable(const std::string& fromClass, const std::string& toClass);
};
}
