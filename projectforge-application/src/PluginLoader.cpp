// ProjectForge C++ — Plugin Loader stub
#include <iostream>
#include <string>
#include <vector>
#include <spdlog/spdlog.h>
namespace org::projectforge::start {
class PluginLoader {
public:
    static PluginLoader& instance() { static PluginLoader pl; return pl; }
    void initAllPlugins() { spdlog::info("Plugins initialized"); }
    void shutdownAll() { spdlog::info("Plugins shutdown"); }
};
} // namespace
