/////////////////////////////////////////////////////////////////////////////
// (C) 2001-2026 Micromata GmbH - GPL v3
/////////////////////////////////////////////////////////////////////////////
#pragma once
#include <string>
#include <vector>
#include <optional>
namespace org::projectforge::common {
class FileUtils {
public:
    static std::string readFileToString(const std::string& path);
    static void writeStringToFile(const std::string& path, const std::string& content);
    static bool fileExists(const std::string& path);
    static bool deleteFile(const std::string& path);
    static bool createDirectory(const std::string& path);
    static std::vector<std::string> listFiles(const std::string& path);
    static std::string getParentPath(const std::string& path);
    static std::string getFileName(const std::string& path);
    static std::string getFileExtension(const std::string& path);
    static std::string getBaseName(const std::string& path);
    static int64_t fileSize(const std::string& path);
    static bool isDirectory(const std::string& path);
    static std::string getTempDir();
    static std::string createTempFile(const std::string& prefix, const std::string& suffix);
};
}
