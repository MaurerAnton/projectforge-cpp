/////////////////////////////////////////////////////////////////////////////
// (C) 2001-2026 Micromata GmbH - GPL v3
/////////////////////////////////////////////////////////////////////////////
#pragma once
#include <string>
#include <cstdint>
namespace org::projectforge::common {
class MaxFileSizeExceeded {
public:
    MaxFileSizeExceeded(const std::string& filename, int64_t fileSize, int64_t maxFileSize);
    const std::string& getFilename() const { return filename_; }
    int64_t getFileSize() const { return fileSize_; }
    int64_t getMaxFileSize() const { return maxFileSize_; }
private:
    std::string filename_;
    int64_t fileSize_;
    int64_t maxFileSize_;
};
}
