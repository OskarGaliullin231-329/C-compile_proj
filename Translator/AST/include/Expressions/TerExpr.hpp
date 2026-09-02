#ifndef TEREXPR_HPP_
#define TEREXPR_HPP_

#include "Expression.hpp"

// <expr>:_condition ? <expr>:_pos_res : <expr>:_neg_res
class TerExpr : public Expression {
public:
  TerExpr() = default;
  TerExpr(const TerExpr&) = default;

  TypeId type() override;

private:
  ExprPtr _condition;
  ExprPtr _pos_res;
  ExprPtr _neg_res;
};

#endif // TEREXPR_HPP_
