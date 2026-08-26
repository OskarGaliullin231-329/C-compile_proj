#include "../include/Lexer.hpp"

#include <array>
#include <set>
#include <string>

#include "utils/Lexer_utils.hpp"
#include "../../Logger/include/StdLogger.hpp"

Lexer::Token Lexer::currToken() noexcept {
  if (_remains.empty()) { return { "", TokenType::ERR }; }
  if (_token._str.empty()) {
    char sym = _remains[0];
    switch(char_type(sym)) {
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
        _curr_line += (sym == '\n');
        _token._str = _remains.substr(0, 1);
        _token._tok_tp = TokenType::DEL;
        break;
      }
      case CharTypes::ERR: {
        _token._str = _remains.substr(0, 1);
        _token._tok_tp = TokenType::ERR;
        return _token;
      }
    }
  }
  return _token;
}

bool Lexer::advance() noexcept {
  bool result = !(_remains.empty() || (_token._tok_tp == TokenType::ERR));
  if (result) {
    _remains.remove_prefix(_token._str.size());
    _token._str.remove_prefix(_token._str.size());
  }
  return result;
}

void Lexer::operator()(const std::string_view& source_code) {
  _buff = source_code;
  _remains = _buff;
  _curr_line = 0;
}

Lexer::Token Lexer::word() noexcept {
  Token result {
    ._str = _remains,
    ._tok_tp = TokenType::ID
  };
  size_t rem_size = _remains.size();
  size_t tok_len = 0;
  for (tok_len = 0; tok_len < rem_size; tok_len++) {
    switch(char_type(_remains[tok_len])) {
      case CharTypes::WORD:
      case CharTypes::DIGIT: {
        break;
      }
      case CharTypes::DEL: {
        _curr_line += (_remains[tok_len] == '\n');
        goto word_assembly_loop_end;
      }
      case CharTypes::ERR: { return errSymToken(result, tok_len); }
      default: { goto word_assembly_loop_end; }
    }
  }
  word_assembly_loop_end:
  result._str.remove_suffix(rem_size - tok_len);
  return toKeyWord(result);
}

Lexer::Token Lexer::toKeyWord(Lexer::Token& tok) const noexcept {
  const uint8_t num_types = 10;
  std::array<std::set<std::string_view>, num_types> kw_types;
  kw_types[0] = {"void", "int", "float", "double", "char"}; // TP_KEY
  kw_types[1] = {"long", "short", "signed", "unsigned"}; // TS_KEY
  kw_types[2] = {"struct", "enum", "union", "typedef"}; // TD_KEY
  kw_types[3] = {"auto"}; // TW_KEY
  kw_types[4] = {"const", "static", "volatile", "extern", "register"}; // VS_KEY
  kw_types[5] = {"switch", "case", "default"}; // SW_KEY
  kw_types[6] = {"if", "else"}; // CN_KEY
  kw_types[7] = {"for", "while", "do"}; // LP_KEY
  kw_types[8] = {"break", "continue"}; // LM_KEY
  kw_types[9] = {"return", "goto", "sizeof"}; // DEF_KEY
  for (uint8_t i = 0; i < num_types; i++) {
    if (kw_types[i].find(tok._str) != kw_types[i].end()) {
      tok._tok_tp = TokenType(uint8_t(TokenType::TP_KEY) + i);
      break;
    }
  }
  return tok;
}

