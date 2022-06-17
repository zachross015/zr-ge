cmake_minimum_required(VERSION 3.13)

# Configuration and constants
set(GE_PROJECT_NAME game-engine)
project(${GE_PROJECT_NAME} VERSION 1.0)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")

set(GE_ROOT_DIR "${PROJECT_SOURCE_DIR}")
set(GE_RESOURCES_DIR "${PROJECT_SOURCE_DIR}/test/resources")
set(GE_SOURCE_DIR "${PROJECT_SOURCE_DIR}/src")
set(GE_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/include")
set(GE_EXTLIB_DIR "${PROJECT_SOURCE_DIR}/extlib")


# Find SDL Packages
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_mixer REQUIRED)
find_package(SDL2_ttf REQUIRED)

# Construct library
add_library(${GE_PROJECT_NAME})

# Include SDL headers
target_include_directories(${GE_PROJECT_NAME} INTERFACE ${SDL2_INCLUDE_DIR})
target_include_directories(${GE_PROJECT_NAME} INTERFACE ${SDL2_IMAGE_INCLUDE_DIR})
target_include_directories(${GE_PROJECT_NAME} INTERFACE ${SDL2_MIXER_INCLUDE_DIR})
target_include_directories(${GE_PROJECT_NAME} INTERFACE ${SDL2_TTF_INCLUDE_DIR})

# Link SDL
target_link_libraries(${GE_PROJECT_NAME} INTERFACE ${SDL2_LIBRARY})
target_link_libraries(${GE_PROJECT_NAME} INTERFACE ${SDL2_IMAGE_LIBRARY})
target_link_libraries(${GE_PROJECT_NAME} INTERFACE ${SDL2_MIXER_LIBRARY})
target_link_libraries(${GE_PROJECT_NAME} INTERFACE ${SDL2_TTF_LIBRARY})

# Libaries
add_subdirectory(${GE_EXTLIB_DIR})

# Include
target_include_directories(${GE_PROJECT_NAME} PUBLIC ${GE_INCLUDE_DIR})
add_subdirectory(${GE_SOURCE_DIR})

# Options
option(GE_EXAMPLES "Toggle whether the compiler should add the examples to the compilation process" OFF)
if (GE_EXAMPLES)
    message("Compiling examples directory.")
    add_subdirectory(examples)
endif ()

