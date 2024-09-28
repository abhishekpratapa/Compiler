#ifndef ACC_SYNTACTIC_ANALYSIS_AST_STATEMENTS_DEFAULT_STATEMENT_H_
#define ACC_SYNTACTIC_ANALYSIS_AST_STATEMENTS_DEFAULT_STATEMENT_H_

#include <memory>
#include "acc/syntactic_analysis/ast/statements/statement.h"

namespace acc {
namespace syntactic_analysis {
namespace ast {

class DefaultStatement final : public Statement {
 public:
  DefaultStatement(std::unique_ptr<Statement> statement,
                   const common::SourceLocation& location) noexcept;

  void Accept(ASTVisitor& visitor) const override;

  const Statement* GetStatement() const noexcept { return statement_.get(); }

 private:
  std::unique_ptr<Statement> statement_;
};

} // namespace ast
} // namespace syntactic_analysis
} // namespace acc

#endif // ACC_SYNTACTIC_ANALYSIS_AST_DEFAULT_STATEMENT_H_