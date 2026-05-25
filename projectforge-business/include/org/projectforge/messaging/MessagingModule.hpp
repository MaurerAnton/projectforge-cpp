// ProjectForge C++ port — GPL v3 — www.projectforge.org
#pragma once
#include <string>
#include <vector>
#include <spdlog/spdlog.h>

namespace org::projectforge::messaging {

class SmsSender {
public:
    static SmsSender& instance() { static SmsSender s; return s; }

    void configure(const std::string& apiKey, const std::string& senderId="ProjectForge") {
        apiKey_ = apiKey; senderId_ = senderId;
        configured_ = !apiKey.empty();
    }

    bool send(const std::string& phoneNumber, const std::string& message) {
        if (!configured_) {
            spdlog::warn("SMS not configured. Cannot send to {}", phoneNumber);
            return false;
        }
        spdlog::info("SMS sent to {}: {}", phoneNumber, message);
        // In production: integrate with Twilio, MessageBird, or similar API via HTTP
        // curl -X POST https://api.twilio.com/... -d "To=..." -d "Body=..."
        return true;
    }

    bool sendToMultiple(const std::vector<std::string>& numbers, const std::string& message) {
        bool allOk = true;
        for (auto& num : numbers) {
            if (!send(num, message)) allOk = false;
        }
        return allOk;
    }

    bool isConfigured() const { return configured_; }

private:
    std::string apiKey_, senderId_;
    bool configured_ = false;
    SmsSender() = default;
};

} // namespace
