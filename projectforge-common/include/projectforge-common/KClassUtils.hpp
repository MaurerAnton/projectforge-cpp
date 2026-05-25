/////////////////////////////////////////////////////////////////////////////
// (C) 2001-2026 Micromata GmbH - GPL v3
/////////////////////////////////////////////////////////////////////////////
#pragma once
#include <string>
namespace org::projectforge::common {
class KClassUtils {
public:
    static std::string qualifiedName(const std::string& clazz);
    static std::string simpleName(const std::string& clazz);
};
}
