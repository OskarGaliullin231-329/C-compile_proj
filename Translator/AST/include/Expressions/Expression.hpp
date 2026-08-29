#ifndef EXPREESSION_HPP_
#define EXPREESSION_HPP_

#include "../ASTNode.hpp"
#include <memory>

class Expression : public ASTNode {
public:
  using ExprPtr = std::shared_ptr<Expression>;
  using Expr = Expression;
};

#endif // EXPREESSION_HPP_
