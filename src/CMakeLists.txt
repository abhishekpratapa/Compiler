set(CMAKE_POSITION_INDEPENDENT_CODE ON)

add_library(acc SHARED
    acc/lexical_analysis/lexer.cpp
    acc/lexical_analysis/concrete_lexer.cpp
    acc/lexical_analysis/token.cpp
    acc/syntactic_analysis/ast/ast_node.cpp
    acc/syntactic_analysis/ast/function_declaration.cpp
    acc/syntactic_analysis/ast/binary_expression.cpp
    acc/syntactic_analysis/ast/unary_expression.cpp
    acc/syntactic_analysis/ast/literal.cpp
    acc/syntactic_analysis/parser.cpp
    acc/syntactic_analysis/concrete_parser.cpp
    acc/semantic_analysis/semantic_analyzer.cpp
    acc/intermediate_code_gen/ir_generator.cpp
    acc/optimization/machine_independent_optimizer.cpp
    acc/optimization/machine_dependent_optimizer.cpp
    acc/code_generation/code_generator.cpp
    acc/error_handling/error_handler.cpp
    acc/symbol_table/symbol_table.cpp
)

target_include_directories(acc PUBLIC ${CMAKE_SOURCE_DIR}/include)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fprofile-arcs -ftest-coverage")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fprofile-arcs -ftest-coverage")
