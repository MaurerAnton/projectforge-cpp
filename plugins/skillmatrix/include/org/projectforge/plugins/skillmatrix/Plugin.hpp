// ProjectForge C++ port — GPL v3 — www.projectforge.org
#pragma once
#include <string>
#include <vector>
#include <map>

namespace org::projectforge::plugins::skillmatrix {

struct SkillEntry {
    int64_t id=-1; std::string name, category, description;
    std::map<int64_t,int> userRatings; // userId -> rating 1-5
};

struct UserSkillProfile { int64_t userId=-1; std::vector<std::pair<int64_t,int>> skills; };

class SkillMatrixPlugin {
public:
    static void init() {}
    static std::string getName() { return "Skill Matrix Plugin"; }
};
}