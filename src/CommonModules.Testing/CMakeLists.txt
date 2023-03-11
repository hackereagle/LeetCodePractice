cmake_minimum_required(VERSION 3.14.0)
set(PROJECT_NAME CommonModulesTesting)
project(${PROJECT_NAME})

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

message(STATUS "In CommonModules: ${PROJECT_SOURCE_DIR}")
include_directories(${PROJECT_SOURCE_DIR}/../CommomModules)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} ${CMAKE_DL_LIBS} Threads::Threads)

set(CMAKE_CXX_FLAGS "-std=c++17${CMAKE_CXX_FLAGS}")