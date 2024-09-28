#include "acc/lexical_analysis/concrete_lexer.h"

#include <cctype>

#include "acc/lexical_analysis/token.h"

namespace acc {
namespace lexical_analysis {

ConcreteLexer::ConcreteLexer()
    : error_handler_(nullptr),
      current_pos_(0),
      current_line_(1),
      current_column_(1) {
  // Initialize keywords
  keywords_ = {
      {"int", Token::Type::kKeyword},   {"char", Token::Type::kKeyword},
      {"if", Token::Type::kKeyword},    {"else", Token::Type::kKeyword},
      {"while", Token::Type::kKeyword}, {"return", Token::Type::kKeyword}};
}

std::vector<std::unique_ptr<Token>> ConcreteLexer::Tokenize(
    const std::string &source) {
  source_ = source;
  current_pos_ = 0;
  current_line_ = 1;
  current_column_ = 1;

  std::vector<std::unique_ptr<Token>> tokens;

  while (current_pos_ < source_.length()) {
    auto token = GetNextToken();
    if (token) {
      tokens.push_back(std::move(token));
    }
  }

  tokens.push_back(std::make_unique<Token>(Token::Type::kEOF, "", current_line_,
                                           current_column_));
  return tokens;
}

void ConcreteLexer::SetErrorHandler(
    error_handling::ErrorHandler *error_handler) {
  error_handler_ = error_handler;
}

std::unique_ptr<Token> ConcreteLexer::GetNextToken() {
  SkipWhitespace();

  if (current_pos_ >= source_.length()) {
    return nullptr;
  }

  char c = source_[current_pos_];
  if (std::isalpha(c) || c == '_') {
    // Identifier or keyword
    size_t start = current_pos_;
    while (
        current_pos_ < source_.length() &&
        (std::isalnum(source_[current_pos_]) || source_[current_pos_] == '_')) {
      ++current_pos_;
      ++current_column_;
    }
    std::string identifier = source_.substr(start, current_pos_ - start);
    Token::Type type = IsKeyword(identifier) ? Token::Type::kKeyword
                                             : Token::Type::kIdentifier;
    return std::make_unique<Token>(type, identifier, current_line_,
                                   current_column_ - identifier.length());
  } else if (std::isdigit(c)) {
    // Number literal
    size_t start = current_pos_;
    while (current_pos_ < source_.length() &&
           std::isdigit(source_[current_pos_])) {
      ++current_pos_;
      ++current_column_;
    }
    std::string number = source_.substr(start, current_pos_ - start);
    return std::make_unique<Token>(Token::Type::kLiteral, number, current_line_,
                                   current_column_ - number.length());
  } else {
    // Operators and punctuation
    ++current_pos_;
    ++current_column_;
    switch (c) {
      case '+':
        return std::make_unique<Token>(Token::Type::kOperator, "+",
                                       current_line_, current_column_ - 1);
      case '-':
        return std::make_unique<Token>(Token::Type::kOperator, "-",
                                       current_line_, current_column_ - 1);
      case '*':
        return std::make_unique<Token>(Token::Type::kOperator, "*",
                                       current_line_, current_column_ - 1);
      case '/':
        return std::make_unique<Token>(Token::Type::kOperator, "/",
                                       current_line_, current_column_ - 1);
      case '=':
        return std::make_unique<Token>(Token::Type::kOperator, "=",
                                       current_line_, current_column_ - 1);
      case ';':
        return std::make_unique<Token>(Token::Type::kPunctuation, ";",
                                       current_line_, current_column_ - 1);
      case '(':
        return std::make_unique<Token>(Token::Type::kPunctuation, "(",
                                       current_line_, current_column_ - 1);
      case ')':
        return std::make_unique<Token>(Token::Type::kPunctuation, ")",
                                       current_line_, current_column_ - 1);
      case '{':
        return std::make_unique<Token>(Token::Type::kPunctuation, "{",
                                       current_line_, current_column_ - 1);
      case '}':
        return std::make_unique<Token>(Token::Type::kPunctuation, "}",
                                       current_line_, current_column_ - 1);
      case '!':
        return std::make_unique<Token>(Token::Type::kOperator, "!",
                                       current_line_, current_column_ - 1);
      default:
        if (error_handler_) {
          error_handler_->ReportError(
              "Unexpected character: " + std::string(1, c), current_line_,
              current_column_ - 1);
        }
        return nullptr;
    }
  }
}

bool ConcreteLexer::IsKeyword(const std::string &identifier) const {
  return keywords_.find(identifier) != keywords_.end();
}

void ConcreteLexer::SkipWhitespace() {
  while (current_pos_ < source_.length() &&
         std::isspace(source_[current_pos_])) {
    if (source_[current_pos_] == '\n') {
      ++current_line_;
      current_column_ = 1;
    } else {
      ++current_column_;
    }
    ++current_pos_;
  }
}

}  // namespace lexical_analysis
}  // namespace acc