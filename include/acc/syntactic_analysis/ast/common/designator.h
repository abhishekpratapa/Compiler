#ifndef ACC_SYNTACTIC_ANALYSIS_AST_DESIGNATOR_H_
#define ACC_SYNTACTIC_ANALYSIS_AST_DESIGNATOR_H_

#include <memory>
#include <string>
#include "acc/syntactic_analysis/ast/common/ast_node.h"
#include "acc/syntactic_analysis/ast/expressions/expression.h"

namespace acc {
namespace syntactic_analysis {
namespace ast {

class Designator final : public ASTNode {
 public:
  explicit Designator(std::unique_ptr<Expression> index_expr,
                      const common::SourceLocation& location) noexcept;
  explicit Designator(std::string member_name,
                      const common::SourceLocation& location) noexcept;

  void Accept(ASTVisitor& visitor) const override;

  bool IsArrayIndex() const noexcept { return is_array_index_; }
  const Expression* GetIndexExpression() const noexcept { return index_expr_.get(); }
  const std::string& GetMemberName() const noexcept { return member_name_; }

 private:
  bool is_array_index_;
  std::unique_ptr<Expression> index_expr_;
  std::string member_name_;
};

} // namespace ast
} // namespace syntactic_analysis
} // namespace acc

#endif // ACC_SYNTACTIC_ANALYSIS_AST_DESIGNATOR_H_