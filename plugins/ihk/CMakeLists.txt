add_library(plugin_ihk STATIC src/IhkPlugin.cpp src/IhkDao.cpp)
target_include_directories(plugin_ihk PUBLIC include)
target_link_libraries(plugin_ihk PUBLIC projectforge_business)
