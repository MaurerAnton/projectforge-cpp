/////////////////////////////////////////////////////////////////////////////
// (C) 2001-2026 Micromata GmbH - GPL v3
/////////////////////////////////////////////////////////////////////////////
#pragma once
#include <string>
#include <any>
#include <stdexcept>
#include "projectforge-common/i18n/MessageParamType.hpp"
namespace org::projectforge::common::i18n {
class I18nEnum;
class MessageParam {
public:
    explicit MessageParam(const std::any& value);
    explicit MessageParam(const I18nEnum& value);
    explicit MessageParam(const std::string& value);
    MessageParam(const std::string& value, MessageParamType paramType);
    const std::any& getValue() const { return value_; }
    std::string getI18nKey() const;
    bool isI18nKey() const;
    std::string toString() const;
private:
    std::any value_;
    MessageParamType paramType_ = MessageParamType::VALUE;
};
}
