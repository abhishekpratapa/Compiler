#ifndef ACC_SYNTACTIC_ANALYSIS_AST_STATEMENTS_CASE_STATEMENT_H_
#define ACC_SYNTACTIC_ANALYSIS_AST_STATEMENTS_CASE_STATEMENT_H_

#include <memory>
#include "acc/syntactic_analysis/ast/statements/statement.h"
#include "acc/syntactic_analysis/ast/expressions/expression.h"

namespace acc {
namespace syntactic_analysis {
namespace ast {

class CaseStatement final : public Statement {
 public:
  CaseStatement(std::unique_ptr<Expression> case_value,
                std::unique_ptr<Statement> statement,
                const common::SourceLocation& location) noexcept;

  void Accept(ASTVisitor& visitor) const override;

  const Expression* GetCaseValue() const noexcept { return case_value_.get(); }
  const Statement* GetStatement() const noexcept { return statement_.get(); }

 private:
  std::unique_ptr<Expression> case_value_;
  std::unique_ptr<Statement> statement_;
};

} // namespace ast
} // namespace syntactic_analysis
} // namespace acc

#endif // ACC_SYNTACTIC_ANALYSIS_AST_CASE_STATEMENT_H_