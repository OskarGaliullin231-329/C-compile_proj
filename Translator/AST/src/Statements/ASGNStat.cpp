#include "../../include/Statements/ASGNStat.hpp"

typedef ASTNode::TypeId TypeId;

TypeId ASGNStat::type() { return Statement::type() * _num_sys_base + 1; }
