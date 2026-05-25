/////////////////////////////////////////////////////////////////////////////
//
// Project ProjectForge Community Edition
//         www.projectforge.org
//
// Copyright (C) 2001-2026 Micromata GmbH, Germany (www.micromata.com)
//
// ProjectForge is dual-licensed.
//
// This community edition is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License as published
// by the Free Software Foundation; version 3 of the License.
//
// This community edition is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General
// Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this program; if not, see http://www.gnu.org/licenses/.
//
/////////////////////////////////////////////////////////////////////////////

#pragma once

#include <string>
#include <vector>
#include <map>
#include <memory>
#include <optional>

namespace org::projectforge::common {

/**
 * Simple csv parser
 */
class CSVParser {
public:
    static constexpr const char* ERROR_UNEXPECTED_QUOTATIONMARK = "Unexpected quotation mark \" (only allowed in quoted cells).";
    static constexpr const char* ERROR_QUOTATIONMARK_MISSED_AT_END_OF_CELL = "Quotation \" missed at the end of cell.";
    static constexpr const char* ERROR_DELIMITER_OR_NEW_LINE_EXPECTED_AFTER_QUOTATION_MARK = "Delimiter or new line expected after quotation mark.";
    static constexpr const char* ERROR_UNEXPECTED_CHARACTER_AFTER_QUOTATION_MARK = "Unexpected character after quotation mark.";

    enum class Type {
        EOF_TOKEN,
        EOL,
        CHAR
    };

    explicit CSVParser(std::istream& source);
    ~CSVParser() = default;

    /**
     * Parses the first (next) line and returns the cells as string.
     * Stores also the col numbers of the head cols.
     */
    std::optional<std::vector<std::string>> parseHeadCols();

    /**
     * Get the cell with the given colname.
     */
    std::string getCell(const std::vector<std::string>& cells, const std::string& colname);

    /**
     * Returns nullopt, if EOF.
     */
    std::optional<std::vector<std::string>> parseLine();

    std::string parseCell();

    void setCsvSeparatorChar(char csvSeparatorChar);

    int lineno() const;

    static std::string createMessage(const std::string& msg, const std::string& s, int line, int col);

private:
    char csvSeparatorChar_ = ';';
    std::istream& source_;
    Type type_ = Type::EOF_TOKEN;
    int lineno_ = 1;
    int colno_ = 0;
    int val_ = 0;
    char cval_ = 0;
    int pushbackBuffer_[5] = {0};
    int pushbackIndex_ = -1;
    std::map<std::string, int> colMap_;

    void skipBOM();
    std::string createMessage(const std::string& msg, const std::string& s);
    std::string createMessage(const std::string& msg);
    void skipWhitespaces();
    bool isIdentifierPart(char ch);
    Type nextToken();
    void unread(int b);
    void unread();
    int read();
};

} // namespace org::projectforge::common
