// ProjectForge C++ port — GPL v3 — www.projectforge.org
#pragma once
#include <string>
#include <vector>

namespace org::projectforge::plugins::ihk {

struct IhkEntry { int64_t id=-1; std::string title, description, category; int hours=0; };

class IhkPlugin {
public:
    static void init() {}
    static std::string getName() { return "IHK Plugin"; }
};
}