cmake_minimum_required(VERSION 3.0)
project(engine)

# Add executable
add_executable(my_program main.cpp ECS/entitymanager.cpp)

# Include directories
target_include_directories(my_program PRIVATE ECS)
