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
#include <filesystem>
#include <functional>
#include <fstream>
#include <map>
#include <vector>
#include <system_error>

namespace org::projectforge::jcr {

namespace fs = std::filesystem;

/**
 * Thin wrapper around a JCR-like session.
 * In the C++ port, this maps to filesystem operations under a repository root.
 * Ported from SessionWrapper.kt.
 */
class SessionWrapper {
public:
    explicit SessionWrapper(const fs::path& repositoryRoot)
        : repository_root_(repositoryRoot) {}

    /**
     * Get a node (directory) by absolute path within the repository.
     */
    fs::path getNode(const std::string& absPath) const {
        fs::path p = toFsPath(absPath);
        if (!fs::exists(p)) {
            throw std::runtime_error("Node not found: " + absPath);
        }
        return p;
    }

    /**
     * Check if a node (directory) exists.
     */
    bool nodeExists(const std::string& absPath) const {
        return fs::exists(toFsPath(absPath));
    }

    /**
     * Get the root node (repository root).
     */
    fs::path getRootNode() const {
        return repository_root_;
    }

    /**
     * Save/persist changes. In filesystem mode this is a no-op
     * since operations write directly. For SQLite, this would commit a transaction.
     */
    void save() {
        // Filesystem mode: no-op (writes are immediate)
        // SQLite mode: commit transaction
    }

    /**
     * Logout: save and close session.
     */
    void logout() {
        save();
        // Session closed
    }

    const fs::path& getRepositoryRoot() const { return repository_root_; }

private:
    fs::path repository_root_;

    fs::path toFsPath(const std::string& absPath) const {
        std::string path = absPath;
        // Remove leading slash if present
        if (!path.empty() && path[0] == '/') {
            path = path.substr(1);
        }
        return repository_root_ / path;
    }
};

} // namespace org::projectforge::jcr
