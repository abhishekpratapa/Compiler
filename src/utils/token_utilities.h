#ifndef TOKEN_UTILITIES
#define TOKEN_UTILITIES

#include <vector>

#include <lexical_analyzer.h>

namespace acc {
namespace utils {

void print_tokens(std::vector<acc::lexical_analyzer::Token> &token_vector);

}
} // namespace acc

#endif