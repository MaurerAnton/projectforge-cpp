/////////////////////////////////////////////////////////////////////////////
// Project ProjectForge Community Edition — www.projectforge.org
// Copyright (C) 2001-2026 Micromata GmbH, Germany (www.micromata.com)
// ProjectForge is dual-licensed (GPL v3).
/////////////////////////////////////////////////////////////////////////////

#include "org/projectforge/common/XmlHelper.hpp"
#include "org/projectforge/common/StringHelper.hpp"
#include <stack>
#include <cstring>

namespace org::projectforge::common {

std::optional<std::string> XmlNode::getAttribute(const std::string& key) const {
    auto it = attributes.find(key);
    return (it != attributes.end()) ? std::optional<std::string>(it->second) : std::nullopt;
}

std::vector<XmlNode> XmlNode::getChildren(const std::string& name) const {
    std::vector<XmlNode> result;
    for (const auto& child : children) {
        if (child.name == name) result.push_back(child);
    }
    return result;
}

std::optional<XmlNode> XmlNode::getFirstChild(const std::string& name) const {
    for (const auto& child : children) {
        if (child.name == name) return child;
    }
    return std::nullopt;
}

std::string XmlHelper::escapeXml(const std::string& str) {
    return StringHelper::escapeXml(str);
}

std::string XmlHelper::unescapeXml(const std::string& str) {
    std::string result = str;
    result = StringHelper::replace(result, "&amp;", "&");
    result = StringHelper::replace(result, "&lt;", "<");
    result = StringHelper::replace(result, "&gt;", ">");
    result = StringHelper::replace(result, "&quot;", "\"");
    result = StringHelper::replace(result, "&#39;", "'");
    result = StringHelper::replace(result, "&#xD;", "");
    return result;
}

std::optional<XmlNode> XmlHelper::parseXml(const std::string& xml) {
    XmlNode root;
    std::stack<XmlNode*> nodeStack;
    nodeStack.push(&root);

    size_t pos = 0;
    while (pos < xml.size()) {
        if (xml[pos] == '<') {
            size_t end = xml.find('>', pos);
            if (end == std::string::npos) break;
            std::string tag = xml.substr(pos + 1, end - pos - 1);
            pos = end + 1;

            if (tag.empty()) continue;
            if (tag[0] == '/') {
                if (nodeStack.size() > 1) nodeStack.pop();
                continue;
            }
            if (tag.back() == '/') {
                tag.pop_back();
                // Self-closing tag
                XmlNode child;
                // Parse attributes
                size_t space = tag.find(' ');
                if (space != std::string::npos) {
                    child.name = tag.substr(0, space);
                    // Parse remaining attributes
                    std::string attrs = tag.substr(space + 1);
                    size_t eq = attrs.find('=');
                    while (eq != std::string::npos) {
                        std::string key = attrs.substr(0, eq);
                        StringHelper::trim(key);
                        size_t quoteStart = attrs.find('"', eq);
                        if (quoteStart != std::string::npos) {
                            size_t quoteEnd = attrs.find('"', quoteStart + 1);
                            if (quoteEnd != std::string::npos) {
                                child.attributes[key] = attrs.substr(quoteStart + 1, quoteEnd - quoteStart - 1);
                                attrs = attrs.substr(quoteEnd + 1);
                            }
                        }
                        eq = attrs.find('=');
                    }
                } else {
                    child.name = tag;
                }
                nodeStack.top()->children.push_back(child);
                continue;
            }

            XmlNode child;
            size_t space = tag.find(' ');
            if (space != std::string::npos) {
                child.name = tag.substr(0, space);
            } else {
                child.name = tag;
            }
            nodeStack.top()->children.push_back(child);
            nodeStack.push(&nodeStack.top()->children.back());
        } else {
            size_t nextTag = xml.find('<', pos);
            std::string text = xml.substr(pos, nextTag - pos);
            if (StringHelper::isNotBlank(text)) {
                nodeStack.top()->text += text;
            }
            pos = (nextTag != std::string::npos) ? nextTag : xml.size();
        }
    }
    return root.children.empty() ? std::nullopt : std::optional<XmlNode>(root.children[0]);
}

std::string XmlHelper::toXml(const XmlNode& node, bool pretty) {
    std::string result;
    std::function<void(const XmlNode&, int)> serialize = [&](const XmlNode& n, int depth) {
        if (pretty) result += std::string(depth * 2, ' ');
        result += "<" + n.name;
        for (const auto& [k, v] : n.attributes) {
            result += " " + k + "=\"" + escapeXml(v) + "\"";
        }
        if (n.children.empty() && n.text.empty()) {
            result += "/>";
            if (pretty) result += "\n";
            return;
        }
        result += ">";
        if (!n.text.empty()) {
            result += escapeXml(n.text);
        }
        if (!n.children.empty()) {
            if (pretty) result += "\n";
            for (const auto& child : n.children) {
                serialize(child, depth + 1);
            }
            if (pretty) result += std::string(depth * 2, ' ');
        }
        result += "</" + n.name + ">";
        if (pretty) result += "\n";
    };
    serialize(node, 0);
    return result;
}

nlohmann::json XmlHelper::xmlToJson(const XmlNode& node) {
    nlohmann::json j;
    j["name"] = node.name;
    if (!node.text.empty()) j["text"] = node.text;
    if (!node.attributes.empty()) {
        nlohmann::json attrs;
        for (const auto& [k, v] : node.attributes) attrs[k] = v;
        j["attributes"] = attrs;
    }
    if (!node.children.empty()) {
        nlohmann::json children = nlohmann::json::array();
        for (const auto& child : node.children) children.push_back(xmlToJson(child));
        j["children"] = children;
    }
    return j;
}

XmlNode XmlHelper::jsonToXml(const nlohmann::json& j, const std::string& rootName) {
    XmlNode node(rootName);
    if (j.is_object()) {
        for (auto& [key, value] : j.items()) {
            if (key == "text" || key == "name" || key == "children" || key == "attributes") continue;
            if (value.is_string()) {
                XmlNode child(key);
                child.text = value.get<std::string>();
                node.children.push_back(child);
            } else if (value.is_object()) {
                node.children.push_back(jsonToXml(value, key));
            } else if (value.is_array()) {
                for (const auto& item : value) {
                    if (item.is_object()) node.children.push_back(jsonToXml(item, key));
                }
            }
        }
    }
    return node;
}
} // namespace
