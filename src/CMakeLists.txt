cmake_minimum_required(VERSION 3.12.4)
project(Compiler)

set(EXECUTABLE_OUTPUT_PATH ${parent_directory}/target/)

find_package(Boost COMPONENTS program_options REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

add_executable(acc
  main.cc
)

target_link_libraries(acc
  ${Boost_LIBRARIES}
)
