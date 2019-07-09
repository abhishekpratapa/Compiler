cmake_minimum_required(VERSION 3.10.2)
project(Compiler)

set(parent_directory ${PROJECT_SOURCE_DIR})
set(src_includes ${PROJECT_SOURCE_DIR}/src)

add_subdirectory(src)
add_subdirectory(test)
