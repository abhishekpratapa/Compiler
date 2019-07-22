#include <utils/file_utilities.h>

namespace acc {
namespace utils {

FileReader::FileReader(std::string &file_name)
    : m_line(1), m_column(0), m_file_ptr(file_name.c_str()) {}

char FileReader::next() {
  char value = m_file_ptr.get();

  ++m_column;
  ++m_line;

  if (value == '\n') {
    ++m_line;
    m_column = 0;
  }

  m_current_char = value;
  
  return value;
}

void FileReader::unget() { m_file_ptr.unget(); }

char FileReader::peek() { return m_file_ptr.peek(); }

int FileReader::get_line() { return m_line; }

int FileReader::get_column() { return m_column; }

char FileReader::get_current_char() { return m_current_char; }

} // namespace utils
} // namespace acc