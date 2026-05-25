/////////////////////////////////////////////////////////////////////////////
// (C) 2001-2026 Micromata GmbH - GPL v3
/////////////////////////////////////////////////////////////////////////////
#pragma once
#include <string>
#include <vector>
namespace org::projectforge::common {
class BackupFilesPurging {
public:
    static void purgeBackupFiles(const std::string& directory, int maxNumberOfBackups);
private:
    BackupFilesPurging() = delete;
};
}
