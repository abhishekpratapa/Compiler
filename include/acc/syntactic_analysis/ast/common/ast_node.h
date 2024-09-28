#ifndef ACC_SYNTACTIC_ANALYSIS_AST_AST_NODE_H_
#define ACC_SYNTACTIC_ANALYSIS_AST_AST_NODE_H_

#include "acc/common/source_location.h"

namespace acc {
namespace syntactic_analysis {
namespace ast {

class ASTVisitor;

class ASTNode {
 public:
  virtual ~ASTNode() noexcept = default;

  virtual void Accept(ASTVisitor& visitor) const = 0;

  const common::SourceLocation& GetLocation() const noexcept { return location_; }

  // Disable copying and assignment
  ASTNode(const ASTNode&) = delete;
  ASTNode& operator=(const ASTNode&) = delete;

  // Enable moving
  ASTNode(ASTNode&&) noexcept = default;
  ASTNode& operator=(ASTNode&&) noexcept = default;

 protected:
  explicit ASTNode(const common::SourceLocation& location) noexcept
    : location_(location) {}

 private:
  common::SourceLocation location_;
};

static_assert(alignof(ASTNode) >= alignof(void*), "ASTNode alignment is insufficient");
static_assert(sizeof(ASTNode) >= sizeof(void*), "ASTNode size is insufficient");

} // namespace ast
} // namespace syntactic_analysis
} // namespace acc

#endif // ACC_SYNTACTIC_ANALYSIS_AST_AST_NODE_H_