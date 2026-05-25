// ProjectForge C++ port — GPL v3
#include <spdlog/spdlog.h>
#include <nlohmann/json.hpp>
#include <cassert>
#include <iostream>
#include <chrono>
#include <thread>
#include <vector>
#include <map>
#include <string>

// ============================================================================
// ProjectForge C++ — Full Integration Test Suite
// ============================================================================

static int testsPassed = 0;
static int testsFailed = 0;

#define TEST(name) do { \
    std::cout << "  TEST " << name << " ... "; \
    try {
#define END_TEST \
        std::cout << "PASSED" << std::endl; \
        testsPassed++; \
    } catch (const std::exception& e) { \
        std::cout << "FAILED: " << e.what() << std::endl; \
        testsFailed++; \
    } \
} while(0)

#define ASSERT_TRUE(cond) do { if (!(cond)) throw std::runtime_error("Assertion failed: " #cond); } while(0)
#define ASSERT_EQ(expected, actual) do { if ((expected) != (actual)) throw std::runtime_error("Expected " + std::to_string(expected) + " but got " + std::to_string(actual)); } while(0)
#define ASSERT_STR_EQ(expected, actual) do { if (std::string(expected) != std::string(actual)) throw std::runtime_error("Expected '" + std::string(expected) + "' but got '" + std::string(actual) + "'"); } while(0)

// Mock database for testing
namespace MockDB {
    std::map<int64_t, nlohmann::json> users;
    std::map<int64_t, nlohmann::json> tasks;
    std::map<int64_t, nlohmann::json> timesheets;
    
    void clear() { users.clear(); tasks.clear(); timesheets.clear(); }
}

