add_subdirectory(frontend)

add_executable(lamb main.cpp)
target_link_libraries(lamb PRIVATE ${PROJECT_WARNINGS})
