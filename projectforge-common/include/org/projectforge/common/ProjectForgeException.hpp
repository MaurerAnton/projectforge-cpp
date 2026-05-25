// ProjectForge C++ port — GPL v3 — www.projectforge.org
#pragma once
#include <stdexcept>
#include <string>

namespace org::projectforge::common {

class ProjectForgeException : public std::runtime_error {
public:
    explicit ProjectForgeException(const std::string& message) : std::runtime_error(message) {}
    explicit ProjectForgeException(const char* message) : std::runtime_error(message) {}
};

class UserException : public ProjectForgeException {
public:
    explicit UserException(const std::string& message) : ProjectForgeException(message) {}
    explicit UserException(const std::string& message, const std::string& i18nKey)
        : ProjectForgeException(message), i18nKey_(i18nKey) {}
    const std::string& i18nKey() const { return i18nKey_; }
private:
    std::string i18nKey_;
};

class MaxFileSizeExceededException : public ProjectForgeException {
public:
    explicit MaxFileSizeExceededException(const std::string& msg) : ProjectForgeException(msg) {}
};
}