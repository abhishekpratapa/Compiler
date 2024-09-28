#ifndef ACC_SYNTACTIC_ANALYSIS_AST_TRANSLATION_UNIT_H_
#define ACC_SYNTACTIC_ANALYSIS_AST_TRANSLATION_UNIT_H_

#include <memory>
#include <vector>
#include "acc/syntactic_analysis/ast/common/ast_node.h"
#include "acc/syntactic_analysis/ast/declarations/external_declaration.h"
#include "acc/syntactic_analysis/ast/common/preprocessor_directive.h"

namespace acc {
namespace syntactic_analysis {
namespace ast {

class TranslationUnit final : public ASTNode {
 public:
  TranslationUnit(std::vector<std::unique_ptr<ExternalDeclaration>> declarations,
                  std::vector<std::unique_ptr<PreprocessorDirective>> directives,
                  const common::SourceLocation& location) noexcept;

  void Accept(ASTVisitor& visitor) const override;

  const std::vector<std::unique_ptr<ExternalDeclaration>>& GetDeclarations() const noexcept { return declarations_; }
  const std::vector<std::unique_ptr<PreprocessorDirective>>& GetDirectives() const noexcept { return directives_; }

 private:
  std::vector<std::unique_ptr<ExternalDeclaration>> declarations_;
  std::vector<std::unique_ptr<PreprocessorDirective>> directives_;
};

} // namespace ast
} // namespace syntactic_analysis
} // namespace acc

#endif // ACC_SYNTACTIC_ANALYSIS_AST_TRANSLATION_UNIT_H_