/////////////////////////////////////////////////////////////////////////////
// (C) 2001-2026 Micromata GmbH - GPL v3
/////////////////////////////////////////////////////////////////////////////
#pragma once
#include <string>
namespace org::projectforge::shared::storage {
class StorageUtils {
public:
    static std::string getStoragePath(const std::string& baseDir, const std::string& subDir);
    static std::string getAttachmentPath(const std::string& baseDir, int entityId, const std::string& filename);
    static bool ensureDirectory(const std::string& path);
};
}
