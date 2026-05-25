/////////////////////////////////////////////////////////////////////////////
// Project ProjectForge Community Edition — www.projectforge.org
// Copyright (C) 2001-2026 Micromata GmbH, Germany (www.micromata.com)
// ProjectForge is dual-licensed (GPL v3).
/////////////////////////////////////////////////////////////////////////////

#include "org/projectforge/common/CryptoHelper.hpp"
#include <openssl/sha.h>
#include <openssl/md5.h>
#include <openssl/hmac.h>
#include <openssl/evp.h>
#include <openssl/rand.h>
#include <sstream>
#include <iomanip>
#include <random>
#include <cstring>

namespace org::projectforge::common {

static const char BASE64_CHARS[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

std::string CryptoHelper::sha256(const std::string& data) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256(reinterpret_cast<const unsigned char*>(data.c_str()), data.size(), hash);
    return std::string(reinterpret_cast<char*>(hash), SHA256_DIGEST_LENGTH);
}

std::string CryptoHelper::sha256Hex(const std::string& data) {
    return hexEncode(std::vector<uint8_t>(sha256(data).begin(), sha256(data).end()));
}

std::string CryptoHelper::sha512(const std::string& data) {
    unsigned char hash[SHA512_DIGEST_LENGTH];
    SHA512(reinterpret_cast<const unsigned char*>(data.c_str()), data.size(), hash);
    return std::string(reinterpret_cast<char*>(hash), SHA512_DIGEST_LENGTH);
}

std::string CryptoHelper::sha512Hex(const std::string& data) {
    return hexEncode(std::vector<uint8_t>(sha512(data).begin(), sha512(data).end()));
}

std::string CryptoHelper::md5(const std::string& data) {
    unsigned char hash[MD5_DIGEST_LENGTH];
    MD5(reinterpret_cast<const unsigned char*>(data.c_str()), data.size(), hash);
    return std::string(reinterpret_cast<char*>(hash), MD5_DIGEST_LENGTH);
}

std::string CryptoHelper::md5Hex(const std::string& data) {
    return hexEncode(std::vector<uint8_t>(md5(data).begin(), md5(data).end()));
}

std::string CryptoHelper::hmacSha256(const std::string& key, const std::string& data) {
    unsigned char result[EVP_MAX_MD_SIZE];
    unsigned int len = 0;
    HMAC(EVP_sha256(), key.c_str(), key.size(),
         reinterpret_cast<const unsigned char*>(data.c_str()), data.size(), result, &len);
    return std::string(reinterpret_cast<char*>(result), len);
}

std::string CryptoHelper::base64Encode(const std::string& data) {
    std::string result;
    int val = 0, valb = -6;
    for (unsigned char c : data) {
        val = (val << 8) + c;
        valb += 8;
        while (valb >= 0) {
            result.push_back(BASE64_CHARS[(val >> valb) & 0x3F]);
            valb -= 6;
        }
    }
    if (valb > -6) result.push_back(BASE64_CHARS[((val << 8) >> (valb + 8)) & 0x3F]);
    while (result.size() % 4) result.push_back('=');
    return result;
}

std::string CryptoHelper::base64Decode(const std::string& data) {
    static int decode_table[256];
    static bool init = false;
    if (!init) {
        for (int i = 0; i < 256; ++i) decode_table[i] = -1;
        for (int i = 0; i < 64; ++i) decode_table[static_cast<unsigned char>(BASE64_CHARS[i])] = i;
        init = true;
    }
    std::string result;
    int val = 0, valb = -8;
    for (unsigned char c : data) {
        if (c == '=') break;
        int idx = decode_table[c];
        if (idx == -1) continue;
        val = (val << 6) + idx;
        valb += 6;
        if (valb >= 0) {
            result.push_back(static_cast<char>((val >> valb) & 0xFF));
            valb -= 8;
        }
    }
    return result;
}

std::string CryptoHelper::base64UrlEncode(const std::string& data) {
    std::string result = base64Encode(data);
    for (char& c : result) {
        if (c == '+') c = '-';
        else if (c == '/') c = '_';
    }
    while (!result.empty() && result.back() == '=') result.pop_back();
    return result;
}

std::string CryptoHelper::base64UrlDecode(const std::string& data) {
    std::string result = data;
    for (char& c : result) {
        if (c == '-') c = '+';
        else if (c == '_') c = '/';
    }
    while (result.size() % 4) result.push_back('=');
    return base64Decode(result);
}

std::string CryptoHelper::hexEncode(const std::vector<uint8_t>& data) {
    std::ostringstream ss;
    ss << std::hex << std::setfill('0');
    for (uint8_t b : data) ss << std::setw(2) << static_cast<int>(b);
    return ss.str();
}

std::vector<uint8_t> CryptoHelper::hexDecode(const std::string& hex) {
    std::vector<uint8_t> result;
    for (size_t i = 0; i + 1 < hex.size(); i += 2) {
        unsigned int b;
        std::istringstream ss(hex.substr(i, 2));
        ss >> std::hex >> b;
        result.push_back(static_cast<uint8_t>(b));
    }
    return result;
}

std::optional<std::string> CryptoHelper::aesEncrypt(const std::string& key, const std::string& plaintext, const std::string& iv) {
    std::string padded = pkcs7Pad(plaintext, 16);
    EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
    if (!ctx) return std::nullopt;
    std::vector<unsigned char> ciphertext(padded.size() + 16);
    int len = 0, totalLen = 0;
    EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), nullptr,
        reinterpret_cast<const unsigned char*>(key.substr(0, 32).c_str()),
        reinterpret_cast<const unsigned char*>(iv.substr(0, 16).c_str()));
    EVP_EncryptUpdate(ctx, ciphertext.data(), &len,
        reinterpret_cast<const unsigned char*>(padded.data()), padded.size());
    totalLen = len;
    EVP_EncryptFinal_ex(ctx, ciphertext.data() + totalLen, &len);
    totalLen += len;
    EVP_CIPHER_CTX_free(ctx);
    return std::string(reinterpret_cast<char*>(ciphertext.data()), totalLen);
}

