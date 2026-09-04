#include "../../include/Expressions/ValExpr.hpp"

typedef ASTNode::TypeId TypeId;
typedef Lexer::Token Token;

TypeId ValExpr::type() { return Expression::type() * _num_sys_base + 1; }

Token& ValExpr::token() { return _val_token; }

TypeId IDExpr::type() { return ValExpr::type() * _num_sys_base + 1; }

TypeId LITExpr::type() { return ValExpr::type() * _num_sys_base + 2; }

TypeId FuncExpr::type() { return ValExpr::type() * _num_sys_base + 3; }

void FuncExpr::addParam(ExprPtr expr) { _params.push_back(expr); }

TypeId ArrExpr::type() { return ValExpr::type() * _num_sys_base + 4; }
