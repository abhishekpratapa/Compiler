#ifndef ACC_SYNTACTIC_ANALYSIS_AST_TYPES_BOOLEAN_TYPE_H_
#define ACC_SYNTACTIC_ANALYSIS_AST_TYPES_BOOLEAN_TYPE_H_

#include "acc/syntactic_analysis/ast/common/ast_node.h"

namespace acc {
namespace syntactic_analysis {
namespace ast {

class BooleanType final : public ASTNode {
 public:
  explicit BooleanType(const common::SourceLocation& location) noexcept;

  void Accept(ASTVisitor& visitor) const override;
};

} // namespace ast
} // namespace syntactic_analysis
} // namespace acc

#endif // ACC_SYNTACTIC_ANALYSIS_AST_BOOLEAN_TYPE_H_