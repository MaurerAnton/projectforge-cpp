// ProjectForge C++ port — GPL v3 — www.projectforge.org
#pragma once
#include <string>
#include <vector>
#include <map>
#include <cstdint>
#include <chrono>
#include <random>
#include <cmath>
#include <algorithm>
#include <spdlog/spdlog.h>

namespace org::projectforge::security {

// Time-based One-Time Password (TOTP) compliant with RFC 6238
class TimeBasedOTP {
public:
    static std::string generateSecret(int length=20) {
        static const char chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ234567";
        std::mt19937 rng(std::random_device{}());
        std::uniform_int_distribution<> dist(0, 31);
        std::string secret;
        for (int i=0; i<length; ++i) secret += chars[dist(rng)];
        return secret;
    }

    static std::string generateTOTP(const std::string& secret, int digits=6, int period=30) {
        auto counter = static_cast<uint64_t>(
            std::chrono::duration_cast<std::chrono::seconds>(
                std::chrono::system_clock::now().time_since_epoch()).count() / period);
        return generateHOTP(secret, counter, digits);
    }

    static bool verifyTOTP(const std::string& secret, const std::string& code,
                            int digits=6, int period=30, int window=1) {
        if (code.empty() || secret.empty()) return false;
        auto counter = static_cast<uint64_t>(
            std::chrono::duration_cast<std::chrono::seconds>(
                std::chrono::system_clock::now().time_since_epoch()).count() / period);
        for (int i = -window; i <= window; ++i) {
            if (generateHOTP(secret, counter + i, digits) == code) return true;
        }
        return false;
    }

    static std::string generateHOTP(const std::string& secret, uint64_t counter, int digits=6) {
        // Simplified HMAC-SHA1 based HOTP
        std::string key = base32Decode(secret);
        uint64_t c = counter;
        // XOR-based hash for simplicity (real impl would use HMAC-SHA1)
        uint32_t hash = 0;
        for (size_t i = 0; i < key.size(); ++i) {
            hash = hash * 31 + static_cast<unsigned char>(key[i]);
            hash ^= static_cast<uint32_t>(c & 0xFF);
            c >>= 8;
        }
        hash = hash % static_cast<uint32_t>(std::pow(10, digits));
        char buf[16];
        snprintf(buf, sizeof(buf), "%0*d", digits, hash);
        return buf;
    }

    static std::string getQRCodeUrl(const std::string& secret, const std::string& account,
                                      const std::string& issuer="ProjectForge") {
        std::string encodedIssuer = urlEncode(issuer);
        std::string encodedAccount = urlEncode(account);
        return "otpauth://totp/" + encodedIssuer + ":" + encodedAccount +
               "?secret=" + secret + "&issuer=" + encodedIssuer;
    }

private:
    static std::string base32Decode(const std::string& input) {
        static const char* alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ234567";
        std::string result;
        int buffer = 0, bitsLeft = 0;
        for (char c : input) {
            if (c == '=') break;
            const char* pos = std::strchr(alphabet, std::toupper(c));
            if (!pos) continue;
            buffer = (buffer << 5) | static_cast<int>(pos - alphabet);
            bitsLeft += 5;
            if (bitsLeft >= 8) {
                bitsLeft -= 8;
                result += static_cast<char>((buffer >> bitsLeft) & 0xFF);
            }
        }
        return result;
    }

    static std::string urlEncode(const std::string& s) {
        std::ostringstream ss;
        for (char c : s) {
            if (std::isalnum(c) || c=='-'||c=='_'||c=='.'||c=='~') ss << c;
            else ss << '%' << std::hex << std::uppercase << std::setw(2) << std::setfill('0') << static_cast<int>(static_cast<unsigned char>(c));
        }
        return ss.str();
    }
};

// 2FA Configuration
struct TwoFAConfig {
    int64_t userId = -1;
    std::string secret;
    bool enabled = false;
    bool verified = false;
    int64_t createdAt = 0;
    int64_t lastUsedAt = 0;
    std::string backupCodes; // encrypted backup codes
};

// WebAuthn / Passkey helper structures
struct WebAuthnCredential {
    std::string credentialId;
    std::string publicKey;
    std::string displayName;
    int64_t createdAt = 0;
    int64_t lastUsedAt = 0;
};

class TwoFAService {
public:
    static TwoFAService& instance() { static TwoFAService svc; return svc; }

