#ifndef DECLSTAT_HPP_
#define DECLSTAT_HPP_

#include "Statement.hpp"
#include "../TypeNode.hpp"

class DeclStat : public Statement {
public:
  using TpNdPtr = std::shared_ptr<TypeNode>;

protected:
  TpNdPtr _type_node;
};

class VarDeclStat final : public DeclStat {};

class FuncDeclStat final : public DeclStat {};

#endif // DECLSTAT_HPP_
