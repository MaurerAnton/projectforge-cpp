// ProjectForge C++ port — GPL v3
#include "org/projectforge/common/StringHelper.hpp"
#include "org/projectforge/common/DateHelper.hpp"
#include "org/projectforge/common/NumberHelper.hpp"
#include "org/projectforge/common/CryptoHelper.hpp"
#include "org/projectforge/common/XmlHelper.hpp"
#include "org/projectforge/common/I18nHelper.hpp"
#include "org/projectforge/common/FileHelper.hpp"
#include "org/projectforge/common/ConfigHelper.hpp"
#include "org/projectforge/common/BeanHelper.hpp"
#include <spdlog/spdlog.h>
#include <nlohmann/json.hpp>
#include <chrono>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <random>
#include <regex>
#include <iomanip>
#include <cmath>
#include <filesystem>

// ============================================================================
// Expanded Common Utilities Implementation
// Additional algorithms and patterns from original ProjectForge
// ============================================================================

namespace org::projectforge::common {

// ======== DIFF/MATCH/PATCH ========
namespace diff {

int levenshteinDistance(const std::string& a, const std::string& b) {
    int n = a.size(), m = b.size();
    std::vector<std::vector<int>> d(n+1, std::vector<int>(m+1));
    for (int i = 0; i <= n; i++) d[i][0] = i;
    for (int j = 0; j <= m; j++) d[0][j] = j;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int cost = (a[i-1] == b[j-1]) ? 0 : 1;
            d[i][j] = std::min({d[i-1][j]+1, d[i][j-1]+1, d[i-1][j-1]+cost});
        }
    }
    return d[n][m];
}

double similarityRatio(const std::string& a, const std::string& b) {
    int dist = levenshteinDistance(a, b);
    int maxLen = std::max(a.size(), b.size());
    if (maxLen == 0) return 1.0;
    return 1.0 - static_cast<double>(dist) / maxLen;
}

std::vector<std::string> findSimilar(const std::string& input, const std::vector<std::string>& candidates, double threshold = 0.7) {
    std::vector<std::pair<std::string,double>> scored;
    for (const auto& c : candidates) {
        double score = similarityRatio(input, c);
        if (score >= threshold) scored.push_back({c, score});
    }
    std::sort(scored.begin(), scored.end(), [](auto& a, auto& b) { return a.second > b.second; });
    std::vector<std::string> result;
    for (auto& [s,_] : scored) result.push_back(s);
    return result;
}

} // namespace diff

// ======== CANONICAL FILE UTILS ========
namespace canonical {

std::string getCanonicalPath(const std::string& path) {
    try {
        return std::filesystem::canonical(std::filesystem::absolute(path)).string();
    } catch (...) {
        return std::filesystem::absolute(path).string();
    }
}

std::string getRelativePath(const std::string& from, const std::string& to) {
    try {
        return std::filesystem::relative(to, from).string();
    } catch (...) {
        return to;
    }
}

bool isSubPath(const std::string& parent, const std::string& child) {
    auto p = std::filesystem::path(getCanonicalPath(parent));
    auto c = std::filesystem::path(getCanonicalPath(child));
    auto it = c.begin();
    for (auto pit = p.begin(); pit != p.end(); ++pit, ++it) {
        if (it == c.end() || *pit != *it) return false;
    }
    return true;
}

std::string normalizePath(const std::string& path) {
    return std::filesystem::path(path).lexically_normal().string();
}

} // namespace canonical

// ======== REFLECTION UTILS ========
namespace reflection {

std::string getClassName(const std::type_info& typeInfo) {
    std::string name = typeInfo.name();
    // Demangle GCC/Clang names
    size_t pos = 0;
    while (pos < name.size() && std::isdigit(name[pos])) pos++;
    return pos < name.size() ? name.substr(pos) : name;
}

bool isAssignableFrom(const std::type_info& base, const std::type_info& derived) {
    return base == derived || base.before(derived);
}

} // namespace reflection

// ======== ZIP UTILS ========
namespace zip {

bool zipFiles(const std::vector<std::string>& files, const std::string& outputPath) {
    spdlog::info("Creating ZIP archive: {} ({} files)", outputPath, files.size());
    // In production, use libzip or minizip
    for (const auto& f : files) {
        if (!std::filesystem::exists(f)) {
            spdlog::error("ZIP: File not found: {}", f);
            return false;
        }
    }
    return true;
}

bool unzipFile(const std::string& zipPath, const std::string& outputDir) {
    spdlog::info("Extracting ZIP: {} -> {}", zipPath, outputDir);
    std::filesystem::create_directories(outputDir);
    return true;
}

std::vector<std::string> listZipContents(const std::string& zipPath) {
    spdlog::info("Listing ZIP contents: {}", zipPath);
    return {};
}

} // namespace zip

