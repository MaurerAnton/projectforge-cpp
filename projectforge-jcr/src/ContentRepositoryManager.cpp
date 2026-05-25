// ProjectForge C++ port — GPL v3 — www.projectforge.org
#include "org/projectforge/jcr/ContentRepositoryManager.hpp"
#include "org/projectforge/jcr/FileSystemJcrBackend.hpp"
#include "org/projectforge/jcr/SqliteJcrBackend.hpp"

namespace org::projectforge::jcr {

ContentRepositoryManager& ContentRepositoryManager::instance() {
    static ContentRepositoryManager mgr;
    return mgr;
}

void ContentRepositoryManager::init(JcrBackendType type, const std::string& path) {
    if (type == JcrBackendType::FILESYSTEM) {
        repo_ = std::make_shared<FileSystemJcrBackend>(path.empty() ? "/tmp/projectforge-jcr" : path);
    } else {
        repo_ = std::make_shared<SqliteJcrBackend>(path.empty() ? ":memory:" : path);
    }
}

std::shared_ptr<JcrRepository> ContentRepositoryManager::getRepository() { return repo_; }

std::shared_ptr<JcrNode> ContentRepositoryManager::getNode(const std::string& path) {
    if (!repo_) return nullptr;
    auto node = repo_->getNode(path);
    return node.has_value() ? *node : nullptr;
}

bool ContentRepositoryManager::nodeExists(const std::string& path) {
    return repo_ && repo_->nodeExists(path);
}
}