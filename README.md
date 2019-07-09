# Compiler

[![Build Status](https://travis-ci.com/abhishekpratapa/Compiler.svg?branch=master)](https://travis-ci.com/abhishekpratapa/Compiler)

This is going to be my attempt at building a compiler. We'll see how it goes, and no this is not for a class project. I make my own classes and structs. Lolz.

## Build

Build the project by following the directions in the [Build](https://github.com/abhishekpratapa/Compiler/blob/master/BUILD.md) document.

## The Code Breakdown

Here is a code breakdown for the Compiler its high level functions.

### Argument Parser

code: `src/utils/argument_parser.cc`

I'm starting with a very basic argument parser. The only flag recognized is the `-o` or `--output` flag followed by a list of source files. There are only two exit codes other than the success error codes, `OUTPUT_FILE_ERROR` and `SOURCE_FILES_ERROR`. More will be added as needed.


#### Reference

Here are all of the internet pages I used to build this compiler. I really am standing on the shoulders of giants. Thanks to everyone that make this technology possible, I don't really know who they are, but thanks!

##### Utilities:

- [ifstream](http://www.cplusplus.com/reference/fstream/ifstream/)
- [istreambuf_iterator](https://en.cppreference.com/w/cpp/iterator/istreambuf_iterator)

##### Tokenizer:

- [C Program to Detect Tokens](https://www.geeksforgeeks.org/c-program-detect-tokens-c-program/)
- [C/C++ Tokens](https://www.geeksforgeeks.org/cc-tokens/)
- [Basic Optimizations in C](https://www.geeksforgeeks.org/basic-code-optimizations-in-c/)
