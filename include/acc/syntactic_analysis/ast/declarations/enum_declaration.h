#ifndef ACC_SYNTACTIC_ANALYSIS_AST_ENUM_DECLARATION_H_
#define ACC_SYNTACTIC_ANALYSIS_AST_ENUM_DECLARATION_H_

#include <memory>
#include <string>
#include <vector>
#include "acc/syntactic_analysis/ast/declarations/declaration.h"
#include "acc/syntactic_analysis/ast/expressions/expression.h"
#include "acc/type_system/type.h"

namespace acc {
namespace syntactic_analysis {
namespace ast {

class EnumDeclaration final : public Declaration {
 public:
  struct Enumerator {
    std::string name;
    std::unique_ptr<Expression> value;
  };

  EnumDeclaration(std::shared_ptr<type_system::EnumType> type,
                  std::string name,
                  std::vector<Enumerator> enumerators,
                  const common::SourceLocation& location) noexcept;

  void Accept(ASTVisitor& visitor) const override;

  const type_system::EnumType* GetDeclaredType() const noexcept override { return type_.get(); }
  const std::string& GetName() const noexcept override { return name_; }
  const std::vector<Enumerator>& GetEnumerators() const noexcept { return enumerators_; }

 private:
  std::shared_ptr<type_system::EnumType> type_;
  std::string name_;
  std::vector<Enumerator> enumerators_;
};

} // namespace ast
} // namespace syntactic_analysis
} // namespace acc

#endif // ACC_SYNTACTIC_ANALYSIS_AST_ENUM_DECLARATION_H_