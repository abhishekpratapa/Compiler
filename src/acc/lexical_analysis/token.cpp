// src/acc/lexical_analysis/token.cpp

#include "acc/lexical_analysis/token.h"

namespace acc {
namespace lexical_analysis {

Token::Token(Type type, const std::string& value, int line, int column)
    : type_(type), value_(value), line_(line), column_(column) {}

Token::Type Token::GetType() const { return type_; }

const std::string& Token::GetValue() const { return value_; }

int Token::GetLine() const { return line_; }

int Token::GetColumn() const { return column_; }

}  // namespace lexical_analysis
}  // namespace acc