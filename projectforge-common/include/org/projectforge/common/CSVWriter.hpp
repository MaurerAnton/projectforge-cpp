// ProjectForge C++ port — GPL v3 — www.projectforge.org
#pragma once
#include <string>
#include <vector>
#include <sstream>

namespace org::projectforge::common {

class CSVWriter {
public:
    explicit CSVWriter(char delimiter = ',', char quote = '"') : delimiter_(delimiter), quote_(quote) {}
    void writeRow(const std::vector<std::string>& fields);
    std::string toString() const;
    void writeToFile(const std::string& path);
private:
    std::ostringstream buf_;
    char delimiter_, quote_;
};
}