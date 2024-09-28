#ifndef ACC_SYNTACTIC_ANALYSIS_AST_EXPRESSIONS_BINARY_EXPRESSION_H_
#define ACC_SYNTACTIC_ANALYSIS_AST_EXPRESSIONS_BINARY_EXPRESSION_H_

#include <memory>
#include <string>
#include "acc/lexical_analysis/token.h"
#include "acc/syntactic_analysis/ast/expressions/expression.h"

namespace acc {
namespace syntactic_analysis {
namespace ast {

class BinaryExpression final : public Expression {
 public:
  BinaryExpression(std::unique_ptr<Expression> left,
                   lexical_analysis::Token::Type op,
                   std::string op_value,
                   std::unique_ptr<Expression> right,
                   const common::SourceLocation& location) noexcept;

  void Accept(ASTVisitor& visitor) const override;

  lexical_analysis::Token::Type GetOperator() const noexcept { return op_; }
  const Expression& GetLeft() const noexcept { return *left_; }
  const Expression& GetRight() const noexcept { return *right_; }
  const std::string& GetOperatorValue() const noexcept { return op_value_; }

  const type_system::Type* GetType() const noexcept override;

 private:
  std::unique_ptr<Expression> left_;
  lexical_analysis::Token::Type op_;
  std::string op_value_;
  std::unique_ptr<Expression> right_;
  mutable std::shared_ptr<type_system::Type> cached_type_;
};

} // namespace ast
} // namespace syntactic_analysis
} // namespace acc

#endif // ACC_SYNTACTIC_ANALYSIS_AST_BINARY_EXPRESSION_H_