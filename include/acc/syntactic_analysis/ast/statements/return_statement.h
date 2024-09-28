#ifndef ACC_SYNTACTIC_ANALYSIS_AST_STATEMENTS_RETURN_STATEMENT_H_
#define ACC_SYNTACTIC_ANALYSIS_AST_STATEMENTS_RETURN_STATEMENT_H_

#include <memory>
#include "acc/syntactic_analysis/ast/statements/statement.h"
#include "acc/syntactic_analysis/ast/expressions/expression.h"

namespace acc {
namespace syntactic_analysis {
namespace ast {

class ReturnStatement final : public Statement {
 public:
  explicit ReturnStatement(std::unique_ptr<Expression> expression,
                           const common::SourceLocation& location) noexcept;

  void Accept(ASTVisitor& visitor) const override;

  const Expression* GetExpression() const noexcept { return expression_.get(); }

 private:
  std::unique_ptr<Expression> expression_;
};

} // namespace ast
} // namespace syntactic_analysis
} // namespace acc

#endif // ACC_SYNTACTIC_ANALYSIS_AST_RETURN_STATEMENT_H_