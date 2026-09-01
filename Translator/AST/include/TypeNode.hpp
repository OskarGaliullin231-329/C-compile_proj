#ifndef TYPENODE_HPP_
#define TYPENODE_HPP_

#include "ASTNode.hpp"

class TypeNode final : public ASTNode {
public:
  TypeId type() override;

private:
  Token _type;      // TP_KEY or TW_KEY
  Token _tp_spec;   // TS_KEY
  Token _var_spec;  // VS_KEY
};

#endif // TYPENODE_HPP_
