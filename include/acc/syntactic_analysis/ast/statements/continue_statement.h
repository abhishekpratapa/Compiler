#ifndef ACC_SYNTACTIC_ANALYSIS_AST_STATEMENTS_CONTINUE_STATEMENT_H_
#define ACC_SYNTACTIC_ANALYSIS_AST_STATEMENTS_CONTINUE_STATEMENT_H_

#include "acc/syntactic_analysis/ast/statements/statement.h"

namespace acc {
namespace syntactic_analysis {
namespace ast {

class ContinueStatement final : public Statement {
 public:
  explicit ContinueStatement(const common::SourceLocation& location) noexcept;

  void Accept(ASTVisitor& visitor) const override;
};

} // namespace ast
} // namespace syntactic_analysis
} // namespace acc

#endif // ACC_SYNTACTIC_ANALYSIS_AST_CONTINUE_STATEMENT_H_