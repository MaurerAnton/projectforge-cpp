cmake_minimum_required(VERSION 3.20)
project(projectforge VERSION 8.2.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Global compilation flags
add_compile_options(-Wall -Wextra -Wpedantic -Wno-unused-parameter)

# Find dependencies
find_package(Threads REQUIRED)

# --- Third-party libraries ---
# We use FetchContent for modern dependency management
include(FetchContent)

# nlohmann/json for JSON handling
FetchContent_Declare(json
    GIT_REPOSITORY https://github.com/nlohmann/json.git
    GIT_TAG v3.11.3
)
FetchContent_MakeAvailable(json)

# spdlog for logging
FetchContent_Declare(spdlog
    GIT_REPOSITORY https://github.com/gabime/spdlog.git
    GIT_TAG v1.14.1
)
FetchContent_MakeAvailable(spdlog)

# cpp-httplib for HTTP server (header-only)
FetchContent_Declare(httplib
    GIT_REPOSITORY https://github.com/yhirose/cpp-httplib.git
    GIT_TAG v0.18.3
)
FetchContent_MakeAvailable(httplib)

# SQLite as embedded database (via sqlite_orm or direct)
FetchContent_Declare(sqlite_orm
    GIT_REPOSITORY https://github.com/fnc12/sqlite_orm.git
    GIT_TAG v1.9
)
FetchContent_MakeAvailable(sqlite_orm)

# jwt-cpp for JWT tokens
FetchContent_Declare(jwt-cpp
    GIT_REPOSITORY https://github.com/Thalhammer/jwt-cpp.git
    GIT_TAG v0.7.0
)
FetchContent_MakeAvailable(jwt-cpp)

# Drogon for full-featured HTTP framework
FetchContent_Declare(drogon
    GIT_REPOSITORY https://github.com/drogonframework/drogon.git
    GIT_TAG v1.9.8
)
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(BUILD_DOC OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(drogon)

# --- Core Modules ---
add_subdirectory(projectforge-common)
add_subdirectory(projectforge-model)
add_subdirectory(projectforge-jcr)
add_subdirectory(projectforge-business)
add_subdirectory(projectforge-rest)
add_subdirectory(projectforge-carddav)
add_subdirectory(projectforge-idp)
add_subdirectory(projectforge-wicket)
add_subdirectory(projectforge-application)
add_subdirectory(projectforge-commons-test)

# --- Plugins ---
add_subdirectory(plugins/banking)
add_subdirectory(plugins/datatransfer)
add_subdirectory(plugins/ihk)
add_subdirectory(plugins/licensemanagement)
add_subdirectory(plugins/liquidityplanning)
add_subdirectory(plugins/marketing)
add_subdirectory(plugins/memo)
add_subdirectory(plugins/merlin)
add_subdirectory(plugins/skillmatrix)
add_subdirectory(plugins/todo)

# --- Installation ---
install(DIRECTORY projectforge-webapp/ DESTINATION share/projectforge/webapp)
install(DIRECTORY config/ DESTINATION etc/projectforge)
