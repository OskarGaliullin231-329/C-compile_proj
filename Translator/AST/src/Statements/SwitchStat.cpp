#include "../../include/Statements/SwitchStat.hpp"

typedef ASTNode::TypeId TypeId;

TypeId SwitchStat::type() { return Statement::type() + 5; }

TypeId SwCondStat::type() { return SwitchStat::type() + 1; }

TypeId CaseStat::type() { return SwitchStat::type() + 2; }

TypeId DefaultStat::type() { return SwitchStat::type() + 3; }
