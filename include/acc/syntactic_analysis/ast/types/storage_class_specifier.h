#ifndef ACC_SYNTACTIC_ANALYSIS_AST_TYPES_STORAGE_CLASS_SPECIFIER_H_
#define ACC_SYNTACTIC_ANALYSIS_AST_TYPES_STORAGE_CLASS_SPECIFIER_H_

#include "acc/syntactic_analysis/ast/common/ast_node.h"

namespace acc {
namespace syntactic_analysis {
namespace ast {

class StorageClassSpecifier final : public ASTNode {
 public:
  enum class Kind {
    kAuto,
    kRegister,
    kStatic,
    kExtern,
    kThreadLocal
  };

  StorageClassSpecifier(Kind kind, const common::SourceLocation& location) noexcept;

  void Accept(ASTVisitor& visitor) const override;

  Kind GetKind() const noexcept { return kind_; }

 private:
  Kind kind_;
};

} // namespace ast
} // namespace syntactic_analysis
} // namespace acc

#endif // ACC_SYNTACTIC_ANALYSIS_AST_STORAGE_CLASS_SPECIFIER_H_