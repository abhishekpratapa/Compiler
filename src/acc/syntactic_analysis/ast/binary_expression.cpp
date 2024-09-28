// src/acc/syntactic_analysis/ast/binary_expression.cpp
#include "acc/syntactic_analysis/ast/binary_expression.h"

#include "acc/syntactic_analysis/ast/ast_visitor.h"

namespace acc
{
  namespace syntactic_analysis
  {
    namespace ast
    {

      BinaryExpression::BinaryExpression(std::unique_ptr<ASTNode> left,
                                         lexical_analysis::Token::Type op,
                                         const std::string &op_value,
                                         std::unique_ptr<ASTNode> right)
          : left_(std::move(left)), op_(op), op_value_(op_value), right_(std::move(right)) {}

      void BinaryExpression::Accept(ASTVisitor &visitor)
      {
        visitor.VisitBinaryExpression(*this);
      }

      const ASTNode *BinaryExpression::GetLeft() const { return left_.get(); }

      lexical_analysis::Token::Type BinaryExpression::GetOperator() const
      {
        return op_;
      }

      const std::string &BinaryExpression::GetOperatorValue() const
      {
        return op_value_;
      }

      const ASTNode *BinaryExpression::GetRight() const { return right_.get(); }

    } // namespace ast
  } // namespace syntactic_analysis
} // namespace acc