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

#include "file_object.hpp"
#include <vector>
#include <memory>

namespace org::projectforge::jcr {

/**
 * Wrapper for a list of file objects.
 * Ported from FileObjectList.kt.
 */
class FileObjectList {
public:
    FileObjectList() = default;
    explicit FileObjectList(std::vector<std::shared_ptr<FileObject>> files)
        : files_(std::move(files)) {}

    std::vector<std::shared_ptr<FileObject>>& getFiles() { return files_; }
    const std::vector<std::shared_ptr<FileObject>>& getFiles() const { return files_; }

    std::string toString() const;

private:
    std::vector<std::shared_ptr<FileObject>> files_;
};

} // namespace org::projectforge::jcr
