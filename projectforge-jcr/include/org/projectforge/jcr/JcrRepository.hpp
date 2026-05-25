// ProjectForge C++ port — GPL v3 — www.projectforge.org
#pragma once
#include "JcrNode.hpp"
#include <memory>
#include <string>
#include <functional>

namespace org::projectforge::jcr {

class JcrRepository {
public:
    virtual ~JcrRepository() = default;

    virtual std::shared_ptr<JcrNode> getRootNode() = 0;
    virtual std::optional<std::shared_ptr<JcrNode>> getNode(const std::string& path) = 0;
    virtual bool nodeExists(const std::string& path) = 0;

    virtual std::shared_ptr<JcrNode> createNode(const std::string& path, const std::string& type = "nt:unstructured") = 0;
    virtual bool deleteNode(const std::string& path) = 0;

    virtual void save() = 0;
    virtual void refresh(bool keepChanges = false) = 0;

    virtual void move(const std::string& srcPath, const std::string& destPath) = 0;
    virtual void copy(const std::string& srcPath, const std::string& destPath) = 0;
};
}