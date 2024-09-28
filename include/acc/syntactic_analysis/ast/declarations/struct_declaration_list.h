#ifndef ACC_SYNTACTIC_ANALYSIS_AST_STRUCT_DECLARATION_LIST_H_
#define ACC_SYNTACTIC_ANALYSIS_AST_STRUCT_DECLARATION_LIST_H_

#include <memory>
#include <vector>
#include "acc/syntactic_analysis/ast/common/ast_node.h"

namespace acc {
namespace syntactic_analysis {
namespace ast {

class Declaration;

class StructDeclarationList final : public ASTNode {
 public:
  StructDeclarationList(std::vector<std::unique_ptr<Declaration>> declarations,
                        const common::SourceLocation& location) noexcept;

  void Accept(ASTVisitor& visitor) const override;

  const std::vector<std::unique_ptr<Declaration>>& GetDeclarations() const noexcept { return declarations_; }

 private:
  std::vector<std::unique_ptr<Declaration>> declarations_;
};

} // namespace ast
} // namespace syntactic_analysis
} // namespace acc

#endif // ACC_SYNTACTIC_ANALYSIS_AST_STRUCT_DECLARATION_LIST_H_