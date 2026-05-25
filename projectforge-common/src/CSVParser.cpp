// ProjectForge C++ port — GPL v3 — www.projectforge.org
#include "org/projectforge/common/CSVParser.hpp"
#include "org/projectforge/common/FileHelper.hpp"
#include <sstream>

namespace org::projectforge::common {

std::vector<std::vector<std::string>> CSVParser::parse(const std::string& csv) {
    std::vector<std::vector<std::string>> result;
    std::istringstream ss(csv);
    std::string line;
    while (std::getline(ss, line)) {
        if (line.empty()) continue;
        result.push_back(parseLine(line));
    }
    return result;
}

std::vector<std::vector<std::string>> CSVParser::parseFile(const std::string& path) {
    return parse(FileHelper::readFile(path));
}

std::vector<std::string> CSVParser::parseLine(const std::string& line) {
    std::vector<std::string> result;
    std::string field;
    bool inQuotes = false;
    for (size_t i = 0; i < line.size(); ++i) {
        char c = line[i];
        if (inQuotes) {
            if (c == quote_) {
                if (i + 1 < line.size() && line[i + 1] == quote_) {
                    field += quote_;
                    ++i;
                } else {
                    inQuotes = false;
                }
            } else {
                field += c;
            }
        } else {
            if (c == quote_) {
                inQuotes = true;
            } else if (c == delimiter_) {
                result.push_back(field);
                field.clear();
            } else {
                field += c;
            }
        }
    }
    result.push_back(field);
    return result;
}
}