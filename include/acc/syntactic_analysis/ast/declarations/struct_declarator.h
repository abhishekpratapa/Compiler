#ifndef ACC_SYNTACTIC_ANALYSIS_AST_STRUCT_DECLARATOR_H_
#define ACC_SYNTACTIC_ANALYSIS_AST_STRUCT_DECLARATOR_H_

#include <memory>
#include <string>
#include "acc/syntactic_analysis/ast/common/ast_node.h"
#include "acc/syntactic_analysis/ast/expressions/expression.h"

namespace acc {
namespace syntactic_analysis {
namespace ast {

class StructDeclarator final : public ASTNode {
 public:
  StructDeclarator(std::string name,
                   std::unique_ptr<Expression> bit_field_size,
                   const common::SourceLocation& location) noexcept;

  void Accept(ASTVisitor& visitor) const override;

  const std::string& GetName() const noexcept { return name_; }
  const Expression* GetBitFieldSize() const noexcept { return bit_field_size_.get(); }
  bool IsBitField() const noexcept { return bit_field_size_ != nullptr; }

 private:
  std::string name_;
  std::unique_ptr<Expression> bit_field_size_;
};

} // namespace ast
} // namespace syntactic_analysis
} // namespace acc

#endif // ACC_SYNTACTIC_ANALYSIS_AST_STRUCT_DECLARATOR_H_