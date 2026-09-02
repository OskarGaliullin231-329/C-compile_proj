#ifndef BINEXPR_HPP_
#define BINEXPR_HPP_

#include "Expression.hpp"

// <expr> <BIN_OP> <expr>
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

// <expr> <BIN_OP -> BitOp> <expr>
class BitExpr final : public BinExpr {
public:
  TypeId type() override;
};

// <expr> <BIN_OP -> ArithOp> <expr>
class ArithExpr final : public BinExpr {
public:
  TypeId type() override;
};

// <expr> <BIN_OP -> LogicOp> <expr>
class LgcExpr final : public BinExpr {
public:
  TypeId type() override;
};

// <ID> <ASGN_OP> <expr>
class ASGNExpr : public BinExpr {
public:
  TypeId type() override;
};

#endif // BINEXPR_HPP_
