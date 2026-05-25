#pragma once

#include <string>
#include <vector>
#include <memory>
#include <optional>
#include <cstdint>
#include <nlohmann/json.hpp>

namespace sqlite_orm { class database; }

namespace org::projectforge::business::email {

using json = nlohmann::json;

struct EmailMessage {
    std::string from_address;
    std::string from_name;
    std::vector<std::string> to_addresses;
    std::vector<std::string> cc_addresses;
    std::vector<std::string> bcc_addresses;
    std::string subject;
    std::string body_text;
    std::string body_html;
    std::vector<std::string> attachment_paths;
    std::string reply_to;
    bool is_html = false;
};

struct EmailConfig {
    std::string smtp_host;
    int32_t smtp_port = 587;
    bool use_tls = true;
    bool use_ssl = false;
    std::string username;
    std::string password;
    std::string default_from_address;
    std::string default_from_name;
    bool enabled = true;
    int32_t max_attachment_size_mb = 10;
};

struct EmailTemplate {
    int64_t id = 0;
    std::string name;
    std::string subject_template;
    std::string body_template;
    std::string description;
    bool is_html = false;
    int64_t created_at = 0;
};

struct EmailLogEntry {
    int64_t id = 0;
    std::string to_address;
    std::string subject;
    int64_t sent_at = 0;
    std::string status; // SENT, FAILED, QUEUED
    std::string error_message;
    int64_t user_id = 0;
    int64_t related_entity_id = 0;
    std::string related_entity_type;
};

class EmailService {
public:
    explicit EmailService(std::shared_ptr<sqlite_orm::database> db);

    bool initialize(const EmailConfig& config);
    EmailConfig getConfig() const;
    bool updateConfig(const EmailConfig& config);

    bool sendEmail(const EmailMessage& msg);
    bool sendTemplateEmail(const std::string& templateName, const json& templateVars,
                          const std::vector<std::string>& toAddresses, const std::string& fromAddress = "");

    bool sendPasswordResetEmail(const std::string& toAddress, const std::string& resetToken);
    bool sendWelcomeEmail(const std::string& toAddress, const std::string& username);
    bool sendVacationApprovalEmail(const std::string& toAddress, const std::string& userName,
                                   const std::string& approverName, bool approved);
    bool sendTaskAssignmentEmail(const std::string& toAddress, const std::string& taskTitle,
                                 const std::string& assignedByName);
    bool sendInvoiceEmail(const std::string& toAddress, const std::string& invoiceNumber,
                          const std::string& attachmentPath);
    bool sendReminderEmail(const std::string& toAddress, const std::string& eventTitle, int64_t eventTime);
    bool sendReportEmail(const std::string& toAddress, const std::string& reportName, const std::string& reportContent);

    // Templates
    std::vector<EmailTemplate> getTemplates() const;
    EmailTemplate saveTemplate(const EmailTemplate& tmpl);
    bool deleteTemplate(int64_t templateId);
    std::optional<EmailTemplate> getTemplate(const std::string& name) const;
    std::string processTemplate(const std::string& templateStr, const json& vars) const;

    // Queue
    size_t getQueueSize() const;
    bool processQueue(int32_t batchSize = 50);

    // Logs
    std::vector<EmailLogEntry> getLogs(int limit = 100) const;
    std::vector<EmailLogEntry> getLogsByUser(int64_t userId, int limit = 50) const;

    // Testing
    bool testConnection() const;
    bool sendTestEmail(const std::string& toAddress) const;

private:
    std::shared_ptr<sqlite_orm::database> db_;
    EmailConfig config_;
    bool initialized_ = false;

    bool sendSmtp(const EmailMessage& msg, std::string& error) const;
    void logEmail(const EmailLogEntry& entry);
    bool addToQueue(const EmailMessage& msg);
    std::string replaceTemplateVariables(const std::string& templateStr, const json& vars) const;
};

} // namespace org::projectforge::business::email
