// src/acc/error_handling/error_handler.cpp
#include "acc/error_handling/error_handler.h"

#include <iostream>

namespace acc {
namespace error_handling {

void ErrorHandler::ReportError(const std::string& message, int line,
                               int column) {
  errors_.emplace_back(message, line, column);
  std::cerr << "Error at line " << line << ", column " << column << ": "
            << message << std::endl;
}

}  // namespace error_handling
}  // namespace acc