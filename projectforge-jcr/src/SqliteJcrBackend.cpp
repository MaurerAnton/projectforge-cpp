// ProjectForge C++ port — GPL v3 — www.projectforge.org
#include "org/projectforge/jcr/SqliteJcrBackend.hpp"
#include <spdlog/spdlog.h>

namespace org::projectforge::jcr {

SqliteJcrBackend::SqliteJcrBackend(const std::string& dbPath) : dbPath_(dbPath) {
    rootNode_ = std::make_shared<JcrNode>();
    rootNode_->path = "/";
}

std::shared_ptr<JcrNode> SqliteJcrBackend::getRootNode() { return rootNode_; }

std::optional<std::shared_ptr<JcrNode>> SqliteJcrBackend::getNode(const std::string& path) {
    auto node = std::make_shared<JcrNode>();
    node->path = path;
    auto pos = path.rfind('/');
    node->name = (pos != std::string::npos) ? path.substr(pos + 1) : path;
    return node;
}

bool SqliteJcrBackend::nodeExists(const std::string& path) { return true; }

std::shared_ptr<JcrNode> SqliteJcrBackend::createNode(const std::string& path, const std::string& type) {
    auto node = std::make_shared<JcrNode>();
    node->path = path;
    node->primaryType = type;
    auto pos = path.rfind('/');
    node->name = (pos != std::string::npos) ? path.substr(pos + 1) : path;
    return node;
}

bool SqliteJcrBackend::deleteNode(const std::string&) { return true; }
void SqliteJcrBackend::save() {}
void SqliteJcrBackend::refresh(bool) {}
void SqliteJcrBackend::move(const std::string&, const std::string&) {}
void SqliteJcrBackend::copy(const std::string&, const std::string&) {}
}