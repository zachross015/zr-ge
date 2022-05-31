cmake_minimum_required(VERSION 3.13)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")

# Project Name
project(GameEngine VERSION 1.0)

# Libaries
add_subdirectory(lib)
add_subdirectory(src)

# Input all the cpp files
file(GLOB SOURCES CONFIGURE_DEPENDS "src/*.cpp")

# Input all the includes
include_directories(include)

# Centurion
include_directories(${SDL2_INCLUDE_DIR})
include_directories(lib/centurion/src)

# Executable
add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} EnTT::EnTT armadillo)
