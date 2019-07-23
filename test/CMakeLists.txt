cmake_minimum_required(VERSION 3.12.4)
project(Compiler_tests)
enable_testing()

set(EXECUTABLE_OUTPUT_PATH ${parent_directory}/target/tests/)

find_package(Boost COMPONENTS system filesystem unit_test_framework REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

include_directories(${src_includes})

function(create_testing_executable test_name file_name)
  add_executable(${test_name}
    ${file_name}
  )

  target_link_libraries(${test_name}
    ${Boost_LIBRARIES}
    ${Boost_FILESYSTEM_LIBRARY}
    ${Boost_SYSTEM_LIBRARY}
    ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
    acc_testing
  )

  add_test(NAME ${test_name} COMMAND ${test_name})
  add_dependencies(${test_name} acc_testing)
endfunction()

add_custom_target(copy_example_files ALL
    COMMAND cmake -E copy_directory ${parent_directory}/examples ${EXECUTABLE_OUTPUT_PATH}/examples
    DEPENDS test_lexical_analyzer)

create_testing_executable(test_argument_parser test_argument_parser.cc)
create_testing_executable(test_lexical_analyzer test_lexical_analyzer.cc)