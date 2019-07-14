#include <iostream>

#include <utils/token_utilities.h>

namespace acc {
namespace utils {

void print_tokens(std::vector<acc::lexical_analyzer::Token> &token_vector) {
  const char *TokenTypeArray[] = {"Add",
                                  "And",
                                  "Assign",
                                  "Comma",
                                  "Division",
                                  "Else",
                                  "EOI",
                                  "Equal",
                                  "GreaterThanOrEqual",
                                  "GreaterThan",
                                  "Identifier",
                                  "If",
                                  "Integer",
                                  "LeftBrace",
                                  "LessThan",
                                  "LessThanOrEqual",
                                  "LeftParenthesis",
                                  "Lss",
                                  "Modulo",
                                  "Muliplication",
                                  "Negate",
                                  "NotEqual",
                                  "Not",
                                  "Or",
                                  "Print",
                                  "Putc",
                                  "RightBrace",
                                  "RightParenthesis",
                                  "Semicolon",
                                  "String",
                                  "Subtraction",
                                  "While"};

  for (size_t x = 0; x < token_vector.size(); x++) {
    std::cout << "Token Type: " << TokenTypeArray[token_vector[x].type]
              << ", Token Value: " << token_vector[x].value << std::endl;
  }
}

} // namespace utils
} // namespace acc