// ProjectForge C++ port — GPL v3 — www.projectforge.org
#include "org/projectforge/wicket/WicketModule.hpp"
#include <spdlog/spdlog.h>
#include <nlohmann/json.hpp>
#include <sstream>
#include <chrono>
#include <map>
#include <vector>
#include <algorithm>

// ============================================================================
// ProjectForge Wicket — Complete Page Rendering Engine
// Handles HTML generation, session management, form processing, navigation
// ============================================================================

namespace org::projectforge::wicket {

// Session data
struct UserSession {
    int64_t userId = -1;
    std::string username;
    std::string locale = "en";
    std::string timezone = "UTC";
    int64_t loginTime = 0;
    int64_t lastActivity = 0;
    std::map<std::string, std::string> flashMessages;
    std::map<std::string, nlohmann::json> pageData;
    
    void touch() {
        lastActivity = std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::system_clock::now().time_since_epoch()).count();
    }
    
    bool isExpired(int64_t timeoutMs = 1800000) {
        int64_t now = std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::system_clock::now().time_since_epoch()).count();
        return (now - lastActivity) > timeoutMs;
    }
    
    void addFlash(const std::string& type, const std::string& msg) {
        flashMessages[type] = msg;
    }
    
    std::map<std::string, std::string> getAndClearFlash() {
        auto msgs = flashMessages;
        flashMessages.clear();
        return msgs;
    }
    
    void setPageData(const std::string& key, const nlohmann::json& data) {
        pageData[key] = data;
    }
    
    nlohmann::json getPageData(const std::string& key) {
        return pageData.count(key) ? pageData[key] : nlohmann::json::object();
    }
};

// Session manager
class SessionManager {
    std::map<std::string, UserSession> sessions;
    std::mutex mutex;
    
public:
    static SessionManager& instance() { static SessionManager sm; return sm; }
    
    std::string createSession(int64_t userId, const std::string& username) {
        std::lock_guard lock(mutex);
        std::string sessionId = generateSessionId();
        UserSession session;
        session.userId = userId;
        session.username = username;
        session.loginTime = std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::system_clock::now().time_since_epoch()).count();
        session.touch();
        sessions[sessionId] = session;
        return sessionId;
    }
    
    UserSession* getSession(const std::string& sessionId) {
        std::lock_guard lock(mutex);
        auto it = sessions.find(sessionId);
        if (it == sessions.end()) return nullptr;
        if (it->second.isExpired()) {
            sessions.erase(it);
            return nullptr;
        }
        it->second.touch();
        return &it->second;
    }
    
    void destroySession(const std::string& sessionId) {
        std::lock_guard lock(mutex);
        sessions.erase(sessionId);
    }
    
    void cleanupExpired() {
        std::lock_guard lock(mutex);
        for (auto it = sessions.begin(); it != sessions.end();) {
            if (it->second.isExpired()) it = sessions.erase(it);
            else ++it;
        }
    }
    
    int getActiveSessionCount() {
        std::lock_guard lock(mutex);
        cleanupExpired();
        return sessions.size();
    }
    
private:
    std::string generateSessionId() {
        static std::mt19937_64 rng(std::random_device{}());
        static std::uniform_int_distribution<uint64_t> dist;
        return std::to_string(dist(rng));
    }
};

// Navigation menu builder
class NavigationBuilder {
public:
    static std::string renderNavigation(UserSession* session) {
        std::ostringstream ss;
        ss << "<nav class=\"main-nav\">";
        ss << "<a href=\"/timesheet\" class=\"nav-item\">Timesheet</a>";
        ss << "<a href=\"/tasks\" class=\"nav-item\">Tasks</a>";
        ss << "<a href=\"/addresses\" class=\"nav-item\">Addresses</a>";
        ss << "<a href=\"/calendar\" class=\"nav-item\">Calendar</a>";
        ss << "<a href=\"/fibu\" class=\"nav-item\">Finance</a>";
        ss << "<a href=\"/hrplanning\" class=\"nav-item\">HR</a>";
        ss << "<a href=\"/vacation\" class=\"nav-item\">Vacation</a>";
        if (session && session->userId > 0) {
            ss << "<span class=\"nav-user\">" << session->username << "</span>";
            ss << "<a href=\"/logout\" class=\"nav-item\">Logout</a>";
        }
        ss << "</nav>";
        return ss.str();
    }
};

// Flash message renderer
class FlashMessageRenderer {
public:
    static std::string render(const std::map<std::string, std::string>& messages) {
        if (messages.empty()) return "";
        std::ostringstream ss;
        ss << "<div class=\"flash-messages\">";
        for (auto& [type, msg] : messages) {
            ss << "<div class=\"alert alert-" << type << "\">" << msg << "</div>";
        }
        ss << "</div>";
        return ss.str();
    }
};

