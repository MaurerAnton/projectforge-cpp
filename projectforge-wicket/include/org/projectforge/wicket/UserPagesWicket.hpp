#pragma once
// ProjectForge C++ Port - User Pages (Wicket-style)
// Concrete page implementations for user management: list, edit, view.

#include "BasePage.hpp"
#include "BaseEditPage.hpp"
#include "BaseListPage.hpp"
#include "FormComponent.hpp"
#include "SearchFilter.hpp"
#include <string>
#include <vector>

namespace org::projectforge::wicket {

struct UserEntity {
    int id = 0;
    std::string username;
    std::string firstName;
    std::string lastName;
    std::string email;
    std::string phone;
    std::string role;
    bool active = true;
    bool localUser = false;
    std::string lastLogin;
    std::string created;
    std::string modified;
};

class UserListPage : public BaseListPage<UserEntity> {
public:
    UserListPage() : BaseListPage<UserEntity>("Users") {
        initColumns();
        addBreadcrumb({"Home", "/"});
        addBreadcrumb({"Administration", "/admin/"});
        addBreadcrumb({"Users", "/admin/users/"});
        setNewEntityUrl("/admin/users/new");
        setEditUrl("/admin/users/edit?id=");
        setViewUrl("/admin/users/view?id=");
    }

    void initColumns() {
        addColumn("id", "ID",
            [](const UserEntity& u, size_t) { return std::to_string(u.id); });
        addColumn("username", "Username",
            [](const UserEntity& u, size_t) {
                return "<a href=\"/admin/users/view?id=" + std::to_string(u.id) + "\">" +
                    u.username + "</a>";
            });
        addColumn("firstName", "First Name",
            [](const UserEntity& u, size_t) { return u.firstName; });
        addColumn("lastName", "Last Name",
            [](const UserEntity& u, size_t) { return u.lastName; });
        addColumn("email", "Email",
            [](const UserEntity& u, size_t) {
                return "<a href=\"mailto:" + u.email + "\">" + u.email + "</a>";
            });
        addColumn("role", "Role",
            [](const UserEntity& u, size_t) { return u.role; });
        addColumn("active", "Active",
            [](const UserEntity& u, size_t) {
                return u.active ? "<span class=\"badge badge-success\">Yes</span>"
                    : "<span class=\"badge badge-danger\">No</span>";
            });
        addColumn("lastLogin", "Last Login",
            [](const UserEntity& u, size_t) { return u.lastLogin; });
    }
};

class UserEditPage : public BaseEditPage<UserEntity> {
public:
    UserEditPage() : BaseEditPage<UserEntity>("User") {
        addBreadcrumb({"Home", "/"});
        addBreadcrumb({"Administration", "/admin/"});
        addBreadcrumb({"Users", "/admin/users/"});
        setFormAction("/admin/users/save");
        setCancelUrl("/admin/users/");
        setShowDelete(true);

        initForm();
        setupValidators();
    }

    void initForm() {
        addField("username", "Username", FieldType::TEXT).required = true;
        addField("firstName", "First Name", FieldType::TEXT).required = true;
        addField("lastName", "Last Name", FieldType::TEXT).required = true;
        addField("email", "Email", FieldType::EMAIL).required = true;
        addField("phone", "Phone", FieldType::TEXT);

        auto& roleField = addField("role", "Role", FieldType::SELECT);
        roleField.required = true;
        roleField.options = {
            {"USER", "User"},
            {"MANAGER", "Manager"},
            {"ADMIN", "Administrator"},
            {"FINANCE", "Finance"},
        };

        auto& activeField = addField("active", "Active", FieldType::CHECKBOX);
        activeField.value = "true";

        addField("localUser", "Local User", FieldType::CHECKBOX).helpText =
            "If checked, this user is managed locally and not synced to external IdP.";
    }

    void setupValidators() {
        addValidator("username", [](const UserEntity& entity, const std::string& value)
            -> std::optional<ValidationError> {
            if (value.size() < 3) {
                return ValidationError{"username", "Username must be at least 3 characters."};
            }
            if (value.size() > 50) {
                return ValidationError{"username", "Username must be at most 50 characters."};
            }
            for (char c : value) {
                if (!isalnum(c) && c != '_' && c != '-' && c != '.') {
                    return ValidationError{"username",
                        "Username may only contain letters, numbers, underscores, hyphens, and dots."};
                }
            }
            return std::nullopt;
        });

        addValidator("email", [](const UserEntity&, const std::string& value)
            -> std::optional<ValidationError> {
            if (value.find('@') == std::string::npos || value.find('.') == std::string::npos) {
                return ValidationError{"email", "Please enter a valid email address."};
            }
            return std::nullopt;
        });
    }
};

class UserViewPage : public BasePage {
public:
    UserViewPage() : BasePage("View User") {
        addBreadcrumb({"Home", "/"});
        addBreadcrumb({"Administration", "/admin/"});
        addBreadcrumb({"Users", "/admin/users/"});
    }

    void setUser(const UserEntity& user) { user_ = user; }

    std::string render() override {
        onBeforeRender();

        std::string content;
        content += "<div class=\"pf-view-page\">";
        content += "<div class=\"view-header\">";
        content += "<h2>" + TemplateContext::escape(user_.firstName + " " + user_.lastName, EscapeMode::HTML) + "</h2>";
        content += "<div class=\"view-actions\">";
        content += "<a href=\"/admin/users/edit?id=" + std::to_string(user_.id) +
            "\" class=\"btn btn-primary\">Edit</a>";
        content += "<a href=\"/admin/users/\" class=\"btn btn-secondary\">Back to List</a>";
        content += "</div></div>";

        content += "<div class=\"view-details\">";
        content += renderDetailRow("ID", std::to_string(user_.id));
        content += renderDetailRow("Username", user_.username);
        content += renderDetailRow("Email", "<a href=\"mailto:" + user_.email + "\">" + user_.email + "</a>");
        content += renderDetailRow("Phone", user_.phone);
        content += renderDetailRow("Role", user_.role);
        content += renderDetailRow("Status", user_.active ? "Active" : "Inactive");
        content += renderDetailRow("Local User", user_.localUser ? "Yes" : "No");
        content += renderDetailRow("Last Login", user_.lastLogin);
        content += renderDetailRow("Created", user_.created);
        content += "</div></div>";

        setContent(content);

        TemplateContext pageCtx = buildPageContext();
        std::string result = templateEngine_.render("page", pageCtx);
        onAfterRender();
        return result;
    }

private:
    std::string renderDetailRow(const std::string& label, const std::string& value) const {
        return "<div class=\"detail-row\"><span class=\"detail-label\">" +
            TemplateContext::escape(label, EscapeMode::HTML) + ":</span> " +
            "<span class=\"detail-value\">" + value + "</span></div>";
    }

    UserEntity user_;
};

} // namespace org::projectforge::wicket
