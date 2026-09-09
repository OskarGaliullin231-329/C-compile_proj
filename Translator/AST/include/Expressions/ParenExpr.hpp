#ifndef PARENEXPR_HPP_
#define PARENEXPR_HPP_

#include "Expression.hpp"

class ParenExpr final: public Expression {
public:
  ParenExpr(ExprPtr);

  TypeId type() override;

private:
  ExprPtr _expr;
};

#endif // PARENEXPR_HPP_
