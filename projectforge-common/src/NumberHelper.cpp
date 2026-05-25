// ProjectForge C++ port — GPL v3 — www.projectforge.org
#include "org/projectforge/common/NumberHelper.hpp"
#include <algorithm>
#include <charconv>
#include <locale>

namespace org::projectforge::common {

std::string NumberHelper::formatInteger(int value) {
    return std::to_string(value);
}
std::string NumberHelper::formatLong(int64_t value) {
    return std::to_string(value);
}
std::string NumberHelper::formatDouble(double value, int precision) {
    std::ostringstream ss;
    ss << std::fixed << std::setprecision(precision) << value;
    return ss.str();
}
std::string NumberHelper::formatBytes(int64_t bytes) {
    if (bytes < 1024) return std::to_string(bytes) + " B";
    double v = bytes / 1024.0;
    if (v < 1024) return formatDouble(v, 1) + " KB";
    v /= 1024;
    if (v < 1024) return formatDouble(v, 1) + " MB";
    v /= 1024;
    if (v < 1024) return formatDouble(v, 1) + " GB";
    v /= 1024;
    return formatDouble(v, 1) + " TB";
}
std::string NumberHelper::formatPercentage(double value) {
    return formatDouble(value * 100, 1) + "%";
}
std::string NumberHelper::formatCurrency(double value, const std::string& currency) {
    std::ostringstream ss;
    ss << std::fixed << std::setprecision(2) << value;
    std::string s = ss.str();
    return s + " " + currency;
}
std::string NumberHelper::formatDecimal(double value, int minD, int maxD) {
    std::ostringstream ss;
    ss << std::fixed << std::setprecision(maxD) << value;
    std::string s = ss.str();
    while (s.find('.') != std::string::npos && s.back() == '0') s.pop_back();
    if (s.back() == '.') s.pop_back();
    return s;
}
std::string NumberHelper::formatFileSize(int64_t bytes) { return formatBytes(bytes); }
std::string NumberHelper::padLeft(const std::string& s, int l, char c) {
    return s.size() >= static_cast<size_t>(l) ? s : std::string(l - s.size(), c) + s;
}
std::string NumberHelper::padRight(const std::string& s, int l, char c) {
    return s.size() >= static_cast<size_t>(l) ? s : s + std::string(l - s.size(), c);
}
std::optional<int> NumberHelper::parseInteger(const std::string& str) {
    try { return std::stoi(str); } catch (...) { return std::nullopt; }
}
std::optional<int64_t> NumberHelper::parseLong(const std::string& str) {
    try { return std::stoll(str); } catch (...) { return std::nullopt; }
}
std::optional<double> NumberHelper::parseDouble(const std::string& str) {
    try { return std::stod(str); } catch (...) { return std::nullopt; }
}
int NumberHelper::gcd(int a, int b) {
    while (b) { int t = b; b = a % b; a = t; }
    return a;
}
bool NumberHelper::isEven(int64_t v) { return v % 2 == 0; }
bool NumberHelper::isOdd(int64_t v) { return v % 2 != 0; }
int NumberHelper::parseFractionDigits(const std::string& str, int def) {
    auto pos = str.find('.');
    if (pos == std::string::npos) return def;
    return static_cast<int>(str.size() - pos - 1);
}
std::string NumberHelper::formatHours(int64_t seconds) {
    int64_t h = seconds / 3600, m = (seconds % 3600) / 60;
    std::ostringstream ss;
    ss << h << ":" << std::setfill('0') << std::setw(2) << m;
    return ss.str();
}
std::string NumberHelper::formatGermanNumber(double value, int decimals) {
    std::ostringstream ss;
    ss << std::fixed << std::setprecision(decimals) << value;
    std::string s = ss.str();
    auto pos = s.find('.');
    std::string intPart = pos != std::string::npos ? s.substr(0, pos) : s;
    std::string decPart = pos != std::string::npos ? "," + s.substr(pos + 1) : "";
    for (int i = static_cast<int>(intPart.size()) - 3; i > 0; i -= 3)
        intPart.insert(i, ".");
    return intPart + decPart;
}
std::string NumberHelper::formatEnglishNumber(double value, int decimals) {
    std::ostringstream ss;
    ss.imbue(std::locale("en_US.UTF-8"));
    ss << std::fixed << std::setprecision(decimals) << value;
    return ss.str();
}
int NumberHelper::getFractionDigitsCount(const std::string& str) {
    return parseFractionDigits(str, 0);
}
std::string NumberHelper::groupThousands(const std::string& str, char sep) {
    std::string result;
    int count = 0;
    for (auto it = str.rbegin(); it != str.rend(); ++it) {
        if (count > 0 && count % 3 == 0) result += sep;
        result += *it;
        ++count;
    }
    std::reverse(result.begin(), result.end());
    return result;
}
bool NumberHelper::isNumeric(const std::string& str) {
    if (str.empty()) return false;
    size_t pos;
    try { std::stod(str, &pos); return pos == str.size(); }
    catch (...) { return false; }
}
double NumberHelper::round(double value, int decimals) {
    double m = std::pow(10.0, decimals);
    return std::round(value * m) / m;
}
double NumberHelper::roundHalfUp(double value, int decimals) {
    return round(value, decimals);
}
int64_t NumberHelper::roundToInt(double value) {
    return static_cast<int64_t>(std::round(value));
}
std::string NumberHelper::formatSignificantDigits(double value, int sig) {
    if (value == 0) return "0";
    int digits = static_cast<int>(std::floor(std::log10(std::abs(value)))) + 1;
    return formatDouble(value, std::max(0, sig - digits));
}
}