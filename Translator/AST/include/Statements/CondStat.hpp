#ifndef CONDSTAT_HPP_
#define CONDSTAT_HPP_

#include "../CodeBlock.hpp"
#include "Statement.hpp"

class CondStat : public Statement {
public:
  using CBPtr = std::shared_ptr<CodeBlock>;

  TypeId type() override;

protected:
  CBPtr _code_block;
};

class IfStat final : public CondStat {
public:
  TypeId type() override;
};

class ElseIfStat final : public CondStat {
public:
  TypeId type() override;
};

class ElseStat final : public CondStat {
public:
  TypeId type() override;
};

#endif // CONDSTAT_HPP_
