// ProjectForge C++ port — GPL v3 — www.projectforge.org
#pragma once
#include <string>
#include <vector>
#include <nlohmann/json.hpp>

namespace org::projectforge::plugins::datatransfer {

struct DataTransferConfig {
    std::string sourceType, targetType, mapping;
    bool autoSync = false;
};

class DataTransferPlugin {
public:
    static void init() {}
    static std::string getName() { return "Data Transfer Plugin"; }
    static nlohmann::json exportData(const std::string& type) { return nlohmann::json::object(); }
    static bool importData(const std::string& type, const nlohmann::json& data) { return true; }
};
}