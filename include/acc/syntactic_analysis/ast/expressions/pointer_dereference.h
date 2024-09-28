#ifndef ACC_SYNTACTIC_ANALYSIS_AST_EXPRESSIONS_POINTER_DEREFERENCE_H_
#define ACC_SYNTACTIC_ANALYSIS_AST_EXPRESSIONS_POINTER_DEREFERENCE_H_

#include <memory>
#include "acc/syntactic_analysis/ast/expressions/expression.h"

namespace acc {
namespace syntactic_analysis {
namespace ast {

class PointerDereference final : public Expression {
 public:
  PointerDereference(std::unique_ptr<Expression> pointer,
                     const common::SourceLocation& location) noexcept;

  void Accept(ASTVisitor& visitor) const override;

  const Expression* GetPointer() const noexcept { return pointer_.get(); }
  const type_system::Type* GetType() const noexcept override;

 private:
  std::unique_ptr<Expression> pointer_;
  mutable std::shared_ptr<type_system::Type> cached_type_;
};

} // namespace ast
} // namespace syntactic_analysis
} // namespace acc

#endif // ACC_SYNTACTIC_ANALYSIS_AST_POINTER_DEREFERENCE_H_