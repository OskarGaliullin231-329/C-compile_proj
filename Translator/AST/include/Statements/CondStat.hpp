#ifndef CONDSTAT_HPP_
#define CONDSTAT_HPP_

#include "../CodeBlock.hpp"
#include "Statement.hpp"

class CondStat : public Statement {
public:
  using CBPtr = std::shared_ptr<CodeBlock>;

protected:
  CBPtr _code_block;
};

class IfStat final : public CondStat {};

class ElseIfStat final : public CondStat {};

class ElseStat final : public CondStat {};

#endif // CONDSTAT_HPP_
