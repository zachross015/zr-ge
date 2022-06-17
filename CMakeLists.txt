cmake_minimum_required(VERSION 3.13)

# Configuration
set(GE_PROJECT_NAME game-engine)
project(${GE_PROJECT_NAME} VERSION 1.0)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")

set(GE_ROOT_DIR "${PROJECT_SOURCE_DIR}")
set(GE_RESOURCES_DIR "${PROJECT_SOURCE_DIR}/test/resources")
set(GE_SOURCE_DIR "${PROJECT_SOURCE_DIR}/src")
set(GE_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/include")
set(GE_EXTLIB_DIR "${PROJECT_SOURCE_DIR}/extlib")


# Libaries
add_subdirectory(${GE_EXTLIB_DIR})

# Executable
add_library(${GE_PROJECT_NAME})
target_include_directories(${GE_PROJECT_NAME} PUBLIC ${GE_INCLUDE_DIR})
target_link_libraries(${GE_PROJECT_NAME} EnTT::EnTT armadillo centurion effolkronium_random)


add_subdirectory(${GE_SOURCE_DIR})

# Options
option(GE_EXAMPLES "Toggle whether the compiler should add the examples to the compilation process" OFF)
if (GE_EXAMPLES)
    message("Compiling examples directory.")
    add_subdirectory(examples)
endif ()

