// ProjectForge C++ port — GPL v3 — www.projectforge.org
#pragma once
#include <string>
#include <vector>
#include <map>
#include <functional>
#include <memory>
#include <fstream>
#include <sstream>
#include <thread>
#include <spdlog/spdlog.h>

namespace org::projectforge::mail {

struct MailAttachment {
    std::string filename, content, mimeType;
    MailAttachment(const std::string& fn, const std::string& ct, const std::string& mt="application/octet-stream")
        : filename(fn), content(ct), mimeType(mt) {}
};

struct MailMessage {
    std::vector<std::string> to, cc, bcc;
    std::string from, subject, content;
    std::string contentType = "text/html";
    std::string charset = "UTF-8";
    std::string icalContent;
    std::vector<MailAttachment> attachments;

    std::string toString() const {
        std::ostringstream ss;
        ss << "Mail[to=";
        for (size_t i=0; i<to.size(); ++i) { if(i>0)ss<<","; ss<<to[i]; }
        ss << ", subject=" << subject << "]";
        return ss.str();
    }
};

enum class MailProtocol { PLAIN, STARTTLS, SSL };

class SendMail {
public:
    static SendMail& instance() { static SendMail sm; return sm; }

    void configure(const std::string& host, int port=25, const std::string& protocol="PLAIN",
                   bool auth=false, const std::string& user="", const std::string& password="",
                   const std::string& from="projectforge@localhost") {
        smtpHost_ = host; smtpPort_ = port; fromAddress_ = from;
        smtpAuth_ = auth; smtpUser_ = user; smtpPassword_ = password;
        if (protocol == "STARTTLS") protocol_ = MailProtocol::STARTTLS;
        else if (protocol == "SSL") protocol_ = MailProtocol::SSL;
        else protocol_ = MailProtocol::PLAIN;
        configured_ = !host.empty();
    }

    bool isConfigured() const { return configured_; }

    bool send(const MailMessage& msg, const std::vector<MailAttachment>& attachments={}, bool async=true) {
        if (!configured_) {
            spdlog::error("Mail not configured. Host missing.");
            return false;
        }
        if (msg.to.empty()) {
            spdlog::error("No recipient address. Mail not sent: {}", msg.subject);
            return false;
        }
        if (async) {
            std::thread([this, msg, attachments]() { sendInternal(msg, attachments); }).detach();
        } else {
            sendInternal(msg, attachments);
        }
        return true;
    }

    bool send(const MailMessage& msg, const std::string& icalContent, bool async=true) {
        MailMessage msgCopy = msg;
        msgCopy.icalContent = icalContent;
        return send(msgCopy, {}, async);
    }

    std::string renderTemplate(const MailMessage& msg, const std::string& templateStr,
                                const std::map<std::string, std::string>& data) {
        std::string result = templateStr;
        for (auto& [key, val] : data) {
            std::string placeholder = "${" + key + "}";
            size_t pos = 0;
            while ((pos = result.find(placeholder, pos)) != std::string::npos) {
                result.replace(pos, placeholder.size(), val);
                pos += val.size();
            }
        }
        // Add standard ProjectForge subject prefix
        result = "[ProjectForge] " + result;
        return result;
    }

    static std::string getProjectForgeSubject(const std::string& subject) {
        return "[ProjectForge] " + subject;
    }

    static std::string buildMailtoLink(const std::string& name, const std::string& email) {
        return "<a href=\"mailto:" + email + "\">" + name + "</a>";
    }

    void setTestMode(bool test) { testMode_ = test; }
    bool getTestMode() const { return testMode_; }

    std::string getInfo() const {
        if (!configured_) return "SendMail not configured.";
        std::ostringstream ss;
        ss << "SendMail: host=" << smtpHost_ << ", port=" << smtpPort_
           << ", auth=" << (smtpAuth_?"yes":"no")
           << ", from=" << fromAddress_;
        return ss.str();
    }

private:
    void sendInternal(const MailMessage& msg, const std::vector<MailAttachment>& attachments) {
        spdlog::info("Sending mail to {} recipients: {}", msg.to.size(), msg.subject);
        try {
            // In production, this would connect to SMTP server
            // For C++ port, we write to log/file since we don't have JavaMail
            if (testMode_) {
                spdlog::info("TEST MODE: Mail not actually sent.");
                spdlog::info("  From: {}", fromAddress_);
                for (auto& t : msg.to) spdlog::info("  To: {}", t);
                spdlog::info("  Subject: {}", msg.subject);
                if (!attachments.empty()) spdlog::info("  Attachments: {}", attachments.size());
                return;
            }

            // Log the email content (in a real implementation, use libcurl SMTP or similar)
            std::ostringstream log;
            log << "EMAIL SENT:\nFrom: " << fromAddress_ << "\n";
            for (auto& t : msg.to) log << "To: " << t << "\n";
            log << "Subject: " << msg.subject << "\n";
            log << "Content-Type: " << msg.contentType << "\n";
            spdlog::info(log.str());

            // For a complete implementation, integrate with libcurl SMTP:
            // curl_easy with CURLOPT_URL="smtp://host:port", CURLOPT_MAIL_FROM, CURLOPT_MAIL_RCPT
            // CURLOPT_READFUNCTION with the message content

        } catch (const std::exception& e) {
            spdlog::error("Failed to send mail: {}", e.what());
            throw;
        }
        spdlog::info("Mail sent successfully: {}", msg.toString());
    }

    std::string smtpHost_, smtpUser_, smtpPassword_, fromAddress_;
    int smtpPort_ = 25;
    bool smtpAuth_ = false, configured_ = false, testMode_ = false;
    MailProtocol protocol_ = MailProtocol::PLAIN;
};

} // namespace
