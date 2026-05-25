// ProjectForge C++ — Config stub
#include <string>
namespace org::projectforge::start {
struct ProjectForgeConfig {
    int port = 8080;
    std::string bindAddress = "0.0.0.0";
    std::string databasePath = "projectforge.db";
    std::string logLevel = "info";
};
} // namespace
