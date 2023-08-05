project(acc)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

add_subdirectory(lexical)

add_library(acc SHARED
  $<TARGET_OBJECTS:lexical>
)

target_link_libraries(acc
  lexical
)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fprofile-arcs -ftest-coverage")
set(CMAKE_EXE_LINKER_FLAGS
    "${CMAKE_EXE_LINKER_FLAGS} -fprofile-arcs -ftest-coverage")
