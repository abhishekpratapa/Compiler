#ifndef ACC_SYNTACTIC_ANALYSIS_AST_TYPES_FUNCTION_SPECIFIER_H_
#define ACC_SYNTACTIC_ANALYSIS_AST_TYPES_FUNCTION_SPECIFIER_H_

#include "acc/syntactic_analysis/ast/common/ast_node.h"

namespace acc {
namespace syntactic_analysis {
namespace ast {

class FunctionSpecifier final : public ASTNode {
 public:
  enum class Kind {
    kInline,
    kNoreturn
  };

  FunctionSpecifier(Kind kind, const common::SourceLocation& location) noexcept;

  void Accept(ASTVisitor& visitor) const override;

  Kind GetKind() const noexcept { return kind_; }

 private:
  Kind kind_;
};

} // namespace ast
} // namespace syntactic_analysis
} // namespace acc

#endif // ACC_SYNTACTIC_ANALYSIS_AST_FUNCTION_SPECIFIER_H_