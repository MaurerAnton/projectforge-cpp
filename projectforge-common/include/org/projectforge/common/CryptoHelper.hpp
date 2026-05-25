/////////////////////////////////////////////////////////////////////////////
// Project ProjectForge Community Edition — www.projectforge.org
// Copyright (C) 2001-2026 Micromata GmbH, Germany (www.micromata.com)
// ProjectForge is dual-licensed (GPL v3).
/////////////////////////////////////////////////////////////////////////////

#pragma once

#include <string>
#include <vector>
#include <optional>
#include <cstdint>

namespace org::projectforge::common {

class CryptoHelper {
public:
    /** SHA-256 hash */
    static std::string sha256(const std::string& data);
    static std::string sha256Hex(const std::string& data);

    /** SHA-512 hash */
    static std::string sha512(const std::string& data);
    static std::string sha512Hex(const std::string& data);

    /** MD5 hash (for legacy compat) */
    static std::string md5(const std::string& data);
    static std::string md5Hex(const std::string& data);

    /** HMAC-SHA256 */
    static std::string hmacSha256(const std::string& key, const std::string& data);

    /** Base64 encode/decode */
    static std::string base64Encode(const std::string& data);
    static std::string base64Decode(const std::string& data);

    /** URL-safe Base64 */
    static std::string base64UrlEncode(const std::string& data);
    static std::string base64UrlDecode(const std::string& data);

    /** Hex encode/decode */
    static std::string hexEncode(const std::vector<uint8_t>& data);
    static std::vector<uint8_t> hexDecode(const std::string& hex);

    /** AES encryption/decryption (CBC mode) */
    static std::optional<std::string> aesEncrypt(const std::string& key, const std::string& plaintext, const std::string& iv);
    static std::optional<std::string> aesDecrypt(const std::string& key, const std::string& ciphertext, const std::string& iv);

    /** Random number generation */
    static std::string randomHex(int bytes);
    static std::string randomAlphanumeric(int length);
    static std::string generateSalt(int length = 32);

    /** Password hashing (bcrypt-like) */
    static std::string hashPassword(const std::string& password, const std::string& salt);
    static bool verifyPassword(const std::string& password, const std::string& hash, const std::string& salt);

    /** Encrypt/decrypt with stream ciphers */
    static std::string encryptStream(const std::string& key, const std::string& data);
    static std::string decryptStream(const std::string& key, const std::string& data);

    /** PKCS7 padding */
    static std::string pkcs7Pad(const std::string& data, size_t blockSize);
    static std::string pkcs7Unpad(const std::string& data);

    /** UUID generation */
    static std::string generateUUID();
};
} // namespace
