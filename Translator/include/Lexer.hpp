#ifndef LEXER_HPP_
#define LEXER_HPP_

#include <cstdint>
#include <string_view>

class Lexer final {
public:
  enum class TokenType : uint8_t {
    ID,
    KEY,
    // literals
    INT_LIT,
    FL_LIT,
    STR_LIT,
    CH_LIT,
    // operators
    ADD_OP,
    MUL_OP,
    LGC_OP,
    BIT_OP,
    ASGN_OP,
    // delimiters
    DEL,
    // punctuation symbols
    SC_PUNC,
    ST_PUNC
  };

  struct Token final {
    std::string_view _str;
    TokenType _tok_tp;
  };

public:
  Lexer(const std::string_view&);
  Lexer(const Lexer&) = delete;
  Lexer(Lexer&&) = delete;

  Token nextToken();

private:
  Token word();
  Token numLit();
  Token symLit();
  Token oper();
  Token punc();

private:
  std::string_view _buff;
  std::string_view _remains;
};

#endif // LEXER_HPP_
