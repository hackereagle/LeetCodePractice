cmake_minimum_required(VERSION 3.11)
set(PROJECT_NAME LeetcodeTestFrameworkUnitTest)
set(CMAKE_VERBOSE_MAKEFILE ON)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)
add_compile_definitions(_UNIT_TEST_)
# checked preprocessor definition
get_directory_property(MY_DEF_PREPROC COMPILE_DEFINITIONS)
message(STATUS "LeetTestFramework.UnitTest preprocessor definition:\n" ${MY_DEF_PREPROC})

enable_testing()
find_package(GTest CONFIG REQUIRED)
include_directories(${CMAKE_SOURCE_DIR}/src/CommomModules)
include_directories(${CMAKE_SOURCE_DIR}/src/LeetcodeTestFramework)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} stdc++ GTest::gtest)