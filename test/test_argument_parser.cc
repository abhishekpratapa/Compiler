#include <boost/test/unit_test.hpp>
#include <utils/argument_parser.h>

using namespace acc::utils;

BOOST_AUTO_TEST_SUITE(argument_parser)

BOOST_AUTO_TEST_CASE(default_output_file) {
  // MOCK `argc` and `argv`
  int argc = 2;
  char **argv;
  argv = (char **)malloc(argc * sizeof(char *));
  argv[0] = (char *)malloc(100 * sizeof(char));
  argv[1] = (char *)malloc(100 * sizeof(char));

  std::string FILE_NAME = "main.cc";

  strcpy(argv[0], "./acc");
  strcpy(argv[1], FILE_NAME.c_str());

  // Run tests on expected output
  std::string output_program_name;
  std::vector<std::string> file_list;

  ERROR_CODE code = argument_parse(output_program_name, file_list, argc, argv);

  BOOST_CHECK_EQUAL(code, NO_ERROR);
  BOOST_CHECK_EQUAL(DEFAULT_PROGRAM_NAME, output_program_name);
  BOOST_CHECK_EQUAL(file_list.size(), 1);
  BOOST_CHECK_EQUAL(file_list.at(0), FILE_NAME);

  // Free allocated memory
  free(argv[0]);
  free(argv[1]);
  free(argv);
}

BOOST_AUTO_TEST_CASE(no_output_file) {
  // MOCK `argc` and `argv`
  int argc = 2;
  char **argv;
  argv = (char **)malloc(argc * sizeof(char *));
  argv[0] = (char *)malloc(100 * sizeof(char));
  argv[1] = (char *)malloc(100 * sizeof(char));

  strcpy(argv[0], "./acc");
  strcpy(argv[1], "-o");

  // Run tests on expected output
  std::string output_program_name;
  std::vector<std::string> file_list;

  ERROR_CODE code = argument_parse(output_program_name, file_list, argc, argv);

  BOOST_CHECK_EQUAL(code, OUTPUT_FILE_ERROR);

  // Free allocated memory
  free(argv[0]);
  free(argv[1]);
  free(argv);
}

BOOST_AUTO_TEST_CASE(no_source_files) {
  // MOCK `argc` and `argv`
  int argc = 1;
  char **argv;
  argv = (char **)malloc(argc * sizeof(char *));
  argv[0] = (char *)malloc(100 * sizeof(char));

  strcpy(argv[0], "./acc");

  // Run tests on expected output
  std::string output_program_name;
  std::vector<std::string> file_list;

  ERROR_CODE code = argument_parse(output_program_name, file_list, argc, argv);

  BOOST_CHECK_EQUAL(code, SOURCE_FILES_ERROR);

  // Free allocated memory
  free(argv[0]);
  free(argv);
}

BOOST_AUTO_TEST_CASE(correct_input) {
  // MOCK `argc` and `argv`
  int argc = 4;
  char **argv;
  argv = (char **)malloc(argc * sizeof(char *));
  argv[0] = (char *)malloc(100 * sizeof(char));
  argv[1] = (char *)malloc(100 * sizeof(char));
  argv[2] = (char *)malloc(100 * sizeof(char));
  argv[3] = (char *)malloc(100 * sizeof(char));

  std::string FILE_NAME = "main.cc";
  std::string OUTPUT_NAME = "main";

  strcpy(argv[0], "./acc");
  strcpy(argv[1], "-o");
  strcpy(argv[2], OUTPUT_NAME.c_str());
  strcpy(argv[3], FILE_NAME.c_str());

  // Run tests on expected output
  std::string output_program_name;
  std::vector<std::string> file_list;

  ERROR_CODE code = argument_parse(output_program_name, file_list, argc, argv);

  BOOST_CHECK_EQUAL(code, NO_ERROR);
  BOOST_CHECK_EQUAL(OUTPUT_NAME, output_program_name);
  BOOST_CHECK_EQUAL(file_list.size(), 1);
  BOOST_CHECK_EQUAL(file_list.at(0), FILE_NAME);

  // Free allocated memory
  free(argv[0]);
  free(argv[1]);
  free(argv[2]);
  free(argv[3]);
  free(argv);
}

BOOST_AUTO_TEST_SUITE_END()