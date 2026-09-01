#include "../../include/Expressions/ValExpr.hpp"

typedef ASTNode::TypeId TypeId;

TypeId ValExpr::type() { return Expression::type() * _num_sys_base + 1; }

TypeId IDExpr::type() { return ValExpr::type() * _num_sys_base + 1; }

TypeId LITExpr::type() { return ValExpr::type() * _num_sys_base + 2; }

TypeId FuncExpr::type() { return ValExpr::type() * _num_sys_base + 3; }
