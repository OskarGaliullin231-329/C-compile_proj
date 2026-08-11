#ifndef LEXER_HPP_
#define LEXER_HPP_

#include <cstdint>
#include <string>

class Lexer final {
public:
  enum class TokenType : uint8_t {
    ID,
    KEY,
    LIT,
    OP,
    DEL,
    PUNC
  };

  struct Token final {
    std::string_view _str;
    TokenType _tok_tp;
  };

public:
  Lexer(const std::string& source_code) { _buff = source_code; }
  Lexer(const Lexer&) = delete;
  Lexer(Lexer&&) = delete;

  Token nextToken();

private:
  std::string_view _buff;
};

#endif // LEXER_HPP_
