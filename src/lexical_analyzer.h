#ifndef LEXICAL_ANALYZER
#define LEXICAL_ANALYZER

#include <string>
#include <vector>

#include <utils/file_utilities.h>

namespace acc {
namespace lexical_analyzer {

// TODO: update token types
enum TokenType {
  KEYWORD,
  IDENTIFIERS,
  CONSTANTS,
  STRINGS,
  SPECIAL_SYMBOLS,
  OPERATORS
};

// TODO: update enumerated types
struct Token {
  std::string value;
  TokenType type;
};

std::vector<Token> tokenize_file(std::vector<std::string> &files);

} // namespace lexical_analyzer
} // namespace acc

#endif