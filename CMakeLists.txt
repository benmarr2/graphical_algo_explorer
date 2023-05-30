cmake_minimum_required(VERSION 3.12)
project(GraphicalAlgoExplorer)

set(CMAKE_C_STANDARD 99)

# Find the installed Raylib package
find_package(raylib 4.5) # adjust the version number as needed

add_executable(GraphicalAlgoExplorer main.c)

# Link your executable with the Raylib library
target_link_libraries(GraphicalAlgoExplorer raylib m)
