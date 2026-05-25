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

#include <string>
#include <optional>
#include <chrono>
#include <cstdint>

namespace org::projectforge::jcr {

/**
 * Enum for zip mode (encryption algorithm detection).
 */
enum class ZipMode {
    NONE = 0,
    AES_128 = 1,
    AES_256 = 2,
    ZIP_CRYPTO = 3,
    AES_192 = 4
};

/**
 * Filesystem file attribute information.
 * Ported from FileInfo.kt.
 */
class FileInfo {
public:
    FileInfo() = default;
    virtual ~FileInfo() = default;

    // -- fileName (UTF-8) --
    std::optional<std::string> fileName;

    // -- description --
    std::optional<std::string> description;

    // -- created --
    std::optional<std::chrono::system_clock::time_point> created;

    // -- lastUpdate --
    std::optional<std::chrono::system_clock::time_point> lastUpdate;

    // -- createdByUser --
    std::optional<std::string> createdByUser;

    // -- lastUpdateByUser --
    std::optional<std::string> lastUpdateByUser;

    // -- checksum (SHA256) --
    std::optional<std::string> checksum;

    // -- aesEncrypted --
    std::optional<bool> aesEncrypted = false;

    // -- zipMode --
    std::optional<ZipMode> zipMode;

    // -- encryptionInProgress --
    std::optional<bool> encryptionInProgress;

    // -- size (file size in bytes) --
    std::optional<int64_t> size;

    // -- fileExtension (derived) --
    std::string fileExtension() const {
        if (!fileName.has_value()) return "";
        const auto& name = fileName.value();
        auto pos = name.rfind('.');
        if (pos == std::string::npos) return "";
        return name.substr(pos + 1);
    }

    /**
     * Copy all fields from another FileInfo.
     */
    void copyFrom(const FileInfo* other) {
        if (other == nullptr) return;
        fileName = other->fileName;
        description = other->description;
        created = other->created;
        lastUpdate = other->lastUpdate;
        createdByUser = other->createdByUser;
        lastUpdateByUser = other->lastUpdateByUser;
        size = other->size;
        checksum = other->checksum;
        aesEncrypted = other->aesEncrypted;
        zipMode = other->zipMode;
    }
};

} // namespace org::projectforge::jcr
