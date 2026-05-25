/////////////////////////////////////////////////////////////////////////////
// (C) 2001-2026 Micromata GmbH - GPL v3
/////////////////////////////////////////////////////////////////////////////
#pragma once
#include <string>
#include <cstdint>
namespace org::projectforge::common {
class NumberOfBytes {
public:
    explicit NumberOfBytes(int64_t bytes);
    int64_t getBytes() const { return bytes_; }
    int64_t getKiloBytes() const { return bytes_ / 1024; }
    int64_t getMegaBytes() const { return bytes_ / (1024*1024); }
    std::string format() const;
    std::string toString() const { return format(); }
private:
    int64_t bytes_;
};
}
