#include "../../include/Statements/LoopMgrStat.hpp"

typedef ASTNode::TypeId TypeId;

LoopMgrStat::LoopMgrStat(const Token& tok) {
  switch(tok._tok_tp) {
    case TokenType::LM_KEY: { _key_word = tok; }
    default: { break; }
  }
}

TypeId LoopMgrStat::type() { return Statement::type() * _num_sys_base + 6; }
