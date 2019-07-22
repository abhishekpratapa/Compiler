cmake_minimum_required(VERSION 3.12.4)
project(Compiler)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "-g -O0 -Wall -fprofile-arcs -ftest-coverage")
set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE ON)

set(EXECUTABLE_OUTPUT_PATH ${parent_directory}/target/)
set(LIBRARY_OUTPUT_PATH ${parent_directory}/target/)

include_directories(${src_includes})

find_package(Boost COMPONENTS program_options REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

add_custom_target(gcov
  COMMAND mkdir -p coverage
  COMMAND ${CMAKE_MAKE_PROGRAM} test
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)


set(src_files
  lexical_analyzer.cc
  utils/argument_parser.cc
  utils/file_utilities.cc
  utils/token_utilities.cc
)

add_executable(acc
  main.cc
  ${src_files}
)

target_link_libraries(acc
  ${Boost_LIBRARIES}
)

add_library(acc_testing
  ${src_files}
)

target_link_libraries(acc_testing
  ${Boost_LIBRARIES}
)

# TODO: add code coverage