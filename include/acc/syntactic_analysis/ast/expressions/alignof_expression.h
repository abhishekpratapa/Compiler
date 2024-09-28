#ifndef ACC_SYNTACTIC_ANALYSIS_AST_EXPRESSIONS_ALIGNOF_EXPRESSION_H_
#define ACC_SYNTACTIC_ANALYSIS_AST_EXPRESSIONS_ALIGNOF_EXPRESSION_H_

#include <memory>
#include "acc/syntactic_analysis/ast/expressions/expression.h"
#include "acc/type_system/type.h"

namespace acc {
namespace syntactic_analysis {
namespace ast {

class AlignofExpression final : public Expression {
 public:
  AlignofExpression(std::shared_ptr<type_system::Type> type,
                    std::unique_ptr<Expression> expression,
                    const common::SourceLocation& location) noexcept;

  void Accept(ASTVisitor& visitor) const override;

  const type_system::Type* GetArgumentType() const noexcept { return type_.get(); }
  const Expression* GetExpression() const noexcept { return expression_.get(); }

  const type_system::Type* GetType() const noexcept override;

 private:
  std::shared_ptr<type_system::Type> type_;
  std::unique_ptr<Expression> expression_;
  mutable std::shared_ptr<type_system::Type> cached_result_type_;
};

} // namespace ast
} // namespace syntactic_analysis
} // namespace acc

#endif // ACC_SYNTACTIC_ANALYSIS_AST_ALIGNOF_EXPRESSION_H_