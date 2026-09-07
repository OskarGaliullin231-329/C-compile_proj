#ifndef EXPRFACTORY_HPP_
#define EXPRFACTORY_HPP_

#include "../AST/include/Expressions/Expression.hpp"
#include "NodeFactory.hpp"

class ExprFactory final : public NodeFactory<ExprFactory> {
public:
  using ExprPtr = std::shared_ptr<Expression>;

  ExprFactory() = default;
  ExprFactory(const ExprFactory&) = default;
  ExprFactory(ExprFactory&&) = default;
  ~ExprFactory() = default;

  ExprPtr create();

private:
  ExprPtr createBinExpr();
  ExprPtr createStructExpr();
  ExprPtr createBitExpr();
  ExprPtr createArithExpr();
  ExprPtr createLgcExpr();
  ExprPtr createASGNExpr();

  ExprPtr createTerExpr();

  ExprPtr createUnExpr();

  ExprPtr createValExpr();
  ExprPtr createIDExpr();
  ExprPtr createLITExpr();
  ExprPtr createFuncExpr();
  ExprPtr createArrExpr();

private:
  // no explicit usage of Lexer::advance()
  ExprPtr handleValTok();
  ExprPtr handleParenTok();
};

#endif // EXPRFACTORY_HPP_
