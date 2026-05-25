/////////////////////////////////////////////////////////////////////////////
// (C) 2001-2026 Micromata GmbH - GPL v3
/////////////////////////////////////////////////////////////////////////////
#pragma once
#include <string>
namespace org::projectforge::common::mgc {
class MatchResult {
public:
    MatchResult(bool success, const std::string& message = "");
    bool isSuccess() const { return success_; }
    const std::string& getMessage() const { return message_; }
    static MatchResult success() { return MatchResult(true); }
    static MatchResult failure(const std::string& msg) { return MatchResult(false, msg); }
private:
    bool success_;
    std::string message_;
};
}
