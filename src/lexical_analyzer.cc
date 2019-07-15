#include <lexical_analyzer.h>
#include <utils/file_utilities.h>

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
    
  /* Follow this through */
  /*
        case '<':  next_ch(); return follow('=', tk_Leq, tk_Lss,    err_line, err_col);
        case '>':  next_ch(); return follow('=', tk_Geq, tk_Gtr,    err_line, err_col);
        case '=':  next_ch(); return follow('=', tk_Eq,  tk_Assign, err_line, err_col);
        case '!':  next_ch(); return follow('=', tk_Neq, tk_Not,    err_line, err_col);
        case '&':  next_ch(); return follow('&', tk_And, tk_EOI,    err_line, err_col);
        case '|':  next_ch(); return follow('|', tk_Or,  tk_EOI,    err_line, err_col);
  */
  case EOF:
    return (Token){EOI, fr.get_line(), fr.get_column(),
                   boost::variant<int, char, std::string>(value)};
  default:
    return (Token){String, fr.get_line(), fr.get_column(),
                   boost::variant<int, char, std::string>(value)};
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
  if (fr.get_current_char() != '*')
    return (Token){
        Division, fr.get_line(), fr.get_column(),
        boost::variant<int, char, std::string>(fr.get_current_char())};

  char value = (char)fr.next();

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