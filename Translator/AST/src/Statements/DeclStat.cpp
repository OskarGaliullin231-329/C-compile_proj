#include "../../include/Statements/DeclStat.hpp"

typedef ASTNode::TypeId TypeId;

TypeId DeclStat::type() { return Statement::type() * _num_sys_base + 3; }

TypeId VarDeclStat::type() { return DeclStat::type() * _num_sys_base + 1; }

TypeId FuncDeclStat::type() { return DeclStat::type() * _num_sys_base + 2; }

TypeId StructDeclStat::type() { return DeclStat::type() * _num_sys_base + 3; }

TypeId TypedefDeclStat::type() { return DeclStat::type() * _num_sys_base + 4; }
