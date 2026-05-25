// ProjectForge C++ port — GPL v3 — www.projectforge.org
#include "org/projectforge/common/CSVWriter.hpp"
#include "org/projectforge/common/StringHelper.hpp"
#include "org/projectforge/common/FileHelper.hpp"
#include <fstream>

namespace org::projectforge::common {

void CSVWriter::writeRow(const std::vector<std::string>& fields) {
    for (size_t i = 0; i < fields.size(); ++i) {
        if (i > 0) buf_ << delimiter_;
        std::string f = fields[i];
        bool needsQuote = f.find(delimiter_) != std::string::npos || f.find('\n') != std::string::npos || f.find(quote_) != std::string::npos;
        if (needsQuote) {
            buf_ << quote_ << StringHelper::replace(f, std::string(1, quote_), std::string(2, quote_)) << quote_;
        } else {
            buf_ << f;
        }
    }
    buf_ << "\n";
}

std::string CSVWriter::toString() const { return buf_.str(); }

void CSVWriter::writeToFile(const std::string& path) {
    FileHelper::writeFile(path, buf_.str());
}
}