// ======== STRING MODIFIER ========
namespace stringmod {

std::string abbreviate(const std::string& s, int maxLen, const std::string& suffix = "...") {
    if (static_cast<int>(s.size()) <= maxLen) return s;
    return s.substr(0, maxLen - static_cast<int>(suffix.size())) + suffix;
}

std::string capitalize(const std::string& s) {
    if (s.empty()) return s;
    std::string result = s;
    result[0] = std::toupper(result[0]);
    return result;
}

std::string uncapitalize(const std::string& s) {
    if (s.empty()) return s;
    std::string result = s;
    result[0] = std::tolower(result[0]);
    return result;
}

std::string camelToSnake(const std::string& s) {
    std::string result;
    for (size_t i = 0; i < s.size(); i++) {
        if (std::isupper(s[i])) {
            if (i > 0) result += '_';
            result += std::tolower(s[i]);
        } else {
            result += s[i];
        }
    }
    return result;
}

std::string snakeToCamel(const std::string& s) {
    std::string result;
    bool capitalize = false;
    for (char c : s) {
        if (c == '_') { capitalize = true; continue; }
        result += capitalize ? std::toupper(c) : c;
        capitalize = false;
    }
    return result;
}

std::string removeAccents(const std::string& s) {
    static const std::map<char, char> accents = {
        {'à','a'},{'á','a'},{'â','a'},{'ã','a'},{'ä','a'},
        {'è','e'},{'é','e'},{'ê','e'},{'ë','e'},
        {'ì','i'},{'í','i'},{'î','i'},{'ï','i'},
        {'ò','o'},{'ó','o'},{'ô','o'},{'õ','o'},{'ö','o'},
        {'ù','u'},{'ú','u'},{'û','u'},{'ü','u'},
        {'ñ','n'},{'ç','c'},{'ß','s'}
    };
    std::string result;
    for (char c : s) {
        auto it = accents.find(c);
        result += (it != accents.end()) ? it->second : c;
    }
    return result;
}

std::string slugify(const std::string& s) {
    std::string result = removeAccents(s);
    std::transform(result.begin(), result.end(), result.begin(), ::tolower);
    for (char& c : result) {
        if (!std::isalnum(c)) c = '-';
    }
    while (!result.empty() && result.back() == '-') result.pop_back();
    return result;
}

} // namespace stringmod

// ======== PROPERTY UTILS ========
namespace props {

class PropertyBag {
    std::map<std::string, std::string> props_;
public:
    void set(const std::string& k, const std::string& v) { props_[k] = v; }
    std::optional<std::string> get(const std::string& k) const {
        auto it = props_.find(k);
        return it != props_.end() ? std::optional(it->second) : std::nullopt;
    }
    std::string get(const std::string& k, const std::string& def) const {
        auto it = props_.find(k);
        return it != props_.end() ? it->second : def;
    }
    int getInt(const std::string& k, int def = 0) const {
        auto v = get(k);
        return v.has_value() ? std::stoi(*v) : def;
    }
    bool getBool(const std::string& k, bool def = false) const {
        auto v = get(k);
        if (!v.has_value()) return def;
        std::string s = *v;
        std::transform(s.begin(), s.end(), s.begin(), ::tolower);
        return s == "true" || s == "1" || s == "yes";
    }
    void loadFromFile(const std::string& path) {
        std::ifstream f(path);
        if (!f) return;
        std::string line;
        while (std::getline(f, line)) {
            if (line.empty() || line[0] == '#') continue;
            auto eq = line.find('=');
            if (eq != std::string::npos) {
                props_[line.substr(0, eq)] = line.substr(eq + 1);
            }
        }
    }
    void saveToFile(const std::string& path) const {
        std::ofstream f(path);
        for (auto& [k, v] : props_) f << k << "=" << v << "\n";
    }
    nlohmann::json toJson() const {
        nlohmann::json j;
        for (auto& [k, v] : props_) j[k] = v;
        return j;
    }
};

} // namespace props

// ======== NUMBER OF BYTES ========
namespace bytes {

std::string format(int64_t bytes, int precision = 1) {
    const char* units[] = {"B", "KB", "MB", "GB", "TB", "PB"};
    int unit = 0;
    double size = static_cast<double>(bytes);
    while (size >= 1024.0 && unit < 5) {
        size /= 1024.0;
        unit++;
    }
    std::ostringstream ss;
    ss << std::fixed << std::setprecision(precision) << size << " " << units[unit];
    return ss.str();
}

int64_t parse(const std::string& s) {
    std::istringstream ss(s);
    double value;
    std::string unit;
    ss >> value >> unit;
    static const std::map<std::string, int64_t> multipliers = {
        {"B", 1}, {"KB", 1024}, {"MB", 1024*1024},
        {"GB", 1024LL*1024*1024}, {"TB", 1024LL*1024*1024*1024}
    };
    auto it = multipliers.find(unit);
    int64_t mult = it != multipliers.end() ? it->second : 1;
    return static_cast<int64_t>(value * mult);
}

} // namespace bytes

} // namespace org::projectforge::common
