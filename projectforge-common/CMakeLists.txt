# projectforge-common: Foundation utilities, XML, date/time, i18n
add_library(projectforge_common STATIC
    src/ProjectForgeVersion.cpp
    src/StringHelper.cpp
    src/DateHelper.cpp
    src/NumberHelper.cpp
    src/XmlHelper.cpp
    src/I18nHelper.cpp
    src/FileHelper.cpp
    src/CryptoHelper.cpp
    src/ConfigHelper.cpp
    src/MimeTypeHelper.cpp
    src/IdGenerator.cpp
    src/LambdaKeyMap.cpp
    src/PropertyBag.cpp
    src/ThreadLocalUserContext.cpp
    src/ShortDao.cpp
    src/ExtendedBaseDO.cpp
    src/UserGroupCache.cpp
    src/CoreEntityListener.cpp
    src/AbstractCache.cpp
    src/Logging.cpp
    src/SpringWrappedBeanFactory.cpp
    src/BeanHelper.cpp
    src/ApplicationContext.cpp
    src/IdUtils.cpp
    src/FilenameUtils.cpp
    src/ReflectionUtils.cpp
    src/ObjectUtils.cpp
    src/RandomUtils.cpp
)
target_include_directories(projectforge_common PUBLIC include)
target_link_libraries(projectforge_common PUBLIC
    spdlog::spdlog
    nlohmann_json::nlohmann_json
    Threads::Threads
)

# Tests
enable_testing()
add_executable(projectforge_common_tests
    tests/StringHelperTest.cpp
    tests/DateHelperTest.cpp
    tests/NumberHelperTest.cpp
    tests/XmlHelperTest.cpp
    tests/I18nHelperTest.cpp
)
target_link_libraries(projectforge_common_tests PRIVATE projectforge_common)
add_test(NAME CommonTests COMMAND projectforge_common_tests)
