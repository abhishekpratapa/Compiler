#ifndef ACC_SYNTACTIC_ANALYSIS_AST_EXPRESSIONS_INITIALIZER_LIST_H_
#define ACC_SYNTACTIC_ANALYSIS_AST_EXPRESSIONS_INITIALIZER_LIST_H_

#include <memory>
#include <vector>
#include "acc/syntactic_analysis/ast/expressions/expression.h"

namespace acc {
namespace syntactic_analysis {
namespace ast {

class Designator;

class InitializerList final : public Expression {
 public:
  struct DesignatedInitializer {
    std::vector<std::unique_ptr<Designator>> designators;
    std::unique_ptr<Expression> initializer;

    DesignatedInitializer(std::vector<std::unique_ptr<Designator>> des,
                          std::unique_ptr<Expression> init) noexcept
        : designators(std::move(des)), initializer(std::move(init)) {}
  };

  InitializerList(std::vector<DesignatedInitializer> initializers,
                  const common::SourceLocation& location) noexcept;

  void Accept(ASTVisitor& visitor) const override;

  const std::vector<DesignatedInitializer>& GetInitializers() const noexcept { return initializers_; }

  const type_system::Type* GetType() const noexcept override;

 private:
  std::vector<DesignatedInitializer> initializers_;
  mutable std::shared_ptr<type_system::Type> cached_type_;
};

} // namespace ast
} // namespace syntactic_analysis
} // namespace acc

#endif // ACC_SYNTACTIC_ANALYSIS_AST_INITIALIZER_LIST_H_