#include <boost/test/unit_test.hpp>
#include <utils/argument_parser.h>
#include <lexical_analyzer.h>

#include <string>
#include <vector>

using namespace acc::utils;
using namespace acc::lexical_analyzer;

BOOST_AUTO_TEST_SUITE(lexical_analyzer)

BOOST_AUTO_TEST_CASE(simple_main) {
  std::vector<std::string> file_list = {"examples/main.c"};
  std::vector<Token> tokens = tokenize_file(file_list);
  BOOST_CHECK_EQUAL(tokens.size(), 10);
}

BOOST_AUTO_TEST_SUITE_END()