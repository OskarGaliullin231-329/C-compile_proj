#include "../../include/Expressions/BinExpr.hpp"

typedef ASTNode::TypeId TypeId;

TypeId BinExpr::type() { return Expression::type() * _num_sys_base + 4; }

TypeId BitExpr::type() { return BinExpr::type() * _num_sys_base + 1; }

TypeId ArithExpr::type() { return BinExpr::type() * _num_sys_base + 2; }

TypeId LgcExpr::type() { return BinExpr::type() * _num_sys_base + 3; }

TypeId ASGNExpr::type() { return BinExpr::type() * _num_sys_base + 4; }
