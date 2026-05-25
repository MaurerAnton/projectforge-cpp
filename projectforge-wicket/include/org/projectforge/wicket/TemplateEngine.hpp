#pragma once
// ProjectForge C++ Port - Wicket Template Engine
// Server-side HTML template rendering with placeholder substitution,
// conditional blocks, loops, and component-driven page composition.

#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>
#include <functional>
#include <sstream>
#include <regex>
#include <stdexcept>

namespace org::projectforge::wicket {

enum class EscapeMode {
    NONE,
    HTML,
    URL,
    JAVASCRIPT
};

struct TemplateFragment {
    std::string name;
    std::string content;
    std::vector<TemplateFragment> children;
};

class TemplateContext {
public:
    void set(const std::string& key, const std::string& value) {
        vars_[key] = value;
    }
    void setEscaped(const std::string& key, const std::string& value, EscapeMode mode = EscapeMode::HTML) {
        vars_[key] = escape(value, mode);
    }
    void setInt(const std::string& key, int value) {
        vars_[key] = std::to_string(value);
    }
    void setBool(const std::string& key, bool value) {
        vars_[key] = value ? "true" : "false";
    }
    const std::string& get(const std::string& key) const {
        static const std::string empty;
        auto it = vars_.find(key);
        return it != vars_.end() ? it->second : empty;
    }
    bool has(const std::string& key) const {
        return vars_.find(key) != vars_.end();
    }
    const std::unordered_map<std::string, std::string>& vars() const { return vars_; }

    static std::string escape(const std::string& input, EscapeMode mode) {
        std::string result;
        result.reserve(input.size());
        for (char c : input) {
            switch (mode) {
            case EscapeMode::HTML:
                switch (c) {
                case '&': result += "&amp;"; break;
                case '<': result += "&lt;"; break;
                case '>': result += "&gt;"; break;
                case '"': result += "&quot;"; break;
                case '\'': result += "&#39;"; break;
                default: result += c;
                }
                break;
            case EscapeMode::URL:
                if (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~') {
                    result += c;
                } else {
                    char buf[4];
                    snprintf(buf, sizeof(buf), "%%%02X", static_cast<unsigned char>(c));
                    result += buf;
                }
                break;
            case EscapeMode::JAVASCRIPT:
                switch (c) {
                case '\\': result += "\\\\"; break;
                case '\'': result += "\\'"; break;
                case '"': result += "\\\""; break;
                case '\n': result += "\\n"; break;
                case '\r': result += "\\r"; break;
                case '\t': result += "\\t"; break;
                default: result += c;
                }
                break;
            case EscapeMode::NONE:
            default:
                result += c;
            }
        }
        return result;
    }

private:
    std::unordered_map<std::string, std::string> vars_;
};

class TemplateEngine {
public:
    TemplateEngine() = default;

    void loadTemplate(const std::string& name, const std::string& content) {
        templates_[name] = content;
    }

    std::string getTemplate(const std::string& name) const {
        auto it = templates_.find(name);
        return it != templates_.end() ? it->second : "";
    }

    void registerComponent(const std::string& placeholder,
                          std::function<std::string(const TemplateContext&)> renderer) {
        components_[placeholder] = std::move(renderer);
    }

    std::string render(const std::string& templateName, const TemplateContext& ctx) const {
        auto it = templates_.find(templateName);
        if (it == templates_.end()) {
            return "<div class=\"error\">Template not found: " + escapeHtml(templateName) + "</div>";
        }
        return renderString(it->second, ctx);
    }

