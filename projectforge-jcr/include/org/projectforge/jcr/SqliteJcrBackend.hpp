// ProjectForge C++ port — GPL v3 — www.projectforge.org
#pragma once
#include "JcrRepository.hpp"
#include <string>
#include <sqlite_orm/sqlite_orm.h>

namespace org::projectforge::jcr {

class SqliteJcrBackend : public JcrRepository {
public:
    explicit SqliteJcrBackend(const std::string& dbPath);
    ~SqliteJcrBackend() override = default;

    std::shared_ptr<JcrNode> getRootNode() override;
    std::optional<std::shared_ptr<JcrNode>> getNode(const std::string& path) override;
    bool nodeExists(const std::string& path) override;
    std::shared_ptr<JcrNode> createNode(const std::string& path, const std::string& type = "nt:unstructured") override;
    bool deleteNode(const std::string& path) override;
    void save() override;
    void refresh(bool keepChanges = false) override;
    void move(const std::string& srcPath, const std::string& destPath) override;
    void copy(const std::string& srcPath, const std::string& destPath) override;

private:
    std::string dbPath_;
    std::shared_ptr<JcrNode> rootNode_;
};
}