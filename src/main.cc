#include <stdlib.h>

#include <lexical_analyzer.h>
#include <utils/argument_parser.h>

using namespace acc::lexical_analyzer;
using namespace acc::utils;

int main(int argc, char *argv[]) {
  std::string output_program_name;
  std::vector<std::string> file_list;

  ERROR_CODE code = argument_parse(output_program_name, file_list, argc, argv);

  if (code != NO_ERROR) {
    exit(code);
  }

  std::vector<Token> tokens = tokenize_file(file_list);

  return 0;
}
