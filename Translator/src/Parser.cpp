#include "../include/Parser.hpp"

void Parser::operator() (const std::string_view& str) { _lexer(str); }
