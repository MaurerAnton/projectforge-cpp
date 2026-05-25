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

#include "org/projectforge/jcr/file_object.hpp"
#include <sstream>

namespace org::projectforge::jcr {

FileObject::FileObject(const std::optional<std::string>& pnp,
                       const std::optional<std::string>& rp,
                       const std::optional<std::string>& fid,
                       const FileInfo* fileInfo,
                       std::optional<bool> encInProgress)
    : fileId(fid)
    , parentNodePath(pnp)
    , relPath(rp)
{
    encryptionInProgress = encInProgress;
    if (fileInfo != nullptr) {
        copyFrom(fileInfo);
    }
}

std::string FileObject::location() const {
    std::string result;
    if (parentNodePath.has_value()) result += parentNodePath.value();
    if (relPath.has_value()) {
        if (!result.empty() && result.back() != '/') result += '/';
        result += relPath.value();
    }
    return result;
}

std::string FileObject::toString() const {
    std::ostringstream oss;
    oss << "location=[" << location() << "]"
        << ",id=[" << (fileId.has_value() ? fileId.value() : "null") << "]"
        << ",fileName=[" << (fileName.has_value() ? fileName.value() : "null") << "]"
        << ",size=[" << (size.has_value() ? std::to_string(size.value()) : "null") << "]"
        << ",isEncrypted=[" << (aesEncrypted.has_value() && aesEncrypted.value() ? "true" : "false") << "]";
    return oss.str();
}

void FileObject::copyFromFile(const fs::path& filePath) {
    if (!fs::exists(filePath)) return;
    fileName = filePath.filename().string();
    size = static_cast<int64_t>(fs::file_size(filePath));
    auto ftime = fs::last_write_time(filePath);
    // Convert filesystem time to system_clock::time_point
    auto sctp = std::chrono::time_point_cast<std::chrono::system_clock::duration>(
        ftime - fs::file_time_type::clock::now() + std::chrono::system_clock::now());
    created = sctp;
    lastUpdate = sctp;
}

} // namespace org::projectforge::jcr
