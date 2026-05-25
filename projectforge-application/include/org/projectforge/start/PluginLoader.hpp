// ProjectForge C++ port — GPL v3 — www.projectforge.org
#pragma once
#include <string>
#include <vector>
#include <functional>
#include <memory>

namespace org::projectforge::start {

class Plugin {
public:
    virtual ~Plugin() = default;
    virtual std::string getName() const = 0;
    virtual std::string getVersion() const = 0;
    virtual void init() = 0;
    virtual void shutdown() = 0;
};

using PluginFactory = std::function<std::shared_ptr<Plugin>()>;

class PluginLoader {
public:
    static PluginLoader& instance();
    void registerPlugin(const std::string& name, PluginFactory factory);
    void initAllPlugins();
    void shutdownAll();
    std::vector<std::string> getPluginNames() const;

private:
    std::vector<std::pair<std::string, PluginFactory>> factories_;
    std::vector<std::shared_ptr<Plugin>> plugins_;
};
}