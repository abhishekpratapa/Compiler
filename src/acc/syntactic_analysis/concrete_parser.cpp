// src/acc/syntactic_analysis/concrete_parser.cpp
#include "acc/syntactic_analysis/concrete_parser.h"

#include <stdexcept>

#include "acc/syntactic_analysis/ast/binary_expression.h"
#include "acc/syntactic_analysis/ast/function_declaration.h"
#include "acc/syntactic_analysis/ast/literal.h"
#include "acc/syntactic_analysis/ast/unary_expression.h"

namespace acc {
namespace syntactic_analysis {

std::unique_ptr<ast::ASTNode> ConcreteParser::Parse(
    const std::vector<std::unique_ptr<lexical_analysis::Token>>& tokens) {
  tokens_.clear();
  for (const auto& token : tokens) {
    tokens_.push_back(token.get());
  }
  current_token_ = 0;

  try {
    return ParseExpression();
  } catch (const std::runtime_error& e) {
    error_handler_->ReportError(e.what(), Peek()->GetLine(),
                                Peek()->GetColumn());
    return nullptr;
  }
}

void ConcreteParser::SetErrorHandler(
    error_handling::ErrorHandler* error_handler) {
  error_handler_ = error_handler;
}

std::unique_ptr<ast::ASTNode> ConcreteParser::ParseExpression() {
  auto left = ParseTerm();
  
  while (Match(lexical_analysis::Token::Type::kOperator) &&
         (Previous()->GetValue() == "+" || Previous()->GetValue() == "-")) {
    auto op = Previous()->GetType();
    std::string op_value = Previous()->GetValue();
    auto right = ParseTerm();
    left = std::make_unique<ast::BinaryExpression>(std::move(left), op, op_value, std::move(right));
  }
  
  return left;
}


std::unique_ptr<ast::ASTNode> ConcreteParser::ParseTerm() {
  auto left = ParseFactor();
  
  while (Match(lexical_analysis::Token::Type::kOperator) &&
         (Previous()->GetValue() == "*" || Previous()->GetValue() == "/")) {
    auto op = Previous()->GetType();
    std::string op_value = Previous()->GetValue();
    auto right = ParseFactor();
    left = std::make_unique<ast::BinaryExpression>(std::move(left), op, op_value, std::move(right));
  }
  
  return left;
}

std::unique_ptr<ast::ASTNode> ConcreteParser::ParseFactor() {
  return ParseUnary();
}

std::unique_ptr<ast::ASTNode> ConcreteParser::ParseUnary() {
  if (Match(lexical_analysis::Token::Type::kOperator) &&
      (Previous()->GetValue() == "-" || Previous()->GetValue() == "!")) {
    auto op = Previous()->GetType();
    auto right = ParseUnary();
    return std::make_unique<ast::UnaryExpression>(op, std::move(right));
  }
  return ParsePrimary();
}

std::unique_ptr<ast::ASTNode> ConcreteParser::ParseDeclaration() {
  if (Match(lexical_analysis::Token::Type::kKeyword) &&
      Previous()->GetValue() == "int") {
    return ParseFunctionDeclaration();
  }
  // Add more declaration types here as needed
  return ParseStatement();
}

std::unique_ptr<ast::ASTNode> ConcreteParser::ParsePrimary() {
  if (Match(lexical_analysis::Token::Type::kLiteral)) {
    return std::make_unique<ast::Literal>(Previous()->GetValue());
  }
  if (Match(lexical_analysis::Token::Type::kPunctuation) &&
      Previous()->GetValue() == "(") {
    auto expr = ParseExpression();
    Consume(lexical_analysis::Token::Type::kPunctuation,
            "Expect ')' after expression.");
    return expr;
  }
  throw std::runtime_error("Expect expression.");
}

std::unique_ptr<ast::ASTNode> ConcreteParser::ParseStatement() {
  // For now, we'll just parse expressions as statements
  return ParseExpression();
}

std::unique_ptr<ast::FunctionDeclaration>
ConcreteParser::ParseFunctionDeclaration() {
  std::string return_type = Previous()->GetValue();
  std::string name = Consume(lexical_analysis::Token::Type::kIdentifier,
                             "Expect function name.")
                         ->GetValue();

  Consume(lexical_analysis::Token::Type::kPunctuation,
          "Expect '(' after function name.");
  std::vector<std::pair<std::string, std::string>> parameters;
  if (!Check(lexical_analysis::Token::Type::kPunctuation)) {
    do {
      std::string param_type = Consume(lexical_analysis::Token::Type::kKeyword,
                                       "Expect parameter type.")
                                   ->GetValue();
      std::string param_name =
          Consume(lexical_analysis::Token::Type::kIdentifier,
                  "Expect parameter name.")
              ->GetValue();
      parameters.emplace_back(param_type, param_name);
    } while (Match(lexical_analysis::Token::Type::kPunctuation) &&
             Previous()->GetValue() == ",");
  }
  Consume(lexical_analysis::Token::Type::kPunctuation,
          "Expect ')' after parameters.");

  Consume(lexical_analysis::Token::Type::kPunctuation,
          "Expect '{' before function body.");
  auto body = ParseStatement();
  Consume(lexical_analysis::Token::Type::kPunctuation,
          "Expect '}' after function body.");

  return std::make_unique<ast::FunctionDeclaration>(
      return_type, name, std::move(parameters), std::move(body));
}

lexical_analysis::Token* ConcreteParser::Consume(
    lexical_analysis::Token::Type type, const std::string& message) {
  if (Check(type)) return Advance();
  throw std::runtime_error(message);
}

// Helper methods
bool ConcreteParser::Match(lexical_analysis::Token::Type type) {
  if (Check(type)) {
    Advance();
    return true;
  }
  return false;
}

bool ConcreteParser::Check(lexical_analysis::Token::Type type) {
  if (IsAtEnd()) return false;
  return Peek()->GetType() == type;
}

lexical_analysis::Token* ConcreteParser::Peek() {
  return tokens_[current_token_];
}

lexical_analysis::Token* ConcreteParser::Previous() {
  return tokens_[current_token_ - 1];
}

lexical_analysis::Token* ConcreteParser::Advance() {
  if (!IsAtEnd()) current_token_++;
  return Previous();
}

bool ConcreteParser::IsAtEnd() {
  return current_token_ >= tokens_.size();
}

}  // namespace syntactic_analysis
}  // namespace acc
