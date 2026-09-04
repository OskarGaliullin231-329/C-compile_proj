#ifndef DECLSTAT_HPP_
#define DECLSTAT_HPP_

#include <vector>

#include "../CodeBlock.hpp"
#include "Statement.hpp"
#include "../TypeNode.hpp"

class DeclStat : public Statement {
public:
  using CBPtr = std::shared_ptr<CodeBlock>;
  using TpNdPtr = std::shared_ptr<TypeNode>;

  TypeId type() override;

protected:
  Token _id;
};

// <TypeNode> <ID>;           // in CodeBlock
// <TypeNode> <ID> = <expr>;  // in CodeBlock
// <TypeNode> <ID>,           // in FuncParams
class VarDeclStat final : public DeclStat {
public:
  TypeId type() override;

private:
  TpNdPtr _type_node;
  ExprPtr _val;
};

// <TypeNode> <ID>[<LITExpr || NONE>];
class ArrDeclStat final : public DeclStat {
public:
  TypeId type() override;

private:
  TpNdPtr _type_node;
};

// <TypeNode> <ID>() <CodeBlock>
// <TypeNode> <ID>(<VarDeclStat>, ...) <CodeBlock>
class FuncDeclStat final : public DeclStat {
public:
  using VDSPtr = VarDeclStat;
  using FuncParams = std::vector<VDSPtr>;

  bool addParam(TpNdPtr);

  TypeId type() override;

private:
  FuncParams _params;
  TpNdPtr _type_node;
  CBPtr _code_block;
};

// <struct || enum || union> <ID> <CodeBlock>;
class StructDeclStat final : public DeclStat {
public:
  TypeId type() override;

private:
  Token _def_type; // struct || enum || union
  CBPtr _code_block;
};

// typedef <TypeNode> <ID>;
class TypedefDeclStat final : public DeclStat {
public:
  TypeId type() override;

private:
  TpNdPtr _type_node;
};

#endif // DECLSTAT_HPP_
