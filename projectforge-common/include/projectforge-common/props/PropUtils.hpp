/////////////////////////////////////////////////////////////////////////////
// (C) 2001-2026 Micromata GmbH - GPL v3
/////////////////////////////////////////////////////////////////////////////
#pragma once
#include <string>
namespace org::projectforge::common::props {
class PropUtils {
public:
    static std::string getPropName(const std::string& fieldName);
    static std::string getPropertyGetterName(const std::string& fieldName);
    static std::string getPropertySetterName(const std::string& fieldName);
};
}
