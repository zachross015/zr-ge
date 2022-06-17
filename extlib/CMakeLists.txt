add_subdirectory(entt)
add_subdirectory(armadillo)
add_subdirectory(centurion)
add_subdirectory(random)

# Include Header-Only Libraries
target_include_directories(${GE_PROJECT_NAME} INTERFACE centurion/src)

# Link other libraries
target_link_libraries(${GE_PROJECT_NAME} INTERFACE EnTT::EnTT armadillo effolkronium_random)
