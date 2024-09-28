#ifndef ACC_SYNTACTIC_ANALYSIS_AST_STATEMENTS_GOTO_STATEMENT_H_
#define ACC_SYNTACTIC_ANALYSIS_AST_STATEMENTS_GOTO_STATEMENT_H_

#include <string>
#include "acc/syntactic_analysis/ast/statements/statement.h"

namespace acc {
namespace syntactic_analysis {
namespace ast {

class GotoStatement final : public Statement {
 public:
  GotoStatement(std::string label_name,
                const common::SourceLocation& location) noexcept;

  void Accept(ASTVisitor& visitor) const override;

  const std::string& GetLabelName() const noexcept { return label_name_; }

 private:
  std::string label_name_;
};

} // namespace ast
} // namespace syntactic_analysis
} // namespace acc

#endif // ACC_SYNTACTIC_ANALYSIS_AST_GOTO_STATEMENT_H_