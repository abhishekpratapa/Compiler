#ifndef ACC_SYNTACTIC_ANALYSIS_AST_EXPRESSIONS_INITIALIZER_H_
#define ACC_SYNTACTIC_ANALYSIS_AST_EXPRESSIONS_INITIALIZER_H_

#include <memory>
#include "acc/syntactic_analysis/ast/expressions/expression.h"

namespace acc {
namespace syntactic_analysis {
namespace ast {

class InitializerList;

class Initializer final : public Expression {
 public:
  Initializer(std::unique_ptr<Expression> expression,
              const common::SourceLocation& location) noexcept;
  Initializer(std::unique_ptr<InitializerList> initializer_list,
              const common::SourceLocation& location) noexcept;

  void Accept(ASTVisitor& visitor) const override;

  bool IsExpression() const noexcept { return is_expression_; }
  const Expression* GetExpression() const noexcept { return expression_.get(); }
  const InitializerList* GetInitializerList() const noexcept { return initializer_list_.get(); }

  const type_system::Type* GetType() const noexcept override;

 private:
  bool is_expression_;
  std::unique_ptr<Expression> expression_;
  std::unique_ptr<InitializerList> initializer_list_;
  mutable std::shared_ptr<type_system::Type> cached_type_;
};

} // namespace ast
} // namespace syntactic_analysis
} // namespace acc

#endif // ACC_SYNTACTIC_ANALYSIS_AST_INITIALIZER_H_