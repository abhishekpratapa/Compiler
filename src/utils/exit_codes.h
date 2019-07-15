#ifndef EXIT_CODES
#define EXIT_CODES

typedef int ERROR_CODE;

#define NO_ERROR                                       0
#define OUTPUT_FILE_ERROR                            101
#define SOURCE_FILES_ERROR                           102

#define LEXICAL_ANALYZER_EOF                         201
#define LEXICAL_ANALYZER_EMPTY_CHAR                  202
#define LEXICAL_ANALYZER_UNKNOWN_ESCAPE              203
#define LEXICAL_ANALYZER_MULTILINE_CHAR_CONSTANT     204

#endif
