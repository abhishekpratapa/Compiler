#ifndef ACC_SYNTACTIC_ANALYSIS_AST_ENUMERATOR_H_
#define ACC_SYNTACTIC_ANALYSIS_AST_ENUMERATOR_H_

#include <memory>
#include <string>
#include "acc/syntactic_analysis/ast/common/ast_node.h"
#include "acc/syntactic_analysis/ast/expressions/expression.h"

namespace acc {
namespace syntactic_analysis {
namespace ast {

class Enumerator final : public ASTNode {
 public:
  Enumerator(const std::string& name,
             std::unique_ptr<Expression> value_expr,
             const common::SourceLocation& location) noexcept;

  void Accept(ASTVisitor& visitor) const override;

  const std::string& GetName() const noexcept { return name_; }
  const Expression* GetValueExpression() const noexcept { return value_expr_.get(); }

 private:
  std::string name_;
  std::unique_ptr<Expression> value_expr_;
};

} // namespace ast
} // namespace syntactic_analysis
} // namespace acc

#endif // ACC_SYNTACTIC_ANALYSIS_AST_ENUMERATOR_H_