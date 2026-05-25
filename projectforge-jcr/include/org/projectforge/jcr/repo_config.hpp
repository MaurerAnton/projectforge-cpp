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
#include <cstdint>
#include <filesystem>

namespace org::projectforge::jcr {

/**
 * Configuration for the JCR repository.
 * Ported from RepoConfig.kt.
 */
class RepoConfig {
public:
    RepoConfig() = default;

    // -- Data source settings (for RDB storage) --
    void setDataSourceUrl(const std::string& url) { data_source_url_ = url; }
    std::string getDataSourceUrl() const { return data_source_url_; }

    void setDataSourceUser(const std::string& user) { data_source_user_ = user; }
    std::string getDataSourceUser() const { return data_source_user_; }

    void setDataSourcePassword(const std::string& pw) { data_source_password_ = pw; }
    std::string getDataSourcePassword() const { return data_source_password_; }

    void setDataSourceDriver(const std::string& driver) { data_source_driver_ = driver; }
    std::string getDataSourceDriver() const { return data_source_driver_; }

    void setMaximumPoolSize(int size) { max_pool_size_ = size; }
    int getMaximumPoolSize() const { return max_pool_size_; }

    void setMinimumIdle(int idle) { min_idle_ = idle; }
    int getMinimumIdle() const { return min_idle_; }

    void setConnectionTimeout(int64_t timeout) { connection_timeout_ = timeout; }
    int64_t getConnectionTimeout() const { return connection_timeout_; }

    void setIdleTimeout(int64_t timeout) { idle_timeout_ = timeout; }
    int64_t getIdleTimeout() const { return idle_timeout_; }

    // Whether the data source is configured (URL is not blank)
    bool isDataSourceConfigured() const {
        return !data_source_url_.empty() && data_source_url_.find_first_not_of(" \t\n\r") != std::string::npos;
    }

    // Post-construct initialization (creates data source if configured)
    void initialize();

    // Factory method for tests
    static RepoConfig createForTests() {
        RepoConfig config;
        config.setDataSourceUrl("");
        return config;
    }

private:
    std::string data_source_url_;
    std::string data_source_user_;
    std::string data_source_password_;
    std::string data_source_driver_;
    int max_pool_size_ = 10;
    int min_idle_ = 2;
    int64_t connection_timeout_ = 30000;
    int64_t idle_timeout_ = 600000;
};

} // namespace org::projectforge::jcr
