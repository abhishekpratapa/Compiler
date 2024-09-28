#ifndef ACC_SYNTACTIC_ANALYSIS_AST_STATEMENTS_COMPOUND_STATEMENT_H_
#define ACC_SYNTACTIC_ANALYSIS_AST_STATEMENTS_COMPOUND_STATEMENT_H_

#include <memory>
#include <vector>
#include "acc/syntactic_analysis/ast/statements/statement.h"

namespace acc {
namespace syntactic_analysis {
namespace ast {

class CompoundStatement final : public Statement {
 public:
  CompoundStatement(std::vector<std::unique_ptr<Statement>> statements,
                    const common::SourceLocation& location) noexcept;

  void Accept(ASTVisitor& visitor) const override;

  const std::vector<std::unique_ptr<Statement>>& GetStatements() const noexcept { return statements_; }

 private:
  std::vector<std::unique_ptr<Statement>> statements_;
};

} // namespace ast
} // namespace syntactic_analysis
} // namespace acc

#endif // ACC_SYNTACTIC_ANALYSIS_AST_COMPOUND_STATEMENT_H_