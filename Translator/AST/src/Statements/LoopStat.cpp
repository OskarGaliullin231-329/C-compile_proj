#include "../../include/Statements/LoopStat.hpp"

typedef ASTNode::TypeId TypeId;

TypeId LoopStat::type() { return Statement::type() + 4; }

TypeId ForStat::type() { return LoopStat::type() + 1; }

TypeId WhileStat::type() { return LoopStat::type() + 2; }

TypeId DoWhileStat::type() { return LoopStat::type() + 3; }
