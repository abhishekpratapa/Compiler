#include <utils/argument_parser.h>

int main(int argc, char *argv[]) {
  std::string output_program_name;
  std::vector<std::string> file_list;

  argument_parse(output_program_name, file_list, argc, argv);

  return 0;
}
