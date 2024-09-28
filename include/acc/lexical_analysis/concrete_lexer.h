#ifndef ACC_LEXICAL_ANALYSIS_CONCRETE_LEXER_H_
#define ACC_LEXICAL_ANALYSIS_CONCRETE_LEXER_H_

#include <memory>
#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>

#include "acc/error_handling/error_handler.h"
#include "acc/lexical_analysis/lexer.h"
#include "acc/lexical_analysis/token.h"

namespace acc {
namespace lexical_analysis {

class TokenFactory {
 public:
  static std::unique_ptr<Token> CreateToken(Token::Type type,
                                            std::string_view value,
                                            int line,
                                            int column);
};

class LexerException : public std::runtime_error {
 public:
  LexerException(const std::string& message, int line, int column);
  int GetLine() const noexcept;
  int GetColumn() const noexcept;

 private:
  int line_;
  int column_;
};

class ConcreteLexer : public Lexer {
 public:
  ConcreteLexer();

  std::vector<std::unique_ptr<Token>> Tokenize(
      std::string_view source) override;
  void SetErrorHandler(error_handling::ErrorHandler* error_handler) override;

 private:
  error_handling::ErrorHandler* error_handler_;
  std::unordered_map<std::string_view, Token::Type> keywords_;

  std::unique_ptr<Token> GetNextToken();
  bool IsKeyword(std::string_view identifier) const noexcept;
  void SkipWhitespace();

  std::string_view source_;
  size_t current_pos_;
  int current_line_;
  int current_column_;
};

}  // namespace lexical_analysis
}  // namespace acc

#endif  // ACC_LEXICAL_ANALYSIS_CONCRETE_LEXER_H_