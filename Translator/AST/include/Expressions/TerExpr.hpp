#ifndef TEREXPR_HPP_
#define TEREXPR_HPP_

#include "Expression.hpp"

class TerExpr : public Expression {
public:
  TerExpr() = default;
  TerExpr(const TerExpr&) = default;

private:
  ExprPtr _condition;
  ExprPtr _pos_res;
  ExprPtr _neg_res;
};

#endif // TEREXPR_HPP_
