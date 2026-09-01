#include "../../include/Expressions/Expression.hpp"

typedef ASTNode::TypeId TypeId;

TypeId Expression::type() { return ASTNode::type() * _num_sys_base + 1; }
