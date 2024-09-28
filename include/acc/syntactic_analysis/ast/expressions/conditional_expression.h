#ifndef ACC_SYNTACTIC_ANALYSIS_AST_EXPRESSIONS_CONDITIONAL_EXPRESSION_H_
#define ACC_SYNTACTIC_ANALYSIS_AST_EXPRESSIONS_CONDITIONAL_EXPRESSION_H_

#include <memory>
#include "acc/syntactic_analysis/ast/expressions/expression.h"

namespace acc {
namespace syntactic_analysis {
namespace ast {

class ConditionalExpression final : public Expression {
 public:
  ConditionalExpression(std::unique_ptr<Expression> condition,
                        std::unique_ptr<Expression> true_expr,
                        std::unique_ptr<Expression> false_expr,
                        const common::SourceLocation& location) noexcept;

  void Accept(ASTVisitor& visitor) const override;

  const Expression* GetCondition() const noexcept { return condition_.get(); }
  const Expression* GetTrueExpression() const noexcept { return true_expr_.get(); }
  const Expression* GetFalseExpression() const noexcept { return false_expr_.get(); }

  const type_system::Type* GetType() const noexcept override;

 private:
  std::unique_ptr<Expression> condition_;
  std::unique_ptr<Expression> true_expr_;
  std::unique_ptr<Expression> false_expr_;
  mutable std::shared_ptr<type_system::Type> cached_type_;
};

} // namespace ast
} // namespace syntactic_analysis
} // namespace acc

#endif // ACC_SYNTACTIC_ANALYSIS_AST_CONDITIONAL_EXPRESSION_H_