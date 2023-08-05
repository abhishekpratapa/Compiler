project(acc_test)
enable_testing()

include_directories(${gtest_build_include_dirs})
include_directories(${GTEST_INCLUDE_DIR})

add_subdirectory(unit)
add_subdirectory(benchmark)
