#include "../../include/Statements/JumpStat.hpp"

typedef ASTNode::TypeId TypeId;

TypeId JumpStat::type() { return Statement::type() * _num_sys_base + 7; }

TypeId FlagStat::type() { return JumpStat::type() * _num_sys_base + 1; }

TypeId GotoStat::type() { return JumpStat::type() * _num_sys_base + 2; }
