// ProjectForge C++ port — GPL v3 — www.projectforge.org
#include "org/projectforge/common/ConfigHelper.hpp"
#include <fstream>

namespace org::projectforge::common {

ConfigHelper& ConfigHelper::instance() { static ConfigHelper inst; return inst; }

void ConfigHelper::loadFromFile(const std::string& path) {
    std::ifstream f(path);
    if (!f) return;
    nlohmann::json j;
    f >> j;
    loadFromJson(j);
}

void ConfigHelper::loadFromJson(const nlohmann::json& config) {
    for (auto& [k, v] : config.items()) {
        if (v.is_string()) properties_[k] = v.get<std::string>();
        else properties_[k] = v.dump();
    }
}

void ConfigHelper::setProperty(const std::string& k, const std::string& v) { properties_[k] = v; }

std::optional<std::string> ConfigHelper::getProperty(const std::string& k) const {
    auto it = properties_.find(k);
    return (it != properties_.end()) ? std::optional(it->second) : std::nullopt;
}

std::string ConfigHelper::getProperty(const std::string& k, const std::string& def) const {
    auto it = properties_.find(k);
    return (it != properties_.end()) ? it->second : def;
}

int ConfigHelper::getInt(const std::string& k, int def) const {
    auto v = getProperty(k);
    return v.has_value() ? std::stoi(*v) : def;
}

bool ConfigHelper::getBool(const std::string& k, bool def) const {
    auto v = getProperty(k);
    if (!v.has_value()) return def;
    std::string s = *v;
    for (char& c : s) c = static_cast<char>(std::tolower(c));
    return s == "true" || s == "1" || s == "yes";
}

double ConfigHelper::getDouble(const std::string& k, double def) const {
    auto v = getProperty(k);
    return v.has_value() ? std::stod(*v) : def;
}

std::map<std::string, std::string> ConfigHelper::getAll() const { return properties_; }
void ConfigHelper::clear() { properties_.clear(); }
}