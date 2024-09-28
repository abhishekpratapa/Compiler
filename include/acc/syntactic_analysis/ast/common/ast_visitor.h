#ifndef ACC_SYNTACTIC_ANALYSIS_AST_AST_VISITOR_H_
#define ACC_SYNTACTIC_ANALYSIS_AST_AST_VISITOR_H_

namespace acc {
namespace syntactic_analysis {
namespace ast {

// Forward declarations for all AST node types
class FunctionDeclaration;
class BinaryExpression;
class UnaryExpression;
class Literal;
class IfStatement;
class WhileStatement;
class ForStatement;
class ReturnStatement;
class CompoundStatement;
class ExpressionStatement;
class VariableDeclaration;
class ArrayDeclaration;
class StructDeclaration;
class UnionDeclaration;
class EnumDeclaration;
class TypedefDeclaration;
class FunctionCall;
class ArraySubscript;
class MemberAccess;
class PointerMemberAccess;
class CastExpression;
class SizeofExpression;
class AlignofExpression;
class ConditionalExpression;
class CommaExpression;
class InitializerList;
class Designator;
class TypeName;
class AbstractDeclarator;
class DirectAbstractDeclarator;
class ParameterDeclaration;
class StructDeclarator;
class VariableLengthArrayDeclaration;
class PreprocessorDirective;
class DoWhileStatement;
class SwitchStatement;
class CaseStatement;
class DefaultStatement;
class LabelStatement;
class GotoStatement;
class ContinueStatement;
class BreakStatement;
class NullStatement;
class InlineAssembly;
class TranslationUnit;
class ExternalDeclaration;
class ComplexOrImaginaryType;
class BooleanType;
class TypedefName;
class EllipsisParameter;
class PointerDeclaration;
class BitFieldDeclaration;
class AddressOf;
class PointerDereference;
class Initializer;
class Designation;
class CompoundLiteral;
class StructDeclarationList;
class ParameterTypeList;
class TypeSpecifier;
class TypeQualifier;
class StorageClassSpecifier;
class FunctionSpecifier;
class SpecifierQualifierList;

class ASTVisitor {
 public:
  virtual ~ASTVisitor() = default;

  // Visit methods for all AST node types
  virtual void VisitFunctionDeclaration(const FunctionDeclaration& node) = 0;
  virtual void VisitBinaryExpression(const BinaryExpression& node) = 0;
  virtual void VisitUnaryExpression(const UnaryExpression& node) = 0;
  virtual void VisitLiteral(const Literal& node) = 0;
  virtual void VisitIfStatement(const IfStatement& node) = 0;
  virtual void VisitWhileStatement(const WhileStatement& node) = 0;
  virtual void VisitForStatement(const ForStatement& node) = 0;
  virtual void VisitReturnStatement(const ReturnStatement& node) = 0;
  virtual void VisitCompoundStatement(const CompoundStatement& node) = 0;
  virtual void VisitExpressionStatement(const ExpressionStatement& node) = 0;
  virtual void VisitVariableDeclaration(const VariableDeclaration& node) = 0;
  virtual void VisitArrayDeclaration(const ArrayDeclaration& node) = 0;
  virtual void VisitStructDeclaration(const StructDeclaration& node) = 0;
  virtual void VisitUnionDeclaration(const UnionDeclaration& node) = 0;
  virtual void VisitEnumDeclaration(const EnumDeclaration& node) = 0;
  virtual void VisitTypedefDeclaration(const TypedefDeclaration& node) = 0;
  virtual void VisitFunctionCall(const FunctionCall& node) = 0;
  virtual void VisitArraySubscript(const ArraySubscript& node) = 0;
  virtual void VisitMemberAccess(const MemberAccess& node) = 0;
  virtual void VisitPointerMemberAccess(const PointerMemberAccess& node) = 0;
  virtual void VisitCastExpression(const CastExpression& node) = 0;
  virtual void VisitSizeofExpression(const SizeofExpression& node) = 0;
  virtual void VisitAlignofExpression(const AlignofExpression& node) = 0;
  virtual void VisitConditionalExpression(const ConditionalExpression& node) = 0;
  virtual void VisitCommaExpression(const CommaExpression& node) = 0;
  virtual void VisitInitializerList(const InitializerList& node) = 0;
  virtual void VisitDesignator(const Designator& node) = 0;
  virtual void VisitTypeName(const TypeName& node) = 0;
  virtual void VisitAbstractDeclarator(const AbstractDeclarator& node) = 0;
  virtual void VisitDirectAbstractDeclarator(const DirectAbstractDeclarator& node) = 0;
  virtual void VisitParameterDeclaration(const ParameterDeclaration& node) = 0;
  virtual void VisitStructDeclarator(const StructDeclarator& node) = 0;
  virtual void VisitVariableLengthArrayDeclaration(const VariableLengthArrayDeclaration& node) = 0;
  virtual void VisitPreprocessorDirective(const PreprocessorDirective& node) = 0;
  virtual void VisitDoWhileStatement(const DoWhileStatement& node) = 0;
  virtual void VisitSwitchStatement(const SwitchStatement& node) = 0;
  virtual void VisitCaseStatement(const CaseStatement& node) = 0;
  virtual void VisitDefaultStatement(const DefaultStatement& node) = 0;
  virtual void VisitLabelStatement(const LabelStatement& node) = 0;
  virtual void VisitGotoStatement(const GotoStatement& node) = 0;
  virtual void VisitContinueStatement(const ContinueStatement& node) = 0;
  virtual void VisitBreakStatement(const BreakStatement& node) = 0;
  virtual void VisitNullStatement(const NullStatement& node) = 0;
  virtual void VisitInlineAssembly(const InlineAssembly& node) = 0;
  virtual void VisitTranslationUnit(const TranslationUnit& node) = 0;
  virtual void VisitExternalDeclaration(const ExternalDeclaration& node) = 0;
  virtual void VisitComplexOrImaginaryType(const ComplexOrImaginaryType& node) = 0;
  virtual void VisitBooleanType(const BooleanType& node) = 0;
  virtual void VisitTypedefName(const TypedefName& node) = 0;
  virtual void VisitEllipsisParameter(const EllipsisParameter& node) = 0;
  virtual void VisitPointerDeclaration(const PointerDeclaration& node) = 0;
  virtual void VisitBitFieldDeclaration(const BitFieldDeclaration& node) = 0;
  virtual void VisitAddressOf(const AddressOf& node) = 0;
  virtual void VisitPointerDereference(const PointerDereference& node) = 0;
  virtual void VisitInitializer(const Initializer& node) = 0;
  virtual void VisitDesignation(const Designation& node) = 0;
  virtual void VisitCompoundLiteral(const CompoundLiteral& node) = 0;
  virtual void VisitStructDeclarationList(const StructDeclarationList& node) = 0;
  virtual void VisitParameterTypeList(const ParameterTypeList& node) = 0;
  virtual void VisitTypeSpecifier(const TypeSpecifier& node) = 0;
  virtual void VisitTypeQualifier(const TypeQualifier& node) = 0;
  virtual void VisitStorageClassSpecifier(const StorageClassSpecifier& node) = 0;
  virtual void VisitFunctionSpecifier(const FunctionSpecifier& node) = 0;
  virtual void VisitSpecifierQualifierList(const SpecifierQualifierList& node) = 0;
};

}  // namespace ast
}  // namespace syntactic_analysis
}  // namespace acc

#endif  // ACC_SYNTACTIC_ANALYSIS_AST_AST_VISITOR_H_