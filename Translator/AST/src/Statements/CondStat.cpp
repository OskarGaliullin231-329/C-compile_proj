#include "../../include/Statements/CondStat.hpp"

typedef ASTNode::TypeId TypeId;

TypeId CondStat::type() { return Statement::type() * _num_sys_base + 2; }

TypeId IfStat::type() { return CondStat::type() * _num_sys_base + 1; }

TypeId ElseIfStat::type() { return CondStat::type() * _num_sys_base + 2; }

TypeId ElseStat::type() { return CondStat::type() * _num_sys_base + 3; }
