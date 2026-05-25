#pragma once
// ProjectForge C++ Port - Address Pages (Wicket-style)
// Concrete page implementations for address/contact management:
// list, edit, view with address fields, categories, and vCard support.

#include "BasePage.hpp"
#include "BaseEditPage.hpp"
#include "BaseListPage.hpp"
#include "FormComponent.hpp"
#include "SearchFilter.hpp"
#include <string>
#include <vector>

namespace org::projectforge::wicket {

struct AddressEntity {
    int id = 0;
    std::string firstName;
    std::string lastName;
    std::string organization;
    std::string title;
    std::string email;
    std::string phoneBusiness;
    std::string phoneMobile;
    std::string phonePrivate;
    std::string fax;
    std::string website;
    std::string street;
    std::string zipCode;
    std::string city;
    std::string state;
    std::string country;
    std::string category;
    std::string notes;
    bool favorite = false;
    bool hasImage = false;
    std::string created;
    std::string modified;
};

class AddressListPage : public BaseListPage<AddressEntity> {
public:
    AddressListPage() : BaseListPage<AddressEntity>("Addresses") {
        initColumns();
        addBreadcrumb({"Home", "/"});
        addBreadcrumb({"Addresses", "/address/"});
        setNewEntityUrl("/address/new");
        setEditUrl("/address/edit?id=");
        setViewUrl("/address/view?id=");
        setPageSize(20);
    }

    void initColumns() {
        addColumn("name", "Name",
            [](const AddressEntity& a, size_t) {
                return "<a href=\"/address/view?id=" + std::to_string(a.id) + "\">" +
                    a.lastName + ", " + a.firstName + "</a>";
            });
        addColumn("organization", "Organization",
            [](const AddressEntity& a, size_t) { return a.organization; });
        addColumn("email", "Email",
            [](const AddressEntity& a, size_t) {
                return a.email.empty() ? "" :
                    "<a href=\"mailto:" + a.email + "\">" + a.email + "</a>";
            });
        addColumn("phoneBusiness", "Phone",
            [](const AddressEntity& a, size_t) { return a.phoneBusiness; });
        addColumn("city", "City",
            [](const AddressEntity& a, size_t) { return a.city; });
        addColumn("country", "Country",
            [](const AddressEntity& a, size_t) { return a.country; });
        addColumn("category", "Category",
            [](const AddressEntity& a, size_t) {
                return a.category.empty() ? "" :
                    "<span class=\"badge badge-info\">" + a.category + "</span>";
            });
        addColumn("favorite", "Fav",
            [](const AddressEntity& a, size_t) {
                return a.favorite ?
                    "<span class=\"star-icon\">&#9733;</span>" : "";
            });
    }
};

class AddressEditPage : public BaseEditPage<AddressEntity> {
public:
    AddressEditPage() : BaseEditPage<AddressEntity>("Address") {
        addBreadcrumb({"Home", "/"});
        addBreadcrumb({"Addresses", "/address/"});
        setFormAction("/address/save");
        setCancelUrl("/address/");
        setShowDelete(true);

        initForm();
        setupValidators();
    }

    void initForm() {
        // Name
        addField("title", "Title", FieldType::TEXT);
        addField("firstName", "First Name", FieldType::TEXT).required = true;
        addField("lastName", "Last Name", FieldType::TEXT).required = true;

        // Organization
        addField("organization", "Organization", FieldType::TEXT);

        // Contact
        addField("email", "Email", FieldType::EMAIL);
        addField("phoneBusiness", "Phone (Business)", FieldType::TEXT);
        addField("phoneMobile", "Phone (Mobile)", FieldType::TEXT);
        addField("phonePrivate", "Phone (Private)", FieldType::TEXT);
        addField("fax", "Fax", FieldType::TEXT);
        addField("website", "Website", FieldType::TEXT);

        // Address
        addField("street", "Street", FieldType::TEXT);
        addField("zipCode", "ZIP Code", FieldType::TEXT);
        addField("city", "City", FieldType::TEXT);
        addField("state", "State/Province", FieldType::TEXT);

        // Country select
        auto& countryField = addField("country", "Country", FieldType::SELECT);
        countryField.options = {
            {"DE", "Germany"},
            {"AT", "Austria"},
            {"CH", "Switzerland"},
            {"FR", "France"},
            {"GB", "United Kingdom"},
            {"US", "United States"},
            {"IT", "Italy"},
            {"ES", "Spain"},
            {"NL", "Netherlands"},
            {"BE", "Belgium"},
        };

        // Category
        auto& catField = addField("category", "Category", FieldType::SELECT);
        catField.options = {
            {"", ""},
            {"BUSINESS", "Business"},
            {"PRIVATE", "Private"},
            {"CUSTOMER", "Customer"},
            {"SUPPLIER", "Supplier"},
            {"PARTNER", "Partner"},
        };

        // Details
        addField("notes", "Notes", FieldType::TEXTAREA).rows = 5;
        addField("favorite", "Favorite", FieldType::CHECKBOX).helpText =
            "Mark this address as a favorite for quick access.";

        // Photo
        addField("photo", "Photo", FieldType::FILE_UPLOAD).helpText =
            "Upload a photo (PNG or JPEG, max 5 MB).";
    }

