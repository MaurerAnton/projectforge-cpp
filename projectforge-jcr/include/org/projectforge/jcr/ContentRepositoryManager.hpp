// ProjectForge C++ port — GPL v3 — www.projectforge.org
#pragma once
#include "JcrRepository.hpp"
#include <memory>
#include <string>

namespace org::projectforge::jcr {

enum class JcrBackendType { FILESYSTEM, SQLITE };

class ContentRepositoryManager {
public:
    static ContentRepositoryManager& instance();
    void init(JcrBackendType type, const std::string& backendPath = "");
    std::shared_ptr<JcrRepository> getRepository();

    std::shared_ptr<JcrNode> getNode(const std::string& path);
    bool nodeExists(const std::string& path);

private:
    std::shared_ptr<JcrRepository> repo_;
};
}