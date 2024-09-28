// src/acc/syntactic_analysis/ast/unary_expression.cpp
#include "acc/syntactic_analysis/ast/unary_expression.h"

#include "acc/syntactic_analysis/ast/ast_visitor.h"

namespace acc {
namespace syntactic_analysis {
namespace ast {

UnaryExpression::UnaryExpression(lexical_analysis::Token::Type op,
                                 std::unique_ptr<ASTNode> operand)
    : op_(op), operand_(std::move(operand)) {}

void UnaryExpression::Accept(ASTVisitor& visitor) {
  visitor.VisitUnaryExpression(*this);
}

lexical_analysis::Token::Type UnaryExpression::GetOperator() const {
  return op_;
}

const ASTNode* UnaryExpression::GetOperand() const { return operand_.get(); }

}  // namespace ast
}  // namespace syntactic_analysis
}  // namespace acc