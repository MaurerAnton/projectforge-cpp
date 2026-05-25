/////////////////////////////////////////////////////////////////////////////
// (C) 2001-2026 Micromata GmbH - GPL v3
/////////////////////////////////////////////////////////////////////////////
#pragma once
#include <string>
namespace org::projectforge::common::props {
enum class PropertyType {
    STRING, INTEGER, LONG, DOUBLE, BOOLEAN, DATE, TIMESTAMP, ENUM, CUSTOM
};
std::string propertyTypeToString(PropertyType type);
PropertyType propertyTypeFromString(const std::string& str);
}
