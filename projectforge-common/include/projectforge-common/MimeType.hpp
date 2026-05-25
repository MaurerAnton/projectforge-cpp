/////////////////////////////////////////////////////////////////////////////
// (C) 2001-2026 Micromata GmbH - GPL v3
/////////////////////////////////////////////////////////////////////////////
#pragma once
#include <string>
#include <vector>
#include <optional>
namespace org::projectforge::common {
class MimeType {
public:
    static const MimeType DOC, GZIP, JPG, MS_PROJECT, PDF, PNG, SVG, TEXT, VCARD, XLS, XLSX, XML, ZIP;
    static const std::vector<const MimeType*> values;

    const std::string& getMimeTypeString() const { return mimeType_; }
    static const MimeType* getMimeType(const std::string& filename);
    const std::vector<std::string>& getExtensions() const { return extensions_; }
private:
    std::string mimeType_;
    std::vector<std::string> extensions_;
    MimeType(const std::string& mt, std::vector<std::string> exts) : mimeType_(mt), extensions_(std::move(exts)) {}
};
} // namespace org::projectforge::common
