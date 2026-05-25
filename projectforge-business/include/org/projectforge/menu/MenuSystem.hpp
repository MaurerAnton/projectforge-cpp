// ProjectForge C++ port — GPL v3 — www.projectforge.org
#pragma once
#include <string>
#include <vector>
#include <memory>
#include <functional>
#include <nlohmann/json.hpp>

namespace org::projectforge::menu {

struct MenuItemDefId {
    static constexpr const char* TIMESHEET = "TIMESHEET";
    static constexpr const char* TASKS = "TASKS";
    static constexpr const char* ADDRESSES = "ADDRESSES";
    static constexpr const char* CALENDAR = "CALENDAR";
    static constexpr const char* FIBU = "FIBU";
    static constexpr const char* HR_PLANNING = "HR_PLANNING";
    static constexpr const char* VACATION = "VACATION";
    static constexpr const char* ADMINISTRATION = "ADMINISTRATION";
    static constexpr const char* BOOK = "BOOK";
    static constexpr const char* CONFIGURATION = "CONFIGURATION";
    static constexpr const char* POLL = "POLL";
    static constexpr const char* MEMO = "MEMO";
    static constexpr const char* MERLIN = "MERLIN";
    static constexpr const char* MARKETING = "MARKETING";
    static constexpr const char* BANKING = "BANKING";
    static constexpr const char* TODO = "TODO";
};

class MenuItem {
public:
    MenuItem(const std::string& id, const std::string& label, const std::string& icon="", const std::string& url="")
        : id_(id), label_(label), icon_(icon), url_(url) {}

    MenuItem& addChild(const MenuItem& child) { children_.push_back(child); return *this; }
    MenuItem& setVisible(bool v) { visible_ = v; return *this; }
    MenuItem& setFavorite(bool f) { favorite_ = f; return *this; }
    MenuItem& setBadge(const std::string& b) { badge_ = b; return *this; }
    MenuItem& setDivider() { isDivider_ = true; return *this; }
    MenuItem& addRequiredRight(const std::string& right) { requiredRights_.push_back(right); return *this; }

    nlohmann::json toJson() const {
        nlohmann::json j;
        j["id"] = id_;
        j["label"] = label_;
        if (!icon_.empty()) j["icon"] = icon_;
        if (!url_.empty()) j["url"] = url_;
        if (favorite_) j["favorite"] = true;
        if (!badge_.empty()) j["badge"] = badge_;
        if (isDivider_) j["divider"] = true;
        if (!children_.empty()) {
            nlohmann::json kids = nlohmann::json::array();
            for (auto& c : children_) kids.push_back(c.toJson());
            j["children"] = kids;
        }
        return j;
    }

    const std::string& getId() const { return id_; }
    const std::string& getLabel() const { return label_; }
    bool isVisible() const { return visible_; }

private:
    std::string id_, label_, icon_, url_, badge_;
    bool visible_ = true, favorite_ = false, isDivider_ = false;
    std::vector<MenuItem> children_;
    std::vector<std::string> requiredRights_;
};

class MenuCreator {
public:
    static MenuItem createMainMenu(bool isAdmin = false) {
        MenuItem root("root", "Menu");

        root.addChild(MenuItem(MenuItemDefId::TIMESHEET, "Timesheet", "clock", "/timesheet"));
        root.addChild(MenuItem(MenuItemDefId::TASKS, "Tasks", "tasks", "/tasks"));
        root.addChild(MenuItem(MenuItemDefId::ADDRESSES, "Addresses", "address-book", "/addresses"));
        root.addChild(MenuItem(MenuItemDefId::CALENDAR, "Calendar", "calendar", "/calendar"));

        MenuItem fibu(MenuItemDefId::FIBU, "Finance", "euro", "/fibu");
        fibu.addChild(MenuItem("FIBU_RECHNUNG", "Invoices", "file-invoice", "/fibu/rechnung"));
        fibu.addChild(MenuItem("FIBU_KONTO", "Accounts", "list", "/fibu/konto"));
        fibu.addChild(MenuItem("FIBU_KOST", "Cost Centers", "money-bill", "/fibu/kost"));
        fibu.addChild(MenuItem("FIBU_AUFTRAG", "Orders", "shopping-cart", "/fibu/auftrag"));
        fibu.addChild(MenuItem("FIBU_DATEV", "DATEV Export", "file-export", "/fibu/datev"));
        root.addChild(fibu);

        root.addChild(MenuItem(MenuItemDefId::HR_PLANNING, "HR Planning", "users", "/hrplanning"));
        root.addChild(MenuItem(MenuItemDefId::VACATION, "Vacation", "umbrella-beach", "/vacation"));
        root.addChild(MenuItem(MenuItemDefId::BOOK, "Book", "book", "/book"));
        root.addChild(MenuItem(MenuItemDefId::POLL, "Polls", "poll", "/poll"));
        root.addChild(MenuItem(MenuItemDefId::MEMO, "Memos", "sticky-note", "/memo"));

        if (isAdmin) {
            MenuItem admin(MenuItemDefId::ADMINISTRATION, "Administration", "cog", "/admin");
            admin.addChild(MenuItem("ADMIN_USERS", "Users", "user", "/admin/users"));
            admin.addChild(MenuItem("ADMIN_GROUPS", "Groups", "users-cog", "/admin/groups"));
            admin.addChild(MenuItem("ADMIN_SYSTEM", "System", "server", "/admin/system"));
            admin.addChild(MenuItem("ADMIN_CONFIG", "Configuration", "sliders-h", "/admin/config"));
            admin.addChild(MenuItem("ADMIN_LOGS", "Logs", "file-alt", "/admin/logs"));
            admin.addChild(MenuItem("ADMIN_JOBS", "Jobs", "cogs", "/admin/jobs"));
            admin.addChild(MenuItem("ADMIN_BACKUP", "Backup", "database", "/admin/backup"));
            root.addChild(admin);
        }

        return root;
    }
};

} // namespace
