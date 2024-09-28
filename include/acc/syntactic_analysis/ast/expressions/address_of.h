#ifndef ACC_SYNTACTIC_ANALYSIS_AST_EXPRESSIONS_ADDRESS_OF_H_
#define ACC_SYNTACTIC_ANALYSIS_AST_EXPRESSIONS_ADDRESS_OF_H_

#include <memory>
#include "acc/syntactic_analysis/ast/expressions/expression.h"

namespace acc {
namespace syntactic_analysis {
namespace ast {

class AddressOf final : public Expression {
 public:
  explicit AddressOf(std::unique_ptr<Expression> operand,
                     const common::SourceLocation& location) noexcept;

  void Accept(ASTVisitor& visitor) const override;

  const Expression* GetOperand() const noexcept { return operand_.get(); }
  const type_system::Type* GetType() const noexcept override;

 private:
  std::unique_ptr<Expression> operand_;
  mutable std::shared_ptr<type_system::Type> cached_type_;
};

} // namespace ast
} // namespace syntactic_analysis
} // namespace acc

#endif // ACC_SYNTACTIC_ANALYSIS_AST_ADDRESS_OF_H_