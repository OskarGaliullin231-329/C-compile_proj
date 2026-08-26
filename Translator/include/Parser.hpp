#ifndef PARSER_HPP_
#define PARSER_HPP_

#include <string_view>

#include "Lexer.hpp"

class Parser {
public:
  Parser() = default;
  Parser(const Parser&) = delete;
  Parser(Parser&&) = delete;
  ~Parser() = default;

  void operator() (const std::string_view&);

private:
  Lexer _lexer;
};

#endif // PARSER_HPP_
