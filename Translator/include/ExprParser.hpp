#ifndef EXPRPARSER_HPP_
#define EXPRPARSER_HPP_

#include "../AST/include/Expressions/Expression.hpp"

class ExprParser {
public:
  using LexerPtr = std::shared_ptr<Lexer>;
  using ExprPtr = std::shared_ptr<Expression>;

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
  LexerPtr _lexer;
};

#endif // EXPRPARSER_HPP_
