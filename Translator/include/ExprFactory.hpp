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
  ExprPtr createParenExpr();

  ExprPtr createValExpr();
  ExprPtr createIDExpr();
  ExprPtr createLITExpr();
  ExprPtr createFuncExpr();
  ExprPtr createArrExpr();

  ExprPtr createUnExpr();

  ExprPtr createTerExpr(ExprPtr);

  ExprPtr createBinExpr(ExprPtr, const Token&);
  ExprPtr createStructExpr();
  ExprPtr createBitExpr();
  ExprPtr createArithExpr();
  ExprPtr createLgcExpr();
  ExprPtr createASGNExpr();

private:
  // no explicit usage of NodeFactory::advance()
  ExprPtr createValExprIDHandler();
};

#endif // EXPRFACTORY_HPP_
