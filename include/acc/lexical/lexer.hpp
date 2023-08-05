#pragma once

#include <sstream>
#include <string>

namespace acc {
namespace lexical {

struct Token {
  std::string name;
};

class Lexer {
public:
  Lexer() = delete;

  Lexer(std::string &code);
  ~Lexer() = default;

  Token Next();
  bool HasNext();

private:
  std::stringstream token_stream_;
};

} // namespace lexical
} // namespace acc