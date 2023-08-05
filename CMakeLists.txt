cmake_minimum_required(VERSION 3.10.2)
project(acc)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_MODULE_PATH
  ${PROJECT_SOURCE_DIR}/deps/cmake
  ${PROJECT_SOURCE_DIR}/cmake
)

include(CodeCoverage)
include(Utilities)

enable_code_coverage()

include_directories(${CMAKE_SOURCE_DIR}/include)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/target/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/target/libs)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/target/libs)

add_subdirectory(extern)
add_subdirectory(src)
add_subdirectory(test)
