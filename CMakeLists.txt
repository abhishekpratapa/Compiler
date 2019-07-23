cmake_minimum_required(VERSION 3.10.2)
project(Compiler)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/deps/cmake)

set(parent_directory ${PROJECT_SOURCE_DIR})
set(src_includes ${PROJECT_SOURCE_DIR}/src)

include(CodeCoverage)
APPEND_COVERAGE_COMPILER_FLAGS()

set(COVERAGE_LCOV_EXCLUDES '*usr/include/*' '*/usr/include/c++/*' '/usr/local/include/*' ${CMAKE_BINARY_DIR}'*')

setup_target_for_coverage_lcov(
  NAME test_argument_parser_coverage
  EXECUTABLE test_argument_parser
  DEPENDENCIES test_argument_parser
)

add_subdirectory(src)
add_subdirectory(test)
