#ifndef BINEXPR_HPP_
#define BINEXPR_HPP_

#include "Expression.hpp"

class BinExpr : public Expression {
public:
  BinExpr() = default;
  BinExpr(const BinExpr&) = default;
  BinExpr(const ExprPtr, const ExprPtr, const Token&);

protected:
  ExprPtr _l_operand;
  ExprPtr _r_operand;
  Token _operator;
};

class BitExpr final : public BinExpr {};

class ArithExpr final : public BinExpr {};

class LgcExpr final : public BinExpr {};

#endif // BINEXPR_HPP_
