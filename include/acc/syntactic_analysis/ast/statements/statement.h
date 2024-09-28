#ifndef ACC_SYNTACTIC_ANALYSIS_AST_STATEMENTS_STATEMENT_H_
#define ACC_SYNTACTIC_ANALYSIS_AST_STATEMENTS_STATEMENT_H_

#include "acc/syntactic_analysis/ast/common/ast_node.h"

namespace acc {
namespace syntactic_analysis {
namespace ast {

class Statement : public ASTNode {
 public:
  virtual ~Statement() noexcept override = default;

  // Disable copying and assignment
  Statement(const Statement&) = delete;
  Statement& operator=(const Statement&) = delete;

  // Enable moving
  Statement(Statement&&) noexcept = default;
  Statement& operator=(Statement&&) noexcept = default;

 protected:
  explicit Statement(const common::SourceLocation& location) noexcept
    : ASTNode(location) {}
};

static_assert(alignof(Statement) >= alignof(void*), "Statement alignment is insufficient");
static_assert(sizeof(Statement) >= sizeof(void*), "Statement size is insufficient");

} // namespace ast
} // namespace syntactic_analysis
} // namespace acc

#endif // ACC_SYNTACTIC_ANALYSIS_AST_STATEMENT_H_