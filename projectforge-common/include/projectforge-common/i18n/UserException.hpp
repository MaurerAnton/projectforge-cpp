/////////////////////////////////////////////////////////////////////////////
// (C) 2001-2026 Micromata GmbH - GPL v3
/////////////////////////////////////////////////////////////////////////////
#pragma once
#include <string>
#include <vector>
#include <any>
#include <optional>
#include "projectforge-common/ProjectForgeException.hpp"
namespace org::projectforge::common::i18n {
class MessageParam;
class UserException : public org::projectforge::common::ProjectForgeException {
public:
    static constexpr const char* I18N_KEY_FLOWSCOPE_NOT_EXIST = "exception.flowscope.notExists";
    static constexpr const char* I18N_KEY_PLEASE_CONTACT_DEVELOPER_TEAM = "exception.pleaseContactDeveloperTeam";

    explicit UserException(const std::string& i18nKey);
    UserException(const std::string& i18nKey, const std::vector<std::any>& params);
    UserException(const std::string& i18nKey, const std::vector<MessageParam>& msgParams);
    const std::string& getI18nKey() const { return i18nKey_; }
    const std::vector<std::any>* getParams() const { return params_.has_value() ? &params_.value() : nullptr; }
    const std::vector<MessageParam>* getMsgParams() const { return msgParams_.has_value() ? &msgParams_.value() : nullptr; }
    UserException& setCausedByField(const std::string& field);
    const std::string* getCausedByField() const { return causedByField_.has_value() ? &causedByField_.value() : nullptr; }
    std::string getLogHintMessage() const { return logHintMessage_; }
    void setLogHintMessage(const std::string& msg) { logHintMessage_ = msg; }
    bool isDisplayUserMessage() const { return displayUserMessage_; }
    void setDisplayUserMessage(bool v) { displayUserMessage_ = v; }
    std::string toString() const;
private:
    std::string i18nKey_;
    std::optional<std::vector<std::any>> params_;
    std::optional<std::vector<MessageParam>> msgParams_;
    std::optional<std::string> causedByField_;
    std::string logHintMessage_;
    bool displayUserMessage_ = true;
};
}
