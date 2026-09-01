#ifndef CODEBLOCK_HPP_
#define CODEBLOCK_HPP_

#include <vector>

#include "ASTNode.hpp"
#include "Statements/Statement.hpp"

struct CodeBlock {
  using StatPtr = std::shared_ptr<Statement>;
  using Iterator = std::vector<StatPtr>::iterator;

  std::vector<ASTNode> _statements;
};

#endif // CODEBLOCK_HPP_
