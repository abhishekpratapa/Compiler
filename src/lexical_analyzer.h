#ifndef LEXICAL_ANALYZER
#define LEXICAL_ANALYZER

#include <cctype>
#include <sstream>
#include <string>
#include <vector>

#include <boost/variant.hpp>

#include <utils/file_utilities.h>

namespace acc {
namespace lexical_analyzer {

enum TokenType {
  Add,
  And,
  Assign,
  Comma,
  Division,
  Else,
  EOI,
  Equal,
  GreaterThanOrEqual,
  GreaterThan,
  Identifier,
  If,
  Integer,
  LeftBrace,
  LessThan,
  LessThanOrEqual,
  LeftParenthesis,
  Lss,
  Modulo,
  Muliplication,
  Negate,
  NotEqual,
  Not,
  Or,
  Print,
  Putc,
  RightBrace,
  RightParenthesis,
  Semicolon,
  String,
  Subtraction,
  While
};

struct Token {
  TokenType type;

  int error_line;
  int error_column;

  boost::variant<int, char, std::string> value;
};

Token get_token(acc::utils::FileReader &fr);
std::vector<Token> tokenize_file(std::vector<std::string> &files);

} // namespace lexical_analyzer
} // namespace acc

#endif