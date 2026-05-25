// ProjectForge C++ port — GPL v3 — www.projectforge.org
#pragma once
#include <string>

namespace org::projectforge::common {

class MimeType {
public:
    static std::string getMimeType(const std::string& filename);
    static bool isImage(const std::string& mimeType);
    static bool isPdf(const std::string& mimeType);
    static bool isText(const std::string& mimeType);
    static bool isOffice(const std::string& mimeType);
    static std::string getExtension(const std::string& mimeType);
};
}