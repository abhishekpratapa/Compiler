#ifndef ACC_SYNTACTIC_ANALYSIS_AST_PARAMETER_TYPE_LIST_H_
#define ACC_SYNTACTIC_ANALYSIS_AST_PARAMETER_TYPE_LIST_H_

#include <memory>
#include <vector>
#include "acc/syntactic_analysis/ast/common/ast_node.h"

namespace acc {
namespace syntactic_analysis {
namespace ast {

class ParameterDeclaration;

class ParameterTypeList final : public ASTNode {
 public:
  ParameterTypeList(std::vector<std::unique_ptr<ParameterDeclaration>> parameters,
                    bool has_ellipsis,
                    const common::SourceLocation& location) noexcept;

  void Accept(ASTVisitor& visitor) const override;

  const std::vector<std::unique_ptr<ParameterDeclaration>>& GetParameters() const noexcept { return parameters_; }
  bool HasEllipsis() const noexcept { return has_ellipsis_; }

 private:
  std::vector<std::unique_ptr<ParameterDeclaration>> parameters_;
  bool has_ellipsis_;
};

} // namespace ast
} // namespace syntactic_analysis
} // namespace acc

#endif // ACC_SYNTACTIC_ANALYSIS_AST_PARAMETER_TYPE_LIST_H_