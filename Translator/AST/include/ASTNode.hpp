#ifndef ASTNODE_HPP_
#define ASTNODE_HPP_

#include <memory>

#include "../../include/Lexer.hpp"

// this is an interface for other types of nodes
class ASTNode {
public:
  using NodePtr = std::shared_ptr<ASTNode>;
  using Token = Lexer::Token;
  using TokenType = Lexer::TokenType;

private:
};

#endif // ASTNODE_HPP_
