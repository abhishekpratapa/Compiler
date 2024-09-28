// File: include/acc/syntactic_analysis/parser.h

#ifndef ACC_SYNTACTIC_ANALYSIS_PARSER_H_
#define ACC_SYNTACTIC_ANALYSIS_PARSER_H_

#include <memory>
#include <vector>

#include "acc/error_handling/error_handler.h"
#include "acc/lexical_analysis/token.h"
#include "acc/syntactic_analysis/ast/declarations/translation_unit.h"

namespace acc {
namespace syntactic_analysis {

/**
 * @class Parser
 * @brief Abstract base class for syntactic analysis.
 *
 * This class defines the interface for parsing tokens into an Abstract Syntax
 * Tree (AST).
 */
class Parser {
 public:
  virtual ~Parser() = default;

  /**
   * @brief Parses the input tokens into an AST.
   * @param tokens The input tokens to parse.
   * @return A unique pointer to the root of the AST (TranslationUnit).
   */
  virtual std::unique_ptr<ast::TranslationUnit> Parse(
      const std::vector<std::unique_ptr<lexical_analysis::Token>>& tokens) = 0;

  /**
   * @brief Sets the error handler for the parser.
   * @param error_handler A pointer to the ErrorHandler object.
   */
  virtual void SetErrorHandler(error_handling::ErrorHandler* error_handler) = 0;

 protected:
  Parser() = default;
};

}  // namespace syntactic_analysis
}  // namespace acc

#endif  // ACC_SYNTACTIC_ANALYSIS_PARSER_H_