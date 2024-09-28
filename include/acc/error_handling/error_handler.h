// include/acc/error_handling/error_handler.h
#ifndef ACC_ERROR_HANDLING_ERROR_HANDLER_H_
#define ACC_ERROR_HANDLING_ERROR_HANDLER_H_

#include <string>
#include <vector>
#include "acc/error_handling/logger.h"

namespace acc {
namespace error_handling {

// Manages compilation errors and integrates with the Logger.
class ErrorHandler {
 public:
  // Represents a single error with its details.
  struct Error {
    std::string message;  // Description of the error
    int line;             // Line number where the error occurred
    int column;           // Column number where the error occurred
    Logger::Level level;  // Severity level of the error

    Error(const std::string& msg, int l, int c, Logger::Level lvl)
        : message(msg), line(l), column(c), level(lvl) {}
  };

  // Reports and logs an error.
  void ReportError(const std::string& message, int line, int column, 
                   Logger::Level level = Logger::Level::kError);

  // Checks if any errors have been reported.
  bool HasErrors() const { return !errors_.empty(); }

  // Returns all reported errors.
  const std::vector<Error>& GetErrors() const { return errors_; }

  // Clears all reported errors.
  void ClearErrors() { errors_.clear(); }

 private:
  std::vector<Error> errors_;  // Collection of all reported errors
};

}  // namespace error_handling
}  // namespace acc

#endif  // ACC_ERROR_HANDLING_ERROR_HANDLER_H_