#ifndef ACC_SYNTACTIC_ANALYSIS_AST_EXPRESSIONS_LITERAL_H_
#define ACC_SYNTACTIC_ANALYSIS_AST_EXPRESSIONS_LITERAL_H_

#include <string>
#include "acc/syntactic_analysis/ast/expressions/expression.h"
#include "acc/type_system/type.h"

namespace acc {
namespace syntactic_analysis {
namespace ast {

class Literal final : public Expression {
 public:
  Literal(std::string value,
          std::shared_ptr<type_system::Type> type,
          const common::SourceLocation& location) noexcept;

  void Accept(ASTVisitor& visitor) const override;

  const std::string& GetValue() const noexcept { return value_; }
  const type_system::Type* GetType() const noexcept override { return type_.get(); }

 private:
  std::string value_;
  std::shared_ptr<type_system::Type> type_;
};

} // namespace ast
} // namespace syntactic_analysis
} // namespace acc

#endif // ACC_SYNTACTIC_ANALYSIS_AST_LITERAL_H_