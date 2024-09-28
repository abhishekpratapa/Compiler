#ifndef ACC_SYNTACTIC_ANALYSIS_AST_TYPES_TYPEDEF_NAME_H_
#define ACC_SYNTACTIC_ANALYSIS_AST_TYPES_TYPEDEF_NAME_H_

#include <string>
#include "acc/syntactic_analysis/ast/common/ast_node.h"
#include "acc/type_system/type.h"

namespace acc {
namespace syntactic_analysis {
namespace ast {

class TypedefName final : public ASTNode {
 public:
  TypedefName(std::string name,
              std::shared_ptr<type_system::Type> underlying_type,
              const common::SourceLocation& location) noexcept;

  void Accept(ASTVisitor& visitor) const override;

  const std::string& GetName() const noexcept { return name_; }
  const type_system::Type* GetUnderlyingType() const noexcept { return underlying_type_.get(); }

 private:
  std::string name_;
  std::shared_ptr<type_system::Type> underlying_type_;
};

} // namespace ast
} // namespace syntactic_analysis
} // namespace acc

#endif // ACC_SYNTACTIC_ANALYSIS_AST_TYPEDEF_NAME_H_