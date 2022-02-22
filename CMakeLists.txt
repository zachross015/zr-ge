cmake_minimum_required(VERSION 3.13)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")

# Project Name
project(GameEngine VERSION 1.0)

# Libaries
add_subdirectory(lib)
add_subdirectory(src)

# Input all the cpp files
file(GLOB SOURCES CONFIGURE_DEPENDS "src/*.cpp" "src/sdl_wrapper/*.cpp")

# Input all the includes
include_directories(include)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
include_directories(${SDL2_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIR})

# Executable
add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} EnTT::EnTT armadillo ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY})
