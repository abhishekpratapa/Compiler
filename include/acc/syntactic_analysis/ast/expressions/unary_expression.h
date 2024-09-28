#ifndef ACC_SYNTACTIC_ANALYSIS_AST_EXPRESSIONS_UNARY_EXPRESSION_H_
#define ACC_SYNTACTIC_ANALYSIS_AST_EXPRESSIONS_UNARY_EXPRESSION_H_

#include <memory>
#include "acc/lexical_analysis/token.h"
#include "acc/syntactic_analysis/ast/expressions/expression.h"
#include "acc/common/source_location.h"

namespace acc {
namespace syntactic_analysis {
namespace ast {

class UnaryExpression final : public Expression {
 public:
  UnaryExpression(lexical_analysis::Token::Type op,
                  std::unique_ptr<Expression> operand,
                  const common::SourceLocation& location) noexcept;

  void Accept(ASTVisitor& visitor) const override;

  lexical_analysis::Token::Type GetOperator() const noexcept { return op_; }
  const Expression& GetOperand() const noexcept { return *operand_; }

  const type_system::Type* GetType() const noexcept override;

 private:
  lexical_analysis::Token::Type op_;
  std::unique_ptr<Expression> operand_;
  mutable std::shared_ptr<type_system::Type> cached_type_;
};

} // namespace ast
} // namespace syntactic_analysis
} // namespace acc

#endif // ACC_SYNTACTIC_ANALYSIS_AST_UNARY_EXPRESSION_H_