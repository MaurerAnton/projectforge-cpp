// ProjectForge C++ port — GPL v3 — www.projectforge.org
#pragma once
#include <string>
#include <chrono>

namespace org::projectforge::common {

class ProjectForgeVersion {
public:
    static constexpr const char* VERSION = "8.2.0";
    static constexpr const char* BUILD_TIMESTAMP = __TIMESTAMP__;
    static constexpr int MAJOR = 8;
    static constexpr int MINOR = 2;
    static constexpr int PATCH = 0;

    static std::string getVersionString();
    static std::string getBuildInfo();
    static bool isSnapshot();
};
}