cmake_minimum_required(VERSION 3.12.4)
project(Compiler_tests)
enable_testing()

set(EXECUTABLE_OUTPUT_PATH ${parent_directory}/target/tests/)

find_package(Boost COMPONENTS system filesystem unit_test_framework REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

include_directories(${src_includes})

add_executable(test_executable
  test_argument_parser.cc
)

target_link_libraries(test_executable
  ${Boost_LIBRARIES}
  ${Boost_FILESYSTEM_LIBRARY}
  ${Boost_SYSTEM_LIBRARY}
  ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
  acc_testing
)

add_test(NAME test1 COMMAND test_executable)

add_dependencies(test_executable acc_testing)