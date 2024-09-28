#ifndef ACC_COMMON_SOURCE_LOCATION_H_
#define ACC_COMMON_SOURCE_LOCATION_H_

#include <string>
#include <string_view>

namespace acc {
namespace common {

struct SourceLocation {
  std::string_view file;
  int line;
  int column;

  SourceLocation(std::string_view f, int l, int c)
      : file(f), line(l), column(c) {}

  bool operator==(const SourceLocation& other) const {
    return file == other.file && line == other.line && column == other.column;
  }

  bool operator!=(const SourceLocation& other) const {
    return !(*this == other);
  }

  std::string ToString() const;
};

}  // namespace common
}  // namespace acc

#endif  // ACC_COMMON_SOURCE_LOCATION_H_