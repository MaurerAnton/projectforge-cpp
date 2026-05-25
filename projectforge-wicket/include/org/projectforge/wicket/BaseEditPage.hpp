#pragma once
// ProjectForge C++ Port - Base Edit Page
// Provides form-based entity editing with validation, field management,
// and CRUD operations support for server-side rendering.

#include "BasePage.hpp"
#include "AbstractForm.hpp"
#include <string>
#include <string_view>
#include <vector>
#include <unordered_map>
#include <functional>
#include <memory>
#include <optional>

namespace org::projectforge::wicket {

enum class FieldType {
    TEXT,
    PASSWORD,
    TEXTAREA,
    SELECT,
    CHECKBOX,
    DATE,
    DATETIME,
    NUMBER,
    EMAIL,
    HIDDEN,
    FILE_UPLOAD,
    READONLY_TEXT,
    RICH_TEXT
};

struct ValidationError {
    std::string fieldName;
    std::string message;
};

struct FormField {
    std::string id;
    std::string name;
    std::string label;
    FieldType type = FieldType::TEXT;
    std::string value;
    std::string placeholder;
    std::string helpText;
    std::vector<std::pair<std::string, std::string>> options; // value, label pairs
    bool required = false;
    bool disabled = false;
    bool readonly = false;
    int maxLength = 0;
    int rows = 4; // for textarea
    int cols = 40;
    std::string cssClass;
    std::string error;

    std::string render(const TemplateContext* parentCtx = nullptr) const {
        TemplateEngine tmpl;
        tmpl.loadTemplate("form", TemplateEngine::defaultFormTemplate());
        TemplateContext ctx;
        if (parentCtx) ctx = *parentCtx;
        ctx.set("fieldId", id);
        ctx.set("fieldName", name);
        ctx.setEscaped("fieldLabel", label, EscapeMode::HTML);
        ctx.setEscaped("fieldValue", value, EscapeMode::HTML);
        ctx.setEscaped("fieldHelp", helpText, EscapeMode::HTML);
        ctx.set("disabled", disabled || readonly ? "disabled" : "");

        switch (type) {
        case FieldType::TEXT: ctx.set("fieldType", "text"); break;
        case FieldType::PASSWORD: ctx.set("fieldType", "password"); break;
        case FieldType::TEXTAREA:
            ctx.set("fieldType", "textarea");
            ctx.setInt("rows", rows > 0 ? rows : 4);
            break;
        case FieldType::SELECT:
        case FieldType::SELECT: {
            ctx.set("fieldType", "select");
            std::string opts;
            for (const auto& [optVal, optLabel] : options) {
                opts += "<option value=\"" + TemplateContext::escape(optVal, EscapeMode::HTML) + "\"";
                if (optVal == value) opts += " selected";
                opts += ">" + TemplateContext::escape(optLabel, EscapeMode::HTML) + "</option>";
            }
            ctx.set("options", opts);
            break;
        }
        case FieldType::CHECKBOX:
            ctx.set("fieldType", "checkbox");
            ctx.set("checked", value == "true" ? "checked" : "");
            break;
        case FieldType::DATE:
        case FieldType::DATETIME:
            ctx.set("fieldType", "date");
            break;
        case FieldType::NUMBER:
            ctx.set("fieldType", "text");
            break;
        case FieldType::EMAIL:
            ctx.set("fieldType", "text");
            break;
        case FieldType::HIDDEN:
            return "<input type=\"hidden\" name=\"" + TemplateContext::escape(name, EscapeMode::HTML) +
                "\" value=\"" + TemplateContext::escape(value, EscapeMode::HTML) + "\">";
        case FieldType::READONLY_TEXT:
            return "<div class=\"pf-readonly-field\" id=\"" + TemplateContext::escape(id, EscapeMode::HTML) + "\">" +
                "<label>" + TemplateContext::escape(label, EscapeMode::HTML) + "</label>" +
                "<span>" + TemplateContext::escape(value, EscapeMode::HTML) + "</span></div>";
        case FieldType::RICH_TEXT:
            ctx.set("fieldType", "textarea");
            ctx.setInt("rows", 12);
            break;
        default:
            ctx.set("fieldType", "text");
        }

        if (!error.empty()) {
            ctx.setEscaped("fieldError", error, EscapeMode::HTML);
        }

        return tmpl.render("form", ctx);
    }
};

template<typename EntityType>
class BaseEditPage : public BasePage {
public:
    using ValidatorFunc = std::function<std::optional<ValidationError>(const EntityType&, const std::string& value)>;
    using SubmitHandler = std::function<bool(const EntityType&)>;
    using DeleteHandler = std::function<bool(const EntityType&)>;

    BaseEditPage() {
        templateEngine_.loadTemplate("edit", TemplateEngine::defaultEditPageTemplate());
        BasePage::setTitle("Edit");
    }

    explicit BaseEditPage(const std::string& title) {
        templateEngine_.loadTemplate("edit", TemplateEngine::defaultEditPageTemplate());
        BasePage::setTitle(title);
    }

    virtual ~BaseEditPage() = default;

