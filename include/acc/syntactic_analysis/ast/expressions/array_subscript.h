#ifndef ACC_SYNTACTIC_ANALYSIS_AST_EXPRESSIONS_ARRAY_SUBSCRIPT_H_
#define ACC_SYNTACTIC_ANALYSIS_AST_EXPRESSIONS_ARRAY_SUBSCRIPT_H_

#include <memory>
#include "acc/syntactic_analysis/ast/expressions/expression.h"
#include "acc/type_system/type.h"

namespace acc {
namespace syntactic_analysis {
namespace ast {

class ArraySubscript final : public Expression {
 public:
  ArraySubscript(std::unique_ptr<Expression> array,
                 std::unique_ptr<Expression> index,
                 const common::SourceLocation& location) noexcept;

  void Accept(ASTVisitor& visitor) const override;

  const Expression* GetArray() const noexcept { return array_.get(); }
  const Expression* GetIndex() const noexcept { return index_.get(); }

  const type_system::Type* GetType() const noexcept override;

 private:
  std::unique_ptr<Expression> array_;
  std::unique_ptr<Expression> index_;
  mutable std::shared_ptr<type_system::Type> cached_type_;
};

} // namespace ast
} // namespace syntactic_analysis
} // namespace acc

#endif // ACC_SYNTACTIC_ANALYSIS_AST_ARRAY_SUBSCRIPT_H_