#include <lexical_analyzer.h>
#include <utils/file_utilities.h>

using namespace acc::utils;

namespace acc {
namespace lexical_analyzer {

std::vector<Token> tokenize_file(std::vector<std::string> &files) {
  std::vector<Token> token_vec;
  
  for (size_t index = 0; index < files.size(); index++) {
    std::string file_contents = read_file_contents(files.at(index));
  }

  return token_vec;
}

} // namespace lexical_analyzer
} // namespace acc