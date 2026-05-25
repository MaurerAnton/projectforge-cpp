// ProjectForge C++ port — GPL v3 — www.projectforge.org
#pragma once
#include <string>
#include <map>
#include <optional>
#include <nlohmann/json.hpp>

namespace org::projectforge::common {

class ConfigHelper {
public:
    static ConfigHelper& instance();
    void loadFromFile(const std::string& path);
    void loadFromJson(const nlohmann::json& config);
    void setProperty(const std::string& key, const std::string& value);
    std::optional<std::string> getProperty(const std::string& key) const;
    std::string getProperty(const std::string& key, const std::string& defaultValue) const;
    int getInt(const std::string& key, int defaultValue = 0) const;
    bool getBool(const std::string& key, bool defaultValue = false) const;
    double getDouble(const std::string& key, double defaultValue = 0.0) const;
    std::map<std::string, std::string> getAll() const;
    void clear();

private:
    std::map<std::string, std::string> properties_;
};
}