/////////////////////////////////////////////////////////////////////////////
// Project ProjectForge Community Edition — www.projectforge.org
// Copyright (C) 2001-2026 Micromata GmbH, Germany (www.micromata.com)
// ProjectForge is dual-licensed (GPL v3).
/////////////////////////////////////////////////////////////////////////////

#include "org/projectforge/common/Logging.hpp"
#include <spdlog/sinks/stdout_color_sinks.h>

namespace org::projectforge::common {

std::shared_ptr<spdlog::logger> Logging::getLogger(const std::string& name) {
    return spdlog::get(name);
}

void Logging::init(const std::string& level) {
    auto logger = spdlog::stdout_color_mt("projectforge");
    if (level == "debug") logger->set_level(spdlog::level::debug);
    else if (level == "trace") logger->set_level(spdlog::level::trace);
    else if (level == "warn") logger->set_level(spdlog::level::warn);
    else if (level == "error") logger->set_level(spdlog::level::err);
    else logger->set_level(spdlog::level::info);
    spdlog::set_default_logger(logger);
}

} // namespace
