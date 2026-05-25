cmake_minimum_required(VERSION 3.20)
project(projectforge VERSION 8.2.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_POLICY_VERSION_MINIMUM 3.5)

add_compile_options(-Wno-unused-parameter)

find_package(Threads REQUIRED)
include(FetchContent)

FetchContent_Declare(nlohmann_json GIT_REPOSITORY https://github.com/nlohmann/json.git GIT_TAG v3.11.3)
FetchContent_MakeAvailable(nlohmann_json)

FetchContent_Declare(spdlog GIT_REPOSITORY https://github.com/gabime/spdlog.git GIT_TAG v1.14.1)
FetchContent_MakeAvailable(spdlog)

FetchContent_Declare(httplib GIT_REPOSITORY https://github.com/yhirose/cpp-httplib.git GIT_TAG v0.18.3)
FetchContent_MakeAvailable(httplib)

FetchContent_Declare(sqlite_orm GIT_REPOSITORY https://github.com/fnc12/sqlite_orm.git GIT_TAG v1.9)
FetchContent_MakeAvailable(sqlite_orm)

FetchContent_Declare(jwt-cpp GIT_REPOSITORY https://github.com/Thalhammer/jwt-cpp.git GIT_TAG v0.7.0)
FetchContent_MakeAvailable(jwt-cpp)

add_subdirectory(projectforge-common)
add_subdirectory(projectforge-model)
add_subdirectory(projectforge-jcr)
add_subdirectory(projectforge-business)
add_subdirectory(projectforge-rest)
add_subdirectory(projectforge-carddav)
add_subdirectory(projectforge-idp)
add_subdirectory(projectforge-wicket)
add_subdirectory(projectforge-commons-test)
add_subdirectory(projectforge-application)
