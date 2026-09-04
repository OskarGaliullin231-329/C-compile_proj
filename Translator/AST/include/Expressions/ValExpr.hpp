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
  Token& token();

protected:
  Token _val_token;
};

// <ID>
class IDExpr final : public ValExpr {
public:
  IDExpr(const Token&);

  TypeId type() override;
};

// <INT_LIT || FL_LIT || CH_LIT || STR_LIT>
class LITExpr final : public ValExpr {
public:
  LITExpr(const Token&);

  TypeId type() override;
};

// <ID>()
// <ID>(<expr>, ...)
// sizeof(<expr>)
// sizeof(<TypeNode>)
class FuncExpr final : public ValExpr {
public:
  using FuncParams = std::vector<ExprPtr>;

  FuncExpr(const Token&);

  TypeId type() override;
  void addParam(ExprPtr);

private:
  FuncParams _params;
};

class ArrExpr : public ValExpr {
public:
  ArrExpr(const Token&);

  TypeId type() override;

private:
  ExprPtr _index_expr;
};

#endif // VALEXPR_HPP_
