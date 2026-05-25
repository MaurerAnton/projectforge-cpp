/////////////////////////////////////////////////////////////////////////////
// (C) 2001-2026 Micromata GmbH - GPL v3
/////////////////////////////////////////////////////////////////////////////
#pragma once
#include <string>
#include <chrono>
namespace org::projectforge::common::logging {
class LogDuration {
public:
    enum class TimeUnit { STANDARD, SECONDS };
    LogDuration() : start_(std::chrono::steady_clock::now()) {}
    std::string getDuration() const;
    std::string toString() const { return toString(TimeUnit::STANDARD); }
    std::string toString(TimeUnit unit) const;
    std::string toSeconds(int scale = 1) const;
private:
    std::chrono::steady_clock::time_point start_;
};
}
