/////////////////////////////////////////////////////////////////////////////
// (C) 2001-2026 Micromata GmbH - GPL v3
/////////////////////////////////////////////////////////////////////////////
#pragma once
#include <string>
#include <optional>
#include <spdlog/common.h>
namespace org::projectforge::common::logging {
enum class LogLevel { FATAL=0, ERROR=1, WARN=2, INFO=3, DEBUG=4, TRACE=5 };
class LogLevelHelper {
public:
    static std::string getI18nKey(LogLevel level);
    static std::optional<LogLevel> safeValueOf(const std::string& name);
    static bool matches(LogLevel level, LogLevel threshold);
    static LogLevel fromSpdlog(spdlog::level::level_enum lvl);
};
}
