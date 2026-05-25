/////////////////////////////////////////////////////////////////////////////
//
// Project ProjectForge Community Edition
//         www.projectforge.org
//
// Copyright (C) 2001-2026 Micromata GmbH, Germany (www.micromata.com)
//
// ProjectForge is dual-licensed.
//
// This community edition is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License as published
// by the Free Software Foundation; version 3 of the License.
//
// This community edition is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General
// Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this program; if not, see http://www.gnu.org/licenses/.
//
/////////////////////////////////////////////////////////////////////////////

#pragma once

#include "file_info.hpp"
#include <string>
#include <optional>
#include <vector>
#include <cstdint>
#include <nlohmann/json.hpp>
#include <filesystem>

namespace org::projectforge::jcr {

namespace fs = std::filesystem;

/**
 * File object representing a file in the content repository.
 * Files are addressed by location (parent node) and id or filename.
 * Ported from FileObject.kt.
 */
class FileObject : public FileInfo {
public:
    FileObject() = default;

    // Constructor with parentNodePath, relPath, fileId, fileInfo
    FileObject(const std::optional<std::string>& parentNodePath,
               const std::optional<std::string>& relPath,
               const std::optional<std::string>& fileId,
               const FileInfo* fileInfo = nullptr,
               std::optional<bool> encryptionInProgress = std::nullopt);

    // -- fileId (unique random alphanumeric string) --
    std::optional<std::string> fileId;

    // -- content (raw bytes) --
    std::optional<std::vector<uint8_t>> content;

    // -- parentNodePath --
    std::optional<std::string> parentNodePath;

    // -- relPath --
    std::optional<std::string> relPath;

    // -- location (computed: parentNodePath + "/" + relPath) --
    std::string location() const;

    /**
     * Copy metadata from filesystem path.
     */
    void copyFromFile(const fs::path& filePath);

    /**
     * Copy metadata to a JSON node representation.
     */
    void copyToNode(nlohmann::json& nodeJson) const;

    /**
     * Copy metadata from a JSON node representation.
     */
    void copyFromNode(const nlohmann::json& nodeJson);

    std::string toString() const;
};

} // namespace org::projectforge::jcr
