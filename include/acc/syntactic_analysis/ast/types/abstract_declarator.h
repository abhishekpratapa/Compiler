#ifndef ACC_SYNTACTIC_ANALYSIS_AST_TYPES_ABSTRACT_DECLARATOR_H_
#define ACC_SYNTACTIC_ANALYSIS_AST_TYPES_ABSTRACT_DECLARATOR_H_

#include <memory>
#include "acc/syntactic_analysis/ast/common/ast_node.h"
#include "acc/type_system/type.h"

namespace acc {
namespace syntactic_analysis {
namespace ast {

class DirectAbstractDeclarator;

class AbstractDeclarator final : public ASTNode {
 public:
  AbstractDeclarator(std::shared_ptr<type_system::Type> base_type,
                     std::unique_ptr<DirectAbstractDeclarator> direct_declarator,
                     const common::SourceLocation& location) noexcept;

  void Accept(ASTVisitor& visitor) const override;

  const type_system::Type* GetBaseType() const noexcept { return base_type_.get(); }
  const DirectAbstractDeclarator* GetDirectDeclarator() const noexcept { return direct_declarator_.get(); }

 private:
  std::shared_ptr<type_system::Type> base_type_;
  std::unique_ptr<DirectAbstractDeclarator> direct_declarator_;
};

} // namespace ast
} // namespace syntactic_analysis
} // namespace acc

#endif // ACC_SYNTACTIC_ANALYSIS_AST_ABSTRACT_DECLARATOR_H_