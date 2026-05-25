// ProjectForge C++ port — GPL v3 — www.projectforge.org
#pragma once
#include <string>
#include <map>
#include <any>
#include <functional>
#include <memory>
#include <stdexcept>

namespace org::projectforge::common {

class BeanNotFoundException : public std::runtime_error {
public:
    explicit BeanNotFoundException(const std::string& msg) : std::runtime_error(msg) {}
};

class BeanHelper {
public:
    static BeanHelper& instance();

    template<typename T>
    void registerBean(const std::string& name, std::shared_ptr<T> bean) {
        beans_[name] = std::static_pointer_cast<void>(bean);
    }

    template<typename T>
    void registerSingleton(const std::string& name, std::function<std::shared_ptr<T>()> factory) {
        factories_[name] = [factory]() -> std::shared_ptr<void> {
            static auto instance = factory();
            return instance;
        };
    }

    template<typename T>
    std::shared_ptr<T> getBean(const std::string& name) {
        auto it = beans_.find(name);
        if (it != beans_.end()) return std::static_pointer_cast<T>(it->second);
        auto fit = factories_.find(name);
        if (fit != factories_.end()) {
            auto bean = std::static_pointer_cast<T>(fit->second());
            beans_[name] = bean;
            return bean;
        }
        throw BeanNotFoundException("Bean not found: " + name);
    }

    bool hasBean(const std::string& name) const;
    void removeBean(const std::string& name);
    void clear();

private:
    BeanHelper() = default;
    std::map<std::string, std::shared_ptr<void>> beans_;
    std::map<std::string, std::function<std::shared_ptr<void>()>> factories_;
};
}