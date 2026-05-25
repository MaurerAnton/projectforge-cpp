/////////////////////////////////////////////////////////////////////////////
// Project ProjectForge Community Edition — www.projectforge.org
// Copyright (C) 2001-2026 Micromata GmbH, Germany (www.micromata.com)
// ProjectForge is dual-licensed (GPL v3).
/////////////////////////////////////////////////////////////////////////////

#pragma once

#include <string>
#include <vector>
#include <map>
#include <optional>
#include <nlohmann/json.hpp>

namespace org::projectforge::common {

class XmlNode {
public:
    std::string name;
    std::string text;
    std::map<std::string, std::string> attributes;
    std::vector<XmlNode> children;

    XmlNode() = default;
    explicit XmlNode(const std::string& name) : name(name) {}

    std::optional<std::string> getAttribute(const std::string& key) const;
    std::vector<XmlNode> getChildren(const std::string& name) const;
    std::optional<XmlNode> getFirstChild(const std::string& name) const;
};

class XmlHelper {
public:
    static std::string escapeXml(const std::string& str);
    static std::string unescapeXml(const std::string& str);

    static std::optional<XmlNode> parseXml(const std::string& xml);
    static std::string toXml(const XmlNode& node, bool pretty = false);

    static nlohmann::json xmlToJson(const XmlNode& node);
    static XmlNode jsonToXml(const nlohmann::json& j, const std::string& rootName = "root");
};
} // namespace
