#ifndef ACC_SYNTACTIC_ANALYSIS_AST_PREPROCESSOR_DIRECTIVE_H_
#define ACC_SYNTACTIC_ANALYSIS_AST_PREPROCESSOR_DIRECTIVE_H_

#include <memory>
#include <string>
#include <vector>
#include "acc/syntactic_analysis/ast/common/ast_node.h"

namespace acc {
namespace syntactic_analysis {
namespace ast {

class PreprocessorDirective : public ASTNode {
 public:
  enum class Type {
    kInclude,
    kDefine,
    kUndef,
    kIfdef,
    kIfndef,
    kIf,
    kElif,
    kElse,
    kEndif,
    kError,
    kPragma
  };

  PreprocessorDirective(Type type, const common::SourceLocation& location) noexcept;
  virtual ~PreprocessorDirective() = default;

  Type GetType() const noexcept { return type_; }
  virtual void Accept(ASTVisitor& visitor) const override = 0;

 private:
  Type type_;
};

class IncludeDirective final : public PreprocessorDirective {
 public:
  IncludeDirective(const std::string& filename, bool is_system_include,
                   const common::SourceLocation& location) noexcept;

  const std::string& GetFilename() const noexcept { return filename_; }
  bool IsSystemInclude() const noexcept { return is_system_include_; }
  void Accept(ASTVisitor& visitor) const override;

 private:
  std::string filename_;
  bool is_system_include_;
};

// Add other preprocessor directive classes (DefineDirective, UndefDirective, etc.) here...

} // namespace ast
} // namespace syntactic_analysis
} // namespace acc

#endif // ACC_SYNTACTIC_ANALYSIS_AST_PREPROCESSOR_DIRECTIVE_H_