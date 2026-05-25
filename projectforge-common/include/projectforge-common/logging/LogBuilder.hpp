/////////////////////////////////////////////////////////////////////////////
// (C) 2001-2026 Micromata GmbH - GPL v3
/////////////////////////////////////////////////////////////////////////////
#pragma once
#include <string>
#include <memory>
namespace org::projectforge::common::logging {
class LoggingEventData;
class LogBuilder {
public:
    explicit LogBuilder(const std::string& loggerName);
    LogBuilder& setMessage(const std::string& msg);
    LogBuilder& setMethodName(const std::string& mn);
    LogBuilder& setClassName(const std::string& cn);
    LogBuilder& setLineNumber(int ln);
    LogBuilder& setStackTrace(const std::string& st);
    LogBuilder& setUser(const std::string& u);
    LogBuilder& setIp(const std::string& i);
    LogBuilder& setUserAgent(const std::string& ua);
    LogBuilder& setSession(const std::string& s);
    std::shared_ptr<LoggingEventData> build();
    static std::shared_ptr<LogBuilder> create(const std::string& loggerName);
private:
    std::string loggerName_;
    std::string message_;
    std::string methodName_;
    std::string className_;
    int lineNumber_ = 0;
    std::string stackTrace_;
    std::string user_;
    std::string ip_;
    std::string userAgent_;
    std::string session_;
};
}
