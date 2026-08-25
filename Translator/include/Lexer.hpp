#ifndef LEXER_HPP_
#define LEXER_HPP_

#include <cstdint>
#include <string_view>

class Lexer final {
public:
  enum class TokenType : uint8_t {
    // identifiers
    ID,
    // keywords
    TP_KEY,   // types
    TS_KEY,   // type specifiers
    TD_KEY,   // type declarations
    TW_KEY,   // type wrappers
    VS_KEY,   // variavle specifiers
    SW_KEY,   // switch-case-default
    CN_KEY,   // if-else
    LP_KEY,   // loops
    LM_KEY,   // loop management
    DEF_KEY,  // default keywords
    // literals
    INT_LIT,
    FL_LIT,
    STR_LIT,
    CH_LIT,
    // operators
    ASGN_OP,
    BIN_OP,
    TER_OP,
    UN_OP,
    // delimiters
    DEL,
    // punctuation symbols
    SC_PUNC,
    ST_PUNC,
    ERR // error type
  };

  struct Token final {
    std::string_view _str;
    TokenType _tok_tp;
  };

public:
  Lexer(const std::string_view&);
  Lexer(const Lexer&) = delete;
  Lexer(Lexer&&) = delete;

public:
  Token currToken();
  bool advance();
  uint32_t currLine() { return _curr_line; }

#if DEBUG
public:
#else
private:
#endif
  // first order utility methods
  Token word();
  Token numLit();
  Token symLit();
  Token oper();
  Token punc();
  // second order utility methods
  Token errSymToken(Token&, size_t);
  Token toKeyWord(Token&);
  Token strLitToken(Token&);
  Token charLitToken(Token&);
  // third order utility methods
  Token errSymLitToken(Token&, size_t);

private:
  std::string_view _buff;
  std::string_view _remains;
  Token _token;
  uint32_t _curr_line;
};

std::string to_string(const Lexer::Token&);

#endif // LEXER_HPP_
