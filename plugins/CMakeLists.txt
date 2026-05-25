# plugins — unified library for all 11 plugins
file(GLOB_RECURSE PLUGIN_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*/src/*.cpp")
file(GLOB_RECURSE PLUGIN_HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/*/include/*.hpp")
add_library(projectforge_plugins STATIC ${PLUGIN_SOURCES})
target_include_directories(projectforge_plugins PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/banking/include
    ${CMAKE_CURRENT_SOURCE_DIR}/complete/include
    ${CMAKE_CURRENT_SOURCE_DIR}/datatransfer/include
    ${CMAKE_CURRENT_SOURCE_DIR}/ihk/include
    ${CMAKE_CURRENT_SOURCE_DIR}/licensemanagement/include
    ${CMAKE_CURRENT_SOURCE_DIR}/liquidityplanning/include
    ${CMAKE_CURRENT_SOURCE_DIR}/marketing/include
    ${CMAKE_CURRENT_SOURCE_DIR}/memo/include
    ${CMAKE_CURRENT_SOURCE_DIR}/merlin/include
    ${CMAKE_CURRENT_SOURCE_DIR}/skillmatrix/include
    ${CMAKE_CURRENT_SOURCE_DIR}/todo/include
)
target_link_libraries(projectforge_plugins PUBLIC projectforge_common)