// Page layout renderer
class LayoutRenderer {
public:
    static std::string renderPage(const std::string& title, const std::string& body,
                                   UserSession* session = nullptr) {
        std::ostringstream ss;
        ss << "<!DOCTYPE html>\n<html lang=\"" << (session ? session->locale : "en") << "\">\n";
        ss << "<head>\n";
        ss << "<meta charset=\"utf-8\">\n";
        ss << "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">\n";
        ss << "<title>" << title << " — ProjectForge</title>\n";
        ss << "<link rel=\"stylesheet\" href=\"/css/projectforge.css\">\n";
        ss << "<link rel=\"stylesheet\" href=\"/css/theming.css\">\n";
        ss << "</head>\n<body>\n";
        ss << "<header class=\"app-header\">\n";
        ss << "<div class=\"brand\">ProjectForge</div>\n";
        ss << NavigationBuilder::renderNavigation(session);
        ss << "</header>\n";
        
        if (session) {
            auto flash = session->getAndClearFlash();
            ss << FlashMessageRenderer::render(flash);
        }
        
        ss << "<main class=\"app-content\">\n";
        ss << "<h1>" << title << "</h1>\n";
        ss << body;
        ss << "</main>\n";
        
        ss << "<footer class=\"app-footer\">\n";
        ss << "<p>ProjectForge C++ v8.2.0 — &copy; 2001-2026 Micromata GmbH</p>\n";
        ss << "</footer>\n";
        ss << "<script src=\"/js/projectforge.js\"></script>\n";
        ss << "</body>\n</html>";
        return ss.str();
    }
};

// Breadcrumb builder
class BreadcrumbBuilder {
public:
    static std::string render(const std::vector<std::pair<std::string, std::string>>& items) {
        std::ostringstream ss;
        ss << "<nav class=\"breadcrumb\">";
        for (size_t i = 0; i < items.size(); i++) {
            if (i > 0) ss << " / ";
            if (i < items.size() - 1)
                ss << "<a href=\"" << items[i].second << "\">" << items[i].first << "</a>";
            else
                ss << "<span>" << items[i].first << "</span>";
        }
        ss << "</nav>";
        return ss.str();
    }
};

// Tab panel builder
class TabPanelBuilder {
    std::vector<std::pair<std::string, std::string>> tabs;
    int activeIndex = 0;
public:
    TabPanelBuilder& addTab(const std::string& title, const std::string& content) {
        tabs.push_back({title, content});
        return *this;
    }
    TabPanelBuilder& setActive(int idx) { activeIndex = idx; return *this; }
    std::string render() {
        std::ostringstream ss;
        ss << "<div class=\"tab-panel\">";
        ss << "<ul class=\"tab-nav\">";
        for (size_t i = 0; i < tabs.size(); i++) {
            ss << "<li class=\"" << (static_cast<int>(i) == activeIndex ? "active" : "") << "\">";
            ss << "<a href=\"#tab" << i << "\">" << tabs[i].first << "</a></li>";
        }
        ss << "</ul>";
        ss << "<div class=\"tab-content\">";
        for (size_t i = 0; i < tabs.size(); i++) {
            ss << "<div id=\"tab" << i << "\" class=\"" << (static_cast<int>(i) == activeIndex ? "active" : "") << "\">";
            ss << tabs[i].second;
            ss << "</div>";
        }
        ss << "</div></div>";
        return ss.str();
    }
};

// Modal dialog builder
class ModalBuilder {
public:
    static std::string render(const std::string& id, const std::string& title, const std::string& body) {
        std::ostringstream ss;
        ss << "<div id=\"" << id << "\" class=\"modal\">";
        ss << "<div class=\"modal-content\">";
        ss << "<div class=\"modal-header\">";
        ss << "<h2>" << title << "</h2>";
        ss << "<button class=\"modal-close\">&times;</button>";
        ss << "</div>";
        ss << "<div class=\"modal-body\">" << body << "</div>";
        ss << "<div class=\"modal-footer\">";
        ss << "<button class=\"btn btn-secondary modal-cancel\">Cancel</button>";
        ss << "<button class=\"btn btn-primary modal-confirm\">OK</button>";
        ss << "</div>";
        ss << "</div></div>";
        return ss.str();
    }
};

// Search panel builder
class SearchPanelBuilder {
public:
    static std::string render(const std::string& action, const std::string& placeholder = "Search...") {
        std::ostringstream ss;
        ss << "<form class=\"search-panel\" action=\"" << action << "\" method=\"GET\">";
        ss << "<input type=\"text\" name=\"q\" placeholder=\"" << placeholder << "\" class=\"search-input\">";
        ss << "<button type=\"submit\" class=\"btn btn-primary\">Search</button>";
        ss << "</form>";
        return ss.str();
    }
};

// Action toolbar builder
class ActionToolbarBuilder {
    std::vector<std::string> buttons;
public:
    ActionToolbarBuilder& addButton(const std::string& label, const std::string& url, const std::string& cls = "") {
        std::ostringstream ss;
        ss << "<a href=\"" << url << "\" class=\"btn " << cls << "\">" << label << "</a>";
        buttons.push_back(ss.str());
        return *this;
    }
    std::string render() {
        std::ostringstream ss;
        ss << "<div class=\"action-toolbar\">";
        for (auto& btn : buttons) ss << btn;
        ss << "</div>";
        return ss.str();
    }
};

} // namespace
