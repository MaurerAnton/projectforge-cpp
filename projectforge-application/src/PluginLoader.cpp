// ProjectForge C++ port — GPL v3 — www.projectforge.org
#include "org/projectforge/start/PluginLoader.hpp"
#include <spdlog/spdlog.h>

namespace org::projectforge::start {

PluginLoader& PluginLoader::instance() { static PluginLoader pl; return pl; }

void PluginLoader::registerPlugin(const std::string& name, PluginFactory factory) {
    factories_.push_back({name, std::move(factory)});
}

void PluginLoader::initAllPlugins() {
    for (auto& [name, factory] : factories_) {
        auto plugin = factory();
        plugin->init();
        plugins_.push_back(plugin);
        spdlog::info("Plugin loaded: {}", name);
    }
}

void PluginLoader::shutdownAll() {
    for (auto& p : plugins_) p->shutdown();
    plugins_.clear();
}

std::vector<std::string> PluginLoader::getPluginNames() const {
    std::vector<std::string> names;
    for (const auto& [name, _] : factories_) names.push_back(name);
    return names;
}
}