    std::string renderString(const std::string& tmpl, const TemplateContext& ctx) const {
        std::string result;
        result.reserve(tmpl.size() * 2);
        size_t pos = 0;

        while (pos < tmpl.size()) {
            // Find next directive
            size_t varStart = tmpl.find("${", pos);
            size_t ifStart = tmpl.find("{{#if ", pos);
            size_t eachStart = tmpl.find("{{#each ", pos);
            size_t componentStart = tmpl.find("{{#component ", pos);

            size_t nextDirective = std::string::npos;
            if (varStart != std::string::npos) nextDirective = varStart;
            if (ifStart != std::string::npos && ifStart < nextDirective) nextDirective = ifStart;
            if (eachStart != std::string::npos && eachStart < nextDirective) nextDirective = eachStart;
            if (componentStart != std::string::npos && componentStart < nextDirective) nextDirective = componentStart;

            if (nextDirective == std::string::npos) {
                result += tmpl.substr(pos);
                break;
            }

            result += tmpl.substr(pos, nextDirective - pos);

            if (nextDirective == varStart) {
                size_t end = tmpl.find('}', varStart + 2);
                if (end != std::string::npos) {
                    std::string key = tmpl.substr(varStart + 2, end - varStart - 2);
                    result += ctx.get(key);
                    pos = end + 1;
                } else {
                    result += "${";
                    pos = varStart + 2;
                }
            } else if (nextDirective == ifStart) {
                size_t condEnd = tmpl.find("}}", ifStart + 6);
                if (condEnd == std::string::npos) { result += "{{"; pos = ifStart + 2; continue; }
                std::string cond = tmpl.substr(ifStart + 6, condEnd - ifStart - 6);
                bool negate = false;
                std::string condKey = cond;
                if (cond.size() > 1 && cond[0] == '!') {
                    negate = true;
                    condKey = cond.substr(1);
                }
                size_t elsePos = tmpl.find("{{else}}", condEnd + 2);
                size_t endIf = tmpl.find("{{/if}}", condEnd + 2);
                if (endIf == std::string::npos) { result += "{{"; pos = ifStart + 2; continue; }
                bool condition = ctx.has(condKey) && !ctx.get(condKey).empty();
                if (negate) condition = !condition;
                if (condition) {
                    size_t contentStart = condEnd + 2;
                    size_t contentEnd = (elsePos != std::string::npos && elsePos < endIf) ? elsePos : endIf;
                    result += renderString(tmpl.substr(contentStart, contentEnd - contentStart), ctx);
                } else if (elsePos != std::string::npos && elsePos < endIf) {
                    result += renderString(tmpl.substr(elsePos + 8, endIf - elsePos - 8), ctx);
                }
                pos = endIf + 7;
            } else if (nextDirective == eachStart) {
                size_t iterEnd = tmpl.find("}}", eachStart + 8);
                if (iterEnd == std::string::npos) { result += "{{"; pos = eachStart + 2; continue; }
                std::string iterSpec = tmpl.substr(eachStart + 8, iterEnd - eachStart - 8);
                // iterSpec format: "items as item" where items is a context key for list
                size_t asPos = iterSpec.find(" as ");
                if (asPos == std::string::npos) { pos = eachStart + 2; continue; }
                std::string listKey = iterSpec.substr(0, asPos);
                std::string itemVar = iterSpec.substr(asPos + 4);
                size_t endEach = tmpl.find("{{/each}}", iterEnd + 2);
                if (endEach == std::string::npos) { result += "{{"; pos = eachStart + 2; continue; }
                // For simplicity, we split by a delimiter stored in context
                std::string listData = ctx.get(listKey);
                if (!listData.empty()) {
                    size_t itemStart = 0;
                    while (itemStart < listData.size()) {
                        size_t itemEnd = listData.find('\n', itemStart);
                        if (itemEnd == std::string::npos) itemEnd = listData.size();
                        std::string item = listData.substr(itemStart, itemEnd - itemStart);
                        TemplateContext itemCtx = ctx;
                        itemCtx.set(itemVar, item);
                        result += renderString(tmpl.substr(iterEnd + 2, endEach - iterEnd - 2), itemCtx);
                        itemStart = itemEnd + 1;
                        if (itemEnd >= listData.size()) break;
                    }
                }
                pos = endEach + 9;
            } else if (nextDirective == componentStart) {
                size_t compEnd = tmpl.find("}}", componentStart + 13);
                if (compEnd == std::string::npos) { result += "{{"; pos = componentStart + 2; continue; }
                std::string compName = tmpl.substr(componentStart + 13, compEnd - componentStart - 13);
                auto compIt = components_.find(compName);
                if (compIt != components_.end()) {
                    result += compIt->second(ctx);
                }
                pos = compEnd + 2;
            }
        }
        return result;
    }

    static std::string escapeHtml(const std::string& input) {
        return TemplateContext::escape(input, EscapeMode::HTML);
    }

