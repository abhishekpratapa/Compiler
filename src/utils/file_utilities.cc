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

  return value;
}

size_t FileReader::get_line() { return m_line; }

size_t FileReader::get_column() { return m_column; }

} // namespace utils
} // namespace acc