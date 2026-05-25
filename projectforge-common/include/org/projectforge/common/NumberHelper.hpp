// ProjectForge C++ port — GPL v3 — www.projectforge.org
'#pragma once
#include <string>
#include <optional>
#include <vector>
#include <cmath>
#include <iomanip>
#include <sstream>

namespace org::projectforge::common {

class NumberHelper {
public:
    static std::string formatInteger(int value);
    static std::string formatLong(int64_t value);
    static std::string formatDouble(double value, int precision = 2);
    static std::string formatBytes(int64_t bytes);
    static std::string formatPercentage(double value);
    static std::string formatCurrency(double value, const std::string& currency = "EUR");
    static std::string formatDecimal(double value, int minDecimals, int maxDecimals);
    static std::string formatFileSize(int64_t bytes);
    static std::string padLeft(const std::string& str, int length, char c = ' ');
    static std::string padRight(const std::string& str, int length, char c = ' ');
    static std::optional<int> parseInteger(const std::string& str);
    static std::optional<int64_t> parseLong(const std::string& str);
    static std::optional<double> parseDouble(const std::string& str);
    static int gcd(int a, int b);
    static bool isEven(int64_t value);
    static bool isOdd(int64_t value);
    static int parseFractionDigits(const std::string& str, int defaultDigits);
    static std::string formatHours(int64_t seconds);
    static std::string formatGermanNumber(double value, int decimals = 2);
    static std::string formatEnglishNumber(double value, int decimals = 2);
    static int getFractionDigitsCount(const std::string& str);
    static std::string groupThousands(const std::string& str, char separator = ',');
    static bool isNumeric(const std::string& str);
    static double round(double value, int decimals = 2);
    static double roundHalfUp(double value, int decimals);
    static int64_t roundToInt(double value);
    static std::string formatSignificantDigits(double value, int significantDigits);
};
}