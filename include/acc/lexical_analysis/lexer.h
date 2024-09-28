#ifndef ACC_LEXICAL_ANALYSIS_LEXER_H_
#define ACC_LEXICAL_ANALYSIS_LEXER_H_

#include <memory>
#include <string>
#include <string_view>
#include <vector>

namespace acc {

namespace error_handling {
class ErrorHandler;
}  // namespace error_handling

namespace lexical_analysis {

class Token;

class Lexer {
 public:
  virtual ~Lexer() = default;

  virtual std::vector<std::unique_ptr<Token>> Tokenize(
      std::string_view source) = 0;

  virtual void SetErrorHandler(error_handling::ErrorHandler* error_handler) = 0;
};

}  // namespace lexical_analysis
}  // namespace acc

#endif  // ACC_LEXICAL_ANALYSIS_LEXER_H_