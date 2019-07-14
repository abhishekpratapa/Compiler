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
  case EOF:
    return (Token){EOI, fr.get_line(), fr.get_column(),
                   boost::variant<int, char, std::string>(value)};
  default:
    return (Token){String, fr.get_line(), fr.get_column(),
                   boost::variant<int, char, std::string>(value)};
  }
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

} // namespace lexical_analyzer
} // namespace acc