#ifndef ACC_SYNTACTIC_ANALYSIS_AST_TYPES_SPECIFIER_QUALIFIER_LIST_H_
#define ACC_SYNTACTIC_ANALYSIS_AST_TYPES_SPECIFIER_QUALIFIER_LIST_H_

#include <memory>
#include <vector>
#include "acc/syntactic_analysis/ast/common/ast_node.h"

namespace acc {
namespace syntactic_analysis {
namespace ast {

class TypeSpecifier;
class TypeQualifier;

class SpecifierQualifierList final : public ASTNode {
 public:
  SpecifierQualifierList(std::vector<std::unique_ptr<ASTNode>> specifiers_and_qualifiers,
                         const common::SourceLocation& location) noexcept;

  void Accept(ASTVisitor& visitor) const override;

  const std::vector<std::unique_ptr<ASTNode>>& GetSpecifiersAndQualifiers() const noexcept {
    return specifiers_and_qualifiers_;
  }

 private:
  std::vector<std::unique_ptr<ASTNode>> specifiers_and_qualifiers_;
};

} // namespace ast
} // namespace syntactic_analysis
} // namespace acc

#endif // ACC_SYNTACTIC_ANALYSIS_AST_SPECIFIER_QUALIFIER_LIST_H_