cmake_minimum_required(VERSION 3.4)
set(PROJ_NAME Sum)

project(${PROJ_NAME})

aux_source_directory(. DIR_SRCS)

add_executable(${PROJ_NAME} ${DIR_SRCS})
target_link_libraries(${PROJ_NAME} ${CMAKE_DL_LIBS} ${SPINNAKER_LIBRARIES})

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 17)