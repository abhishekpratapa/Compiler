#ifndef ACC_LEXICAL_ANALYSIS_TOKEN_H_
#define ACC_LEXICAL_ANALYSIS_TOKEN_H_

#include <string>
#include <string_view>

namespace acc {
namespace lexical_analysis {

class Token {
 public:
  enum class Type {
    kIdentifier,
    kKeyword,
    kLiteral,
    kOperator,
    kPunctuation,
    kEOF
  };

  Token(Type type, std::string_view value, int line, int column);

  Type GetType() const noexcept;
  const std::string& GetValue() const noexcept;
  int GetLine() const noexcept;
  int GetColumn() const noexcept;

 private:
  Type type_;
  std::string value_;
  int line_;
  int column_;
};

}  // namespace lexical_analysis
}  // namespace acc

#endif  // ACC_LEXICAL_ANALYSIS_TOKEN_H_