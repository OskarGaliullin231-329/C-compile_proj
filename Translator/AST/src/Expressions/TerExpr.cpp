#include "../../include/Expressions/TerExpr.hpp"

typedef ASTNode::TypeId TypeId;

TypeId TerExpr::type() { return Expression::type() * _num_sys_base + 3; }
