#ifndef UNEXPR_HPP_
#define UNEXPR_HPP_

#include "Expression.hpp"

class UnExpr : public Expression {
public:
  UnExpr() = default;
  UnExpr(const UnExpr&) = default;
  UnExpr(const Token&, ExprPtr);

  TypeId type() override;

private:
  Token _operator;
  ExprPtr _operand;
};

#endif // UNEXPR_HPP_
