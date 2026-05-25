// ProjectForge C++ port — GPL v3 — www.projectforge.org
#include "org/projectforge/jcr/FileSystemJcrBackend.hpp"
#include <spdlog/spdlog.h>
#include <fstream>

namespace org::projectforge::jcr {

FileSystemJcrBackend::FileSystemJcrBackend(const std::string& baseDir) : baseDir_(baseDir) {
    std::filesystem::create_directories(baseDir_);
    rootNode_ = std::make_shared<JcrNode>();
    rootNode_->path = "/";
    rootNode_->name = "";
    rootNode_->primaryType = "nt:unstructured";
}

std::shared_ptr<JcrNode> FileSystemJcrBackend::getRootNode() { return rootNode_; }

std::optional<std::shared_ptr<JcrNode>> FileSystemJcrBackend::getNode(const std::string& path) {
    auto fsPath = baseDir_ / path.substr(1);
    if (!std::filesystem::exists(fsPath)) return std::nullopt;
    auto node = std::make_shared<JcrNode>();
    node->path = path;
    node->name = fsPath.filename().string();
    return node;
}

bool FileSystemJcrBackend::nodeExists(const std::string& path) {
    return std::filesystem::exists(baseDir_ / path.substr(1));
}

std::shared_ptr<JcrNode> FileSystemJcrBackend::createNode(const std::string& path, const std::string& type) {
    createFsDir(path);
    auto node = std::make_shared<JcrNode>();
    node->path = path;
    node->primaryType = type;
    auto lastSep = path.rfind('/');
    node->name = (lastSep != std::string::npos) ? path.substr(lastSep + 1) : path;
    return node;
}

bool FileSystemJcrBackend::deleteNode(const std::string& path) {
    try { return std::filesystem::remove_all(baseDir_ / path.substr(1)) > 0; }
    catch (...) { return false; }
}

void FileSystemJcrBackend::save() {}
void FileSystemJcrBackend::refresh(bool) {}

void FileSystemJcrBackend::move(const std::string& src, const std::string& dst) {
    std::filesystem::rename(baseDir_ / src.substr(1), baseDir_ / dst.substr(1));
}

void FileSystemJcrBackend::copy(const std::string& src, const std::string& dst) {
    std::filesystem::copy(baseDir_ / src.substr(1), baseDir_ / dst.substr(1),
        std::filesystem::copy_options::recursive);
}

void FileSystemJcrBackend::createFsDir(const std::string& path) {
    std::filesystem::create_directories(baseDir_ / path.substr(1));
}
}