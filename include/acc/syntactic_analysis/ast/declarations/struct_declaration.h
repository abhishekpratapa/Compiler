#ifndef ACC_SYNTACTIC_ANALYSIS_AST_STRUCT_DECLARATION_H_
#define ACC_SYNTACTIC_ANALYSIS_AST_STRUCT_DECLARATION_H_

#include <memory>
#include <string>
#include <vector>
#include "acc/syntactic_analysis/ast/declarations/declaration.h"
#include "acc/type_system/type.h"

namespace acc {
namespace syntactic_analysis {
namespace ast {

class StructDeclaration final : public Declaration {
 public:
  StructDeclaration(std::shared_ptr<type_system::StructType> type,
                    std::string name,
                    std::vector<std::unique_ptr<Declaration>> members,
                    const common::SourceLocation& location) noexcept;

  void Accept(ASTVisitor& visitor) const override;

  const type_system::StructType* GetDeclaredType() const noexcept override { return type_.get(); }
  const std::string& GetName() const noexcept override { return name_; }
  const std::vector<std::unique_ptr<Declaration>>& GetMembers() const noexcept { return members_; }

 private:
  std::shared_ptr<type_system::StructType> type_;
  std::string name_;
  std::vector<std::unique_ptr<Declaration>> members_;
};

} // namespace ast
} // namespace syntactic_analysis
} // namespace acc

#endif // ACC_SYNTACTIC_ANALYSIS_AST_STRUCT_DECLARATION_H_