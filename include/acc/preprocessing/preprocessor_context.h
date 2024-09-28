// include/acc/preprocessing/preprocessor_context.h

#ifndef ACC_PREPROCESSING_PREPROCESSOR_CONTEXT_H_
#define ACC_PREPROCESSING_PREPROCESSOR_CONTEXT_H_

#include <string>
#include <unordered_map>
#include <vector>
#include <memory>
#include <optional>
#include "acc/common/source_location.h"
#include "acc/error_handling/error_handler.h"

namespace acc {
namespace preprocessing {

class PreprocessorContext {
 public:
  struct Macro {
    std::string name;
    std::string value;
    std::vector<std::string> params;
    bool is_function_like;
    common::SourceLocation definition_location;

    Macro(const std::string& n, const std::string& v,
          const std::vector<std::string>& p,
          const common::SourceLocation& loc)
        : name(n), value(v), params(p), is_function_like(!p.empty()),
          definition_location(loc) {}
  };

  explicit PreprocessorContext(error_handling::ErrorHandler* error_handler);

  void DefineMacro(const std::string& name, const std::string& value,
                   const std::vector<std::string>& params,
                   const common::SourceLocation& location);
  void UndefineMacro(const std::string& name);
  bool IsDefined(const std::string& name) const;
  const Macro* GetMacro(const std::string& name) const;

  std::optional<std::string> ExpandMacro(const std::string& name,
                                         const std::vector<std::string>& args,
                                         const common::SourceLocation& location);

  void PushConditional(bool condition);
  void PopConditional();
  bool ShouldSkipCurrentSection() const;

  void AddIncludePath(const std::string& path);
  std::optional<std::string> ResolveInclude(const std::string& filename,
                                            bool is_system_include,
                                            const common::SourceLocation& location);

  void SetCurrentFile(const std::string& filename);
  const std::string& GetCurrentFile() const;

 private:
  std::unordered_map<std::string, std::unique_ptr<Macro>> macros_;
  std::vector<bool> conditional_stack_;
  std::vector<std::string> include_paths_;
  std::string current_file_;
  error_handling::ErrorHandler* error_handler_;

  std::optional<std::string> ExpandMacroRecursive(const std::string& input,
                                                  const common::SourceLocation& location,
                                                  int depth = 0);
  static constexpr int kMaxExpansionDepth = 256;
};

}  // namespace preprocessing
}  // namespace acc

#endif  // ACC_PREPROCESSING_PREPROCESSOR_CONTEXT_H_