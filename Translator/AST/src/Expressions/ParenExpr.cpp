#include "../../include/Expressions/ParenExpr.hpp"

typedef ASTNode::TypeId TypeId;

ParenExpr::ParenExpr(ExprPtr expr) { _expr = expr; }

TypeId ParenExpr::type() { return Expression::type() * _num_sys_base + 1; }
