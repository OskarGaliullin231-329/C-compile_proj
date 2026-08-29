#ifndef STATEMENT_HPP_
#define STATEMENT_HPP_

#include <memory>

#include "../ASTNode.hpp"
#include "../Expressions/Expression.hpp"

class Statement : public ASTNode {
public:
  using StatPtr = std::shared_ptr<Statement>;
  using Expr = Expression;
  using ExprPtr = std::shared_ptr<Expression>;

private:
};

#endif // STATEMENT_HPP_
