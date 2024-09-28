#ifndef ACC_SYNTACTIC_ANALYSIS_AST_STATEMENTS_FOR_STATEMENT_H_
#define ACC_SYNTACTIC_ANALYSIS_AST_STATEMENTS_FOR_STATEMENT_H_

#include <memory>
#include "acc/syntactic_analysis/ast/statements/statement.h"
#include "acc/syntactic_analysis/ast/expressions/expression.h"

namespace acc {
namespace syntactic_analysis {
namespace ast {

class ForStatement final : public Statement {
 public:
  ForStatement(std::unique_ptr<Statement> initialization,
               std::unique_ptr<Expression> condition,
               std::unique_ptr<Expression> increment,
               std::unique_ptr<Statement> body,
               const common::SourceLocation& location) noexcept;

  void Accept(ASTVisitor& visitor) const override;

  const Statement* GetInitialization() const noexcept { return initialization_.get(); }
  const Expression* GetCondition() const noexcept { return condition_.get(); }
  const Expression* GetIncrement() const noexcept { return increment_.get(); }
  const Statement* GetBody() const noexcept { return body_.get(); }

 private:
  std::unique_ptr<Statement> initialization_;
  std::unique_ptr<Expression> condition_;
  std::unique_ptr<Expression> increment_;
  std::unique_ptr<Statement> body_;
};

} // namespace ast
} // namespace syntactic_analysis
} // namespace acc

#endif // ACC_SYNTACTIC_ANALYSIS_AST_FOR_STATEMENT_H_