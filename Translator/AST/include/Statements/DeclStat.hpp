#ifndef DECLSTAT_HPP_
#define DECLSTAT_HPP_

#include <vector>

#include "Statement.hpp"
#include "../TypeNode.hpp"

class DeclStat : public Statement {
public:
  using TpNdPtr = std::shared_ptr<TypeNode>;

  TypeId type() override;
};

class VarDeclStat final : public DeclStat {
public:
  TypeId type() override;

private:
  TpNdPtr _type_node;
  Token _id;
};

class FuncDeclStat final : public DeclStat {
public:
  using FuncParams = std::vector<VarDeclStat>;

  bool addParam(TpNdPtr);

  TypeId type() override;

private:
  TpNdPtr _type_node;
  Token _id;
  FuncParams _params;
};

class StructDeclStat final : public DeclStat {
public:
  TypeId type() override;
};

class TypedefDeclStat final : public DeclStat {
public:
  TypeId type() override;
};

#endif // DECLSTAT_HPP_
