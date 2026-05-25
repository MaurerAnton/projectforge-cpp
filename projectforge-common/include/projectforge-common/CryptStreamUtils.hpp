/////////////////////////////////////////////////////////////////////////////
// (C) 2001-2026 Micromata GmbH - GPL v3
/////////////////////////////////////////////////////////////////////////////
#pragma once
#include <string>
#include <vector>
#include <cstdint>
namespace org::projectforge::common {
class CryptStreamUtils {
public:
    static std::vector<uint8_t> encrypt(const std::vector<uint8_t>& data, const std::string& password);
    static std::vector<uint8_t> decrypt(const std::vector<uint8_t>& data, const std::string& password);
    static std::string encryptToString(const std::string& plainText, const std::string& password);
    static std::string decryptToString(const std::string& encryptedBase64, const std::string& password);
};
}
