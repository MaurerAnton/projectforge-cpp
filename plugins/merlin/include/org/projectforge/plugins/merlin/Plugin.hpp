// ProjectForge C++ port — GPL v3 — www.projectforge.org
#pragma once
#include <string>
#include <vector>
#include <nlohmann/json.hpp>

namespace org::projectforge::plugins::merlin {

struct MerlinEntry {
    int64_t id=-1; std::string title, description, status;
    std::string priority; int64_t deadline=0; int64_t assignedTo=-1;
};

class MerlinPlugin {
public:
    static void init() {}
    static std::string getName() { return "Merlin Plugin"; }
    static nlohmann::json getGanttData() { return nlohmann::json::array(); }
};
}