Lexer::Token Lexer::numLit() noexcept {
  Token result {
    ._str = _remains,
    ._tok_tp = TokenType::INT_LIT
  };
  size_t rem_size = _remains.size();
  size_t tok_len = 0;
  size_t dots_num = 0;
  for (tok_len = 0; tok_len < rem_size; tok_len++) {
    switch(char_type(_remains[tok_len])) {
      case CharTypes::WORD: {
        Logger<StdLogger>::getInstance().addEvent(Event(_curr_line, "Unexpected symbols met in numerical literal."));
        result._str.remove_prefix(rem_size - tok_len);
        result._tok_tp = TokenType::ERR;
        return result;
      }
      case CharTypes::DIGIT: { break; }
      case CharTypes::OPER: {
        if (_remains[tok_len] == '.') { dots_num++; }
        else { goto num_assembly_loop_end; }
        break;
      }
      case CharTypes::DEL: {
        _curr_line += (_remains[tok_len] == '\n');
        goto num_assembly_loop_end;
      }
      case CharTypes::ERR: { return errSymToken(result, tok_len); }
      default: { goto num_assembly_loop_end; }
    }
  }
  num_assembly_loop_end:
  result._str.remove_suffix(rem_size - tok_len);
  switch(dots_num) {
    case 0: {
      result._tok_tp = TokenType::INT_LIT;
      break;
    }
    case 1: {
      result._tok_tp = TokenType::FL_LIT;
      break;
    }
    default: {
      Logger<StdLogger>::getInstance().addEvent(Event(_curr_line, "Incorrect floating point literal: too many dots."));
      result._tok_tp = TokenType::ERR;
    }
  }
  return result;
}

Lexer::Token Lexer::errSymToken(Token& token, size_t index) const noexcept {
  std::string err_msg = "Unsupported symbol: ";
  err_msg += _remains[index];
  err_msg += '.';
  Logger<StdLogger>::getInstance().addEvent(Event(_curr_line, err_msg));
  token._str.remove_suffix(_remains.size() - index - 1);
  token._tok_tp = TokenType::ERR;
  return token;
}

Lexer::Token Lexer::symLit() const noexcept {
  Token result {
    ._str = _remains,
    ._tok_tp = TokenType::CH_LIT
  };
  switch(result._str[0]) {
    case '\'': { return charLitToken(result); }
    case '"': { return strLitToken(result); }
  }
  return result;
}

Lexer::Token Lexer::charLitToken(Token& token) const noexcept {
  token._tok_tp = TokenType::CH_LIT;
  size_t rem_size = _remains.size();
  size_t tok_len = 0;
  for (tok_len = 1; tok_len < rem_size; tok_len++) {
    switch(_remains[tok_len]) {
      case '\'': {
        token._str.remove_suffix(rem_size - tok_len - 1);
        goto ch_lit_assembly_loop_end;
      }
      case '\n': { return errSymLitToken(token, tok_len); }
      default: { continue; }
    }
  }
  ch_lit_assembly_loop_end:
  switch(token._str.size()) {
    case 0: case 1: case 2: {
      Logger<StdLogger>::getInstance().addEvent(Event(_curr_line, "Unterminated character literal."));
      token._tok_tp = TokenType::ERR;
    }
    case 3: { break; }
    default: {
      Logger<StdLogger>::getInstance().addEvent(Event(_curr_line, "Too much symbols in character literal."));
      token._tok_tp = TokenType::ERR;
    }
  }
  return token;
}

Lexer::Token Lexer::strLitToken(Token& token) const noexcept {
  token._tok_tp = TokenType::STR_LIT;
  size_t rem_size = _remains.size();
  size_t tok_len = 0;
  for (tok_len = 1; tok_len < rem_size; tok_len++) {
    switch(_remains[tok_len]) {
      case '"': {
        token._str.remove_suffix(rem_size - tok_len - 1);
        return token;
      }
      case '\n': { return errSymLitToken(token, tok_len); }
      default: { continue; }
    }
  }
  if (tok_len == rem_size) {
    Logger<StdLogger>::getInstance().addEvent(Event(_curr_line, "Unterminated string literal."));
    token._tok_tp = TokenType::ERR;
  }
  return token;
}

Lexer::Token Lexer::errSymLitToken(Token& token, size_t index) const noexcept {
  Logger<StdLogger>::getInstance().addEvent(Event(_curr_line, "Unexpected EOL in symbolic literal."));
  token._str.remove_suffix(_remains.size() - index);
  token._tok_tp = TokenType::ERR;
  return token;
}

