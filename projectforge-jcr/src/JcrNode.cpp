// ProjectForge C++ port — GPL v3 — www.projectforge.org
#include "org/projectforge/jcr/JcrNode.hpp"
#include <algorithm>

namespace org::projectforge::jcr {

std::optional<std::string> JcrNode::getProperty(const std::string& name) const {
    for (const auto& p : properties) {
        if (p.name == name) return p.value;
    }
    return std::nullopt;
}

void JcrNode::setProperty(const std::string& name, const std::string& value) {
    for (auto& p : properties) {
        if (p.name == name) { p.value = value; return; }
    }
    properties.push_back({name, value, 1});
}

std::shared_ptr<JcrNode> JcrNode::addNode(const std::string& name, const std::string& type) {
    auto node = std::make_shared<JcrNode>();
    node->name = name;
    node->primaryType = type;
    node->path = path + "/" + name;
    node->parent = std::weak_ptr<JcrNode>(std::shared_ptr<JcrNode>(this, [](JcrNode*){})); // Hmm
    children.push_back(node);
    return node;
}

std::optional<std::shared_ptr<JcrNode>> JcrNode::getNode(const std::string& path) const {
    for (const auto& c : children) {
        if (c->name == path || c->path == path) return c;
    }
    return std::nullopt;
}

bool JcrNode::hasNode(const std::string& name) const {
    return std::any_of(children.begin(), children.end(), [&](const auto& c) { return c->name == name; });
}

bool JcrNode::hasProperty(const std::string& name) const {
    return std::any_of(properties.begin(), properties.end(), [&](const auto& p) { return p.name == name; });
}

nlohmann::json JcrNode::toJson() const {
    nlohmann::json j;
    j["path"] = path;
    j["name"] = name;
    j["primaryType"] = primaryType;
    if (!properties.empty()) {
        nlohmann::json props = nlohmann::json::array();
        for (const auto& p : properties) props.push_back(p.toJson());
        j["properties"] = props;
    }
    if (!children.empty()) {
        nlohmann::json kids = nlohmann::json::array();
        for (const auto& c : children) kids.push_back(c->toJson());
        j["children"] = kids;
    }
    return j;
}

std::shared_ptr<JcrNode> JcrNode::fromJson(const nlohmann::json& j) {
    auto node = std::make_shared<JcrNode>();
    if (j.contains("path")) node->path = j["path"];
    if (j.contains("name")) node->name = j["name"];
    if (j.contains("primaryType")) node->primaryType = j["primaryType"];
    return node;
}
}