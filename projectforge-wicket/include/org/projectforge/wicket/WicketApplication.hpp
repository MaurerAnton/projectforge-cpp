#pragma once
// ProjectForge C++ Port - Wicket Module Header
// Aggregates all Wicket-like components for server-side HTML rendering.

#include "TemplateEngine.hpp"
#include "BasePage.hpp"
#include "BaseEditPage.hpp"
#include "AbstractForm.hpp"
#include "BaseListPage.hpp"
#include "FormComponent.hpp"
#include "DataTable.hpp"
#include "PagingNavigator.hpp"
#include "SearchFilter.hpp"

namespace org::projectforge::wicket {

// Page factory and application configuration
class WicketApplication {
public:
    WicketApplication() = default;

    void setAppName(const std::string& name) { appName_ = name; }
    const std::string& getAppName() const { return appName_; }

    void setBaseUrl(const std::string& url) { baseUrl_ = url; }
    const std::string& getBaseUrl() const { return baseUrl_; }

    void setStaticResourcePath(const std::string& path) { staticPath_ = path; }
    const std::string& getStaticResourcePath() const { return staticPath_; }

    // Mount a page class at a given URL path
    template<typename PageType>
    void mountPage(const std::string& path) {
        pageRegistry_[path] = []() -> std::unique_ptr<BasePage> {
            return std::make_unique<PageType>();
        };
    }

    // Create a page instance by URL path
    std::unique_ptr<BasePage> createPage(const std::string& path) {
        auto it = pageRegistry_.find(path);
        if (it != pageRegistry_.end()) {
            return it->second();
        }
        return nullptr;
    }

private:
    std::string appName_ = "ProjectForge";
    std::string baseUrl_ = "/";
    std::string staticPath_ = "/static";
    std::unordered_map<std::string, std::function<std::unique_ptr<BasePage>()>> pageRegistry_;
};

} // namespace org::projectforge::wicket
