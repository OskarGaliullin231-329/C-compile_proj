#include "../../include/Expressions/BinExpr.hpp"

typedef ASTNode::TypeId TypeId;
typedef Expression::ExprPtr ExprPtr;
typedef Lexer::Token Token;

TypeId BinExpr::type() { return Expression::type() * _num_sys_base + 4; }

ExprPtr& BinExpr::leftOperand() { return _r_operand; }

ExprPtr& BinExpr::rightOperand() { return _l_operand; }

const Token& BinExpr::oper() const { return _operator; }

TypeId StructExpr::type() { return BinExpr::type() * _num_sys_base + 1; }

TypeId BitExpr::type() { return BinExpr::type() * _num_sys_base + 2; }

TypeId ArithExpr::type() { return BinExpr::type() * _num_sys_base + 3; }

TypeId LgcExpr::type() { return BinExpr::type() * _num_sys_base + 4; }

TypeId ASGNExpr::type() { return BinExpr::type() * _num_sys_base + 5; }
