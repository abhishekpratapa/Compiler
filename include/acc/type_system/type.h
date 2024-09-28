#ifndef ACC_TYPE_SYSTEM_TYPE_H_
#define ACC_TYPE_SYSTEM_TYPE_H_

#include <memory>
#include <string>
#include <vector>
#include <optional>

namespace acc {
namespace type_system {

enum class CallingConvention {
  kCdecl,
  kStdcall,
  kFastcall
};

class Type {
 public:
  enum class Kind {
    kVoid,
    kChar,
    kInt,
    kFloat,
    kDouble,
    kPointer,
    kArray,
    kStruct,
    kUnion,
    kEnum,
    kFunction,
    kFunctionPointer,
    kTypedef,
    kQualified
  };

  virtual ~Type() = default;

  virtual Kind GetKind() const = 0;
  virtual std::string ToString() const = 0;
  virtual bool IsCompatibleWith(const Type& other) const = 0;

  virtual bool IsScalar() const {
    Kind k = GetKind();
    return k == Kind::kChar || k == Kind::kInt || k == Kind::kFloat || 
           k == Kind::kDouble || k == Kind::kPointer || k == Kind::kEnum ||
           k == Kind::kFunctionPointer;
  }

  virtual bool IsFunctionOrFunctionPointer() const {
    Kind k = GetKind();
    return k == Kind::kFunction || k == Kind::kFunctionPointer;
  }

  virtual const Type* ResolveTypedef() const {
    return this;
  }

  bool IsConst() const { return is_const_; }
  bool IsVolatile() const { return is_volatile_; }
  void SetConst(bool value) { is_const_ = value; }
  void SetVolatile(bool value) { is_volatile_ = value; }

 protected:
  Type() : is_const_(false), is_volatile_(false) {}

 private:
  bool is_const_;
  bool is_volatile_;
};


class PrimitiveType : public Type {
 public:
  explicit PrimitiveType(Kind kind);

  Kind GetKind() const override { return kind_; }
  std::string ToString() const override;
  bool IsCompatibleWith(const Type& other) const override;

 private:
  Kind kind_;
};

class PointerType : public Type {
 public:
  explicit PointerType(std::shared_ptr<Type> pointed_type);

  Kind GetKind() const override { return Kind::kPointer; }
  std::string ToString() const override;
  bool IsCompatibleWith(const Type& other) const override;

  const Type* GetPointedType() const { return pointed_type_.get(); }

 private:
  std::shared_ptr<Type> pointed_type_;
};

class ArrayType : public Type {
 public:
  ArrayType(std::shared_ptr<Type> element_type, std::optional<size_t> size = std::nullopt);

  Kind GetKind() const override { return Kind::kArray; }
  std::string ToString() const override;
  bool IsCompatibleWith(const Type& other) const override;

  const Type* GetElementType() const { return element_type_.get(); }
  std::optional<size_t> GetSize() const { return size_; }

 private:
  std::shared_ptr<Type> element_type_;
  std::optional<size_t> size_;
};

class StructType : public Type {
 public:
  struct Member {
    std::string name;
    std::shared_ptr<Type> type;
  };

  explicit StructType(const std::string& name);

  Kind GetKind() const override { return Kind::kStruct; }
  std::string ToString() const override;
  bool IsCompatibleWith(const Type& other) const override;

  void AddMember(const std::string& name, std::shared_ptr<Type> type);
  const std::vector<Member>& GetMembers() const { return members_; }

 private:
  std::string name_;
  std::vector<Member> members_;
};

class FunctionType : public Type {
 public:
  FunctionType(std::shared_ptr<Type> return_type,
               std::vector<std::shared_ptr<Type>> parameter_types,
               CallingConvention convention = CallingConvention::kCdecl,
               bool is_variadic = false);

  Kind GetKind() const override { return Kind::kFunction; }
  std::string ToString() const override;
  bool IsCompatibleWith(const Type& other) const override;
  bool IsEquivalentTo(const FunctionType& other) const;

  const Type* GetReturnType() const { return return_type_.get(); }
  const std::vector<std::shared_ptr<Type>>& GetParameterTypes() const {
    return parameter_types_;
  }
  CallingConvention GetCallingConvention() const { return convention_; }
  bool IsVariadic() const { return is_variadic_; }

  void AddAttribute(const std::string& attribute);
  const std::vector<std::string>& GetAttributes() const { return attributes_; }

 private:
  std::shared_ptr<Type> return_type_;
  std::vector<std::shared_ptr<Type>> parameter_types_;
  CallingConvention convention_;
  bool is_variadic_;
  std::vector<std::string> attributes_;
};

class FunctionPointerType : public Type {
 public:
  explicit FunctionPointerType(std::shared_ptr<FunctionType> function_type);

  Kind GetKind() const override { return Kind::kFunctionPointer; }
  std::string ToString() const override;
  bool IsCompatibleWith(const Type& other) const override;

  const FunctionType* GetFunctionType() const { return function_type_.get(); }

 private:
  std::shared_ptr<FunctionType> function_type_;
};

class TypedefType : public Type {
 public:
  TypedefType(const std::string& name, std::shared_ptr<Type> underlying_type);

  Kind GetKind() const override { return Kind::kTypedef; }
  std::string ToString() const override;
  bool IsCompatibleWith(const Type& other) const override;

  const std::string& GetName() const { return name_; }
  const Type* GetUnderlyingType() const { return underlying_type_.get(); }
  const Type* ResolveTypedef() const override {
    return underlying_type_->ResolveTypedef();
  }

 private:
  std::string name_;
  std::shared_ptr<Type> underlying_type_;
};

class EnumType : public Type {
 public:
  explicit EnumType(const std::string& name);

  Kind GetKind() const override { return Kind::kEnum; }
  std::string ToString() const override;
  bool IsCompatibleWith(const Type& other) const override;

  const std::string& GetName() const { return name_; }
  void AddEnumerator(const std::string& name, int value);

 private:
  std::string name_;
  std::vector<std::pair<std::string, int>> enumerators_;
};

class UnionType : public Type {
 public:
  struct Member {
    std::string name;
    std::shared_ptr<Type> type;
  };

  explicit UnionType(const std::string& name);

  Kind GetKind() const override { return Kind::kUnion; }
  std::string ToString() const override;
  bool IsCompatibleWith(const Type& other) const override;

  void AddMember(const std::string& name, std::shared_ptr<Type> type);
  const std::vector<Member>& GetMembers() const { return members_; }

 private:
  std::string name_;
  std::vector<Member> members_;
};

class QualifiedType : public Type {
 public:
  QualifiedType(std::shared_ptr<Type> base_type, bool is_const, bool is_volatile);

  Kind GetKind() const override { return Kind::kQualified; }
  std::string ToString() const override;
  bool IsCompatibleWith(const Type& other) const override;

  const Type* GetBaseType() const { return base_type_.get(); }
  bool IsConst() const { return is_const_; }
  bool IsVolatile() const { return is_volatile_; }

 private:
  std::shared_ptr<Type> base_type_;
  bool is_const_;
  bool is_volatile_;
};

}  // namespace type_system
}  // namespace acc

#endif  // ACC_TYPE_SYSTEM_TYPE_H_