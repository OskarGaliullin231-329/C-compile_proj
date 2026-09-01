#ifndef BINEXPR_HPP_
#define BINEXPR_HPP_

#include "Expression.hpp"

class BinExpr : public Expression {
public:
  BinExpr() = default;
  BinExpr(const BinExpr&) = default;
  BinExpr(const ExprPtr, const ExprPtr, const Token&);

  TypeId type() override;

protected:
  ExprPtr _l_operand;
  ExprPtr _r_operand;
  Token _operator;
};

class BitExpr final : public BinExpr {
public:
  TypeId type() override;
};

class ArithExpr final : public BinExpr {
public:
  TypeId type() override;
};

class LgcExpr final : public BinExpr {
public:
  TypeId type() override;
};

#endif // BINEXPR_HPP_
