#ifndef ACC_SYNTACTIC_ANALYSIS_AST_EXPRESSIONS_FUNCTION_CALL_H_
#define ACC_SYNTACTIC_ANALYSIS_AST_EXPRESSIONS_FUNCTION_CALL_H_

#include <memory>
#include <vector>
#include "acc/syntactic_analysis/ast/expressions/expression.h"

namespace acc {
namespace syntactic_analysis {
namespace ast {

class FunctionCall final : public Expression {
 public:
  FunctionCall(std::unique_ptr<Expression> function,
               std::vector<std::unique_ptr<Expression>> arguments,
               const common::SourceLocation& location) noexcept;

  void Accept(ASTVisitor& visitor) const override;

  const Expression* GetFunction() const noexcept { return function_.get(); }
  const std::vector<std::unique_ptr<Expression>>& GetArguments() const noexcept { return arguments_; }

  const type_system::Type* GetType() const noexcept override;

 private:
  std::unique_ptr<Expression> function_;
  std::vector<std::unique_ptr<Expression>> arguments_;
  mutable std::shared_ptr<type_system::Type> cached_type_;
};

} // namespace ast
} // namespace syntactic_analysis
} // namespace acc

#endif // ACC_SYNTACTIC_ANALYSIS_AST_FUNCTION_CALL_H_