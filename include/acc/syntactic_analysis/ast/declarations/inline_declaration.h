#ifndef ACC_SYNTACTIC_ANALYSIS_AST_INLINE_DECLARATION_H_
#define ACC_SYNTACTIC_ANALYSIS_AST_INLINE_DECLARATION_H_

#include <memory>
#include "acc/syntactic_analysis/ast/declarations/declaration.h"

namespace acc {
namespace syntactic_analysis {
namespace ast {

class FunctionDeclaration;

class InlineDeclaration final : public Declaration {
 public:
  InlineDeclaration(std::unique_ptr<FunctionDeclaration> function_declaration,
                    const common::SourceLocation& location) noexcept;

  void Accept(ASTVisitor& visitor) const override;

  const FunctionDeclaration* GetFunctionDeclaration() const noexcept { return function_declaration_.get(); }

  // Implement Declaration interface
  const type_system::Type* GetDeclaredType() const noexcept override;
  const std::string& GetName() const noexcept override;

 private:
  std::unique_ptr<FunctionDeclaration> function_declaration_;
};

} // namespace ast
} // namespace syntactic_analysis
} // namespace acc

#endif // ACC_SYNTACTIC_ANALYSIS_AST_INLINE_DECLARATION_H_