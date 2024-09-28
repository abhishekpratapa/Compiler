#ifndef ACC_SYNTACTIC_ANALYSIS_AST_TYPES_TYPE_SPECIFIER_H_
#define ACC_SYNTACTIC_ANALYSIS_AST_TYPES_TYPE_SPECIFIER_H_

#include <memory>
#include <string>
#include "acc/syntactic_analysis/ast/common/ast_node.h"
#include "acc/type_system/type.h"

namespace acc {
namespace syntactic_analysis {
namespace ast {

class TypeSpecifier final : public ASTNode {
 public:
  TypeSpecifier(std::shared_ptr<type_system::Type> type,
                const common::SourceLocation& location) noexcept;

  void Accept(ASTVisitor& visitor) const override;

  const type_system::Type* GetType() const noexcept { return type_.get(); }

 private:
  std::shared_ptr<type_system::Type> type_;
};

} // namespace ast
} // namespace syntactic_analysis
} // namespace acc

#endif // ACC_SYNTACTIC_ANALYSIS_AST_TYPE_SPECIFIER_H_