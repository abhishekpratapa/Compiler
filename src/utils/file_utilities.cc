#include <utils/file_utilities.h>

namespace acc {
namespace utils {

std::string read_file_contents(std::string &file_name) {
  std::ifstream ifs(file_name.c_str());
  std::string data((std::istreambuf_iterator<char>(ifs)),
                   (std::istreambuf_iterator<char>()));
  return data;
}

} // namespace utils
} // namespace acc