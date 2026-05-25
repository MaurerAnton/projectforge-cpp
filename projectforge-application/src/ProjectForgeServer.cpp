// ProjectForge C++ port — GPL v3 — www.projectforge.org
#include "org/projectforge/start/ProjectForgeServer.hpp"
#include "org/projectforge/start/DatabaseInitializer.hpp"
#include "org/projectforge/start/PluginLoader.hpp"
#include "org/projectforge/jcr/ContentRepositoryManager.hpp"
#include "org/projectforge/common/Logging.hpp"
#include "org/projectforge/common/ConfigHelper.hpp"
#include <drogon/drogon.h>
#include <spdlog/spdlog.h>

namespace org::projectforge::start {

ProjectForgeServer::ProjectForgeServer(const ProjectForgeConfig& config) : config_(config) {}

int ProjectForgeServer::run(int argc, char* argv[]) {
    Logging::init(config_.logLevel);
    auto logger = spdlog::get("projectforge");
    logger->info("Starting ProjectForge C++ Server v8.2.0");

    // Initialize database
    DatabaseInitializer::instance().init(config_.databasePath);
    DatabaseInitializer::instance().seedDefaultData();

    // Initialize content repository
    org::projectforge::jcr::ContentRepositoryManager::instance().init(
        org::projectforge::jcr::JcrBackendType::FILESYSTEM, config_.jcrPath);

    // Initialize plugins
    PluginLoader::instance().initAllPlugins();

    // Configure Drogon web server
    drogon::app().addListener(config_.bindAddress, config_.port);
    drogon::app().setThreadNum(config_.maxThreads);
    drogon::app().setDocumentRoot(config_.webappDir);

    if (config_.enableSsl) {
        drogon::app().setSSLFiles(config_.sslCertFile, config_.sslKeyFile);
    }

    // Set session timeout
    drogon::app().setSessionTimeout(config_.sessionTimeoutMinutes * 60);

    // CORS for development
    drogon::app().registerPostHandlingAdvice([](const drogon::HttpRequestPtr& req,
        const drogon::HttpResponsePtr& resp) {
        resp->addHeader("Access-Control-Allow-Origin", "*");
        resp->addHeader("Access-Control-Allow-Methods", "GET,POST,PUT,DELETE,OPTIONS");
        resp->addHeader("Access-Control-Allow-Headers", "Content-Type,Authorization");
    });

    running_ = true;
    logger->info("Server listening on {}:{}", config_.bindAddress, config_.port);
    logger->info("Webapp directory: {}", config_.webappDir);

    drogon::app().run();
    return 0;
}

void ProjectForgeServer::shutdown() {
    PluginLoader::instance().shutdownAll();
    running_ = false;
}
}