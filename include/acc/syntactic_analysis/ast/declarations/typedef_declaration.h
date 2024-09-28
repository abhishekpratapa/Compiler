#ifndef ACC_SYNTACTIC_ANALYSIS_AST_TYPEDEF_DECLARATION_H_
#define ACC_SYNTACTIC_ANALYSIS_AST_TYPEDEF_DECLARATION_H_

#include <memory>
#include <string>
#include "acc/syntactic_analysis/ast/declarations/declaration.h"
#include "acc/type_system/type.h"

namespace acc {
namespace syntactic_analysis {
namespace ast {

class TypedefDeclaration final : public Declaration {
 public:
  TypedefDeclaration(std::shared_ptr<type_system::TypedefType> type,
                     const common::SourceLocation& location) noexcept;

  void Accept(ASTVisitor& visitor) const override;

  const type_system::TypedefType* GetDeclaredType() const noexcept override { return type_.get(); }
  const std::string& GetName() const noexcept override { return type_->GetName(); }

 private:
  std::shared_ptr<type_system::TypedefType> type_;
};

} // namespace ast
} // namespace syntactic_analysis
} // namespace acc

#endif // ACC_SYNTACTIC_ANALYSIS_AST_TYPEDEF_DECLARATION_H_