#ifndef ACC_SYNTACTIC_ANALYSIS_AST_STATEMENTS_LABEL_STATEMENT_H_
#define ACC_SYNTACTIC_ANALYSIS_AST_STATEMENTS_LABEL_STATEMENT_H_

#include <memory>
#include <string>
#include "acc/syntactic_analysis/ast/statements/statement.h"

namespace acc {
namespace syntactic_analysis {
namespace ast {

class LabelStatement final : public Statement {
 public:
  LabelStatement(std::string label_name,
                 std::unique_ptr<Statement> statement,
                 const common::SourceLocation& location) noexcept;

  void Accept(ASTVisitor& visitor) const override;

  const std::string& GetLabelName() const noexcept { return label_name_; }
  const Statement* GetStatement() const noexcept { return statement_.get(); }

 private:
  std::string label_name_;
  std::unique_ptr<Statement> statement_;
};

} // namespace ast
} // namespace syntactic_analysis
} // namespace acc

#endif // ACC_SYNTACTIC_ANALYSIS_AST_LABEL_STATEMENT_H_