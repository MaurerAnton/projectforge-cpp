// ProjectForge C++ port — GPL v3 — www.projectforge.org
#include "org/projectforge/start/ProjectForgeServer.hpp"
#include "org/projectforge/start/ProjectForgeConfig.hpp"
#include <iostream>
#include <string>

using namespace org::projectforge::start;

int main(int argc, char* argv[]) {
    ProjectForgeConfig config;

    // Parse command line arguments
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "--port" && i + 1 < argc) config.port = std::stoi(argv[++i]);
        else if (arg == "--bind" && i + 1 < argc) config.bindAddress = argv[++i];
        else if (arg == "--db" && i + 1 < argc) config.databasePath = argv[++i];
        else if (arg == "--jcr" && i + 1 < argc) config.jcrPath = argv[++i];
        else if (arg == "--loglevel" && i + 1 < argc) config.logLevel = argv[++i];
        else if (arg == "--webapp" && i + 1 < argc) config.webappDir = argv[++i];
        else if (arg == "--ssl-cert" && i + 1 < argc) { config.sslCertFile = argv[++i]; config.enableSsl = true; }
        else if (arg == "--ssl-key" && i + 1 < argc) config.sslKeyFile = argv[++i];
        else if (arg == "--help" || arg == "-h") {
            std::cout << "ProjectForge C++ Server v8.2.0\n\n"
                      << "Usage: projectforge [options]\n"
                      << "  --port PORT          Listen port (default: 8080)\n"
                      << "  --bind ADDRESS       Bind address (default: 0.0.0.0)\n"
                      << "  --db PATH            SQLite database path\n"
                      << "  --jcr PATH           Content repository path\n"
                      << "  --loglevel LEVEL     Log level (debug/info/warn/error)\n"
                      << "  --webapp DIR         Web application directory\n"
                      << "  --ssl-cert FILE      SSL certificate file\n"
                      << "  --ssl-key FILE       SSL key file\n"
                      << "  --help, -h           Show this help\n";
            return 0;
        }
    }

    ProjectForgeServer server(config);
    return server.run(argc, argv);
}
