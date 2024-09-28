#ifndef ACC_SYNTACTIC_ANALYSIS_AST_STATEMENTS_INLINE_ASSEMBLY_H_
#define ACC_SYNTACTIC_ANALYSIS_AST_STATEMENTS_INLINE_ASSEMBLY_H_

#include <string>
#include <vector>
#include <memory>
#include "acc/syntactic_analysis/ast/statements/statement.h"
#include "acc/syntactic_analysis/ast/expressions/expression.h"

namespace acc {
namespace syntactic_analysis {
namespace ast {

class AssemblyOperand final {
 public:
  AssemblyOperand(std::string constraint, std::unique_ptr<Expression> expression) noexcept;

  const std::string& GetConstraint() const noexcept { return constraint_; }
  const Expression* GetExpression() const noexcept { return expression_.get(); }

 private:
  std::string constraint_;
  std::unique_ptr<Expression> expression_;
};

enum class AssemblyDialect {
  kATT,
  kIntel
};

class InlineAssembly final : public Statement {
 public:
  InlineAssembly(std::string assembly_code,
                 std::vector<AssemblyOperand> input_operands,
                 std::vector<AssemblyOperand> output_operands,
                 std::vector<std::string> clobbers,
                 AssemblyDialect dialect,
                 bool is_volatile,
                 const common::SourceLocation& location) noexcept;

  void Accept(ASTVisitor& visitor) const override;

  const std::string& GetAssemblyCode() const noexcept { return assembly_code_; }
  const std::vector<AssemblyOperand>& GetInputOperands() const noexcept { return input_operands_; }
  const std::vector<AssemblyOperand>& GetOutputOperands() const noexcept { return output_operands_; }
  const std::vector<std::string>& GetClobbers() const noexcept { return clobbers_; }
  AssemblyDialect GetDialect() const noexcept { return dialect_; }
  bool IsVolatile() const noexcept { return is_volatile_; }

 private:
  std::string assembly_code_;
  std::vector<AssemblyOperand> input_operands_;
  std::vector<AssemblyOperand> output_operands_;
  std::vector<std::string> clobbers_;
  AssemblyDialect dialect_;
  bool is_volatile_;
};

} // namespace ast
} // namespace syntactic_analysis
} // namespace acc

#endif // ACC_SYNTACTIC_ANALYSIS_AST_INLINE_ASSEMBLY_H_