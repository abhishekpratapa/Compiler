#ifndef ACC_SYNTACTIC_ANALYSIS_AST_TYPES_COMPLEX_OR_IMAGINARY_TYPE_H_
#define ACC_SYNTACTIC_ANALYSIS_AST_TYPES_COMPLEX_OR_IMAGINARY_TYPE_H_

#include "acc/syntactic_analysis/ast/common/ast_node.h"

namespace acc {
namespace syntactic_analysis {
namespace ast {

class ComplexOrImaginaryType final : public ASTNode {
 public:
  enum class Kind {
    kComplex,
    kImaginary
  };

  enum class BaseType {
    kFloat,
    kDouble,
    kLongDouble
  };

  ComplexOrImaginaryType(Kind kind, BaseType base_type,
                         const common::SourceLocation& location) noexcept;

  void Accept(ASTVisitor& visitor) const override;

  Kind GetKind() const noexcept { return kind_; }
  BaseType GetBaseType() const noexcept { return base_type_; }

 private:
  Kind kind_;
  BaseType base_type_;
};

} // namespace ast
} // namespace syntactic_analysis
} // namespace acc

#endif // ACC_SYNTACTIC_ANALYSIS_AST_COMPLEX_OR_IMAGINARY_TYPE_H_