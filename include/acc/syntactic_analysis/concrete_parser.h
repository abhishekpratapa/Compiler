// File: include/acc/syntactic_analysis/concrete_parser.h

#ifndef ACC_SYNTACTIC_ANALYSIS_CONCRETE_PARSER_H_
#define ACC_SYNTACTIC_ANALYSIS_CONCRETE_PARSER_H_

#include <memory>
#include <vector>

#include "acc/error_handling/error_handler.h"
#include "acc/lexical_analysis/token.h"
#include "acc/syntactic_analysis/parser.h"
#include "acc/syntactic_analysis/ast/common/ast_node.h"
#include "acc/syntactic_analysis/ast/declarations/translation_unit.h"
#include "acc/syntactic_analysis/ast/declarations/external_declaration.h"
#include "acc/syntactic_analysis/ast/declarations/declaration.h"
#include "acc/syntactic_analysis/ast/declarations/function_declaration.h"
#include "acc/syntactic_analysis/ast/declarations/variable_declaration.h"
#include "acc/syntactic_analysis/ast/declarations/array_declaration.h"
#include "acc/syntactic_analysis/ast/declarations/struct_declaration.h"
#include "acc/syntactic_analysis/ast/declarations/enum_declaration.h"
#include "acc/syntactic_analysis/ast/declarations/typedef_declaration.h"
#include "acc/syntactic_analysis/ast/statements/statement.h"
#include "acc/syntactic_analysis/ast/statements/compound_statement.h"
#include "acc/syntactic_analysis/ast/statements/if_statement.h"
#include "acc/syntactic_analysis/ast/statements/switch_statement.h"
#include "acc/syntactic_analysis/ast/expressions/expression.h"
#include "acc/syntactic_analysis/ast/types/type_specifier.h"
#include "acc/syntactic_analysis/ast/types/type_qualifier.h"
#include "acc/syntactic_analysis/ast/types/storage_class_specifier.h"

namespace acc {
namespace syntactic_analysis {

class ConcreteParser : public Parser {
 public:
  ConcreteParser();

  std::unique_ptr<ast::TranslationUnit> Parse(
      const std::vector<std::unique_ptr<lexical_analysis::Token>>& tokens) override;
  void SetErrorHandler(error_handling::ErrorHandler* error_handler) override;

 private:
  error_handling::ErrorHandler* error_handler_;
  std::vector<const lexical_analysis::Token*> tokens_;
  size_t current_token_;
  static constexpr int MAX_ERRORS = 10;
  int error_count_;
  bool had_error_;

  // Top-level parsing methods
  std::unique_ptr<ast::TranslationUnit> ParseTranslationUnit();
  std::unique_ptr<ast::ExternalDeclaration> ParseExternalDeclaration();

  // Declaration parsing methods
  std::unique_ptr<ast::Declaration> ParseDeclaration();
  std::unique_ptr<ast::FunctionDeclaration> ParseFunctionDeclaration();
  std::unique_ptr<ast::VariableDeclaration> ParseVariableDeclaration();
  std::unique_ptr<ast::ArrayDeclaration> ParseArrayDeclaration();
  std::unique_ptr<ast::StructDeclaration> ParseStructOrUnionDeclaration();
  std::unique_ptr<ast::EnumDeclaration> ParseEnumDeclaration();
  std::unique_ptr<ast::TypedefDeclaration> ParseTypedefDeclaration();
  std::unique_ptr<ast::Declaration> ParseExternDeclaration();
  std::unique_ptr<ast::Declaration> ParseStaticDeclaration();
  std::unique_ptr<ast::Declaration> ParseAutoDeclaration();
  std::unique_ptr<ast::Declaration> ParseRegisterDeclaration();
  std::unique_ptr<ast::Declaration> ParseConstDeclaration();
  std::unique_ptr<ast::Declaration> ParseVolatileDeclaration();
  std::unique_ptr<ast::Declaration> ParseRestrictDeclaration();
  std::unique_ptr<ast::Declaration> ParseInlineDeclaration();
  std::unique_ptr<ast::Declaration> ParsePointerDeclaration();
  std::unique_ptr<ast::Declaration> ParseBitFieldDeclaration();
  std::unique_ptr<ast::Declaration> ParseVariableLengthArrayDeclaration();

  // Statement parsing methods
  std::unique_ptr<ast::Statement> ParseStatement();
  std::unique_ptr<ast::CompoundStatement> ParseCompoundStatement();
  std::unique_ptr<ast::IfStatement> ParseIfStatement();
  std::unique_ptr<ast::SwitchStatement> ParseSwitchStatement();
  std::unique_ptr<ast::Statement> ParseWhileStatement();
  std::unique_ptr<ast::Statement> ParseDoWhileStatement();
  std::unique_ptr<ast::Statement> ParseForStatement();
  std::unique_ptr<ast::Statement> ParseGotoStatement();
  std::unique_ptr<ast::Statement> ParseContinueStatement();
  std::unique_ptr<ast::Statement> ParseBreakStatement();
  std::unique_ptr<ast::Statement> ParseReturnStatement();
  std::unique_ptr<ast::Statement> ParseLabelStatement();
  std::unique_ptr<ast::Statement> ParseCaseStatement();
  std::unique_ptr<ast::Statement> ParseDefaultStatement();
  std::unique_ptr<ast::Statement> ParseExpressionStatement();
  std::unique_ptr<ast::Statement> ParseNullStatement();
  std::unique_ptr<ast::Statement> ParseInlineAssembly();

