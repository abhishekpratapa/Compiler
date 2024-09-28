#ifndef ACC_SYNTACTIC_ANALYSIS_AST_EXPRESSIONS_COMMA_EXPRESSION_H_
#define ACC_SYNTACTIC_ANALYSIS_AST_EXPRESSIONS_COMMA_EXPRESSION_H_

#include <memory>
#include <vector>
#include "acc/syntactic_analysis/ast/expressions/expression.h"

namespace acc {
namespace syntactic_analysis {
namespace ast {

class CommaExpression final : public Expression {
 public:
  explicit CommaExpression(std::vector<std::unique_ptr<Expression>> expressions,
                           const common::SourceLocation& location) noexcept;

  void Accept(ASTVisitor& visitor) const override;

  const std::vector<std::unique_ptr<Expression>>& GetExpressions() const noexcept { return expressions_; }

  const type_system::Type* GetType() const noexcept override;

 private:
  std::vector<std::unique_ptr<Expression>> expressions_;
  mutable std::shared_ptr<type_system::Type> cached_type_;
};

} // namespace ast
} // namespace syntactic_analysis
} // namespace acc

#endif // ACC_SYNTACTIC_ANALYSIS_AST_COMMA_EXPRESSION_H_