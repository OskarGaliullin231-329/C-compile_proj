#ifndef BINEXPR_HPP_
#define BINEXPR_HPP_

#include "Expression.hpp"

// <expr>:_l_operand <BIN_OP>:_operator <expr>:_r_operand
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

// <expr>:_l_operand <BIN_OP -> BitOp>:_operator <expr>:_r_operand
class BitExpr final : public BinExpr {
public:
  TypeId type() override;
};

// <expr>:_l_operand <BIN_OP -> ArithOp>:_operator <expr>:_r_operand
class ArithExpr final : public BinExpr {
public:
  TypeId type() override;
};

// <expr>:_l_operand <BIN_OP -> LogicOp>:_operator <expr>:_r_operand
class LgcExpr final : public BinExpr {
public:
  TypeId type() override;
};

#endif // BINEXPR_HPP_
