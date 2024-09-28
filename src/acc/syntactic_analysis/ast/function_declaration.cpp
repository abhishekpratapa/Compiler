// src/acc/syntactic_analysis/ast/function_declaration.cpp
#include "acc/syntactic_analysis/ast/function_declaration.h"

#include "acc/syntactic_analysis/ast/ast_visitor.h"

namespace acc {
namespace syntactic_analysis {
namespace ast {

FunctionDeclaration::FunctionDeclaration(
    const std::string& return_type, const std::string& name,
    std::vector<std::pair<std::string, std::string>> parameters,
    std::unique_ptr<ASTNode> body)
    : return_type_(return_type),
      name_(name),
      parameters_(std::move(parameters)),
      body_(std::move(body)) {}

void FunctionDeclaration::Accept(ASTVisitor& visitor) {
  visitor.VisitFunctionDeclaration(*this);
}

const std::string& FunctionDeclaration::GetReturnType() const {
  return return_type_;
}

const std::string& FunctionDeclaration::GetName() const { return name_; }

const std::vector<std::pair<std::string, std::string>>&
FunctionDeclaration::GetParameters() const {
  return parameters_;
}

const ASTNode* FunctionDeclaration::GetBody() const { return body_.get(); }

}  // namespace ast
}  // namespace syntactic_analysis
}  // namespace acc