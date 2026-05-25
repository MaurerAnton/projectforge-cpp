/////////////////////////////////////////////////////////////////////////////
// (C) 2001-2026 Micromata GmbH - GPL v3
/////////////////////////////////////////////////////////////////////////////
#pragma once
#include <string>
namespace org::projectforge::common::logging {
class LogUtils {
public:
    static std::string getOsInfos();
    static std::string getMemoryInfos();
    static std::string getJavaInfos();
};
}
