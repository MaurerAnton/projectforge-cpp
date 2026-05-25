// ProjectForge C++ port — GPL v3 — www.projectforge.org
#pragma once
#include <string>
#include <vector>

namespace org::projectforge::plugins::liquidityplanning {

struct LiquidityEntry {
    int64_t id=-1, date=0; std::string description, type; double amount=0.0;
    int64_t kontoId=-1; std::string status;
};

class LiquidityPlanningPlugin {
public:
    static void init() {}
    static std::string getName() { return "Liquidity Planning Plugin"; }
    static double getProjectedBalance() { return 0.0; }
};
}