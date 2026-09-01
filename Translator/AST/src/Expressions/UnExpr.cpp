#include "../../include/Expressions/UnExpr.hpp"

typedef ASTNode::TypeId TypeId;

TypeId UnExpr::type() { return Expression::type() * _num_sys_base + 2; }
