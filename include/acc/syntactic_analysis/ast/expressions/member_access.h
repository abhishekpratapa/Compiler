#ifndef ACC_SYNTACTIC_ANALYSIS_AST_EXPRESSIONS_MEMBER_ACCESS_H_
#define ACC_SYNTACTIC_ANALYSIS_AST_EXPRESSIONS_MEMBER_ACCESS_H_

#include <memory>
#include <string>
#include "acc/syntactic_analysis/ast/expressions/expression.h"

namespace acc {
namespace syntactic_analysis {
namespace ast {

class MemberAccess final : public Expression {
 public:
  MemberAccess(std::unique_ptr<Expression> struct_or_union,
               std::string member_name,
               const common::SourceLocation& location) noexcept;

  void Accept(ASTVisitor& visitor) const override;

  const Expression* GetStructOrUnion() const noexcept { return struct_or_union_.get(); }
  const std::string& GetMemberName() const noexcept { return member_name_; }

  const type_system::Type* GetType() const noexcept override;

 private:
  std::unique_ptr<Expression> struct_or_union_;
  std::string member_name_;
  mutable std::shared_ptr<type_system::Type> cached_type_;
};

} // namespace ast
} // namespace syntactic_analysis
} // namespace acc

#endif // ACC_SYNTACTIC_ANALYSIS_AST_MEMBER_ACCESS_H_