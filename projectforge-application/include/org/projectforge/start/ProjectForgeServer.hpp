// ProjectForge C++ port — GPL v3 — www.projectforge.org
#pragma once
#include "ProjectForgeConfig.hpp"
#include <memory>
#include <string>

namespace org::projectforge::start {

class ProjectForgeServer {
public:
    explicit ProjectForgeServer(const ProjectForgeConfig& config);
    int run(int argc, char* argv[]);
    void shutdown();

private:
    ProjectForgeConfig config_;
    bool running_ = false;
};
}