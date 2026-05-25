// ProjectForge C++ port — GPL v3 — www.projectforge.org
#pragma once
#include <string>
#include <vector>

namespace org::projectforge::plugins::marketing {

struct MarketingCampaign {
    int64_t id=-1; std::string name, description, status;
    int64_t startDate=0, endDate=0; double budget=0.0, spent=0.0;
};

class MarketingPlugin {
public:
    static void init() {}
    static std::string getName() { return "Marketing Plugin"; }
};
}