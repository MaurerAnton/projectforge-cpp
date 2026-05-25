// ProjectForge C++ port — GPL v3 — www.projectforge.org
#pragma once
#include <string>
#include <vector>
#include <optional>
#include <filesystem>

namespace org::projectforge::common {

class FileHelper {
public:
    namespace fs = std::filesystem;

    static std::string readFile(const std::string& path);
    static std::vector<uint8_t> readBinaryFile(const std::string& path);
    static void writeFile(const std::string& path, const std::string& content);
    static void writeBinaryFile(const std::string& path, const std::vector<uint8_t>& data);

    static bool exists(const std::string& path);
    static bool isDirectory(const std::string& path);
    static bool isFile(const std::string& path);
    static bool deleteFile(const std::string& path);
    static bool createDirectory(const std::string& path);
    static bool createDirectories(const std::string& path);

    static std::string getExtension(const std::string& path);
    static std::string getFilename(const std::string& path);
    static std::string getBasename(const std::string& path);
    static std::string getDirname(const std::string& path);
    static std::string getCanonicalPath(const std::string& path);

    static std::string normalizePath(const std::string& path);
    static std::string joinPath(const std::string& base, const std::string& sub);

    static int64_t getFileSize(const std::string& path);
    static std::vector<std::string> listFiles(const std::string& dir, const std::string& pattern = "*");
    static std::vector<std::string> listDirectories(const std::string& dir);

    static std::string getMimeType(const std::string& filename);

    static std::string getTempDir();
    static std::string createTempFile(const std::string& prefix, const std::string& suffix);

    static void copyFile(const std::string& src, const std::string& dst);
    static void moveFile(const std::string& src, const std::string& dst);

    static std::string readResourceFile(const std::string& resourcePath);
};
}