#pragma once
// ProjectForge C++ Port - Form Components
// Reusable form field components with validation, type coercion,
// and various input widgets for server-side rendering.

#include <string>
#include <string_view>
#include <vector>
#include <functional>
#include <optional>
#include <sstream>
#include <algorithm>
#include <cctype>

namespace org::projectforge::wicket {

class FormComponentBase {
public:
    FormComponentBase(const std::string& id, const std::string& label)
        : id_(id), label_(label) {}
    virtual ~FormComponentBase() = default;

    const std::string& getId() const { return id_; }
    void setLabel(const std::string& label) { label_ = label; }
    const std::string& getLabel() const { return label_; }
    void setRequired(bool r) { required_ = r; }
    bool isRequired() const { return required_; }
    void setEnabled(bool e) { enabled_ = e; }
    bool isEnabled() const { return enabled_; }
    void setVisible(bool v) { visible_ = v; }
    bool isVisible() const { return visible_; }
    void setReadonly(bool r) { readonly_ = r; }
    bool isReadonly() const { return readonly_; }
    void setError(const std::string& err) { error_ = err; }
    const std::string& getError() const { return error_; }
    bool hasError() const { return !error_.empty(); }
    void setHelpText(const std::string& help) { helpText_ = help; }
    const std::string& getHelpText() const { return helpText_; }
    void setCssClass(const std::string& cls) { cssClass_ = cls; }
    const std::string& getCssClass() const { return cssClass_; }

    virtual std::string render() const = 0;
    virtual std::string getValue() const = 0;
    virtual void setValue(const std::string& val) = 0;
    virtual std::optional<std::string> validate() { return std::nullopt; }

protected:
    std::string renderError() const {
        if (error_.empty()) return "";
        return "<span class=\"pf-field-error\">" + escapeHtml(error_) + "</span>";
    }
    std::string renderHelp() const {
        if (helpText_.empty()) return "";
        return "<span class=\"pf-field-help\">" + escapeHtml(helpText_) + "</span>";
    }
    std::string escapeHtml(const std::string& input) const {
        std::string result;
        for (char c : input) {
            switch (c) {
            case '&': result += "&amp;"; break;
            case '<': result += "&lt;"; break;
            case '>': result += "&gt;"; break;
            case '"': result += "&quot;"; break;
            case '\'': result += "&#39;"; break;
            default: result += c;
            }
        }
        return result;
    }

    std::string id_;
    std::string label_;
    bool required_ = false;
    bool enabled_ = true;
    bool visible_ = true;
    bool readonly_ = false;
    std::string error_;
    std::string helpText_;
    std::string cssClass_;
};

class TextField : public FormComponentBase {
public:
    TextField(const std::string& id, const std::string& label)
        : FormComponentBase(id, label) {}

    void setMaxLength(int len) { maxLength_ = len; }
    int getMaxLength() const { return maxLength_; }
    void setPlaceholder(const std::string& ph) { placeholder_ = ph; }
    void setInputType(const std::string& type) { inputType_ = type; }

    std::string render() const override {
        std::string html = "<div class=\"pf-form-group" + (cssClass_.empty() ? "" : " " + cssClass_) + "\">";
        html += "<label for=\"" + escapeHtml(id_) + "\" class=\"pf-label\">" +
            escapeHtml(label_) + (required_ ? " <span class=\"required\">*</span>" : "") + "</label>";
        html += "<input type=\"" + inputType_ + "\" id=\"" + escapeHtml(id_) +
            "\" name=\"" + escapeHtml(id_) + "\" value=\"" + escapeHtml(value_) + "\"";
        if (maxLength_ > 0) html += " maxlength=\"" + std::to_string(maxLength_) + "\"";
        if (!placeholder_.empty()) html += " placeholder=\"" + escapeHtml(placeholder_) + "\"";
        if (!enabled_) html += " disabled";
        if (readonly_) html += " readonly";
        if (required_) html += " required";
        html += " class=\"pf-input\">";
        html += renderError();
        html += renderHelp();
        html += "</div>";
        return html;
    }

    std::string getValue() const override { return value_; }
    void setValue(const std::string& val) override { value_ = val; }

