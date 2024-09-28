#ifndef ACC_SYNTACTIC_ANALYSIS_AST_TYPES_DIRECT_ABSTRACT_DECLARATOR_H_
#define ACC_SYNTACTIC_ANALYSIS_AST_TYPES_DIRECT_ABSTRACT_DECLARATOR_H_

#include <memory>
#include <vector>
#include "acc/syntactic_analysis/ast/common/ast_node.h"
#include "acc/type_system/type.h"

namespace acc {
namespace syntactic_analysis {
namespace ast {

class DirectAbstractDeclarator final : public ASTNode {
 public:
  enum class Kind {
    kArray,
    kFunction
  };

  explicit DirectAbstractDeclarator(std::shared_ptr<type_system::ArrayType> array_type,
                                    const common::SourceLocation& location) noexcept;
  explicit DirectAbstractDeclarator(std::shared_ptr<type_system::FunctionType> function_type,
                                    const common::SourceLocation& location) noexcept;

  void Accept(ASTVisitor& visitor) const override;

  Kind GetKind() const noexcept { return kind_; }
  const type_system::Type* GetType() const noexcept { return type_.get(); }

 private:
  Kind kind_;
  std::shared_ptr<type_system::Type> type_;
};

} // namespace ast
} // namespace syntactic_analysis
} // namespace acc

#endif // ACC_SYNTACTIC_ANALYSIS_AST_DIRECT_ABSTRACT_DECLARATOR_H_