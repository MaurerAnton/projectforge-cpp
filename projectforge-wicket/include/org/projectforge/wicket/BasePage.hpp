#pragma once
// ProjectForge C++ Port - Base Page
// Core page class providing layout, navigation, and rendering support
// for server-side HTML page generation.

#include "TemplateEngine.hpp"
#include <string>
#include <string_view>
#include <functional>
#include <vector>
#include <unordered_map>
#include <memory>
#include <chrono>

namespace org::projectforge::wicket {

class BasePage {
public:
    BasePage() {
        templateEngine_.loadTemplate("page", TemplateEngine::defaultPageTemplate());
        initDefaults();
    }
    explicit BasePage(const std::string& title) : title_(title) {
        templateEngine_.loadTemplate("page", TemplateEngine::defaultPageTemplate());
        initDefaults();
    }
    virtual ~BasePage() = default;

    // Page lifecycle
    virtual void onInitialize() {}
    virtual void onBeforeRender() {}
    virtual void onAfterRender() {}
    virtual void onConfigure() {}

    // Render the full page
    virtual std::string render() {
        onBeforeRender();
        TemplateContext ctx = buildPageContext();
        std::string result = templateEngine_.render("page", ctx);
        onAfterRender();
        return result;
    }

    // Page properties
    void setTitle(const std::string& title) { title_ = title; }
    const std::string& getTitle() const { return title_; }
    void setPageTitle(const std::string& pt) { pageTitle_ = pt; }
    const std::string& getPageTitle() const { return pageTitle_; }
    void setLang(const std::string& lang) { lang_ = lang; }
    const std::string& getLang() const { return lang_; }
    void setCurrentUser(const std::string& user) { currentUser_ = user; }
    const std::string& getCurrentUser() const { return currentUser_; }

    // Navigation
    struct NavItem {
        std::string label;
        std::string url;
        std::string icon;
        bool active = false;
        std::vector<NavItem> children;
    };
    void addNavItem(const NavItem& item) { navItems_.push_back(item); }
    void addNavItem(NavItem&& item) { navItems_.push_back(std::move(item)); }
    const std::vector<NavItem>& getNavItems() const { return navItems_; }
    void setActiveNav(const std::string& navId) { activeNav_ = navId; }

    // Breadcrumb
    struct BreadcrumbItem {
        std::string label;
        std::string url;
    };
    void addBreadcrumb(const BreadcrumbItem& item) { breadcrumbs_.push_back(item); }
    void addBreadcrumb(BreadcrumbItem&& item) { breadcrumbs_.push_back(std::move(item)); }

    // Head extras (CSS, JS, meta)
    void addHeadExtra(const std::string& html) { headExtras_ += html + "\n"; }
    void addScriptExtra(const std::string& html) { scriptExtras_ += html + "\n"; }

    // Content
    void setContent(const std::string& content) { content_ = content; }
    const std::string& getContent() const { return content_; }

    // Template engine access
    TemplateEngine& getTemplateEngine() { return templateEngine_; }
    const TemplateEngine& getTemplateEngine() const { return templateEngine_; }

    // Flash messages
    enum class FlashType { INFO, SUCCESS, WARNING, ERROR };
    struct FlashMessage {
        FlashType type;
        std::string text;
    };
    void addFlash(FlashType type, const std::string& text) {
        flashMessages_.push_back({type, text});
    }
    const std::vector<FlashMessage>& getFlashMessages() const { return flashMessages_; }
    void clearFlash() { flashMessages_.clear(); }

    // Session/request ID
    void setSessionId(const std::string& sid) { sessionId_ = sid; }
    const std::string& getSessionId() const { return sessionId_; }

    // CSRF protection
    std::string generateCsrfToken() {
        auto now = std::chrono::steady_clock::now().time_since_epoch().count();
        csrfToken_ = "csrf_" + std::to_string(now) + "_" + std::to_string(rand());
        return csrfToken_;
    }
    const std::string& getCsrfToken() const { return csrfToken_; }

protected:
    virtual TemplateContext buildPageContext() {
        TemplateContext ctx;
        ctx.set("title", title_);
        ctx.set("pageTitle", pageTitle_.empty() ? title_ : pageTitle_);
        ctx.set("lang", lang_.empty() ? "en" : lang_);
        ctx.set("currentUser", currentUser_);
        ctx.setEscaped("content", content_, EscapeMode::HTML);
        ctx.set("headExtras", headExtras_);
        ctx.set("scriptExtras", scriptExtras_);

        // Build navbar HTML
        std::string navbarHtml = buildNavbarHtml();
        templateEngine_.registerComponent("navbar", [navbarHtml](const TemplateContext&) {
            return navbarHtml;
        });

        // Build sidebar HTML
        std::string sidebarHtml = buildSidebarHtml();
        templateEngine_.registerComponent("sidebar", [sidebarHtml](const TemplateContext&) {
            return sidebarHtml;
        });

        // Build breadcrumb HTML
        std::string breadcrumbHtml = buildBreadcrumbHtml();
        templateEngine_.registerComponent("breadcrumb", [breadcrumbHtml](const TemplateContext&) {
            return breadcrumbHtml;
        });

        // Flash messages
        if (!flashMessages_.empty()) {
            std::string flashHtml;
            for (const auto& fm : flashMessages_) {
                std::string cssClass;
                switch (fm.type) {
                case FlashType::INFO: cssClass = "info"; break;
                case FlashType::SUCCESS: cssClass = "success"; break;
                case FlashType::WARNING: cssClass = "warning"; break;
                case FlashType::ERROR: cssClass = "error"; break;
                }
                flashHtml += "<div class=\"pf-flash pf-flash-" + cssClass + "\">" +
                    TemplateContext::escape(fm.text, EscapeMode::HTML) + "</div>\n";
            }
            ctx.set("flashMessages", flashHtml);
        }

        return ctx;
    }