    std::optional<std::string> validate() override {
        if (required_ && value_.empty()) {
            return "Field '" + label_ + "' is required.";
        }
        if (maxLength_ > 0 && static_cast<int>(value_.size()) > maxLength_) {
            return "Field '" + label_ + "' exceeds maximum length of " + std::to_string(maxLength_) + ".";
        }
        if (inputType_ == "email" && !value_.empty()) {
            if (value_.find('@') == std::string::npos) {
                return "Please enter a valid email address.";
            }
        }
        return std::nullopt;
    }

private:
    std::string value_;
    int maxLength_ = 0;
    std::string placeholder_;
    std::string inputType_ = "text";
};

class PasswordField : public FormComponentBase {
public:
    PasswordField(const std::string& id, const std::string& label)
        : FormComponentBase(id, label) {}

    void setShowConfirm(bool show) { showConfirm_ = show; }

    std::string render() const override {
        std::string html = "<div class=\"pf-form-group\">";
        html += "<label for=\"" + escapeHtml(id_) + "\" class=\"pf-label\">" +
            escapeHtml(label_) + (required_ ? " <span class=\"required\">*</span>" : "") + "</label>";
        html += "<input type=\"password\" id=\"" + escapeHtml(id_) +
            "\" name=\"" + escapeHtml(id_) + "\" value=\"\" class=\"pf-input" +
            (cssClass_.empty() ? "" : " " + cssClass_) + "\"";
        if (!enabled_) html += " disabled";
        if (required_) html += " required";
        html += ">";
        html += renderError();
        html += renderHelp();

        if (showConfirm_) {
            html += "<label for=\"" + escapeHtml(id_) + "_confirm\" class=\"pf-label\">" +
                "Confirm " + escapeHtml(label_) + "</label>";
            html += "<input type=\"password\" id=\"" + escapeHtml(id_) +
                "_confirm\" name=\"" + escapeHtml(id_) + "_confirm\" value=\"\" class=\"pf-input\">";
        }
        html += "</div>";
        return html;
    }

    std::string getValue() const override { return value_; }
    void setValue(const std::string& val) override { value_ = val; }

private:
    std::string value_;
    bool showConfirm_ = false;
};

class TextAreaField : public FormComponentBase {
public:
    TextAreaField(const std::string& id, const std::string& label)
        : FormComponentBase(id, label) {}

    void setRows(int r) { rows_ = r; }
    void setCols(int c) { cols_ = c; }
    void setMaxLength(int len) { maxLength_ = len; }

    std::string render() const override {
        std::string html = "<div class=\"pf-form-group\">";
        html += "<label for=\"" + escapeHtml(id_) + "\" class=\"pf-label\">" +
            escapeHtml(label_) + (required_ ? " <span class=\"required\">*</span>" : "") + "</label>";
        html += "<textarea id=\"" + escapeHtml(id_) + "\" name=\"" + escapeHtml(id_) + "\"";
        html += " rows=\"" + std::to_string(rows_) + "\" cols=\"" + std::to_string(cols_) + "\"";
        if (maxLength_ > 0) html += " maxlength=\"" + std::to_string(maxLength_) + "\"";
        if (!enabled_) html += " disabled";
        if (readonly_) html += " readonly";
        if (required_) html += " required";
        html += " class=\"pf-textarea\">";
        html += escapeHtml(value_);
        html += "</textarea>";
        html += renderError();
        html += renderHelp();
        html += "</div>";
        return html;
    }

    std::string getValue() const override { return value_; }
    void setValue(const std::string& val) override { value_ = val; }

private:
    std::string value_;
    int rows_ = 4;
    int cols_ = 50;
    int maxLength_ = 0;
};

class DropDownChoice : public FormComponentBase {
public:
    DropDownChoice(const std::string& id, const std::string& label)
        : FormComponentBase(id, label) {}

    void addChoice(const std::string& val, const std::string& display) {
        choices_.push_back({val, display});
    }
    void setChoices(const std::vector<std::pair<std::string, std::string>>& choices) {
        choices_ = choices;
    }
    void setAllowEmpty(bool allow) { allowEmpty_ = allow; }
    void setEmptyLabel(const std::string& label) { emptyLabel_ = label; }

    std::string render() const override {
        std::string html = "<div class=\"pf-form-group\">";
        html += "<label for=\"" + escapeHtml(id_) + "\" class=\"pf-label\">" +
            escapeHtml(label_) + (required_ ? " <span class=\"required\">*</span>" : "") + "</label>";
        html += "<select id=\"" + escapeHtml(id_) + "\" name=\"" + escapeHtml(id_) + "\"";
        if (!enabled_) html += " disabled";
        if (required_) html += " required";
        html += " class=\"pf-select\">";
        if (allowEmpty_) {
            html += "<option value=\"\"" + (value_.empty() ? " selected" : "") + ">" +
                escapeHtml(emptyLabel_.empty() ? "-- Select --" : emptyLabel_) + "</option>";
        }
        for (const auto& [val, disp] : choices_) {
            html += "<option value=\"" + escapeHtml(val) + "\"";
            if (val == value_) html += " selected";
            html += ">" + escapeHtml(disp) + "</option>";
        }
        html += "</select>";
        html += renderError();
        html += renderHelp();
        html += "</div>";
        return html;
    }

