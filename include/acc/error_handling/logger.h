// include/acc/error_handling/logger.h
#ifndef ACC_ERROR_HANDLING_LOGGER_H_
#define ACC_ERROR_HANDLING_LOGGER_H_

#include <string>
#include <mutex>

namespace acc {
namespace error_handling {

// Provides a thread-safe logging mechanism with configurable levels.
class Logger {
 public:
  // Defines logging severity levels.
  enum class Level {
    kDebug,    // Detailed information for debugging purposes
    kInfo,     // General information about program execution
    kWarning,  // Potential issues that aren't errors
    kError,    // Errors that don't halt program execution
    kFatal     // Critical errors that may halt program execution
  };

  Logger() = delete;
  ~Logger() = delete;

  // Sets the global logging level.
  static void SetGlobalLevel(Level level);

  // Returns the current global logging level.
  static Level GetGlobalLevel();

  // Logs a message with the specified severity level.
  static void Log(Level level, const std::string& message);

  // Convenience methods for different log levels
  static void Debug(const std::string& message) { Log(Level::kDebug, message); }
  static void Info(const std::string& message) { Log(Level::kInfo, message); }
  static void Warning(const std::string& message) { Log(Level::kWarning, message); }
  static void Error(const std::string& message) { Log(Level::kError, message); }
  static void Fatal(const std::string& message) { Log(Level::kFatal, message); }

 private:
  static Level global_level_;  // Current global logging level
  static std::mutex mutex_;    // Ensures thread-safe logging
};

}  // namespace error_handling
}  // namespace acc

#endif  // ACC_ERROR_HANDLING_LOGGER_H_
