/////////////////////////////////////////////////////////////////////////////
// (C) 2001-2026 Micromata GmbH - GPL v3
/////////////////////////////////////////////////////////////////////////////
#pragma once
#include <string>
#include <optional>
namespace org::projectforge::common::extensions {
std::string format2Digits(int value);
std::string format3Digits(int value);
std::string format(double value, int scale = 2);
std::string formatMillis(int64_t millis);
}
