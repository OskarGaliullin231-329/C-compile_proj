#ifndef STRITER_HPP_
#define STRITER_HPP_

#include <string>

/*
 * This class' goal is to provide interface that lets users to know
 * which line they are on based on iterator.
 * Wanted to carry that logic away from parts of translator such as
 * Lexer, Parser and SemanticAnalizer.
 */

class StrIter final {
public:
  StrIter(const std::string&);
  StrIter(const StrIter&);

  size_t currLine() { return _curr_line; }

  bool atStart() { return (_iter == _buff.begin()); }
  bool atEnd()   { return (_iter == _buff.end()); }

  StrIter operator++(int);
  StrIter operator--(int);
  char operator*();

private:
  std::string_view _buff;
  std::string_view::iterator _iter;
  size_t _curr_line;
};

#endif // STRITER_HPP_