Lexer::Token Lexer::oper() const noexcept {
  Token result { ._str = _remains.substr(0, 3) };
  std::set<std::string_view> un_opers = {"!", "~", "++", "--"};
  std::set<std::string_view> ter_opers = {"?"};
  std::set<std::string_view> bin_opers = {"+", "-", "*", "/", "%", "&&", "||", "&", "|", "^", "<<", ">>", ".", "->", "<", ">", "<=", ">=", "==", "!="};
  std::set<std::string_view> asgn_opers = {"=", "+=", "-=", "*=", "/=", "%=", "&=", "|=", "^=", "<<=", ">>="};
  if (un_opers.find(result._str) != un_opers.end()) { result._tok_tp = TokenType::UN_OP; return result; }
  else if (ter_opers.find(result._str) != ter_opers.end()) { result._tok_tp = TokenType::TER_OP; return result; }
  else if (bin_opers.find(result._str) != bin_opers.end()) { result._tok_tp = TokenType::BIN_OP; return result; }
  if (asgn_opers.find(result._str) != asgn_opers.end()) { result._tok_tp = TokenType::ASGN_OP; return result; }
  else { result._str.remove_suffix(1); }
  if (un_opers.find(result._str) != un_opers.end()) { result._tok_tp = TokenType::UN_OP; return result; }
  else if (ter_opers.find(result._str) != ter_opers.end()) { result._tok_tp = TokenType::TER_OP; return result; }
  else if (bin_opers.find(result._str) != bin_opers.end()) { result._tok_tp = TokenType::BIN_OP; return result; }
  else if (asgn_opers.find(result._str) != asgn_opers.end()) { result._tok_tp = TokenType::ASGN_OP; return result; }
  else { result._str.remove_suffix(1); }
  if (un_opers.find(result._str) != un_opers.end()) { result._tok_tp = TokenType::UN_OP; return result; }
  else if (ter_opers.find(result._str) != ter_opers.end()) { result._tok_tp = TokenType::TER_OP; return result; }
  else if (bin_opers.find(result._str) != bin_opers.end()) { result._tok_tp = TokenType::BIN_OP; return result; }
  else if (asgn_opers.find(result._str) != asgn_opers.end()) { result._tok_tp = TokenType::ASGN_OP; return result; }
  return result;
}

Lexer::Token Lexer::punc() const noexcept {
  Token result { ._str = _remains.substr(0, 1), };
  switch(_remains[0]) {
    case '{': case '}': case '(': case ')': {
      result._tok_tp = TokenType::SC_PUNC;
      break;
    }
    case ',': case ';': case ':': {
      result._tok_tp = TokenType::ST_PUNC;
      break;
    }
  }
  return result;
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
    case Lexer::TokenType::ASGN_OP: { str = "ASGN_OP"; break; }
    case Lexer::TokenType::BIN_OP:  { str = "BIN_OP";  break; }
    case Lexer::TokenType::TER_OP:  { str = "TER_OP";  break; }
    case Lexer::TokenType::UN_OP:   { str = "UN_OP";   break; }
    case Lexer::TokenType::DEL:     { str = "DEL";     break; }
    case Lexer::TokenType::SC_PUNC: { str = "SC_PUNC"; break; }
    case Lexer::TokenType::ST_PUNC: { str = "ST_PUNC"; break; }
    case Lexer::TokenType::ERR:     { str = "ERR";     break; }
  }
  return str;
}

std::string to_string(const Lexer::Token& tok) {
  std::string str = to_string(tok._tok_tp) + "(";
  if (tok._str == " ") { str += "SPACE"; }
  else if (tok._str == "\t") { str += "\\t"; }
  else if (tok._str == "\n") { str += "\\n"; }
  else { str += tok._str; }
  str += ')';
  return str;
}
