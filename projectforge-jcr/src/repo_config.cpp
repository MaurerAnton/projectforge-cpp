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

#include "repo_config.hpp"
#include <iostream>

namespace org::projectforge::jcr {

void RepoConfig::initialize() {
    if (!isDataSourceConfigured()) {
        return;
    }
    std::cout << "[RepoConfig] Creating Oak datasource with url=" << data_source_url_
              << ", user=" << data_source_user_
              << " and driver=" << data_source_driver_ << std::endl;
    // In a real implementation, this would create a database connection pool.
    // For the filesystem-based C++ port, the RDB path uses SQLite via sqlite_orm.
}

} // namespace org::projectforge::jcr
