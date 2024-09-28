#ifndef ACC_TYPE_SYSTEM_TYPE_CHECKER_H_
#define ACC_TYPE_SYSTEM_TYPE_CHECKER_H_

#include <memory>
#include <string>
#include <vector>
#include "acc/type_system/type.h"
#include "acc/error_handling/error_handler.h"

namespace acc {
namespace syntactic_analysis {
namespace ast {
class Expression;  // Forward declaration
}  // namespace ast
}  // namespace syntactic_analysis

namespace type_system {

class TypeChecker {
 public:
  explicit TypeChecker(error_handling::ErrorHandler* error_handler);

  bool CheckCompatibility(const Type& left, const Type& right);
  std::shared_ptr<Type> InferType(const syntactic_analysis::ast::Expression& expr);
  std::shared_ptr<Type> ApplyImplicitConversion(const Type& from, const Type& to);
  std::shared_ptr<Type> ApplyExplicitConversion(const Type& from, const Type& to);

  void CheckAssignment(const Type& left, const Type& right);
  void CheckFunctionCall(const FunctionType& func, const std::vector<std::shared_ptr<Type>>& args);
  void CheckArrayAccess(const Type& array, const Type& index);
  void CheckPointerArithmetic(const Type& pointer, const Type& offset);

  // New methods for function pointer support
  bool CheckFunctionPointerCompatibility(const FunctionPointerType& left, const FunctionPointerType& right);
  void CheckFunctionPointerAssignment(const FunctionPointerType& left, const FunctionPointerType& right);
  void CheckFunctionPointerCall(const FunctionPointerType& func_ptr, const std::vector<std::shared_ptr<Type>>& args);
  void WarnSuspiciousFunctionPointerCast(const FunctionPointerType& from, const FunctionPointerType& to);
  bool CanConvertFunctionToFunctionPointer(const FunctionType& func, const FunctionPointerType& func_ptr);
  void CheckFunctionPointerOperation(const Type& left, const Type& right, const std::string& operation);
  void CheckFunctionPointerComparison(const FunctionPointerType& left, const FunctionPointerType& right);

 private:
  error_handling::ErrorHandler* error_handler_;

  void ReportError(const std::string& message);
  void ReportWarning(const std::string& message);
  std::string GetTypeMismatchError(const Type& expected, const Type& actual);
  const Type* UnwrapQualifiedType(const Type* type);
  bool AreCallingConventionsCompatible(CallingConvention left, CallingConvention right);
};

}  // namespace type_system
}  // namespace acc

#endif  // ACC_TYPE_SYSTEM_TYPE_CHECKER_H_