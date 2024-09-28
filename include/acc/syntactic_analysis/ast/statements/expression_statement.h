#ifndef ACC_SYNTACTIC_ANALYSIS_AST_STATEMENTS_EXPRESSION_STATEMENT_H_
#define ACC_SYNTACTIC_ANALYSIS_AST_STATEMENTS_EXPRESSION_STATEMENT_H_

#include <memory>
#include "acc/syntactic_analysis/ast/statements/statement.h"
#include "acc/syntactic_analysis/ast/expressions/expression.h"

namespace acc {
namespace syntactic_analysis {
namespace ast {

class ExpressionStatement final : public Statement {
 public:
  explicit ExpressionStatement(std::unique_ptr<Expression> expression,
                               const common::SourceLocation& location) noexcept;

  void Accept(ASTVisitor& visitor) const override;

  const Expression* GetExpression() const noexcept { return expression_.get(); }

 private:
  std::unique_ptr<Expression> expression_;
};

} // namespace ast
} // namespace syntactic_analysis
} // namespace acc

#endif // ACC_SYNTACTIC_ANALYSIS_AST_EXPRESSION_STATEMENT_H_