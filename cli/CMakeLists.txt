add_executable(acc_compiler acc/main.cpp)
target_link_libraries(acc_compiler PRIVATE acc)

# Rename the output executable to 'acc'
set_target_properties(acc_compiler PROPERTIES OUTPUT_NAME acc)
