// src/acc/syntactic_analysis/ast/literal.cpp
#include "acc/syntactic_analysis/ast/literal.h"

#include "acc/syntactic_analysis/ast/ast_visitor.h"

namespace acc {
namespace syntactic_analysis {
namespace ast {

Literal::Literal(const std::string& value) : value_(value) {}

void Literal::Accept(ASTVisitor& visitor) { visitor.VisitLiteral(*this); }

const std::string& Literal::GetValue() const { return value_; }

}  // namespace ast
}  // namespace syntactic_analysis
}  // namespace acc