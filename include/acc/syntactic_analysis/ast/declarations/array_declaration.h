#ifndef ACC_SYNTACTIC_ANALYSIS_AST_ARRAY_DECLARATION_H_
#define ACC_SYNTACTIC_ANALYSIS_AST_ARRAY_DECLARATION_H_

#include <memory>
#include <string>
#include "acc/syntactic_analysis/ast/declarations/declaration.h"
#include "acc/type_system/type.h"

namespace acc {
namespace syntactic_analysis {
namespace ast {

class ArrayDeclaration final : public Declaration {
 public:
  ArrayDeclaration(std::shared_ptr<type_system::ArrayType> type,
                   std::string name,
                   const common::SourceLocation& location) noexcept;

  void Accept(ASTVisitor& visitor) const override;

  const type_system::ArrayType* GetDeclaredType() const noexcept override { return type_.get(); }
  const std::string& GetName() const noexcept override { return name_; }

 private:
  std::shared_ptr<type_system::ArrayType> type_;
  std::string name_;
};

} // namespace ast
} // namespace syntactic_analysis
} // namespace acc

#endif // ACC_SYNTACTIC_ANALYSIS_AST_ARRAY_DECLARATION_H_