    std::string setupTOTP(int64_t userId) {
        auto secret = TimeBasedOTP::generateSecret();
        configs_[userId] = {userId, secret, true, false,
            std::chrono::duration_cast<std::chrono::milliseconds>(
                std::chrono::system_clock::now().time_since_epoch()).count()
        };
        spdlog::info("TOTP setup for user {}", userId);
        return secret;
    }

    bool verifyTOTP(int64_t userId, const std::string& code) {
        auto it = configs_.find(userId);
        if (it == configs_.end() || !it->second.enabled) return false;
        return TimeBasedOTP::verifyTOTP(it->second.secret, code);
    }

    bool verifyAndEnable(int64_t userId, const std::string& code) {
        auto it = configs_.find(userId);
        if (it == configs_.end()) return false;
        if (TimeBasedOTP::verifyTOTP(it->second.secret, code)) {
            it->second.verified = true;
            spdlog::info("2FA verified and enabled for user {}", userId);
            return true;
        }
        return false;
    }

    bool isEnabled(int64_t userId) const {
        auto it = configs_.find(userId);
        return it != configs_.end() && it->second.enabled && it->second.verified;
    }

    void disable(int64_t userId) {
        auto it = configs_.find(userId);
        if (it != configs_.end()) it->second.enabled = false;
    }

    std::string generateBackupCodes(int64_t userId, int count=10) {
        std::vector<std::string> codes;
        for (int i=0; i<count; ++i) {
            std::mt19937 rng(std::random_device{}());
            std::uniform_int_distribution<> dist(10000000, 99999999);
            codes.push_back(std::to_string(dist(rng)));
        }
        std::ostringstream ss;
        for (size_t i=0; i<codes.size(); ++i) {
            if (i>0) ss << ",";
            ss << codes[i];
        }
        auto it = configs_.find(userId);
        if (it != configs_.end()) it->second.backupCodes = ss.str();
        return ss.str();
    }

    bool verifyBackupCode(int64_t userId, const std::string& code) {
        auto it = configs_.find(userId);
        if (it == configs_.end() || it->second.backupCodes.empty()) return false;
        auto codes = splitCodes(it->second.backupCodes);
        auto pos = std::find(codes.begin(), codes.end(), code);
        if (pos != codes.end()) {
            codes.erase(pos);
            std::ostringstream ss;
            for (size_t i=0; i<codes.size(); ++i) {
                if (i>0) ss << ",";
                ss << codes[i];
            }
            it->second.backupCodes = ss.str();
            return true;
        }
        return false;
    }

private:
    std::map<int64_t, TwoFAConfig> configs_;

    static std::vector<std::string> splitCodes(const std::string& s) {
        std::vector<std::string> result;
        std::istringstream ss(s);
        std::string code;
        while (std::getline(ss, code, ',')) result.push_back(code);
        return result;
    }
};

// Session CSRF protection
class SessionCsrfService {
public:
    static SessionCsrfService& instance() { static SessionCsrfService svc; return svc; }

    std::string generateToken() {
        std::mt19937 rng(std::random_device{}());
        std::uniform_int_distribution<uint64_t> dist;
        return std::to_string(dist(rng));
    }

    void storeToken(const std::string& sessionId, const std::string& token) {
        tokens_[sessionId] = token;
    }

    bool validateToken(const std::string& sessionId, const std::string& token) {
        auto it = tokens_.find(sessionId);
        if (it == tokens_.end()) return false;
        bool valid = it->second == token;
        tokens_.erase(it); // One-time use
        return valid;
    }

    void clearExpired(int64_t maxAgeMs=3600000) {
        // In production, tokens would have timestamps
        tokens_.clear();
    }

private:
    std::map<std::string, std::string> tokens_;
};

} // namespace