    std::string buildNavbarHtml() const {
        std::string html = "<ul class=\"nav-items\">";
        for (const auto& item : navItems_) {
            std::string activeClass = item.active ? " active" : "";
            html += "<li class=\"nav-item" + activeClass + "\">";
            html += "<a href=\"" + TemplateContext::escape(item.url, EscapeMode::HTML) + "\">";
            if (!item.icon.empty()) {
                html += "<i class=\"fa fa-" + TemplateContext::escape(item.icon, EscapeMode::HTML) + "\"></i> ";
            }
            html += TemplateContext::escape(item.label, EscapeMode::HTML) + "</a>";
            if (!item.children.empty()) {
                html += "<ul class=\"nav-submenu\">";
                for (const auto& child : item.children) {
                    html += "<li><a href=\"" + TemplateContext::escape(child.url, EscapeMode::HTML) + "\">" +
                        TemplateContext::escape(child.label, EscapeMode::HTML) + "</a></li>";
                }
                html += "</ul>";
            }
            html += "</li>";
        }
        html += "</ul>";
        return html;
    }

    std::string buildSidebarHtml() const {
        std::string html = "<div class=\"sidebar-menu\">";
        html += "<h3>Navigation</h3>";
        html += "<ul>";
        for (const auto& item : navItems_) {
            if (!item.active) continue;
            if (!item.children.empty()) {
                for (const auto& child : item.children) {
                    html += "<li><a href=\"" + TemplateContext::escape(child.url, EscapeMode::HTML) + "\">" +
                        TemplateContext::escape(child.label, EscapeMode::HTML) + "</a></li>";
                }
            }
        }
        html += "</ul>";
        html += "</div>";
        return html;
    }

    std::string buildBreadcrumbHtml() const {
        std::string html = "<ol class=\"breadcrumb\">";
        for (size_t i = 0; i < breadcrumbs_.size(); ++i) {
            const auto& bc = breadcrumbs_[i];
            html += "<li class=\"breadcrumb-item";
            if (i == breadcrumbs_.size() - 1) html += " active";
            html += "\">";
            if (i < breadcrumbs_.size() - 1) {
                html += "<a href=\"" + TemplateContext::escape(bc.url, EscapeMode::HTML) + "\">" +
                    TemplateContext::escape(bc.label, EscapeMode::HTML) + "</a>";
            } else {
                html += TemplateContext::escape(bc.label, EscapeMode::HTML);
            }
            html += "</li>";
        }
        html += "</ol>";
        return html;
    }

    void initDefaults() {
        lang_ = "en";
        headExtras_ = R"(<link rel="stylesheet" href="/styles/projectforge.css">
<link rel="stylesheet" href="/styles/jqueryui/1.10.4/smoothness/jquery-ui-1.10.4.custom.css">
<style>.pf-flash { padding: 12px 20px; margin: 10px 0; border-radius: 4px; }
.pf-flash-info { background: #d9edf7; color: #31708f; border: 1px solid #bce8f1; }
.pf-flash-success { background: #dff0d8; color: #3c763d; border: 1px solid #d6e9c6; }
.pf-flash-warning { background: #fcf8e3; color: #8a6d3b; border: 1px solid #faebcc; }
.pf-flash-error { background: #f2dede; color: #a94442; border: 1px solid #ebccd1; }
</style>)";
    }

    std::string title_;
    std::string pageTitle_;
    std::string lang_;
    std::string currentUser_;
    std::string content_;
    std::string headExtras_;
    std::string scriptExtras_;
    std::string activeNav_;
    std::string sessionId_;
    std::string csrfToken_;
    std::vector<NavItem> navItems_;
    std::vector<BreadcrumbItem> breadcrumbs_;
    std::vector<FlashMessage> flashMessages_;
    TemplateEngine templateEngine_;
};

} // namespace org::projectforge::wicket
