#include "../include/Lexer.hpp"

#include <array>
#include <set>
#include <string>

#include "utils/Lexer_utils.hpp"

Lexer::Lexer(const std::string_view& source_code) {
  _buff = source_code;
  _remains = _buff;
}

Lexer::Token Lexer::currToken() {
  if (_remains.empty()) { return { "", TokenType::ERR }; }
  if (_token._str.empty()) {
    char sym = _remains[0];
    switch(type(sym)) {
      case CharTypes::WORD: {
        _token = word();
        break;
      }
      case CharTypes::DIGIT: {
        _token = numLit();
        break;
      }
      case CharTypes::OPER: {
        _token = oper();
        break;
      }
      case CharTypes::PUNC: {
        _token = punc();
        break;
      }
      case CharTypes::QUOT: {
        _token = symLit();
        break;
      }
      case CharTypes::DEL: {
        _token._str = _remains.substr(0, 1);
        _token._tok_tp = TokenType::DEL;
        break;
      }
      case CharTypes::ERR: { return { "", TokenType::ERR }; }
    }
  }
  return _token;
}

bool Lexer::advance() {
  bool result = !_remains.empty();
  if (result) {
    _remains.remove_prefix(_token._str.size());
    _token._str.remove_prefix(_token._str.size());
  }
  return result;
}

Lexer::Token Lexer::word() {
  Token result {
    ._str = _remains,
    ._tok_tp = TokenType::ID
  };
  size_t rem_size = _remains.size();
  size_t tok_len = 0;
  for (tok_len = 0; tok_len < rem_size; tok_len++) {
    switch(type(_remains[tok_len])) {
      case CharTypes::WORD:
      case CharTypes::DIGIT: {
        break;
      }
      case CharTypes::DEL: {
        if (_remains[tok_len] == '\n') { _curr_line++; }
        break;
      }
      default: { goto word_assembly_loop_end; }
    }
  }
  word_assembly_loop_end:
  result._str.remove_suffix(rem_size - tok_len);
  return toKeyWord(result);
}

Lexer::Token Lexer::numLit() {
  Token result{ ._tok_tp = TokenType::INT_LIT };
  // TODO: implement logic
  return result;
}

Lexer::Token Lexer::symLit()  {
  Token result{ ._tok_tp = TokenType::CH_LIT };
  // TODO: implement logic
  return result;
}

Lexer::Token Lexer::oper()  {
  Token result{ ._tok_tp = TokenType::ADD_OP };
  // TODO: implement logic
  return result;
}

Lexer::Token Lexer::punc()  {
  Token result{ ._tok_tp = TokenType::SC_PUNC };
  // TODO: implement logic
  return result;
}

Lexer::Token Lexer::toKeyWord(Lexer::Token& tok) {
  const uint8_t num_types = 10;
  std::array<std::set<std::string_view>, num_types> kw_types;
  kw_types[0] = {
    "void", "int", "float", "double", "char"
  }; // TP_KEY
  kw_types[1] = {
    "long", "short", "signed", "unsigned"
  }; // TS_KEY
  kw_types[2] = {
    "struct", "enum", "union", "typedef"
  }; // TD_KEY
  kw_types[3] = {
    "auto"
  }; // TW_KEY
  kw_types[4] = {
    "const", "static", "volatile", "extern", "register"
  }; // VS_KEY
  kw_types[5] = {
    "switch", "case", "default"
  }; // SW_KEY
  kw_types[6] = {
    "if", "else"
  }; // CN_KEY
  kw_types[7] = {
    "for", "while", "do"
  }; // LP_KEY
  kw_types[8] = {
    "break", "continue"
  }; // LM_KEY
  kw_types[9] = {
    "return", "goto", "sizeof"
  }; // DEF_KEY
  for (uint8_t i = 0; i < num_types; i++) {
    if (kw_types[i].find(tok._str) != kw_types[i].end()) {
      tok._tok_tp = TokenType(uint8_t(TokenType::TP_KEY) + i);
      break;
    }
  }
  return tok;
}

std::string to_string(Lexer::TokenType type) {
  std::string str;
  switch(type) {
    case Lexer::TokenType::ID:      { str = "ID";      break; }
    case Lexer::TokenType::TP_KEY:  { str = "TP_KEY";  break; }
    case Lexer::TokenType::TS_KEY:  { str = "TS_KEY";  break; }
    case Lexer::TokenType::TD_KEY:  { str = "TD_KEY";  break; }
    case Lexer::TokenType::TW_KEY:  { str = "TW_KEY";  break; }
    case Lexer::TokenType::VS_KEY:  { str = "VS_KEY";  break; }
    case Lexer::TokenType::SW_KEY:  { str = "SW_KEY";  break; }
    case Lexer::TokenType::CN_KEY:  { str = "CN_KEY";  break; }
    case Lexer::TokenType::LP_KEY:  { str = "LP_KEY";  break; }
    case Lexer::TokenType::LM_KEY:  { str = "LM_KEY";  break; }
    case Lexer::TokenType::DEF_KEY: { str = "DEF_KEY"; break; }
    case Lexer::TokenType::INT_LIT: { str = "INT_LIT"; break; }
    case Lexer::TokenType::FL_LIT:  { str = "FL_LIT";  break; }
    case Lexer::TokenType::STR_LIT: { str = "STR_LIT"; break; }
    case Lexer::TokenType::CH_LIT:  { str = "CH_LIT";  break; }
    case Lexer::TokenType::ADD_OP:  { str = "ADD_OP";  break; }
    case Lexer::TokenType::MUL_OP:  { str = "MUL_OP";  break; }
    case Lexer::TokenType::LGC_OP:  { str = "LGC_OP";  break; }
    case Lexer::TokenType::BIT_OP:  { str = "BIT_OP";  break; }
    case Lexer::TokenType::ASGN_OP: { str = "ASGN_OP"; break; }
    case Lexer::TokenType::DEL:     { str = "DEL";     break; }
    case Lexer::TokenType::SC_PUNC: { str = "SC_PUNC"; break; }
    case Lexer::TokenType::ST_PUNC: { str = "ST_PUNC"; break; }
    case Lexer::TokenType::ERR:     { str = "ERR";     break; }
  }
  return str;
}

std::string to_string(const Lexer::Token& tok) {
  std::string str = to_string(tok._tok_tp) + "(";
  if (tok._str == " ") { str += "*SPACE*"; }
  else if (tok._str == "\t") { str += "\\t"; }
  else if (tok._str == "\n") { str += "\\n"; }
  else { str += tok._str; }
  str += ')';
  return str;
}
