// ProjectForge C++ port — GPL v3 — www.projectforge.org
#include "org/projectforge/common/MimeType.hpp"
#include <map>
#include <algorithm>

namespace org::projectforge::common {

std::string MimeType::getMimeType(const std::string& filename) {
    auto pos = filename.rfind('.');
    if (pos == std::string::npos) return "application/octet-stream";
    std::string ext = filename.substr(pos);
    for (char& c : ext) c = static_cast<char>(std::tolower(c));
    static const std::map<std::string, std::string> map = {
        {".html","text/html"},{".htm","text/html"},{".css","text/css"},{".js","text/javascript"},
        {".json","application/json"},{".xml","text/xml"},{".pdf","application/pdf"},
        {".png","image/png"},{".jpg","image/jpeg"},{".jpeg","image/jpeg"},
        {".gif","image/gif"},{".svg","image/svg+xml"},{".ico","image/x-icon"},
        {".bmp","image/bmp"},{".tiff","image/tiff"},{".webp","image/webp"},
        {".txt","text/plain"},{".csv","text/csv"},{".rtf","application/rtf"},
        {".zip","application/zip"},{".tar","application/x-tar"},{".gz","application/gzip"},
        {".doc","application/msword"},{".dot","application/msword"},
        {".docx","application/vnd.openxmlformats-officedocument.wordprocessingml.document"},
        {".dotx","application/vnd.openxmlformats-officedocument.wordprocessingml.template"},
        {".xls","application/vnd.ms-excel"},{".xlt","application/vnd.ms-excel"},
        {".xlsx","application/vnd.openxmlformats-officedocument.spreadsheetml.sheet"},
        {".xltx","application/vnd.openxmlformats-officedocument.spreadsheetml.template"},
        {".ppt","application/vnd.ms-powerpoint"},{".pps","application/vnd.ms-powerpoint"},
        {".pptx","application/vnd.openxmlformats-officedocument.presentationml.presentation"},
        {".mp3","audio/mpeg"},{".wav","audio/wav"},{".ogg","audio/ogg"},
        {".mp4","video/mp4"},{".avi","video/x-msvideo"},{".mov","video/quicktime"},
        {".ics","text/calendar"},{".vcf","text/vcard"},{".vcard","text/vcard"},
    };
    auto it = map.find(ext);
    return (it != map.end()) ? it->second : "application/octet-stream";
}

bool MimeType::isImage(const std::string& m) { return m.find("image/") == 0; }
bool MimeType::isPdf(const std::string& m) { return m == "application/pdf"; }
bool MimeType::isText(const std::string& m) { return m.find("text/") == 0 || m == "application/json" || m == "application/xml"; }
bool MimeType::isOffice(const std::string& m) { return m.find("officedocument") != std::string::npos || m.find("ms-") != std::string::npos; }

std::string MimeType::getExtension(const std::string& mime) {
    static const std::map<std::string, std::string> rev = {
        {"text/html",".html"},{"application/json",".json"},{"application/pdf",".pdf"},
        {"image/png",".png"},{"image/jpeg",".jpg"},{"image/gif",".gif"},{"image/svg+xml",".svg"}
    };
    auto it = rev.find(mime);
    return (it != rev.end()) ? it->second : ".bin";
}
}