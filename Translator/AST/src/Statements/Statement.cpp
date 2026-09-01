#include "../../include/Statements/Statement.hpp"

typedef ASTNode::TypeId TypeId;

TypeId Statement::type() { return ASTNode::type() * _num_sys_base + 2; }
