#ifdef INDEPENDENT_TESTS
#include "test_main.h"
#define BOOST_TEST_MODULE main
#endif

#include <boost/test/unit_test.hpp>
#include <utils/argument_parser.h>
#include <lexical_analyzer.h>

#include <string>
#include <vector>

using namespace acc::utils;
using namespace acc::lexical_analyzer;

#ifdef TEST_FILE_PATH
  static std::string root_test_path = TEST_FILE_PATH;
#else
  static std::string root_test_path = TEST_FILE_PATH;
#endif

BOOST_AUTO_TEST_SUITE(lexical_analyzer)

BOOST_AUTO_TEST_CASE(simple_main) {
  std::string file_name = root_test_path + "examples/main.c";
  
  std::vector<std::string> file_list = {file_name};
  std::vector<Token> tokens = tokenize_file(file_list);
  BOOST_CHECK_EQUAL(tokens.size(), 10);
}

BOOST_AUTO_TEST_SUITE_END()