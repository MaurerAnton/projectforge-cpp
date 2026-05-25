/////////////////////////////////////////////////////////////////////////////
// (C) 2001-2026 Micromata GmbH - GPL v3
/////////////////////////////////////////////////////////////////////////////
#pragma once
#include <string>
namespace org::projectforge::common {
enum class DatabaseDialect { POSTGRESQL, MYSQL, H2, HSQL, ORACLE, MSSQL };
std::string databaseDialectToString(DatabaseDialect d);
DatabaseDialect databaseDialectFromString(const std::string& s);
}
