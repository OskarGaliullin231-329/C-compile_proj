#ifndef VALEXPR_HPP_
#define VALEXPR_HPP_

#include "Expression.hpp"

class ValExpr : public Expression {
public:
  ValExpr() = default;
  ValExpr(const ValExpr&) = default;
  ValExpr(const Token&);

  TypeId type() override;

protected:
  Token _val_token;
};

class IDExpr final : public ValExpr {
public:
  TypeId type() override;
};

class LITExpr final : public ValExpr {
public:
  TypeId type() override;
};

class FuncExpr final : public ValExpr {
public:
  TypeId type() override;
};

#endif // VALEXPR_HPP_
