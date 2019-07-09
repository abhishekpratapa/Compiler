#ifndef ARGUMENT_PARSER
#define ARGUMENT_PARSER

#include <iostream>
#include <string>
#include <vector>

void argument_parse(std::string &output_program_name,
                    std::vector<std::string> &file_list, int argc,
                    char *argv[]);

#endif
