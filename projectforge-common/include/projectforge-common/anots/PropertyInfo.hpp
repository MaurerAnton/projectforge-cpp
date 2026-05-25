/////////////////////////////////////////////////////////////////////////////
// (C) 2001-2026 Micromata GmbH - GPL v3
/////////////////////////////////////////////////////////////////////////////
#pragma once
#include <string>
#include <optional>
namespace org::projectforge::common::anots {
struct PropertyInfo {
    std::optional<std::string> i18nKey;
    std::optional<std::string> description;
    PropertyInfo() = default;
    PropertyInfo(const std::string& key) : i18nKey(key) {}
};
}
