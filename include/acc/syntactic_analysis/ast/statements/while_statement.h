#ifndef ACC_SYNTACTIC_ANALYSIS_AST_STATEMENTS_WHILE_STATEMENT_H_
#define ACC_SYNTACTIC_ANALYSIS_AST_STATEMENTS_WHILE_STATEMENT_H_

#include <memory>
#include "acc/syntactic_analysis/ast/statements/statement.h"
#include "acc/syntactic_analysis/ast/expressions/expression.h"

namespace acc {
namespace syntactic_analysis {
namespace ast {

class WhileStatement final : public Statement {
 public:
  WhileStatement(std::unique_ptr<Expression> condition,
                 std::unique_ptr<Statement> body,
                 const common::SourceLocation& location) noexcept;

  void Accept(ASTVisitor& visitor) const override;

  const Expression* GetCondition() const noexcept { return condition_.get(); }
  const Statement* GetBody() const noexcept { return body_.get(); }

 private:
  std::unique_ptr<Expression> condition_;
  std::unique_ptr<Statement> body_;
};

} // namespace ast
} // namespace syntactic_analysis
} // namespace acc

#endif // ACC_SYNTACTIC_ANALYSIS_AST_WHILE_STATEMENT_H_