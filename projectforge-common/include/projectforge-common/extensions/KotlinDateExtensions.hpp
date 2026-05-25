/////////////////////////////////////////////////////////////////////////////
// (C) 2001-2026 Micromata GmbH - GPL v3
/////////////////////////////////////////////////////////////////////////////
#pragma once
#include <string>
#include <chrono>
#include <optional>
namespace org::projectforge::common::extensions {
std::string formatDate(int64_t millis, const std::string& pattern);
std::string formatDateISO(int64_t millis);
std::string formatTimeOfDay(int64_t millis);
int64_t currentTimeMillis();
}