    void setupValidators() {
        addValidator("email", [](const AddressEntity&, const std::string& value)
            -> std::optional<ValidationError> {
            if (!value.empty() && value.find('@') == std::string::npos) {
                return ValidationError{"email", "Please enter a valid email address."};
            }
            return std::nullopt;
        });

        addValidator("website", [](const AddressEntity&, const std::string& value)
            -> std::optional<ValidationError> {
            if (!value.empty() && value.find("http") != 0) {
                return ValidationError{"website", "Website URL should start with http:// or https://"};
            }
            return std::nullopt;
        });
    }
};

class AddressViewPage : public BasePage {
public:
    AddressViewPage() : BasePage("View Address") {
        addBreadcrumb({"Home", "/"});
        addBreadcrumb({"Addresses", "/address/"});
    }

    void setAddress(const AddressEntity& addr) { address_ = addr; }

    std::string render() override {
        onBeforeRender();
        setPageTitle(address_.lastName + ", " + address_.firstName);

        std::string content;
        content += "<div class=\"pf-view-page\">";
        content += "<div class=\"view-header\">";
        content += "<div class=\"view-avatar\">";
        if (address_.hasImage) {
            content += "<img src=\"/address/photo/" + std::to_string(address_.id) +
                "\" alt=\"Photo\" class=\"avatar-image\">";
        } else {
            content += "<div class=\"avatar-placeholder\">" +
                std::string(1, address_.firstName.empty() ? '?' : address_.firstName[0]) +
                std::string(1, address_.lastName.empty() ? '?' : address_.lastName[0]) +
                "</div>";
        }
        content += "</div>";
        content += "<div class=\"view-title\">";
        content += "<h2>" + TemplateContext::escape(
            (address_.title.empty() ? "" : address_.title + " ") +
            address_.firstName + " " + address_.lastName, EscapeMode::HTML);
        if (address_.favorite) {
            content += " <span class=\"star-icon\">&#9733;</span>";
        }
        content += "</h2>";
        if (!address_.organization.empty()) {
            content += "<p class=\"organization\">" +
                TemplateContext::escape(address_.organization, EscapeMode::HTML) + "</p>";
        }
        content += "</div>";
        content += "<div class=\"view-actions\">";
        content += "<a href=\"/address/edit?id=" + std::to_string(address_.id) +
            "\" class=\"btn btn-primary\">Edit</a>";
        content += "<a href=\"/address/\" class=\"btn btn-secondary\">Back to List</a>";
        content += "</div></div>";

        content += "<div class=\"view-details\">";
        content += "<div class=\"detail-section\">";
        content += "<h3>Contact Information</h3>";
        content += renderDetailRow("Email",
            address_.email.empty() ? "" :
            "<a href=\"mailto:" + address_.email + "\">" + address_.email + "</a>");
        content += renderDetailRow("Phone (Business)", address_.phoneBusiness);
        content += renderDetailRow("Phone (Mobile)", address_.phoneMobile);
        content += renderDetailRow("Phone (Private)", address_.phonePrivate);
        content += renderDetailRow("Fax", address_.fax);
        content += renderDetailRow("Website",
            address_.website.empty() ? "" :
            "<a href=\"" + address_.website + "\" target=\"_blank\">" + address_.website + "</a>");
        content += "</div>";

        content += "<div class=\"detail-section\">";
        content += "<h3>Address</h3>";
        content += renderDetailRow("Street", address_.street);
        content += renderDetailRow("ZIP/City",
            (address_.zipCode.empty() ? "" : address_.zipCode + " ") + address_.city);
        content += renderDetailRow("State", address_.state);
        content += renderDetailRow("Country", address_.country);
        content += "</div>";

        if (!address_.category.empty() || !address_.notes.empty()) {
            content += "<div class=\"detail-section\">";
            content += "<h3>Additional Information</h3>";
            if (!address_.category.empty()) {
                content += renderDetailRow("Category",
                    "<span class=\"badge badge-info\">" + address_.category + "</span>");
            }
            if (!address_.notes.empty()) {
                content += "<div class=\"detail-row\"><span class=\"detail-label\">Notes:</span> " +
                    "<div class=\"detail-value notes-content\">" +
                    TemplateContext::escape(address_.notes, EscapeMode::HTML) + "</div></div>";
            }
            content += "</div>";
        }

        content += "<div class=\"detail-section\">";
        content += "<h3>Metadata</h3>";
        content += renderDetailRow("Created", address_.created);
        content += renderDetailRow("Last Modified", address_.modified);
        content += "</div>";

        content += "</div></div>";

        setContent(content);
        TemplateContext pageCtx = buildPageContext();
        std::string result = templateEngine_.render("page", pageCtx);
        onAfterRender();
        return result;
    }

private:
    std::string renderDetailRow(const std::string& label, const std::string& value) const {
        if (value.empty()) return "";
        return "<div class=\"detail-row\"><span class=\"detail-label\">" +
            TemplateContext::escape(label, EscapeMode::HTML) + ":</span> " +
            "<span class=\"detail-value\">" + value + "</span></div>";
    }

    AddressEntity address_;
};

} // namespace org::projectforge::wicket
