#ifndef BINEXPR_HPP_
#define BINEXPR_HPP_

#include "Expression.hpp"

// <expr> <BIN_OP> <expr>
class BinExpr : public Expression {
public:
  BinExpr() = default;
  BinExpr(const BinExpr&) = default;
  BinExpr(const ExprPtr, const ExprPtr, const Token&);
  ~BinExpr() = default;

  TypeId type() override;

protected:
  ExprPtr _l_operand;
  ExprPtr _r_operand;
  Token _operator;
};

// <expr> <BIN_OP -> BitOp> <expr>
class BitExpr final : public BinExpr {
public:
  BitExpr() = default;
  BitExpr(const BitExpr&) = default;
  BitExpr(const ExprPtr, const ExprPtr, const Token&);
  ~BitExpr() = default;

  TypeId type() override;
};

// <expr> <BIN_OP -> ArithOp> <expr>
class ArithExpr final : public BinExpr {
public:
  ArithExpr() = default;
  ArithExpr(const ArithExpr&) = default;
  ArithExpr(const ExprPtr, const ExprPtr, const Token&);
  ~ArithExpr() = default;

  TypeId type() override;
};

// <expr> <BIN_OP -> LogicOp> <expr>
class LgcExpr final : public BinExpr {
public:
  LgcExpr() = default;
  LgcExpr(const LgcExpr&) = default;
  LgcExpr(const ExprPtr, const ExprPtr, const Token&);
  ~LgcExpr() = default;

  TypeId type() override;
};

// <ID> <ASGN_OP> <expr>
class ASGNExpr : public BinExpr {
public:
  ASGNExpr() = default;
  ASGNExpr(const ASGNExpr&) = default;
  ASGNExpr(const ExprPtr, const ExprPtr, const Token&);
  ~ASGNExpr() = default;

  TypeId type() override;
};

class StructExpr : public BinExpr {
  StructExpr() = default;
  StructExpr(const StructExpr&) = default;
  StructExpr(const ExprPtr, const ExprPtr, const Token&);
  ~StructExpr() = default;

  TypeId type() override;
};

#endif // BINEXPR_HPP_
