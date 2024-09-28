#ifndef ACC_SYNTACTIC_ANALYSIS_AST_VARIABLE_DECLARATION_H_
#define ACC_SYNTACTIC_ANALYSIS_AST_VARIABLE_DECLARATION_H_

#include <memory>
#include <string>
#include "acc/syntactic_analysis/ast/declarations/declaration.h"
#include "acc/syntactic_analysis/ast/expressions/expression.h"
#include "acc/type_system/type.h"

namespace acc {
namespace syntactic_analysis {
namespace ast {

class VariableDeclaration final : public Declaration {
 public:
  VariableDeclaration(std::shared_ptr<type_system::Type> type,
                      std::string name,
                      std::unique_ptr<Expression> initializer,
                      const common::SourceLocation& location) noexcept;

  void Accept(ASTVisitor& visitor) const override;

  const type_system::Type* GetDeclaredType() const noexcept override { return type_.get(); }
  const std::string& GetName() const noexcept override { return name_; }
  const Expression* GetInitializer() const noexcept { return initializer_.get(); }

 private:
  std::shared_ptr<type_system::Type> type_;
  std::string name_;
  std::unique_ptr<Expression> initializer_;
};

} // namespace ast
} // namespace syntactic_analysis
} // namespace acc

#endif // ACC_SYNTACTIC_ANALYSIS_AST_VARIABLE_DECLARATION_H_