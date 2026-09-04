#ifndef ASTNODE_HPP_
#define ASTNODE_HPP_

#include <memory>

#include "../../include/Lexer.hpp"
#include "../../../Logger/include/StdLogger.hpp"

// this is an interface for other types of nodes
class ASTNode {
public:
  using Logger = Logger<StdLogger>;
  using NodePtr = std::shared_ptr<ASTNode>;
  using Token = Lexer::Token;
  using TokenType = Lexer::TokenType;
  using TypeId = uint16_t;

  virtual ~ASTNode() = default;

  /*
   * Hexadecimal codes for types;
   * Global ID - unique identificator of type.
   * Local ID - identificator of type that might not be
   * unique among all types, but it's unique among its brother types:
   * types that have same parent.
   * Children have global ID's equal to:
   * <parent global ID> * _num_sys_base + <local ID>.
   */
  virtual TypeId type() = 0;

protected:
  static TypeId _num_sys_base;
};

inline ASTNode::TypeId ASTNode::_num_sys_base = 16;

#endif // ASTNODE_HPP_
