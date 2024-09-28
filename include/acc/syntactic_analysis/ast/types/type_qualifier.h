#ifndef ACC_SYNTACTIC_ANALYSIS_AST_TYPES_TYPE_QUALIFIER_H_
#define ACC_SYNTACTIC_ANALYSIS_AST_TYPES_TYPE_QUALIFIER_H_

#include "acc/syntactic_analysis/ast/common/ast_node.h"

namespace acc {
namespace syntactic_analysis {
namespace ast {

class TypeQualifier final : public ASTNode {
 public:
  enum class Kind {
    kConst,
    kVolatile,
    kRestrict,
    kAtomic
  };

  TypeQualifier(Kind kind, const common::SourceLocation& location) noexcept;

  void Accept(ASTVisitor& visitor) const override;

  Kind GetKind() const noexcept { return kind_; }

 private:
  Kind kind_;
};

} // namespace ast
} // namespace syntactic_analysis
} // namespace acc

#endif // ACC_SYNTACTIC_ANALYSIS_AST_TYPE_QUALIFIER_H_