#ifndef ACC_SYNTACTIC_ANALYSIS_AST_STATEMENTS_IF_STATEMENT_H_
#define ACC_SYNTACTIC_ANALYSIS_AST_STATEMENTS_IF_STATEMENT_H_

#include <memory>
#include "acc/syntactic_analysis/ast/statements/statement.h"

namespace acc {
namespace syntactic_analysis {
namespace ast {

class Expression;

class IfStatement final : public Statement {
 public:
  IfStatement(std::unique_ptr<Expression> condition,
              std::unique_ptr<Statement> if_block,
              std::unique_ptr<Statement> else_block,
              const common::SourceLocation& location) noexcept;

  void Accept(ASTVisitor& visitor) const override;

  const Expression* GetCondition() const noexcept { return condition_.get(); }
  const Statement* GetIfBlock() const noexcept { return if_block_.get(); }
  const Statement* GetElseBlock() const noexcept { return else_block_.get(); }

 private:
  std::unique_ptr<Expression> condition_;
  std::unique_ptr<Statement> if_block_;
  std::unique_ptr<Statement> else_block_;
};

} // namespace ast
} // namespace syntactic_analysis
} // namespace acc

#endif // ACC_SYNTACTIC_ANALYSIS_AST_IF_STATEMENT_H_