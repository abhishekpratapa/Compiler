#include <acc/lexical/lexer.hpp>

#include <sstream>

namespace acc {
namespace lexical {

Lexer::Lexer(std::string &code) : token_stream_(code) {}

Token Lexer::Next() { return Token(); }

bool Lexer::HasNext() { return true; }

} // namespace lexical
} // namespace acc
