#ifndef ACC_SYNTACTIC_ANALYSIS_AST_EXPRESSIONS_CAST_EXPRESSION_H_
#define ACC_SYNTACTIC_ANALYSIS_AST_EXPRESSIONS_CAST_EXPRESSION_H_

#include <memory>
#include "acc/syntactic_analysis/ast/expressions/expression.h"
#include "acc/type_system/type.h"

namespace acc {
namespace syntactic_analysis {
namespace ast {

class CastExpression final : public Expression {
 public:
  CastExpression(std::shared_ptr<type_system::Type> target_type,
                 std::unique_ptr<Expression> expression,
                 const common::SourceLocation& location) noexcept;

  void Accept(ASTVisitor& visitor) const override;

  const type_system::Type* GetTargetType() const noexcept { return target_type_.get(); }
  const Expression* GetExpression() const noexcept { return expression_.get(); }

  const type_system::Type* GetType() const noexcept override { return target_type_.get(); }

 private:
  std::shared_ptr<type_system::Type> target_type_;
  std::unique_ptr<Expression> expression_;
};

} // namespace ast
} // namespace syntactic_analysis
} // namespace acc

#endif // ACC_SYNTACTIC_ANALYSIS_AST_CAST_EXPRESSION_H_