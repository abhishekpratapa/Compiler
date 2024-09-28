#ifndef ACC_SYNTACTIC_ANALYSIS_AST_DESIGNATION_H_
#define ACC_SYNTACTIC_ANALYSIS_AST_DESIGNATION_H_

#include <memory>
#include <vector>
#include "acc/syntactic_analysis/ast/common/ast_node.h"
#include "acc/syntactic_analysis/ast/common/designator.h"

namespace acc {
namespace syntactic_analysis {
namespace ast {

class Designation final : public ASTNode {
 public:
  Designation(std::vector<std::unique_ptr<Designator>> designators,
              const common::SourceLocation& location) noexcept;

  void Accept(ASTVisitor& visitor) const override;

  const std::vector<std::unique_ptr<Designator>>& GetDesignators() const noexcept { return designators_; }

 private:
  std::vector<std::unique_ptr<Designator>> designators_;
};

} // namespace ast
} // namespace syntactic_analysis
} // namespace acc

#endif // ACC_SYNTACTIC_ANALYSIS_AST_DESIGNATION_H_