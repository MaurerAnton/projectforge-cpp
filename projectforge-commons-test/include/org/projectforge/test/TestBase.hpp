// ProjectForge C++ port — GPL v3 — www.projectforge.org
#pragma once
#include <string>
#include <functional>
#include <iostream>
#include <vector>
#include <chrono>
#include <stdexcept>

namespace org::projectforge::test {

class TestSuite {
public:
    void test(const std::string& name, std::function<void()> fn) {
        tests_.push_back({name, fn});
    }

    int run() {
        int passed=0, failed=0;
        for(auto&[name,fn] : tests_) {
            std::cout << "  TEST " << name << " ... ";
            try {
                fn();
                std::cout << "PASSED" << std::endl;
                passed++;
            } catch(const std::exception& e) {
                std::cout << "FAILED: " << e.what() << std::endl;
                failed++;
            }
        }
        std::cout << "Results: " << passed << " passed, " << failed << " failed" << std::endl;
        return failed;
    }

    static void assertEquals(const std::string& expected, const std::string& actual, const std::string& msg="") {
        if(expected != actual) throw std::runtime_error("Expected '" + expected + "' but got '" + actual + "'. " + msg);
    }
    static void assertEquals(int expected, int actual, const std::string& msg="") {
        if(expected != actual) throw std::runtime_error("Expected " + std::to_string(expected) + " but got " + std::to_string(actual) + ". " + msg);
    }
    static void assertEquals(int64_t expected, int64_t actual, const std::string& msg="") {
        if(expected != actual) throw std::runtime_error("Expected " + std::to_string(expected) + " but got " + std::to_string(actual) + ". " + msg);
    }
    static void assertTrue(bool condition, const std::string& msg="") {
        if(!condition) throw std::runtime_error("Expected true. " + msg);
    }
    static void assertFalse(bool condition, const std::string& msg="") {
        if(condition) throw std::runtime_error("Expected false. " + msg);
    }
    static void assertNull(const void* ptr, const std::string& msg="") {
        if(ptr != nullptr) throw std::runtime_error("Expected null. " + msg);
    }
    static void assertNotNull(const void* ptr, const std::string& msg="") {
        if(ptr == nullptr) throw std::runtime_error("Expected not null. " + msg);
    }
    template<typename T>
    static void assertContains(const std::vector<T>& vec, const T& val, const std::string& msg="") {
        if(std::find(vec.begin(), vec.end(), val) == vec.end())
            throw std::runtime_error("Vector does not contain expected value. " + msg);
    }

private:
    std::vector<std::pair<std::string, std::function<void()>>> tests_;
};

} // namespace
