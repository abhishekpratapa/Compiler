#ifndef ACC_SYNTACTIC_ANALYSIS_AST_EXTERNAL_DECLARATION_H_
#define ACC_SYNTACTIC_ANALYSIS_AST_EXTERNAL_DECLARATION_H_

#include <memory>
#include "acc/syntactic_analysis/ast/common/ast_node.h"

namespace acc {
namespace syntactic_analysis {
namespace ast {

class Declaration;
class FunctionDefinition;

class ExternalDeclaration final : public ASTNode {
 public:
  explicit ExternalDeclaration(std::unique_ptr<Declaration> declaration,
                               const common::SourceLocation& location) noexcept;
  explicit ExternalDeclaration(std::unique_ptr<FunctionDefinition> function_definition,
                               const common::SourceLocation& location) noexcept;

  void Accept(ASTVisitor& visitor) const override;

  bool IsDeclaration() const noexcept { return declaration_ != nullptr; }
  bool IsFunctionDefinition() const noexcept { return function_definition_ != nullptr; }
  const Declaration* GetDeclaration() const noexcept { return declaration_.get(); }
  const FunctionDefinition* GetFunctionDefinition() const noexcept { return function_definition_.get(); }

 private:
  std::unique_ptr<Declaration> declaration_;
  std::unique_ptr<FunctionDefinition> function_definition_;
};

} // namespace ast
} // namespace syntactic_analysis
} // namespace acc

#endif // ACC_SYNTACTIC_ANALYSIS_AST_EXTERNAL_DECLARATION_H_