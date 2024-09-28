// tests/unit/syntactic_analysis/parser_test.cpp
#include "acc/error_handling/error_handler.h"
#include "acc/lexical_analysis/concrete_lexer.h"
#include "acc/syntactic_analysis/ast/binary_expression.h"
#include "acc/syntactic_analysis/ast/literal.h"
#include "acc/syntactic_analysis/ast/unary_expression.h"
#include "acc/syntactic_analysis/concrete_parser.h"
#include "gtest/gtest.h"

namespace acc {
namespace syntactic_analysis {
namespace {

class ParserTest : public ::testing::Test {
 protected:
  void SetUp() override {
    lexer_.SetErrorHandler(&error_handler_);
    parser_.SetErrorHandler(&error_handler_);
  }

  std::unique_ptr<ast::ASTNode> ParseExpression(const std::string& input) {
    auto tokens = lexer_.Tokenize(input);
    return parser_.Parse(tokens);
  }

  lexical_analysis::ConcreteLexer lexer_;
  ConcreteParser parser_;
  error_handling::ErrorHandler error_handler_;
};

TEST_F(ParserTest, ParseSimpleLiteral) {
  auto ast = ParseExpression("42");
  ASSERT_NE(ast, nullptr);
  const auto* literal = dynamic_cast<const ast::Literal*>(ast.get());
  ASSERT_NE(literal, nullptr);
  EXPECT_EQ(literal->GetValue(), "42");
}

TEST_F(ParserTest, ParseSimpleBinaryExpression) {
  auto ast = ParseExpression("1 + 2");
  ASSERT_NE(ast, nullptr);
  const auto* binary = dynamic_cast<const ast::BinaryExpression*>(ast.get());
  ASSERT_NE(binary, nullptr);
  EXPECT_EQ(binary->GetOperator(), lexical_analysis::Token::Type::kOperator);

  const auto* left = dynamic_cast<const ast::Literal*>(binary->GetLeft());
  ASSERT_NE(left, nullptr);
  EXPECT_EQ(left->GetValue(), "1");

  const auto* right = dynamic_cast<const ast::Literal*>(binary->GetRight());
  ASSERT_NE(right, nullptr);
  EXPECT_EQ(right->GetValue(), "2");
}

TEST_F(ParserTest, ParseComplexBinaryExpression) {
  auto ast = ParseExpression("1 + 2 * 3");
  ASSERT_NE(ast, nullptr);
  const auto* binary = dynamic_cast<const ast::BinaryExpression*>(ast.get());
  ASSERT_NE(binary, nullptr);
  EXPECT_EQ(binary->GetOperator(), lexical_analysis::Token::Type::kOperator);

  const auto* left = dynamic_cast<const ast::Literal*>(binary->GetLeft());
  ASSERT_NE(left, nullptr);
  EXPECT_EQ(left->GetValue(), "1");

  const auto* right =
      dynamic_cast<const ast::BinaryExpression*>(binary->GetRight());
  ASSERT_NE(right, nullptr);
  EXPECT_EQ(right->GetOperator(), lexical_analysis::Token::Type::kOperator);
}

TEST_F(ParserTest, ParseUnaryExpression) {
  auto ast = ParseExpression("-42");
  ASSERT_NE(ast, nullptr);
  const auto* unary = dynamic_cast<const ast::UnaryExpression*>(ast.get());
  ASSERT_NE(unary, nullptr);
  EXPECT_EQ(unary->GetOperator(), lexical_analysis::Token::Type::kOperator);

  const auto* operand = dynamic_cast<const ast::Literal*>(unary->GetOperand());
  ASSERT_NE(operand, nullptr);
  EXPECT_EQ(operand->GetValue(), "42");
}

TEST_F(ParserTest, ParseComplexUnaryExpression) {
  auto ast = ParseExpression("!(-42)");
  ASSERT_NE(ast, nullptr);
  const auto* outer_unary =
      dynamic_cast<const ast::UnaryExpression*>(ast.get());
  ASSERT_NE(outer_unary, nullptr);
  EXPECT_EQ(outer_unary->GetOperator(),
            lexical_analysis::Token::Type::kOperator);

  const auto* inner_unary =
      dynamic_cast<const ast::UnaryExpression*>(outer_unary->GetOperand());
  ASSERT_NE(inner_unary, nullptr);
  EXPECT_EQ(inner_unary->GetOperator(),
            lexical_analysis::Token::Type::kOperator);

  const auto* literal =
      dynamic_cast<const ast::Literal*>(inner_unary->GetOperand());
  ASSERT_NE(literal, nullptr);
  EXPECT_EQ(literal->GetValue(), "42");
}

}  // namespace
}  // namespace syntactic_analysis
}  // namespace acc