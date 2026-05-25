// ProjectForge C++ port — GPL v3 — www.projectforge.org
#include "org/projectforge/common/FileHelper.hpp"
#include "org/projectforge/common/StringHelper.hpp"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cstdio>

namespace org::projectforge::common {

std::string FileHelper::readFile(const std::string& path) {
    std::ifstream f(path, std::ios::in);
    if (!f) return "";
    std::ostringstream ss;
    ss << f.rdbuf();
    return ss.str();
}

std::vector<uint8_t> FileHelper::readBinaryFile(const std::string& path) {
    std::ifstream f(path, std::ios::binary | std::ios::ate);
    if (!f) return {};
    auto size = f.tellg();
    f.seekg(0);
    std::vector<uint8_t> data(size);
    f.read(reinterpret_cast<char*>(data.data()), size);
    return data;
}

void FileHelper::writeFile(const std::string& path, const std::string& content) {
    fs::create_directories(fs::path(path).parent_path());
    std::ofstream f(path);
    f << content;
}

void FileHelper::writeBinaryFile(const std::string& path, const std::vector<uint8_t>& data) {
    fs::create_directories(fs::path(path).parent_path());
    std::ofstream f(path, std::ios::binary);
    f.write(reinterpret_cast<const char*>(data.data()), data.size());
}

bool FileHelper::exists(const std::string& path) { return fs::exists(path); }
bool FileHelper::isDirectory(const std::string& path) { return fs::is_directory(path); }
bool FileHelper::isFile(const std::string& path) { return fs::is_regular_file(path); }
bool FileHelper::deleteFile(const std::string& path) { return fs::remove(path); }

bool FileHelper::createDirectory(const std::string& path) { return fs::create_directory(path); }
bool FileHelper::createDirectories(const std::string& path) { return fs::create_directories(path); }

std::string FileHelper::getExtension(const std::string& path) { return fs::path(path).extension().string(); }
std::string FileHelper::getFilename(const std::string& path) { return fs::path(path).filename().string(); }
std::string FileHelper::getBasename(const std::string& path) { return fs::path(path).stem().string(); }
std::string FileHelper::getDirname(const std::string& path) { return fs::path(path).parent_path().string(); }
std::string FileHelper::getCanonicalPath(const std::string& path) { return fs::canonical(fs::absolute(path)).string(); }
std::string FileHelper::normalizePath(const std::string& path) { return fs::path(path).lexically_normal().string(); }
std::string FileHelper::joinPath(const std::string& b, const std::string& s) { return (fs::path(b) / s).string(); }

int64_t FileHelper::getFileSize(const std::string& path) {
    try { return static_cast<int64_t>(fs::file_size(path)); } catch (...) { return -1; }
}

std::vector<std::string> FileHelper::listFiles(const std::string& dir, const std::string& pattern) {
    std::vector<std::string> result;
    if (!fs::is_directory(dir)) return result;
    for (const auto& entry : fs::directory_iterator(dir)) {
        if (fs::is_regular_file(entry)) {
            std::string name = entry.path().filename().string();
            if (pattern == "*" || name.find(pattern) != std::string::npos) result.push_back(entry.path().string());
        }
    }
    return result;
}

std::vector<std::string> FileHelper::listDirectories(const std::string& dir) {
    std::vector<std::string> result;
    if (!fs::is_directory(dir)) return result;
    for (const auto& entry : fs::directory_iterator(dir)) {
        if (fs::is_directory(entry)) result.push_back(entry.path().string());
    }
    return result;
}

std::string FileHelper::getMimeType(const std::string& filename) {
    static const std::map<std::string, std::string> mimeMap = {
        {".html","text/html"},{".css","text/css"},{".js","application/javascript"},
        {".json","application/json"},{".xml","application/xml"},{".pdf","application/pdf"},
        {".png","image/png"},{".jpg","image/jpeg"},{".jpeg","image/jpeg"},
        {".gif","image/gif"},{".svg","image/svg+xml"},{".ico","image/x-icon"},
        {".txt","text/plain"},{".csv","text/csv"},{".zip","application/zip"},
        {".doc","application/msword"},{".xls","application/vnd.ms-excel"},
        {".xlsx","application/vnd.openxmlformats-officedocument.spreadsheetml.sheet"},
        {".docx","application/vnd.openxmlformats-officedocument.wordprocessingml.document"}
    };
    std::string ext = getExtension(filename);
    for (char& c : ext) c = static_cast<char>(std::tolower(c));
    auto it = mimeMap.find(ext);
    return (it != mimeMap.end()) ? it->second : "application/octet-stream";
}

std::string FileHelper::getTempDir() { return fs::temp_directory_path().string(); }

std::string FileHelper::createTempFile(const std::string& prefix, const std::string& suffix) {
    auto path = fs::temp_directory_path() / (prefix + "XXXXXX" + suffix);
    return path.string();
}

void FileHelper::copyFile(const std::string& src, const std::string& dst) { fs::copy(src, dst, fs::copy_options::overwrite_existing); }
void FileHelper::moveFile(const std::string& src, const std::string& dst) { fs::rename(src, dst); }

std::string FileHelper::readResourceFile(const std::string& resourcePath) {
    return readFile(resourcePath);
}
}