std::optional<std::string> CryptoHelper::aesDecrypt(const std::string& key, const std::string& ciphertext, const std::string& iv) {
    EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
    if (!ctx) return std::nullopt;
    std::vector<unsigned char> plaintext(ciphertext.size() + 16);
    int len = 0, totalLen = 0;
    EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), nullptr,
        reinterpret_cast<const unsigned char*>(key.substr(0, 32).c_str()),
        reinterpret_cast<const unsigned char*>(iv.substr(0, 16).c_str()));
    EVP_DecryptUpdate(ctx, plaintext.data(), &len,
        reinterpret_cast<const unsigned char*>(ciphertext.data()), ciphertext.size());
    totalLen = len;
    EVP_DecryptFinal_ex(ctx, plaintext.data() + totalLen, &len);
    totalLen += len;
    EVP_CIPHER_CTX_free(ctx);
    return pkcs7Unpad(std::string(reinterpret_cast<char*>(plaintext.data()), totalLen));
}

std::string CryptoHelper::randomHex(int bytes) {
    unsigned char buf[256];
    if (RAND_bytes(buf, bytes) != 1) {
        std::mt19937 rng(std::random_device{}());
        for (int i = 0; i < bytes; ++i) buf[i] = rng() & 0xFF;
    }
    return hexEncode(std::vector<uint8_t>(buf, buf + bytes));
}

std::string CryptoHelper::randomAlphanumeric(int length) {
    static const char chars[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<> dist(0, 61);
    std::string result;
    for (int i = 0; i < length; ++i) result += chars[dist(rng)];
    return result;
}

std::string CryptoHelper::generateSalt(int length) { return randomHex(length); }

std::string CryptoHelper::hashPassword(const std::string& password, const std::string& salt) {
    return sha256Hex(salt + password);
}

bool CryptoHelper::verifyPassword(const std::string& password, const std::string& hash, const std::string& salt) {
    return hashPassword(password, salt) == hash;
}

std::string CryptoHelper::encryptStream(const std::string& key, const std::string& data) {
    auto key_hash = sha256(key);
    std::string iv = key_hash.substr(0, 16);
    auto result = aesEncrypt(key_hash, data, iv);
    return result.value_or("");
}

std::string CryptoHelper::decryptStream(const std::string& key, const std::string& data) {
    auto key_hash = sha256(key);
    std::string iv = key_hash.substr(0, 16);
    auto result = aesDecrypt(key_hash, data, iv);
    return result.value_or("");
}

std::string CryptoHelper::pkcs7Pad(const std::string& data, size_t blockSize) {
    size_t pad = blockSize - (data.size() % blockSize);
    return data + std::string(pad, static_cast<char>(pad));
}

std::string CryptoHelper::pkcs7Unpad(const std::string& data) {
    if (data.empty()) return data;
    size_t pad = static_cast<unsigned char>(data.back());
    if (pad > data.size()) return data;
    return data.substr(0, data.size() - pad);
}

std::string CryptoHelper::generateUUID() {
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<> dist(0, 15);
    std::uniform_int_distribution<> dist2(8, 11);
    const char* hex = "0123456789abcdef";
    std::string uuid;
    for (int i = 0; i < 8; ++i) uuid += hex[dist(rng)];
    uuid += '-';
    for (int i = 0; i < 4; ++i) uuid += hex[dist(rng)];
    uuid += "-4";
    for (int i = 0; i < 3; ++i) uuid += hex[dist(rng)];
    uuid += '-';
    uuid += hex[dist2(rng)];
    for (int i = 0; i < 3; ++i) uuid += hex[dist(rng)];
    uuid += '-';
    for (int i = 0; i < 12; ++i) uuid += hex[dist(rng)];
    return uuid;
}
} // namespace
