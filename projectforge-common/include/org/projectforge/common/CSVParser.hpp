// ProjectForge C++ port — GPL v3 — www.projectforge.org
#pragma once
#include <string>
#include <vector>

namespace org::projectforge::common {

class CSVParser {
public:
    explicit CSVParser(char delimiter = ',', char quote = '"') : delimiter_(delimiter), quote_(quote) {}
    std::vector<std::vector<std::string>> parse(const std::string& csv);
    std::vector<std::vector<std::string>> parseFile(const std::string& path);
    std::vector<std::string> parseLine(const std::string& line);
private:
    char delimiter_, quote_;
};
}