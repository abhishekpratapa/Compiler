#ifndef FILE_UTILITIES
#define FILE_UTILITIES

#include <fstream>
#include <string>

namespace acc {
namespace utils {

class FileReader {
public:
  FileReader() : m_line(1), m_column(0) {}
  FileReader(std::string &file_name);
  ~FileReader() {}

  char next();
  char peek();
  void unget();

  size_t get_line();
  size_t get_column();
  char get_current_char();

private:
  size_t m_line;
  size_t m_column;
  char m_current_char;

  std::ifstream m_file_ptr;
};

} // namespace utils
} // namespace acc

#endif
