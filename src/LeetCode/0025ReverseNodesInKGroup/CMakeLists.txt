cmake_minimum_required(VERSION 3.4.0)
set(PROJECT_NAME ReverseListNodeInKGroup)
project(${PROJECT_NAME})

include_directories(${PROJECT_SOURCE_DIR}/../../CommomModules)

aux_source_directory(. DIR_SRCS)
add_executable(${PROJECT_NAME} ${DIR_SRCS})
target_link_libraries(${PROJECT_NAME} ${CMAKE_DL_LIBS})

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "-std=c++17${CMAKE_CXX_FLAGS}")