#ifndef ARGUMENT_PARSER
#define ARGUMENT_PARSER

#include <iostream>
#include <string>
#include <vector>

#include <utils/defaults.h>
#include <utils/exit_codes.h>

namespace acc {
namespace utils {

ERROR_CODE argument_parse(std::string &output_program_name,
                          std::vector<std::string> &file_list, int argc,
                          char *argv[]);

} // namespace utils
} // namespace acc

#endif