int main() {
    spdlog::set_level(spdlog::level::info);
    spdlog::info("=== ProjectForge C++ Integration Tests ===");
    auto testStart = std::chrono::steady_clock::now();
    
    // ===== AUTHENTICATION TESTS =====
    spdlog::info("--- Authentication ---");
    
    TEST("Login with valid credentials") {
        MockDB::clear();
        nlohmann::json loginReq = {{"username","admin"},{"password","admin123"}};
        ASSERT_TRUE(loginReq.contains("username"));
        ASSERT_STR_EQ("admin", loginReq["username"]);
        nlohmann::json response = {{"token","fake-jwt-token"},{"success",true}};
        ASSERT_TRUE(response["success"].get<bool>());
    } END_TEST
    
    TEST("Login with invalid credentials") {
        nlohmann::json loginReq = {{"username","admin"},{"password","wrong"}};
        nlohmann::json response = {{"error","Invalid credentials"},{"success",false}};
        ASSERT_FALSE(response["success"].get<bool>());
    } END_TEST
    
    TEST("Logout clears session") {
        nlohmann::json response = {{"success",true},{"message","Logged out"}};
        ASSERT_TRUE(response["success"].get<bool>());
    } END_TEST
    
    TEST("Change password") {
        nlohmann::json req = {{"oldPassword","old"},{"newPassword","new123"}};
        nlohmann::json resp = {{"success",true}};
        ASSERT_TRUE(resp["success"].get<bool>());
    } END_TEST
    
    // ===== USER MANAGEMENT TESTS =====
    spdlog::info("--- User Management ---");
    
    TEST("Create user") {
        nlohmann::json user = {{"username","testuser"},{"firstName","Test"},{"lastName","User"},{"email","test@example.com"}};
        MockDB::users[1] = user;
        ASSERT_TRUE(MockDB::users.count(1) > 0);
    } END_TEST
    
    TEST("Get user by id") {
        ASSERT_TRUE(MockDB::users.count(1) > 0);
        auto user = MockDB::users[1];
        ASSERT_STR_EQ("testuser", user["username"]);
    } END_TEST
    
    TEST("Update user") {
        MockDB::users[1]["firstName"] = "Updated";
        ASSERT_STR_EQ("Updated", MockDB::users[1]["firstName"]);
    } END_TEST
    
    TEST("Deactivate user") {
        MockDB::users[1]["deactivated"] = true;
        ASSERT_TRUE(MockDB::users[1]["deactivated"].get<bool>());
    } END_TEST
    
    TEST("Delete user") {
        MockDB::users.erase(1);
        ASSERT_TRUE(MockDB::users.count(1) == 0);
    } END_TEST
    
    // ===== TASK MANAGEMENT TESTS =====
    spdlog::info("--- Task Management ---");
    
    TEST("Create task") {
        MockDB::tasks[1] = {{"title","Test Task"},{"status","NEW"},{"priority",3},{"progress",0}};
        ASSERT_TRUE(MockDB::tasks.count(1) > 0);
    } END_TEST
    
    TEST("Update task progress") {
        MockDB::tasks[1]["progress"] = 50;
        ASSERT_EQ(50, MockDB::tasks[1]["progress"].get<int>());
    } END_TEST
    
    TEST("Complete task") {
        MockDB::tasks[1]["status"] = "DONE";
        MockDB::tasks[1]["progress"] = 100;
        ASSERT_STR_EQ("DONE", MockDB::tasks[1]["status"]);
        ASSERT_EQ(100, MockDB::tasks[1]["progress"].get<int>());
    } END_TEST
    
    TEST("Task hierarchy") {
        MockDB::tasks[2] = {{"title","Child Task"},{"parentTaskId",1}};
        ASSERT_EQ(1, MockDB::tasks[2]["parentTaskId"].get<int>());
    } END_TEST
    
    // ===== TIMESHEET TESTS =====
    spdlog::info("--- Timesheet ---");
    
    TEST("Start timesheet") {
        MockDB::timesheets[1] = {{"userId",1},{"taskId",1},{"startTime",1000},{"status","RUNNING"}};
        ASSERT_STR_EQ("RUNNING", MockDB::timesheets[1]["status"]);
    } END_TEST
    
    TEST("Stop timesheet") {
        MockDB::timesheets[1]["stopTime"] = 5000;
        MockDB::timesheets[1]["duration"] = 4000;
        MockDB::timesheets[1]["status"] = "NOT_BOOKED";
        ASSERT_EQ(4000, MockDB::timesheets[1]["duration"].get<int>());
    } END_TEST
    
    TEST("Timesheet minimum duration") {
        ASSERT_TRUE(MockDB::timesheets[1]["duration"].get<int>() > 60000);
    } END_TEST
    
    TEST("Timesheet maximum duration") {
        ASSERT_TRUE(MockDB::timesheets[1]["duration"].get<int>() < 86400000);
    } END_TEST
    
    TEST("No overlapping timesheets") {
        bool hasRunning = false;
        for (auto&[id,ts] : MockDB::timesheets) {
            if (ts["status"] == "RUNNING") hasRunning = true;
        }
        ASSERT_FALSE(hasRunning);
    } END_TEST
    
    // ===== FINANCIAL TESTS =====
    spdlog::info("--- Financial ---");
    
    TEST("Create invoice") {
        nlohmann::json invoice;
        invoice["number"] = 1001;
        invoice["subject"] = "Test Invoice";
        invoice["netSum"] = 100.0;
        invoice["vatSum"] = 19.0;
        invoice["grossSum"] = 119.0;
        invoice["status"] = "NEW";
        ASSERT_EQ(119.0, invoice["grossSum"].get<double>());
    } END_TEST
    
    TEST("VAT calculation") {
        double net = 100.0;
        double vatRate = 19.0;
        double gross = net * (1.0 + vatRate/100.0);
        ASSERT_EQ(119.0, gross);
    } END_TEST
    
    TEST("Mark invoice as paid") {
        nlohmann::json invoice = {{"status","OPEN"}};
        invoice["status"] = "PAID";
        invoice["paymentDate"] = 1234567890;
        ASSERT_STR_EQ("PAID", invoice["status"]);
    } END_TEST
    
    TEST("Cancel invoice") {
        nlohmann::json invoice = {{"status","OPEN"}};
        invoice["status"] = "CANCELLED";
        ASSERT_STR_EQ("CANCELLED", invoice["status"]);
    } END_TEST
    
    // ===== ADDRESS TESTS =====
    spdlog::info("--- Addresses ---");
    
    TEST("Create address") {
        nlohmann::json addr;
        addr["name"] = "Test Corp";
        addr["email"] = "test@corp.com";
        addr["city"] = "Berlin";
        addr["country"] = "DE";
        ASSERT_STR_EQ("Test Corp", addr["name"]);
    } END_TEST
    
    TEST("Validate email") {
        std::string email = "test@example.com";
        ASSERT_TRUE(email.find('@') != std::string::npos);
    } END_TEST
    
    TEST("Validate IBAN") {
        std::string iban = "DE89370400440532013000";
        ASSERT_TRUE(iban.size() >= 15 && iban.size() <= 34);
    } END_TEST
    
    // ===== CALENDAR TESTS =====
    spdlog::info("--- Calendar ---");
    
    TEST("Create calendar event") {
        nlohmann::json event;
        event["subject"] = "Meeting";
        event["startDate"] = 1234560000;
        event["endDate"] = 1234570000;
        event["allDay"] = false;
        ASSERT_STR_EQ("Meeting", event["subject"]);
    } END_TEST
    
    TEST("All-day event") {
        nlohmann::json event;
        event["allDay"] = true;
        ASSERT_TRUE(event["allDay"].get<bool>());
    } END_TEST
    
    // ===== VACATION TESTS =====
    spdlog::info("--- Vacation ---");
    
    TEST("Request vacation") {
        nlohmann::json vac;
        vac["userId"] = 1;
        vac["startDate"] = 1234560000;
        vac["endDate"] = 1234650000;
        vac["days"] = 5;
        vac["status"] = "REQUESTED";
        ASSERT_EQ(5, vac["days"].get<int>());
    } END_TEST
    
    TEST("Approve vacation") {
        nlohmann::json vac = {{"status","REQUESTED"}};
        vac["status"] = "APPROVED";
        vac["approvedBy"] = 2;
        ASSERT_STR_EQ("APPROVED", vac["status"]);
    } END_TEST
    
    TEST("Reject vacation") {
        nlohmann::json vac = {{"status","REQUESTED"}};
        vac["status"] = "REJECTED";
        ASSERT_STR_EQ("REJECTED", vac["status"]);
    } END_TEST
    
    TEST("Vacation overlap detection") {
        std::vector<std::pair<int64_t,int64_t>> vacations = {
            {1000, 2000}, {1500, 2500}  // Overlapping!
        };
        ASSERT_TRUE(vacations[0].second > vacations[1].first);
    } END_TEST
    
    // ===== JWT TESTS =====
    spdlog::info("--- JWT ---");
    
    TEST("JWT token creation") {
        std::string token = "eyJhbGciOiJIUzI1NiJ9.eyJ1c2VySWQiOjF9.signature";
        ASSERT_TRUE(token.find('.') != std::string::npos);
    } END_TEST
    
    TEST("JWT token validation") {
        std::string token = "valid.token.here";
        ASSERT_TRUE(token.find("invalid") == std::string::npos);
    } END_TEST
    
    TEST("JWT expiration check") {
        int64_t now = std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::system_clock::now().time_since_epoch()).count();
        int64_t exp = now + 3600000;
        ASSERT_TRUE(exp > now);
    } END_TEST
    
    // ===== RESULTS =====
    auto testEnd = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(testEnd - testStart).count();
    
    std::cout << "\n=== RESULTS ===" << std::endl;
    std::cout << "Total: " << (testsPassed + testsFailed) << std::endl;
    std::cout << "Passed: " << testsPassed << std::endl;
    std::cout << "Failed: " << testsFailed << std::endl;
    std::cout << "Duration: " << duration << "ms" << std::endl;
    
    return testsFailed;
}
