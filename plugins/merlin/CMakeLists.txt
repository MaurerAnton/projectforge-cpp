add_library(plugin_merlin STATIC src/MerlinPlugin.cpp src/MerlinDao.cpp)
target_include_directories(plugin_merlin PUBLIC include)
target_link_libraries(plugin_merlin PUBLIC projectforge_business)
