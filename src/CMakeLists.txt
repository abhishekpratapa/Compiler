cmake_minimum_required(VERSION 3.12.4)
project(Compiler)

set(EXECUTABLE_OUTPUT_PATH ${parent_directory}/target/)
set(LIBRARY_OUTPUT_PATH ${parent_directory}/target/)

include_directories(${src_includes})

find_package(Boost COMPONENTS program_options REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

add_executable(acc
  main.cc
  utils/argument_parser.cc
)

target_link_libraries(acc
  ${Boost_LIBRARIES}
)

add_library(acc_testing
  utils/argument_parser.cc
)

target_link_libraries(acc_testing
  ${Boost_LIBRARIES}
)
