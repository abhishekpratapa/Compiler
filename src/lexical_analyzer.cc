#include <lexical_analyzer.h>
#include <limits.h>
#include <utils/file_utilities.h>

#include <iostream>

#include <cerrno>
#include <cstdarg>

using namespace acc::utils;

namespace acc {
namespace lexical_analyzer {

Token get_token(FileReader &fr) {
  char value = (char)fr.next();
  while (isspace(value))
    value = (char)fr.next();

  switch (value) {
  case '{':
    return (Token){LeftBrace, fr.get_line(), fr.get_column(),
                   boost::variant<int, char, std::string>(value)};
  case '}':
    return (Token){RightBrace, fr.get_line(), fr.get_column(),
                   boost::variant<int, char, std::string>(value)};
  case '(':
    return (Token){LeftParenthesis, fr.get_line(), fr.get_column(),
                   boost::variant<int, char, std::string>(value)};
  case ')':
    return (Token){RightParenthesis, fr.get_line(), fr.get_column(),
                   boost::variant<int, char, std::string>(value)};
  case '+':
    return (Token){Add, fr.get_line(), fr.get_column(),
                   boost::variant<int, char, std::string>(value)};
  case '-':
    return (Token){Subtraction, fr.get_line(), fr.get_column(),
                   boost::variant<int, char, std::string>(value)};
  case '*':
    return (Token){Muliplication, fr.get_line(), fr.get_column(),
                   boost::variant<int, char, std::string>(value)};
  case '%':
    return (Token){Modulo, fr.get_line(), fr.get_column(),
                   boost::variant<int, char, std::string>(value)};
  case ';':
    return (Token){Semicolon, fr.get_line(), fr.get_column(),
                   boost::variant<int, char, std::string>(value)};
  case ',':
    return (Token){Comma, fr.get_line(), fr.get_column(),
                   boost::variant<int, char, std::string>(value)};
  case '/':
    return division_or_comment(fr);
  case '\'':
    return char_lit(fr);
  case '<':
    return follow('=', LessThanOrEqual, LessThan, fr);
  case '>':
    return follow('=', GreaterThanOrEqual, GreaterThan, fr);
  case '=':
    return follow('=', Equal, Assign, fr);
  case '!':
    return follow('=', NotEqual, Not, fr);
  case '&':
    return follow('&', And, EOI, fr);
  case '|':
    return follow('|', Or, EOI, fr);
  case '"':
    return string_literal(value, fr);
  case EOF:
    return (Token){EOI, fr.get_line(), fr.get_column(),
                   boost::variant<int, char, std::string>(((int)value))};
  default:
    return identifier_or_int(value, fr);
  }
}

static Token char_lit(FileReader &fr) {
  char value = fr.get_current_char();
  char current_value = value;
  if (value == '\'')
    error(LEXICAL_ANALYZER_EMPTY_CHAR, fr, "empty character constant");
  if (value == '\\') {
    value = fr.get_current_char();
    if (value == 'n')
      current_value = 10;
    else if (value == '\\')
      current_value = '\\';
    else
      error(LEXICAL_ANALYZER_UNKNOWN_ESCAPE, fr, "unknown escape sequence \\%c",
            value);
  }

  if (fr.get_current_char() != '\'')
    error(LEXICAL_ANALYZER_MULTILINE_CHAR_CONSTANT, fr,
          "multi-character constant");

  return (Token){Integer, fr.get_line(), fr.get_column(),
                 boost::variant<int, char, std::string>(current_value)};
}

static Token division_or_comment(FileReader &fr) {
  char value = (char)fr.next();
  if (value != '*')
    return (Token){
        Division, fr.get_line(), fr.get_column(),
        boost::variant<int, char, std::string>(fr.get_current_char())};

  value = (char)fr.next();

  do {
    if (value == '*') {
      if (fr.next() == '/') {
        return get_token(fr);
      }
    } else if (value == EOF) {
      error(LEXICAL_ANALYZER_EOF, fr, "EOF in comment");
    } else {
      value = (char)fr.next();
    }
  } while (true);
}

static Token follow(char expect, TokenType ifyes, TokenType ifno,
                    FileReader &fr) {
  char value = fr.peek();
  if (value == expect) {
    fr.next();
    return (Token){ifyes, fr.get_line(), fr.get_column(),
                   boost::variant<int, char, std::string>(value)};
  }

  if (ifno == EOI)
    error(LEXICAL_ANALYZER_UNRECOGNIZED_CHARACTER, fr,
          "follow: unrecognized character '%c' (%d)\n", value, value);

  return (Token){ifno, fr.get_line(), fr.get_column(),
                 boost::variant<int, char, std::string>(value)};
}

static Token string_literal(char start, FileReader &fr) {
  std::stringstream ss;
  char value = fr.next();

  while (value != start) {
    if (value == '\n')
      error(LEXICAL_ANALYZER_END_LINE, fr, "EOL in string");
    if (value == EOF)
      error(LEXICAL_ANALYZER_EOF, fr, "EOF in string");

    ss << value;
    value = fr.next();
  }

  ss << '\0';

  return (Token){String, fr.get_line(), fr.get_column(),
                 boost::variant<int, char, std::string>(ss.str())};
}

static int kwd_cmp(const void *p1, const void *p2) {
  return strcmp(*(char **)p1, *(char **)p2);
}

// TODO: update to use C++ vs C style tokenization
static TokenType get_ident_type(const char *ident) {
  static struct TempTokenType {
    char *s;
    TokenType sym;
  } kwds[] =
      {
          {(char *)"else", Else},   {(char *)"if", If},
          {(char *)"print", Print}, {(char *)"putc", Putc},
          {(char *)"while", While},
      },
    *kwp;

  return (kwp = (TempTokenType *)bsearch(&ident, kwds,
                                         (sizeof(kwds) / sizeof(kwds[0])),
                                         sizeof(kwds[0]), kwd_cmp)) == NULL
             ? Identifier
             : kwp->sym;
}

// TODO: update to use C++ vs C style tokenization
static Token identifier_or_int(char start, FileReader &fr) {
  int n;
  bool is_number = true;
  char value;

  // TODO: hack
  std::stringstream ss;
  fr.unget();

  while (isalnum(fr.peek()) || fr.peek() == '_') {
    value = fr.next();
    ss << value;
    if (!isdigit(value))
      is_number = false;
  }

  if (ss.str().empty())
    error(LEXICAL_ANALYZER_UNRECOGNIZED_CHARACTER, fr,
          "gettok: unrecognized character (%d) '%c'\n", value, value);

  ss << '\0';
  std::string text = ss.str();

  if (isdigit(text[0])) {
    if (!is_number)
      error(LEXICAL_ANALYZER_INVALID_NUMBER, fr, "invalid number: %s\n",
            text.c_str());
    n = strtol(text.c_str(), NULL, 0);
    if (n == INT_MAX && errno == ERANGE)
      error(LEXICAL_ANALYZER_NUMBER_OUT_OF_RANGE, fr,
            "Number exceeds maximum value");
    return (Token){Integer, fr.get_line(), fr.get_column(),
                   boost::variant<int, char, std::string>(n)};
  }
  return (Token){get_ident_type(text.c_str()), fr.get_line(), fr.get_column(),
                 boost::variant<int, char, std::string>(text)};
}

std::vector<Token> tokenize_file(std::vector<std::string> &files) {
  std::vector<Token> token_vec;

  for (size_t index = 0; index < files.size(); index++) {
    FileReader file_reader(files.at(index));

    Token next_token;

    do {
      next_token = get_token(file_reader);
      token_vec.push_back(next_token);
    } while (next_token.type != EOI);
  }

  return token_vec;
}

static void error(ERROR_CODE error_code, FileReader &fr, const char *fmt, ...) {
  char buf[1000];
  va_list ap;

  va_start(ap, fmt);
  vsprintf(buf, fmt, ap);
  va_end(ap);
  printf("(%lu,%lu) error: %s\n", fr.get_line(), fr.get_column(), buf);
  exit(error_code);
}

} // namespace lexical_analyzer
} // namespace acc