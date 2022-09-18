add_subdirectory(buildings)
add_subdirectory(vehicles)
add_subdirectory(utils)
add_subdirectory(exercises)

add_executable(tracer main.cpp)
target_link_libraries(tracer exercises buildings vehicles utils)
INSTALL(TARGETS tracer DESTINATION bin)
