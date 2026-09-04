#include "../../include/Statements/ExprStat.hpp"

typedef ASTNode::TypeId TypeId;

TypeId ExprStat::type() { return Statement::type() + 3; }
