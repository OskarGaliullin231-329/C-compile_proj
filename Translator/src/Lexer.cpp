#include "../include/Lexer.hpp"

#include <string_view>

#include "utils/Lexer_utils.hpp"

Lexer::Lexer(const std::string_view& source_code) {
  _buff = source_code;
}

Lexer::Token Lexer::nextToken() {
  Token token;
  char sym = _remains[0];
  switch(type(sym)) {
    case charTypes::WORD: {
      token = word();
      break;
    }
    case charTypes::DIGIT: {
      token = numLit();
      break;
    }
    case charTypes::OPER: {
      token = oper();
      break;
    }
    case charTypes::PUNC: {
      token = punc();
      break;
    }
    case charTypes::QUOT: {
      token = symLit();
      break;
    }
    case charTypes::ERR: {}
  }
  _remains.remove_prefix(token._str.size());
  return token;
}

Lexer::Token Lexer::word() {
  Token result{ ._tok_tp = TokenType::ID };
  // TODO: implement logic
  return result;
}

Lexer::Token Lexer::numLit() {
  Token result{ ._tok_tp = TokenType::INT_LIT };
  // TODO: implement logic
  return result;
}

Lexer::Token Lexer::symLit() {
  Token result{ ._tok_tp = TokenType::CH_LIT };
  // TODO: implement logic
  return result;
}

Lexer::Token Lexer::oper() {
  Token result{ ._tok_tp = TokenType::ADD_OP };
  // TODO: implement logic
  return result;
}

Lexer::Token Lexer::punc() {
  Token result{ ._tok_tp = TokenType::SC_PUNC };
  // TODO: implement logic
  return result;
}