  // Expression parsing methods
  std::unique_ptr<ast::Expression> ParseExpression();
  std::unique_ptr<ast::Expression> ParseAssignmentExpression();
  std::unique_ptr<ast::Expression> ParseConditionalExpression();
  std::unique_ptr<ast::Expression> ParseLogicalOrExpression();
  std::unique_ptr<ast::Expression> ParseLogicalAndExpression();
  std::unique_ptr<ast::Expression> ParseInclusiveOrExpression();
  std::unique_ptr<ast::Expression> ParseExclusiveOrExpression();
  std::unique_ptr<ast::Expression> ParseAndExpression();
  std::unique_ptr<ast::Expression> ParseEqualityExpression();
  std::unique_ptr<ast::Expression> ParseRelationalExpression();
  std::unique_ptr<ast::Expression> ParseShiftExpression();
  std::unique_ptr<ast::Expression> ParseAdditiveExpression();
  std::unique_ptr<ast::Expression> ParseMultiplicativeExpression();
  std::unique_ptr<ast::Expression> ParseCastExpression();
  std::unique_ptr<ast::Expression> ParseUnaryExpression();
  std::unique_ptr<ast::Expression> ParsePostfixExpression();
  std::unique_ptr<ast::Expression> ParsePrimaryExpression();

  // Specialized expression parsing methods
  std::unique_ptr<ast::Expression> ParseFunctionCall();
  std::unique_ptr<ast::Expression> ParseArraySubscript();
  std::unique_ptr<ast::Expression> ParseMemberAccess();
  std::unique_ptr<ast::Expression> ParsePointerMemberAccess();
  std::unique_ptr<ast::Expression> ParsePointerDereference();
  std::unique_ptr<ast::Expression> ParseAddressOf();
  std::unique_ptr<ast::Expression> ParseSizeofExpression();
  std::unique_ptr<ast::Expression> ParseAlignofExpression();
  std::unique_ptr<ast::Expression> ParseCommaExpression();
  std::unique_ptr<ast::Expression> ParseCompoundLiteral();

  // Type-related parsing methods
  std::unique_ptr<ast::TypeSpecifier> ParseTypeSpecifier();
  std::unique_ptr<ast::TypeQualifier> ParseTypeQualifier();
  std::unique_ptr<ast::StorageClassSpecifier> ParseStorageClassSpecifier();
  std::unique_ptr<ast::ASTNode> ParseFunctionSpecifier();
  std::unique_ptr<ast::ASTNode> ParseTypeName();
  std::unique_ptr<ast::ASTNode> ParseParameterTypeList();
  std::unique_ptr<ast::ASTNode> ParseParameterDeclaration();
  std::unique_ptr<ast::ASTNode> ParseAbstractDeclarator();
  std::unique_ptr<ast::ASTNode> ParseDirectAbstractDeclarator();
  std::unique_ptr<ast::ASTNode> ParseTypedefName();
  std::unique_ptr<ast::ASTNode> ParseEnumerator();
  std::unique_ptr<ast::ASTNode> ParseStructDeclarationList();
  std::unique_ptr<ast::ASTNode> ParseStructDeclaration();
  std::unique_ptr<ast::ASTNode> ParseSpecifierQualifierList();
  std::unique_ptr<ast::ASTNode> ParseStructDeclaratorList();
  std::unique_ptr<ast::ASTNode> ParseStructDeclarator();
  std::unique_ptr<ast::ASTNode> ParseComplexOrImaginaryType();
  std::unique_ptr<ast::ASTNode> ParseBooleanType();

  // Initialization parsing methods
  std::unique_ptr<ast::ASTNode> ParseInitializer();
  std::unique_ptr<ast::ASTNode> ParseInitializerList();
  std::unique_ptr<ast::ASTNode> ParseDesignation();
  std::unique_ptr<ast::ASTNode> ParseDesignator();

  // Preprocessor-related methods
  std::unique_ptr<ast::ASTNode> ParsePreprocessorDirective();

  // Utility methods
  void Synchronize();
  void ReportError(const std::string& message);
  void ReportWarning(const std::string& message);
  void ReportUnexpectedToken(const std::string& expected);
  void PanicModeRecovery();
  std::string SuggestCorrection(const lexical_analysis::Token& token);
  void PrintParsingContext();

  // Utility methods
  const lexical_analysis::Token* Peek() const;
  bool IsAtEnd() const;
  const lexical_analysis::Token* Consume(lexical_analysis::Token::Type type, const std::string& message);
  
  bool Match(lexical_analysis::Token::Type type) const;
  const lexical_analysis::Token* Advance();
  bool Check(lexical_analysis::Token::Type type) const;
  const lexical_analysis::Token* Previous() const;
  bool IsTypeSpecifier() const;
  bool IsDeclarationSpecifier() const;
  bool IsDeclarator() const;
  bool IsUniversalCharacterName(const std::string& identifier) const;

  std::string TokenTypeToString(lexical_analysis::Token::Type type) const;
};

}  // namespace syntactic_analysis
}  // namespace acc

#endif  // ACC_SYNTACTIC_ANALYSIS_CONCRETE_PARSER_H_