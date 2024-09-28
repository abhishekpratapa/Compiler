#ifndef ACC_SYNTACTIC_ANALYSIS_AST_DECLARATION_H_
#define ACC_SYNTACTIC_ANALYSIS_AST_DECLARATION_H_

#include "acc/syntactic_analysis/ast/common/ast_node.h"
#include "acc/type_system/type.h"

namespace acc {
namespace syntactic_analysis {
namespace ast {

class Declaration : public ASTNode {
 public:
  virtual ~Declaration() noexcept override = default;

  virtual const type_system::Type* GetDeclaredType() const noexcept = 0;
  virtual const std::string& GetName() const noexcept = 0;

  // Disable copying and assignment
  Declaration(const Declaration&) = delete;
  Declaration& operator=(const Declaration&) = delete;

  // Enable moving
  Declaration(Declaration&&) noexcept = default;
  Declaration& operator=(Declaration&&) noexcept = default;

 protected:
  explicit Declaration(const common::SourceLocation& location) noexcept
    : ASTNode(location) {}
};

static_assert(alignof(Declaration) >= alignof(void*), "Declaration alignment is insufficient");
static_assert(sizeof(Declaration) >= sizeof(void*), "Declaration size is insufficient");

} // namespace ast
} // namespace syntactic_analysis
} // namespace acc

#endif // ACC_SYNTACTIC_ANALYSIS_AST_DECLARATION_H_