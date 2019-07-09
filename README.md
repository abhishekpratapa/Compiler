# Compiler

[![Build Status](https://travis-ci.com/abhishekpratapa/Compiler.svg?branch=master)](https://travis-ci.com/abhishekpratapa/Compiler)

This is going to be my attempt at building a compiler. We'll see how it goes.

## The Code Breakdown

Here is a code breakdown for the Compiler

### Argument Parser

code: `src/utils/argument_parser.cc`

I'm starting with a very basic argument parser. The only flag recognized is the `-o` or `--output` flag followed by a list of source files. There are only two exit codes other than the success error codes, `OUTPUT_FILE_ERROR` and `SOURCE_FILES_ERROR`. More will be added as needed.