    // Built-in page chrome templates
    static std::string defaultPageTemplate();
    static std::string defaultEditPageTemplate();
    static std::string defaultListPageTemplate();
    static std::string defaultFormTemplate();

private:
    std::unordered_map<std::string, std::string> templates_;
    std::unordered_map<std::string, std::function<std::string(const TemplateContext&)>> components_;
};

inline std::string TemplateEngine::defaultPageTemplate() {
    return R"HTML(<!DOCTYPE html>
<html lang="${lang}">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>${title} - ProjectForge</title>
    <link rel="stylesheet" href="/styles/projectforge.css">
    <link rel="stylesheet" href="/styles/font-awesome/css/font-awesome.min.css">
    ${headExtras}
</head>
<body>
    <div id="pf-wrapper">
        <nav id="pf-navbar">
            <div class="nav-brand">
                <a href="/">ProjectForge</a>
            </div>
            <div class="nav-menu">
                {{#component navbar}}
            </div>
            <div class="nav-user">
                <span class="user-info">${currentUser}</span>
                <a href="/logout" class="btn-logout">Logout</a>
            </div>
        </nav>
        <div id="pf-content">
            <aside id="pf-sidebar">
                {{#component sidebar}}
            </aside>
            <main id="pf-main">
                <div class="page-header">
                    <h1>${pageTitle}</h1>
                    {{#component breadcrumb}}
                </div>
                <div class="page-content">
                    ${content}
                </div>
            </main>
        </div>
        <footer id="pf-footer">
            <p>ProjectForge Community Edition &copy; 2001-2026</p>
        </footer>
    </div>
    <script src="/scripts/jquery.min.js"></script>
    <script src="/scripts/projectforge.js"></script>
    ${scriptExtras}
</body>
</html>)HTML";
}

inline std::string TemplateEngine::defaultEditPageTemplate() {
    return R"HTML(<div class="edit-page">
    <form method="post" action="${formAction}" class="pf-form" enctype="multipart/form-data">
        <input type="hidden" name="id" value="${entityId}">
        <input type="hidden" name="csrf_token" value="${csrfToken}">
        {{#if hasErrors}}
        <div class="pf-alert pf-alert-error">
            <ul>${errors}</ul>
        </div>
        {{/if}}
        <div class="form-fields">
            ${formFields}
        </div>
        <div class="form-actions">
            <button type="submit" class="btn btn-primary">Save</button>
            <a href="${cancelUrl}" class="btn btn-secondary">Cancel</a>
            {{#if showDelete}}
            <button type="button" class="btn btn-danger" onclick="confirmDelete()">Delete</button>
            {{/if}}
        </div>
    </form>
</div>)HTML";
}

inline std::string TemplateEngine::defaultListPageTemplate() {
    return R"HTML(<div class="list-page">
    <div class="list-toolbar">
        <a href="${newUrl}" class="btn btn-primary">New</a>
        {{#component searchFilter}}
    </div>
    <div class="list-table-container">
        <table class="pf-data-table">
            <thead>
                <tr>${tableHeaders}</tr>
            </thead>
            <tbody>
                {{#each rows as row}}
                <tr>${row}</tr>
                {{/each}}
            </tbody>
        </table>
    </div>
    <div class="list-footer">
        <div class="list-info">Showing ${firstRow}-${lastRow} of ${totalRows}</div>
        {{#component pagingNavigator}}
    </div>
</div>)HTML";
}

inline std::string TemplateEngine::defaultFormTemplate() {
    return R"HTML(<div class="pf-form-group">
    <label for="${fieldId}" class="pf-label">${fieldLabel}</label>
    {{#if fieldType == "text"}}
    <input type="text" id="${fieldId}" name="${fieldName}" value="${fieldValue}" class="pf-input" ${disabled}>
    {{/if}}
    {{#if fieldType == "password"}}
    <input type="password" id="${fieldId}" name="${fieldName}" class="pf-input">
    {{/if}}
    {{#if fieldType == "textarea"}}
    <textarea id="${fieldId}" name="${fieldName}" class="pf-textarea" rows="${rows}">${fieldValue}</textarea>
    {{/if}}
    {{#if fieldType == "select"}}
    <select id="${fieldId}" name="${fieldName}" class="pf-select">
        ${options}
    </select>
    {{/if}}
    {{#if fieldType == "checkbox"}}
    <input type="checkbox" id="${fieldId}" name="${fieldName}" value="true" ${checked}>
    {{/if}}
    {{#if fieldType == "date"}}
    <input type="date" id="${fieldId}" name="${fieldName}" value="${fieldValue}" class="pf-input">
    {{/if}}
    {{#if fieldError}}
    <span class="pf-field-error">${fieldError}</span>
    {{/if}}
    {{#if fieldHelp}}
    <span class="pf-field-help">${fieldHelp}</span>
    {{/if}}
</div>)HTML";
}

} // namespace org::projectforge::wicket
