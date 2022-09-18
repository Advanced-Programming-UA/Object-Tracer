add_subdirectory(exams)
add_subdirectory(vehicles)
add_subdirectory(utils)
add_subdirectory(exercises)

add_executable(tracer main.cpp)
target_link_libraries(tracer exercises buildings_2021 buildings_2022_1 buildings_2022_2 vehicles utils)
INSTALL(TARGETS tracer DESTINATION bin)
