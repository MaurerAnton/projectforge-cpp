/////////////////////////////////////////////////////////////////////////////
// Project ProjectForge Community Edition — www.projectforge.org
// Copyright (C) 2001-2026 Micromata GmbH, Germany (www.micromata.com)
// ProjectForge is dual-licensed (GPL v3).
/////////////////////////////////////////////////////////////////////////////

#pragma once

#include <spdlog/spdlog.h>

namespace org::projectforge::common {

class Logging {
public:
    static std::shared_ptr<spdlog::logger> getLogger(const std::string& name = "projectforge");
    static void init(const std::string& level = "info");
};

inline std::shared_ptr<spdlog::logger> log() {
    return Logging::getLogger();
}

} // namespace