    // Entity management
    void setEntity(const EntityType& entity) { entity_ = entity; }
    const EntityType& getEntity() const { return entity_; }
    EntityType& getEntity() { return entity_; }
    void setNewEntity(bool isNew) { isNewEntity_ = isNew; }
    bool isNewEntity() const { return isNewEntity_; }

    // Form action
    void setFormAction(const std::string& url) { formAction_ = url; }
    const std::string& getFormAction() const { return formAction_; }

    // Field management
    FormField& addField(const std::string& name, const std::string& label, FieldType type = FieldType::TEXT) {
        fields_.push_back({name, name, label, type});
        return fields_.back();
    }

    FormField& addField(FormField&& field) {
        fields_.push_back(std::move(field));
        return fields_.back();
    }

    void addValidator(const std::string& fieldName, ValidatorFunc validator) {
        validators_[fieldName].push_back(std::move(validator));
    }

    void setSubmitHandler(SubmitHandler handler) { submitHandler_ = std::move(handler); }
    void setDeleteHandler(DeleteHandler handler) { deleteHandler_ = std::move(handler); }

    // Validation
    std::vector<ValidationError> validate(const EntityType& entity) {
        std::vector<ValidationError> errors;
        for (auto& field : fields_) {
            if (field.required && field.value.empty()) {
                errors.push_back({field.name, "Field '" + field.label + "' is required."});
                field.error = "This field is required";
                continue;
            }
            auto it = validators_.find(field.name);
            if (it != validators_.end()) {
                for (auto& validator : it->second) {
                    auto err = validator(entity, field.value);
                    if (err) {
                        errors.push_back(*err);
                        field.error = err->message;
                    }
                }
            }
        }
        return errors;
    }

    // Form submission
    virtual bool onSubmit() {
        if (!submitHandler_) return true;
        return submitHandler_(entity_);
    }

    virtual bool onDelete() {
        if (!deleteHandler_) return false;
        return deleteHandler_(entity_);
    }

    // Cancel URL
    void setCancelUrl(const std::string& url) { cancelUrl_ = url; }
    const std::string& getCancelUrl() const { return cancelUrl_; }

    // Show/hide delete button
    void setShowDelete(bool show) { showDelete_ = show; }
    bool getShowDelete() const { return showDelete_; }

    // Override render
    std::string render() override {
        onBeforeRender();
        onConfigure();

        if (!isNewEntity_) {
            setPageTitle("Edit " + BasePage::getTitle());
        } else {
            setPageTitle("New " + BasePage::getTitle());
        }

        // Build form fields HTML
        std::string formFieldsHtml;
        for (const auto& field : fields_) {
            formFieldsHtml += field.render();
        }

        // Build edit context
        TemplateContext editCtx;
        editCtx.set("formAction", formAction_);
        editCtx.set("csrfToken", generateCsrfToken());
        editCtx.setEscaped("formFields", formFieldsHtml, EscapeMode::HTML);
        editCtx.set("cancelUrl", cancelUrl_);
        editCtx.setBool("showDelete", showDelete_ && !isNewEntity_);

        if (!errors_.empty()) {
            editCtx.setBool("hasErrors", true);
            std::string errList = "<ul>";
            for (const auto& err : errors_) {
                errList += "<li>" + TemplateContext::escape(err.message, EscapeMode::HTML) + "</li>";
            }
            errList += "</ul>";
            editCtx.set("errors", errList);
        }

        std::string editContent = templateEngine_.render("edit", editCtx);
        setContent(editContent);

        TemplateContext pageCtx = buildPageContext();
        std::string result = templateEngine_.render("page", pageCtx);
        onAfterRender();
        return result;
    }

    // Process HTTP POST data
    virtual void processPostData(const std::unordered_map<std::string, std::string>& formData) {
        for (auto& field : fields_) {
            auto it = formData.find(field.name);
            if (it != formData.end()) {
                field.value = it->second;
            } else if (field.type == FieldType::CHECKBOX) {
                field.value = "false";
            }
        }
    }

    // Get form data as key-value pairs
    std::unordered_map<std::string, std::string> getFormData() const {
        std::unordered_map<std::string, std::string> data;
        for (const auto& field : fields_) {
            data[field.name] = field.value;
        }
        return data;
    }

    void setErrors(const std::vector<ValidationError>& errors) { errors_ = errors; }
    const std::vector<ValidationError>& getErrors() const { return errors_; }
    void clearErrors() { errors_.clear(); }

protected:
    std::vector<FormField>& getFields() { return fields_; }
    const std::vector<FormField>& getFields() const { return fields_; }

    EntityType entity_;
    bool isNewEntity_ = true;
    std::string formAction_;
    std::string cancelUrl_ = "/";
    bool showDelete_ = false;
    std::vector<FormField> fields_;
    std::vector<ValidationError> errors_;
    std::unordered_map<std::string, std::vector<ValidatorFunc>> validators_;
    SubmitHandler submitHandler_;
    DeleteHandler deleteHandler_;
};

} // namespace org::projectforge::wicket
