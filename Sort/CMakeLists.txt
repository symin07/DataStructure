cmake_minimum_required(VERSION 3.0)
project(Sort)
set(CMAKE_CXX_COMPILER g++)
# set(CMAKE_BUILD_TYPE Release)
message("build type: " ${CMAKE_BUILD_TYPE})
set(SOURCES src/sortVisual.c)
add_executable(${PROJECT_NAME} ${SOURCES})