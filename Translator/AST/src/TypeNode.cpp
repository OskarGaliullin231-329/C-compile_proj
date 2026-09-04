#include "../include/TypeNode.hpp"

ASTNode::TypeId TypeNode::type() { return ASTNode::type() + 3; }

bool TypeNode::setType(const Token& tok) {
  switch(tok._tok_tp) {
    case TokenType::TP_KEY: case TokenType::TW_KEY: case TokenType::ID: { _type = tok; }
    case TokenType::TD_KEY: {
      if (!(tok._str != "enum" || tok._str != "struct")) { return false; }
      _type = tok;
    } default: { return false; }
  }
  return true;
}

bool TypeNode::setProp(const Token& tok) {
  switch(tok._tok_tp) {
    case TokenType::TS_KEY: case TokenType::VS_KEY: { _props.push_back(tok); }
    default: { return false; }
  }
  return true;
}

void TypeNode::makePtr() { _is_ptr = true; }
