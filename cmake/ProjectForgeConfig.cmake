// ProjectForge C++ port — GPL v3

# ProjectForge C++ CMake Configuration Helper
# Provides functions and variables for building the ProjectForge application

set(PROJECTFORGE_VERSION_MAJOR 8)
set(PROJECTFORGE_VERSION_MINOR 2)
set(PROJECTFORGE_VERSION_PATCH 0)
set(PROJECTFORGE_VERSION "${PROJECTFORGE_VERSION_MAJOR}.${PROJECTFORGE_VERSION_MINOR}.${PROJECTFORGE_VERSION_PATCH}")
set(PROJECTFORGE_VERSION_STRING "${PROJECTFORGE_VERSION}-SNAPSHOT")

# C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Compiler flags
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(-Wall -Wextra -Wpedantic -Wno-unused-parameter -Wno-unused-variable)
    if(CMAKE_BUILD_TYPE STREQUAL "Debug")
        add_compile_options(-g -O0 -DDEBUG)
    else()
        add_compile_options(-O3 -DNDEBUG)
    endif()
elseif(MSVC)
    add_compile_options(/W4 /WX- /Zc:__cplusplus)
endif()

# Function to add a ProjectForge module
function(add_projectforge_module MODULE_NAME)
    cmake_parse_arguments(PFM "" "TYPE" "SOURCES;HEADERS;DEPS" ${ARGN})
    
    set(MODULE_SOURCES "")
    set(MODULE_HEADERS "")
    
    if(PFM_SOURCES)
        list(APPEND MODULE_SOURCES ${PFM_SOURCES})
    endif()
    if(PFM_HEADERS)
        list(APPEND MODULE_HEADERS ${PFM_HEADERS})
    endif()
    
    if(PFM_TYPE STREQUAL "EXECUTABLE")
        add_executable(${MODULE_NAME} ${MODULE_SOURCES})
    else()
        add_library(${MODULE_NAME} STATIC ${MODULE_SOURCES})
    endif()
    
    target_include_directories(${MODULE_NAME} PUBLIC include)
    
    if(PFM_DEPS)
        target_link_libraries(${MODULE_NAME} PUBLIC ${PFM_DEPS})
    endif()
    
    # Add test target
    if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/tests")
        enable_testing()
        file(GLOB TEST_SOURCES tests/*.cpp)
        if(TEST_SOURCES)
            add_executable(${MODULE_NAME}_tests ${TEST_SOURCES})
            target_link_libraries(${MODULE_NAME}_tests PRIVATE ${MODULE_NAME})
            add_test(NAME ${MODULE_NAME}_tests COMMAND ${MODULE_NAME}_tests)
        endif()
    endif()
    
    # Installation
    install(TARGETS ${MODULE_NAME} 
        ARCHIVE DESTINATION lib/projectforge
        LIBRARY DESTINATION lib/projectforge
        RUNTIME DESTINATION bin
    )
endfunction()

# Function to discover all sources in a module
function(discover_module_sources MODULE_PATH OUT_SOURCES OUT_HEADERS)
    file(GLOB_RECURSE MODULE_HDRS "${MODULE_PATH}/include/*.hpp")
    file(GLOB_RECURSE MODULE_SRCS "${MODULE_PATH}/src/*.cpp")
    set(${OUT_SOURCES} ${MODULE_SRCS} PARENT_SCOPE)
    set(${OUT_HEADERS} ${MODULE_HDRS} PARENT_SCOPE)
endfunction()

# Platform-specific settings
if(UNIX AND NOT APPLE)
    add_compile_definitions(PLATFORM_LINUX)
    find_package(Threads REQUIRED)
elseif(APPLE)
    add_compile_definitions(PLATFORM_MACOS)
    find_package(Threads REQUIRED)
elseif(WIN32)
    add_compile_definitions(PLATFORM_WINDOWS)
endif()

# Output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

message(STATUS "ProjectForge C++ ${PROJECTFORGE_VERSION_STRING}")
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "C++ Standard: ${CMAKE_CXX_STANDARD}")
message(STATUS "Compiler: ${CMAKE_CXX_COMPILER_ID} ${CMAKE_CXX_COMPILER_VERSION}")