    std::string getValue() const override { return value_; }
    void setValue(const std::string& val) override { value_ = val; }
    void setSelected(const std::string& val) { value_ = val; }
    const std::string& getSelected() const { return value_; }

private:
    std::string value_;
    std::vector<std::pair<std::string, std::string>> choices_;
    bool allowEmpty_ = false;
    std::string emptyLabel_;
};

class CheckBoxField : public FormComponentBase {
public:
    CheckBoxField(const std::string& id, const std::string& label)
        : FormComponentBase(id, label) {}

    std::string render() const override {
        std::string html = "<div class=\"pf-form-group pf-form-checkbox\">";
        html += "<label class=\"pf-checkbox-label\">";
        html += "<input type=\"checkbox\" id=\"" + escapeHtml(id_) +
            "\" name=\"" + escapeHtml(id_) + "\" value=\"true\"";
        if (checked_) html += " checked";
        if (!enabled_) html += " disabled";
        if (readonly_) html += " readonly";
        html += " class=\"pf-checkbox\">";
        html += " " + escapeHtml(label_);
        if (required_) html += " <span class=\"required\">*</span>";
        html += "</label>";
        html += renderError();
        html += renderHelp();
        html += "</div>";
        return html;
    }

    std::string getValue() const override { return checked_ ? "true" : "false"; }
    void setValue(const std::string& val) override { checked_ = (val == "true" || val == "1" || val == "on"); }
    void setChecked(bool checked) { checked_ = checked; }
    bool isChecked() const { return checked_; }

private:
    bool checked_ = false;
};

class DateField : public FormComponentBase {
public:
    DateField(const std::string& id, const std::string& label)
        : FormComponentBase(id, label) {}

    std::string render() const override {
        std::string html = "<div class=\"pf-form-group\">";
        html += "<label for=\"" + escapeHtml(id_) + "\" class=\"pf-label\">" +
            escapeHtml(label_) + (required_ ? " <span class=\"required\">*</span>" : "") + "</label>";
        html += "<input type=\"date\" id=\"" + escapeHtml(id_) +
            "\" name=\"" + escapeHtml(id_) + "\" value=\"" + escapeHtml(value_) + "\"";
        if (!enabled_) html += " disabled";
        if (readonly_) html += " readonly";
        if (required_) html += " required";
        html += " class=\"pf-input pf-date-input\">";
        html += renderError();
        html += renderHelp();
        html += "</div>";
        return html;
    }

    std::string getValue() const override { return value_; }
    void setValue(const std::string& val) override { value_ = val; }

private:
    std::string value_;
};

class FileUploadField : public FormComponentBase {
public:
    FileUploadField(const std::string& id, const std::string& label)
        : FormComponentBase(id, label) {}

    void setAccept(const std::string& accept) { accept_ = accept; }

    std::string render() const override {
        std::string html = "<div class=\"pf-form-group\">";
        html += "<label for=\"" + escapeHtml(id_) + "\" class=\"pf-label\">" +
            escapeHtml(label_) + (required_ ? " <span class=\"required\">*</span>" : "") + "</label>";
        html += "<input type=\"file\" id=\"" + escapeHtml(id_) +
            "\" name=\"" + escapeHtml(id_) + "\"";
        if (!accept_.empty()) html += " accept=\"" + escapeHtml(accept_) + "\"";
        if (!enabled_) html += " disabled";
        if (required_) html += " required";
        html += " class=\"pf-file-input\">";
        html += renderError();
        html += renderHelp();
        html += "</div>";
        return html;
    }

    std::string getValue() const override { return value_; }
    void setValue(const std::string& val) override { value_ = val; }

private:
    std::string value_;
    std::string accept_;
};

class HiddenField : public FormComponentBase {
public:
    HiddenField(const std::string& id) : FormComponentBase(id, "") {}

    std::string render() const override {
        return "<input type=\"hidden\" id=\"" + escapeHtml(id_) +
            "\" name=\"" + escapeHtml(id_) + "\" value=\"" + escapeHtml(value_) + "\">";
    }

    std::string getValue() const override { return value_; }
    void setValue(const std::string& val) override { value_ = val; }

private:
    std::string value_;
};

} // namespace org::projectforge::wicket
