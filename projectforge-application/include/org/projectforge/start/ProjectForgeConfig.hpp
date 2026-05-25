// ProjectForge C++ port — GPL v3 — www.projectforge.org
#pragma once
#include <string>
#include <cstdint>

namespace org::projectforge::start {

struct ProjectForgeConfig {
    int port = 8080;
    std::string bindAddress = "0.0.0.0";
    std::string databasePath = "projectforge.db";
    std::string jcrPath = "jcr-data";
    std::string logLevel = "info";
    std::string webappDir = "projectforge-webapp";
    std::string i18nDir = "i18n";
    std::string uploadDir = "uploads";
    std::string tempDir = "/tmp/projectforge";
    int maxUploadSizeMb = 100;
    int maxThreads = 16;
    bool enableSsl = false;
    std::string sslCertFile;
    std::string sslKeyFile;
    int sessionTimeoutMinutes = 30;
    std::string jwtSecret;
};

}