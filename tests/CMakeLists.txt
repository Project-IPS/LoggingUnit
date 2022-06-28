cmake_minimum_required(VERSION 3.23.0)

#include Catch2
Include(FetchContent)
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.0.1 # or a later release
)
FetchContent_MakeAvailable(Catch2)

#Build the test target
add_executable(tests tests.cpp)

#include the libraries we're supposed to test.
target_link_libraries(tests PUBLIC Logger)

target_include_directories(tests PUBLIC ../Logger)

#Because we would be including Catch2 testing
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)
list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
include(CTest)
include(Catch)
catch_discover_tests(tests)
enable_testing()

#Override the cache variable that's used by Logger interface library.
set(LOG_SETTINGS "warnings" CACHE STRING "LOG_SETTINGS chosen by the user at CMake configure time" FORCE)

