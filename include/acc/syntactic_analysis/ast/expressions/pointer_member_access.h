#ifndef ACC_SYNTACTIC_ANALYSIS_AST_EXPRESSIONS_POINTER_MEMBER_ACCESS_H_
#define ACC_SYNTACTIC_ANALYSIS_AST_EXPRESSIONS_POINTER_MEMBER_ACCESS_H_

#include <memory>
#include <string>
#include "acc/syntactic_analysis/ast/expressions/expression.h"

namespace acc {
namespace syntactic_analysis {
namespace ast {

class PointerMemberAccess final : public Expression {
 public:
  PointerMemberAccess(std::unique_ptr<Expression> pointer,
                      std::string member_name,
                      const common::SourceLocation& location) noexcept;

  void Accept(ASTVisitor& visitor) const override;

  const Expression* GetPointer() const noexcept { return pointer_.get(); }
  const std::string& GetMemberName() const noexcept { return member_name_; }

  const type_system::Type* GetType() const noexcept override;

 private:
  std::unique_ptr<Expression> pointer_;
  std::string member_name_;
  mutable std::shared_ptr<type_system::Type> cached_type_;
};

} // namespace ast
} // namespace syntactic_analysis
} // namespace acc

#endif // ACC_SYNTACTIC_ANALYSIS_AST_POINTER_MEMBER_ACCESS_H_