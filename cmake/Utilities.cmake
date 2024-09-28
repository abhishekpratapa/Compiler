
function(enable_code_coverage)
  APPEND_COVERAGE_COMPILER_FLAGS()

  set(COVERAGE_LCOV_EXCLUDES
    '*usr/include/*'
    '*/usr/local/include/*'
    ${CMAKE_BINARY_DIR}'*'
  )
endfunction()

function(create_coverage_target target_name)
  setup_target_for_coverage_lcov(
    NAME ${target_name}_coverage
    EXECUTABLE ${target_name}
    DEPENDENCIES
      ${target_name}
  )
endfunction()

function(create_benchmarks_test test_name)
  add_executable(benchmarks_${test_name}
    ${test_name}.cpp
  )

  target_link_libraries(
    benchmarks_${test_name}
    acc
    benchmark::benchmark
  )

  add_test(NAME benchmarks_${test_name} COMMAND benchmarks_${test_name})

  create_coverage_target(benchmarks_${test_name})
endfunction()

function(create_unit_test test_name)
  add_executable(unit_${test_name}
    ${test_name}.cxx
  )

  target_link_libraries(
    unit_${test_name}
    acc
    gtest_main
  )

  add_test(NAME unit_${test_name} COMMAND unit_${test_name})

  create_coverage_target(unit_${test_name})
endfunction()