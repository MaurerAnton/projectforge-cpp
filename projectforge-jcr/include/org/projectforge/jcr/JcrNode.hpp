// ProjectForge C++ port — GPL v3 — www.projectforge.org
#pragma once
#include <string>
#include <vector>
#include <map>
#include <memory>
#include <optional>
#include <nlohmann/json.hpp>

namespace org::projectforge::jcr {

class JcrProperty {
public:
    std::string name;
    std::string value;
    int type = 0; // PropertyType: STRING=1, BINARY=2, LONG=3, DOUBLE=4, DATE=5, BOOLEAN=6, NAME=7, PATH=8, REFERENCE=9

    nlohmann::json toJson() const {
        return {{"name", name}, {"value", value}, {"type", type}};
    }
};

class JcrNode {
public:
    int64_t id = -1;
    std::string path;
    std::string name;
    std::string primaryType = "nt:unstructured";
    std::vector<std::string> mixinTypes;
    std::vector<JcrProperty> properties;
    std::vector<std::shared_ptr<JcrNode>> children;
    std::weak_ptr<JcrNode> parent;

    std::optional<std::string> getProperty(const std::string& name) const;
    void setProperty(const std::string& name, const std::string& value);

    std::shared_ptr<JcrNode> addNode(const std::string& name, const std::string& type = "nt:unstructured");
    std::optional<std::shared_ptr<JcrNode>> getNode(const std::string& path) const;
    bool hasNode(const std::string& name) const;
    bool hasProperty(const std::string& name) const;
    bool hasNodes() const { return !children.empty(); }

    nlohmann::json toJson() const;
    static std::shared_ptr<JcrNode> fromJson(const nlohmann::json& j);
};
}