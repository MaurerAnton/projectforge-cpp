// ProjectForge C++ port — GPL v3 — www.projectforge.org
#include "org/projectforge/common/ProjectForgeVersion.hpp"

namespace org::projectforge::common {

std::string ProjectForgeVersion::getVersionString() {
    return std::string(VERSION) + (isSnapshot() ? "-SNAPSHOT" : "");
}
std::string ProjectForgeVersion::getBuildInfo() {
    return std::string("ProjectForge C++ ") + VERSION + " built " + BUILD_TIMESTAMP;
}
bool ProjectForgeVersion::isSnapshot() {
    return PATCH == 0;
}
}