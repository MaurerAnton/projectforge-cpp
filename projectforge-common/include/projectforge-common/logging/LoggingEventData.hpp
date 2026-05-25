/////////////////////////////////////////////////////////////////////////////
// (C) 2001-2026 Micromata GmbH - GPL v3
/////////////////////////////////////////////////////////////////////////////
#pragma once
#include <string>
#include <cstdint>
#include "projectforge-common/logging/LogLevel.hpp"
namespace org::projectforge::common::logging {
class LoggingEventData {
public:
    LoggingEventData(LogLevel level, const std::string& message, const std::string& loggerName,
                     int64_t timestampMillis, const std::string& className, const std::string& methodName,
                     int lineNumber);
    LogLevel getLevel() const { return level_; }
    const std::string& getMessage() const { return message_; }
    void setMessage(const std::string& msg) { message_ = msg; }
    const std::string& getLoggerName() const { return loggerName_; }
    int64_t getTimestampMillis() const { return timestampMillis_; }
    std::string getIsoTimestamp() const;
    const std::string& getJavaClass() const { return javaClass_; }
    const std::string& getJavaClassSimpleName() const { return javaClassSimpleName_; }
    int getLineNumber() const { return lineNumber_; }
    const std::string& getMethodName() const { return methodName_; }
    const std::string& getStackTrace() const { return stackTrace_; }
    void setStackTrace(const std::string& st) { stackTrace_ = st; }
    const std::string& getUser() const { return user_; }
    void setUser(const std::string& u) { user_ = u; }
    const std::string& getIp() const { return ip_; }
    void setIp(const std::string& i) { ip_ = i; }
    const std::string& getUserAgent() const { return userAgent_; }
    void setUserAgent(const std::string& ua) { userAgent_ = ua; }
    const std::string& getSession() const { return session_; }
    void setSession(const std::string& s) { session_ = s; }
    int64_t getId() const { return id_; }
    LoggingEventData clone() const;
private:
    int64_t id_;
    LogLevel level_;
    std::string message_;
    std::string loggerName_;
    int64_t timestampMillis_;
    std::string javaClass_;
    std::string javaClassSimpleName_;
    int lineNumber_;
    std::string methodName_;
    std::string stackTrace_;
    std::string user_;
    std::string ip_;
    std::string userAgent_;
    std::string session_;
};
}
