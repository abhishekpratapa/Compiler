#ifndef ACC_SYNTACTIC_ANALYSIS_AST_EXPRESSIONS_EXPRESSION_H_
#define ACC_SYNTACTIC_ANALYSIS_AST_EXPRESSIONS_EXPRESSION_H_

#include "acc/syntactic_analysis/ast/common/ast_node.h"
#include "acc/type_system/type.h"

namespace acc {
namespace syntactic_analysis {
namespace ast {

class ASTVisitor;

class Expression : public ASTNode {
 public:
  virtual ~Expression() noexcept override = default;

  virtual const type_system::Type* GetType() const noexcept = 0;

  // Disable copying and assignment
  Expression(const Expression&) = delete;
  Expression& operator=(const Expression&) = delete;

  // Enable moving
  Expression(Expression&&) noexcept = default;
  Expression& operator=(Expression&&) noexcept = default;

 protected:
  explicit Expression(const common::SourceLocation& location) noexcept
    : ASTNode(location) {}
};

static_assert(alignof(Expression) >= alignof(void*), "Expression alignment is insufficient");
static_assert(sizeof(Expression) >= sizeof(void*), "Expression size is insufficient");

} // namespace ast
} // namespace syntactic_analysis
} // namespace acc

#endif // ACC_SYNTACTIC_ANALYSIS_AST_EXPRESSION_H_