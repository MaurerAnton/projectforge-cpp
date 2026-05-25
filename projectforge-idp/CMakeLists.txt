# projectforge-idp
file(GLOB_RECURSE projectforge_idp_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE projectforge_idp_HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp")

add_library(projectforge_idp STATIC ${projectforge_idp_SOURCES})
target_include_directories(projectforge_idp PUBLIC include)
target_link_libraries(projectforge_idp PUBLIC projectforge_rest projectforge_common jwt-cpp::jwt-cpp)
