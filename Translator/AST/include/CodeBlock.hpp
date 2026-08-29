#ifndef CODEBLOCK_HPP_
#define CODEBLOCK_HPP_

#include <vector>

#include "Statements/Statement.hpp"

class CodeBlock final {
public:
  using StatPtr = std::shared_ptr<Statement>;
  using Iterator = std::vector<StatPtr>::iterator;

  void addStatement(const Statement&);
  Iterator firstStatIter();
  Iterator endStatIter();

private:
  std::vector<StatPtr> _statements;
};

#endif // CODEBLOCK_HPP_
