// ProjectForge C++ port — GPL v3 — www.projectforge.org
#pragma once
#include <string>
#include <vector>
#include <ctime>

namespace org::projectforge::plugins::licensemanagement {

struct LicenseEntity {
    int64_t id=-1; std::string name, vendor, licenseKey, licenseType;
    int64_t purchaseDate=0, expiryDate=0; int seats=1; double cost=0.0;
};

class LicenseManagementPlugin {
public:
    static void init() {}
    static std::string getName() { return "License Management Plugin"; }
};
}