/////////////////////////////////////////////////////////////////////////////
// (C) 2001-2026 Micromata GmbH - GPL v3
/////////////////////////////////////////////////////////////////////////////
#pragma once
#include <string>
#include <vector>
#include <optional>
#include <cstdint>
#include "projectforge-common/logging/LogLevel.hpp"
namespace org::projectforge::common::logging {
class LogFilter {
public:
    std::optional<LogLevel> level;
    std::string search;
    std::string user;
    std::string ip;
    std::optional<int64_t> startTime;
    std::optional<int64_t> endTime;
    std::optional<int64_t> lastId;
    int maxRows = 500;
    LogFilter() = default;
    bool matchesLevel(LogLevel lvl) const;
};
}
