/////////////////////////////////////////////////////////////////////////////
// (C) 2001-2026 Micromata GmbH - GPL v3
/////////////////////////////////////////////////////////////////////////////
#pragma once
#include <string>
#include <cstdint>
namespace org::projectforge::common::logging {
class LogSubscription {
public:
    LogSubscription(const std::string& sessionId, const std::string& user, const std::string& ip);
    const std::string& getSessionId() const { return sessionId_; }
    const std::string& getUser() const { return user_; }
    const std::string& getIp() const { return ip_; }
    int64_t getSince() const { return since_; }
    void setSince(int64_t s) { since_ = s; }
    int64_t getId() const { return id_; }
private:
    static int64_t nextId_;
    int64_t id_;
    std::string sessionId_;
    std::string user_;
    std::string ip_;
    int64_t since_ = 0;
};
}
