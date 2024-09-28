#ifndef ACC_SYNTACTIC_ANALYSIS_AST_STATEMENTS_DO_WHILE_STATEMENT_H_
#define ACC_SYNTACTIC_ANALYSIS_AST_STATEMENTS_DO_WHILE_STATEMENT_H_

#include <memory>
#include "acc/syntactic_analysis/ast/statements/statement.h"
#include "acc/syntactic_analysis/ast/expressions/expression.h"

namespace acc {
namespace syntactic_analysis {
namespace ast {

class DoWhileStatement final : public Statement {
 public:
  DoWhileStatement(std::unique_ptr<Statement> body,
                   std::unique_ptr<Expression> condition,
                   const common::SourceLocation& location) noexcept;

  void Accept(ASTVisitor& visitor) const override;

  const Statement* GetBody() const noexcept { return body_.get(); }
  const Expression* GetCondition() const noexcept { return condition_.get(); }

 private:
  std::unique_ptr<Statement> body_;
  std::unique_ptr<Expression> condition_;
};

} // namespace ast
} // namespace syntactic_analysis
} // namespace acc

#endif // ACC_SYNTACTIC_ANALYSIS_AST_DO_WHILE_STATEMENT_H_