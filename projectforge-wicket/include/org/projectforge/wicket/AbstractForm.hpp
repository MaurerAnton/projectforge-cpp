#pragma once
// ProjectForge C++ Port - Abstract Form
// Base class for form handling with model binding, nested forms,
// and reusable form component patterns.

#include <string>
#include <string_view>
#include <vector>
#include <unordered_map>
#include <functional>
#include <memory>
#include <optional>

namespace org::projectforge::wicket {

class AbstractForm {
public:
    AbstractForm() = default;
    explicit AbstractForm(const std::string& id) : id_(id) {}
    virtual ~AbstractForm() = default;

    void setId(const std::string& id) { id_ = id; }
    const std::string& getId() const { return id_; }

    void setAction(const std::string& url) { action_ = url; }
    const std::string& getAction() const { return action_; }

    void setMethod(const std::string& method) { method_ = method; }
    const std::string& getMethod() const { return method_; }

    void setMultipart(bool mp) { multipart_ = mp; }
    bool isMultipart() const { return multipart_; }

    void setCsrfToken(const std::string& token) { csrfToken_ = token; }
    const std::string& getCsrfToken() const { return csrfToken_; }

    // Nested forms
    void addNestedForm(std::shared_ptr<AbstractForm> form) {
        nestedForms_.push_back(std::move(form));
    }
    const std::vector<std::shared_ptr<AbstractForm>>& getNestedForms() const {
        return nestedForms_;
    }

    // Submit handler
    using SubmitCallback = std::function<bool(const std::unordered_map<std::string, std::string>&)>;
    void setSubmitCallback(SubmitCallback cb) { submitCallback_ = std::move(cb); }

    virtual bool onSubmit(const std::unordered_map<std::string, std::string>& formData) {
        if (submitCallback_) {
            return submitCallback_(formData);
        }
        return true;
    }

    // Validation
    struct FormError {
        std::string fieldId;
        std::string message;
    };
    using ValidatorFunc = std::function<std::optional<FormError>(const AbstractForm&)>;
    void addValidator(ValidatorFunc validator) {
        validators_.push_back(std::move(validator));
    }

    virtual std::vector<FormError> validate() {
        std::vector<FormError> errors;
        for (auto& v : validators_) {
            auto err = v(*this);
            if (err) errors.push_back(*err);
        }
        return errors;
    }

    // State
    void setSubmitted(bool s) { submitted_ = s; }
    bool isSubmitted() const { return submitted_; }
    void setVisible(bool v) { visible_ = v; }
    bool isVisible() const { return visible_; }
    void setEnabled(bool e) { enabled_ = e; }
    bool isEnabled() const { return enabled_; }

    // Render
    virtual std::string renderOpenTag() const {
        std::string html = "<form id=\"" + id_ + "\" action=\"" + action_ +
            "\" method=\"" + method_ + "\"";
        if (multipart_) html += " enctype=\"multipart/form-data\"";
        html += " class=\"pf-form\">";
        return html;
    }

    virtual std::string renderCloseTag() const {
        return "</form>";
    }

    virtual std::string renderHiddenFields() const {
        std::string html;
        if (!csrfToken_.empty()) {
            html += "<input type=\"hidden\" name=\"csrf_token\" value=\"" + csrfToken_ + "\">";
        }
        return html;
    }

    virtual std::string renderSubmitButton(const std::string& label = "Submit") const {
        return "<button type=\"submit\" class=\"btn btn-primary\">" + label + "</button>";
    }

    virtual std::string renderCancelButton(const std::string& label = "Cancel",
                                            const std::string& url = "#") const {
        return "<a href=\"" + url + "\" class=\"btn btn-secondary\">" + label + "</a>";
    }

    virtual std::string render() {
        std::string html = renderOpenTag();
        html += renderHiddenFields();
        // Nested forms contribute their fields
        for (auto& nested : nestedForms_) {
            if (nested->isVisible()) {
                html += nested->renderHiddenFields();
            }
        }
        return html;
    }

protected:
    std::string id_ = "form";
    std::string action_ = "#";
    std::string method_ = "post";
    bool multipart_ = false;
    std::string csrfToken_;
    bool submitted_ = false;
    bool visible_ = true;
    bool enabled_ = true;
    std::vector<std::shared_ptr<AbstractForm>> nestedForms_;
    SubmitCallback submitCallback_;
    std::vector<ValidatorFunc> validators_;
};

} // namespace org::projectforge::wicket
