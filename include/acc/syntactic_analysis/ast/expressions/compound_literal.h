#ifndef ACC_SYNTACTIC_ANALYSIS_AST_EXPRESSIONS_COMPOUND_LITERAL_H_
#define ACC_SYNTACTIC_ANALYSIS_AST_EXPRESSIONS_COMPOUND_LITERAL_H_

#include <memory>
#include <string>
#include <vector>
#include "acc/syntactic_analysis/ast/expressions/expression.h"
#include "acc/type_system/type.h"

namespace acc {
namespace syntactic_analysis {
namespace ast {

class CompoundLiteral final : public Expression {
 public:
  CompoundLiteral(std::shared_ptr<type_system::Type> type,
                  std::vector<std::unique_ptr<Expression>> initializer_list,
                  const common::SourceLocation& location) noexcept;

  void Accept(ASTVisitor& visitor) const override;

  const type_system::Type* GetType() const noexcept override { return type_.get(); }
  const std::vector<std::unique_ptr<Expression>>& GetInitializerList() const noexcept { return initializer_list_; }

 private:
  std::shared_ptr<type_system::Type> type_;
  std::vector<std::unique_ptr<Expression>> initializer_list_;
};

} // namespace ast
} // namespace syntactic_analysis
} // namespace acc

#endif // ACC_SYNTACTIC_ANALYSIS_AST_COMPOUND_LITERAL_H_