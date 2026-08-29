#ifndef VALEXPR_HPP_
#define VALEXPR_HPP_

#include "Expression.hpp"

class ValExpr : public Expression {
public:
  ValExpr() = default;
  ValExpr(const ValExpr&) = default;
  ValExpr(const Token&);

protected:
  Token _val_token;
};

class IDExpr final : public ValExpr {};

class LITExpr final : public ValExpr {};

class FuncExpr final : public ValExpr {};

#endif // VALEXPR_HPP_
