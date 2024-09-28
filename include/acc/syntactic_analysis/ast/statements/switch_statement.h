#ifndef ACC_SYNTACTIC_ANALYSIS_AST_STATEMENTS_SWITCH_STATEMENT_H_
#define ACC_SYNTACTIC_ANALYSIS_AST_STATEMENTS_SWITCH_STATEMENT_H_

#include <memory>
#include <vector>
#include "acc/syntactic_analysis/ast/statements/statement.h"
#include "acc/syntactic_analysis/ast/expressions/expression.h"

namespace acc {
namespace syntactic_analysis {
namespace ast {

class SwitchStatement final : public Statement {
 public:
  SwitchStatement(std::unique_ptr<Expression> switch_expr,
                  std::vector<std::unique_ptr<Statement>> cases,
                  const common::SourceLocation& location) noexcept;

  void Accept(ASTVisitor& visitor) const override;

  const Expression* GetSwitchExpression() const noexcept { return switch_expr_.get(); }
  const std::vector<std::unique_ptr<Statement>>& GetCases() const noexcept { return cases_; }

 private:
  std::unique_ptr<Expression> switch_expr_;
  std::vector<std::unique_ptr<Statement>> cases_;
};

} // namespace ast
} // namespace syntactic_analysis
} // namespace acc

#endif // ACC_SYNTACTIC_ANALYSIS_AST_SWITCH_STATEMENT_H_