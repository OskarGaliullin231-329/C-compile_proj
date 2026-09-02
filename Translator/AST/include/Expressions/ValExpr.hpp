#ifndef VALEXPR_HPP_
#define VALEXPR_HPP_

#include <vector>

#include "Expression.hpp"

// <Token>
class ValExpr : public Expression {
public:
  ValExpr() = default;
  ValExpr(const ValExpr&) = default;
  ValExpr(const Token&);

  virtual TypeId type() override;
  virtual Token getToken();

protected:
  Token _val_token;
};

// <ID>
class IDExpr final : public ValExpr {
public:
  TypeId type() override;
  Token getToken() override;
};

// <INT_LIT || FL_LIT || CH_LIT || STR_LIT>
class LITExpr final : public ValExpr {
public:
  TypeId type() override;
  Token getToken() override;
};

// <ID>()
// <ID>(<expr>, ...)
class FuncExpr final : public ValExpr {
public:
  using FuncParams = std::vector<ExprPtr>;

  TypeId type() override;
  Token getToken() override;
private:
};

#endif // VALEXPR_HPP_
