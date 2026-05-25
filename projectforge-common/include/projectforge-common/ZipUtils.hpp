/////////////////////////////////////////////////////////////////////////////
// (C) 2001-2026 Micromata GmbH - GPL v3
/////////////////////////////////////////////////////////////////////////////
#pragma once
#include <string>
#include <vector>
#include "projectforge-common/ZipMode.hpp"
namespace org::projectforge::common {
class ZipUtils {
public:
    static void zipFiles(const std::string& zipPath, const std::vector<std::string>& files, ZipMode mode = ZipMode::DEFAULT);
    static void unzip(const std::string& zipPath, const std::string& destDir);
    static std::vector<std::string> listZipEntries(const std::string& zipPath);
};
}
