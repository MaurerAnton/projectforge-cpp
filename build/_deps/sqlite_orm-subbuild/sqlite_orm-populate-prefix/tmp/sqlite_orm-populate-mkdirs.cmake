# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file LICENSE.rst or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION ${CMAKE_VERSION}) # this file comes with cmake

# If CMAKE_DISABLE_SOURCE_CHANGES is set to true and the source directory is an
# existing directory in our source tree, calling file(MAKE_DIRECTORY) on it
# would cause a fatal error, even though it would be a no-op.
if(NOT EXISTS "/home/bym/projectforge-folder/projectforge-cpp/build/_deps/sqlite_orm-src")
  file(MAKE_DIRECTORY "/home/bym/projectforge-folder/projectforge-cpp/build/_deps/sqlite_orm-src")
endif()
file(MAKE_DIRECTORY
  "/home/bym/projectforge-folder/projectforge-cpp/build/_deps/sqlite_orm-build"
  "/home/bym/projectforge-folder/projectforge-cpp/build/_deps/sqlite_orm-subbuild/sqlite_orm-populate-prefix"
  "/home/bym/projectforge-folder/projectforge-cpp/build/_deps/sqlite_orm-subbuild/sqlite_orm-populate-prefix/tmp"
  "/home/bym/projectforge-folder/projectforge-cpp/build/_deps/sqlite_orm-subbuild/sqlite_orm-populate-prefix/src/sqlite_orm-populate-stamp"
  "/home/bym/projectforge-folder/projectforge-cpp/build/_deps/sqlite_orm-subbuild/sqlite_orm-populate-prefix/src"
  "/home/bym/projectforge-folder/projectforge-cpp/build/_deps/sqlite_orm-subbuild/sqlite_orm-populate-prefix/src/sqlite_orm-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/bym/projectforge-folder/projectforge-cpp/build/_deps/sqlite_orm-subbuild/sqlite_orm-populate-prefix/src/sqlite_orm-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/bym/projectforge-folder/projectforge-cpp/build/_deps/sqlite_orm-subbuild/sqlite_orm-populate-prefix/src/sqlite_orm-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
