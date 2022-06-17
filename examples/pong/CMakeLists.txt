cmake_minimum_required(VERSION 3.13)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/examples/pong")

# Project Name
project(pong VERSION 1.0)

# Executable
add_executable(${PROJECT_NAME} main.cpp) 
target_include_directories(${PROJECT_NAME} PUBLIC "${PROJECT_SOURCE_DIR}/include")
target_link_libraries(${PROJECT_NAME} ${GE_PROJECT_NAME})

# Link source files
add_subdirectory(src)

