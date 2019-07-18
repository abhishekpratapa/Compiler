#ifndef LEXICAL_ANALYZER
#define LEXICAL_ANALYZER

#include <cctype>
#include <sstream>
#include <string>
#include <vector>

#include <boost/variant.hpp>

#include <utils/exit_codes.h>
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

Token get_token(utils::FileReader &fr);
static Token char_lit(utils::FileReader &fr);
static Token division_or_comment(utils::FileReader &fr);
static Token follow(char expect, TokenType ifyes, TokenType ifno,
                    utils::FileReader &fr);
static Token string_literal(char start, utils::FileReader &fr);
static Token identifier_or_int(char start, utils::FileReader &fr);
static TokenType get_ident_type(const char *ident);

std::vector<Token> tokenize_file(std::vector<std::string> &files);
static int kwd_cmp(const void *p1, const void *p2);

static void error(ERROR_CODE error_code, utils::FileReader &fr, const char *fmt,
                  ...);

} // namespace lexical_analyzer
} // namespace acc

#endif