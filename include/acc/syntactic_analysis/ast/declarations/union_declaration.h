#ifndef ACC_SYNTACTIC_ANALYSIS_AST_UNION_DECLARATION_H_
#define ACC_SYNTACTIC_ANALYSIS_AST_UNION_DECLARATION_H_

#include <memory>
#include <string>
#include <vector>
#include "acc/syntactic_analysis/ast/declarations/declaration.h"
#include "acc/type_system/type.h"

namespace acc {
namespace syntactic_analysis {
namespace ast {

class UnionDeclaration final : public Declaration {
 public:
  struct Member {
    std::string name;
    std::shared_ptr<type_system::Type> type;
  };

  UnionDeclaration(std::shared_ptr<type_system::UnionType> type,
                   std::string name,
                   std::vector<Member> members,
                   const common::SourceLocation& location) noexcept;

  void Accept(ASTVisitor& visitor) const override;

  const type_system::UnionType* GetDeclaredType() const noexcept override { return type_.get(); }
  const std::string& GetName() const noexcept override { return name_; }
  const std::vector<Member>& GetMembers() const noexcept { return members_; }

 private:
  std::shared_ptr<type_system::UnionType> type_;
  std::string name_;
  std::vector<Member> members_;
};

} // namespace ast
} // namespace syntactic_analysis
} // namespace acc

#endif // ACC_SYNTACTIC_ANALYSIS_AST_UNION_DECLARATION_H_