#include <utils/argument_parser.h>
#include <utils/defaults.h>
#include <utils/exit_codes.h>

void argument_parse(std::string &output_program_name,
                    std::vector<std::string> &file_list, int argc,
                    char *argv[]) {
  output_program_name = DEFAULT_PROGRAM_NAME;
  
  for (int x = 1; x < argc; x++) {
    std::string token = argv[x];
    if (token == "-o" || token == "--output") {
      if (argc > (x + 1)) {
        x++;
        output_program_name = argv[x];
      } else {
        std::cerr << "Specify an output file name" << std::endl;
        exit(OUTPUT_FILE_ERROR);
      }
    } else {
      file_list.push_back(token);
    }
  }

  if (file_list.size() == 0) {
    std::cerr << "No source files for compilation are defined" << std::endl;
    exit(SOURCE_FILES_ERROR);
  }
}