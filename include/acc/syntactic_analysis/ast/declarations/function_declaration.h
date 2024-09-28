#ifndef ACC_SYNTACTIC_ANALYSIS_AST_FUNCTION_DECLARATION_H_
#define ACC_SYNTACTIC_ANALYSIS_AST_FUNCTION_DECLARATION_H_

#include <memory>
#include <string>
#include <vector>
#include "acc/syntactic_analysis/ast/declarations/declaration.h"
#include "acc/type_system/type.h"

namespace acc {
namespace syntactic_analysis {
namespace ast {

class FunctionDeclaration final : public Declaration {
 public:
  FunctionDeclaration(std::shared_ptr<type_system::FunctionType> type,
                      std::string name,
                      std::vector<std::unique_ptr<ASTNode>> parameters,
                      std::unique_ptr<ASTNode> body,
                      const common::SourceLocation& location) noexcept;

  void Accept(ASTVisitor& visitor) const override;

  const type_system::FunctionType* GetType() const noexcept { return type_.get(); }
  const std::string& GetName() const noexcept override { return name_; }
  const std::vector<std::unique_ptr<ASTNode>>& GetParameters() const noexcept { return parameters_; }
  const ASTNode* GetBody() const noexcept { return body_.get(); }

  const type_system::Type* GetDeclaredType() const noexcept override { return type_.get(); }

 private:
  std::shared_ptr<type_system::FunctionType> type_;
  std::string name_;
  std::vector<std::unique_ptr<ASTNode>> parameters_;
  std::unique_ptr<ASTNode> body_;
};

} // namespace ast
} // namespace syntactic_analysis
} // namespace acc

#endif // ACC_SYNTACTIC_ANALYSIS_AST_FUNCTION_DECLARATION_H_