#ifndef TEST_MAIN
#define TEST_MAIN
#define BOOST_TEST_MAIN
#if !defined(WIN32)
#define BOOST_TEST_DYN_LINK
#endif
#endif

#define BOOST_TEST_MODULE main

#include "test_lexical_analyzer.cc"
#include "test_argument_parser.cc"