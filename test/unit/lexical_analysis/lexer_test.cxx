// tests/unit/lexical_analysis/lexer_test.cpp
#include "acc/error_handling/error_handler.h"
#include "acc/lexical_analysis/concrete_lexer.h"
#include "gtest/gtest.h"

namespace acc {
namespace lexical_analysis {
namespace {

class LexerTest : public ::testing::Test {
 protected:
  void SetUp() override { lexer_.SetErrorHandler(&error_handler_); }

  ConcreteLexer lexer_;
  error_handling::ErrorHandler error_handler_;
};

TEST_F(LexerTest, TokenizeEmptyInput) {
  auto tokens = lexer_.Tokenize("");
  ASSERT_EQ(tokens.size(), 1);
  EXPECT_EQ(tokens[0]->GetType(), Token::Type::kEOF);
}

TEST_F(LexerTest, TokenizeIdentifiers) {
  auto tokens = lexer_.Tokenize("foo bar_123 _baz");
  ASSERT_EQ(tokens.size(), 4);  // 3 identifiers + EOF
  EXPECT_EQ(tokens[0]->GetType(), Token::Type::kIdentifier);
  EXPECT_EQ(tokens[0]->GetValue(), "foo");
  EXPECT_EQ(tokens[1]->GetType(), Token::Type::kIdentifier);
  EXPECT_EQ(tokens[1]->GetValue(), "bar_123");
  EXPECT_EQ(tokens[2]->GetType(), Token::Type::kIdentifier);
  EXPECT_EQ(tokens[2]->GetValue(), "_baz");
}

TEST_F(LexerTest, TokenizeKeywords) {
  auto tokens = lexer_.Tokenize("int char if else while return");
  ASSERT_EQ(tokens.size(), 7);  // 6 keywords + EOF
  for (int i = 0; i < 6; ++i) {
    EXPECT_EQ(tokens[i]->GetType(), Token::Type::kKeyword);
  }
}

TEST_F(LexerTest, TokenizeNumbers) {
  auto tokens = lexer_.Tokenize("123 456 789");
  ASSERT_EQ(tokens.size(), 4);  // 3 numbers + EOF
  for (int i = 0; i < 3; ++i) {
    EXPECT_EQ(tokens[i]->GetType(), Token::Type::kLiteral);
  }
}

TEST_F(LexerTest, TokenizeOperatorsAndPunctuation) {
  auto tokens = lexer_.Tokenize("+ - * / = ; ( ) { }");
  ASSERT_EQ(tokens.size(), 11);  // 10 operators/punctuation + EOF
  for (int i = 0; i < 5; ++i) {
    EXPECT_EQ(tokens[i]->GetType(), Token::Type::kOperator);
  }
  for (int i = 5; i < 10; ++i) {
    EXPECT_EQ(tokens[i]->GetType(), Token::Type::kPunctuation);
  }
}

TEST_F(LexerTest, TokenizeMixedInput) {
  auto tokens = lexer_.Tokenize("int main() { return 42; }");
  ASSERT_EQ(tokens.size(), 10);  // 9 tokens + EOF
  EXPECT_EQ(tokens[0]->GetType(), Token::Type::kKeyword);
  EXPECT_EQ(tokens[1]->GetType(), Token::Type::kIdentifier);
  EXPECT_EQ(tokens[2]->GetType(), Token::Type::kPunctuation);
  EXPECT_EQ(tokens[3]->GetType(), Token::Type::kPunctuation);
  EXPECT_EQ(tokens[4]->GetType(), Token::Type::kPunctuation);
  EXPECT_EQ(tokens[5]->GetType(), Token::Type::kKeyword);
  EXPECT_EQ(tokens[6]->GetType(), Token::Type::kLiteral);
  EXPECT_EQ(tokens[7]->GetType(), Token::Type::kPunctuation);
  EXPECT_EQ(tokens[8]->GetType(), Token::Type::kPunctuation);
  EXPECT_EQ(tokens[9]->GetType(), Token::Type::kEOF);
}

TEST_F(LexerTest, HandleInvalidCharacter) {
  auto tokens = lexer_.Tokenize("foo @ bar");
  ASSERT_EQ(tokens.size(), 3);  // 2 identifiers + EOF
  EXPECT_TRUE(error_handler_.HasErrors());
  ASSERT_EQ(error_handler_.GetErrors().size(), 1);
  EXPECT_EQ(error_handler_.GetErrors()[0].message, "Unexpected character: @");
}

}  // namespace
}  // namespace lexical_analysis
}  // namespace acc