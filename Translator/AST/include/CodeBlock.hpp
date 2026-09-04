#ifndef CODEBLOCK_HPP_
#define CODEBLOCK_HPP_

#include <vector>

#include "Statements/Statement.hpp"

// { <Statement || CodeBlock>, ... }
struct CodeBlock {
  using StatPtr = std::shared_ptr<Statement>;
  using Iterator = std::vector<StatPtr>::iterator;

  std::vector<StatPtr> _statements;
};

#endif // CODEBLOCK_HPP_
