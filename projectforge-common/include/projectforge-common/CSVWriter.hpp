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
#include <ostream>
#include <memory>

namespace org::projectforge::common {

/**
 * Helper class for writing comma separated values.
 */
class CSVWriter {
public:
    static constexpr char DEFAULT_CSV_SEPARATOR_CHAR = ';';

    explicit CSVWriter(std::ostream& out);

    void flush();

    CSVWriter& writeLine(const std::vector<std::string>& values);

    CSVWriter& writeEndOfLine();

    /** Appends the given value to the buffer. */
    CSVWriter& write(long value);

    /** Appends the given value to the buffer. */
    CSVWriter& write(double value);

    /** Appends the given value. The string will be encapsulated in quotation marks. */
    CSVWriter& write(const std::string& s);

    void setCsvSeparator(char csvSeparator);

    void setCr(const std::string& cr);

private:
    std::ostream& out_;
    char csvSeparatorChar_ = DEFAULT_CSV_SEPARATOR_CHAR;
    std::string cr_ = "\n";
    bool firstEntry_ = true;

    void writeSeparator();
};

} // namespace org::projectforge::common
