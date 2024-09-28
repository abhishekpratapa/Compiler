#ifndef ACC_SYNTACTIC_ANALYSIS_AST_TYPES_TYPE_NAME_H_
#define ACC_SYNTACTIC_ANALYSIS_AST_TYPES_TYPE_NAME_H_

#include <memory>
#include "acc/syntactic_analysis/ast/common/ast_node.h"
#include "acc/type_system/type.h"

namespace acc {
namespace syntactic_analysis {
namespace ast {

class AbstractDeclarator;

class TypeName final : public ASTNode {
 public:
  TypeName(std::shared_ptr<type_system::Type> type,
           std::unique_ptr<AbstractDeclarator> abstract_declarator,
           const common::SourceLocation& location) noexcept;

  void Accept(ASTVisitor& visitor) const override;

  const type_system::Type* GetType() const noexcept { return type_.get(); }
  const AbstractDeclarator* GetAbstractDeclarator() const noexcept { return abstract_declarator_.get(); }

 private:
  std::shared_ptr<type_system::Type> type_;
  std::unique_ptr<AbstractDeclarator> abstract_declarator_;
};

} // namespace ast
} // namespace syntactic_analysis
} // namespace acc

#endif // ACC_SYNTACTIC_ANALYSIS_AST_TYPE_NAME_H_