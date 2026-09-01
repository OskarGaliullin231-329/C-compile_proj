#ifndef LOOPSTAT_HPP_
#define LOOPSTAT_HPP_

#include "../CodeBlock.hpp"
#include "Statement.hpp"

class LoopStat : public Statement {
public:
  using CBPtr = std::shared_ptr<CodeBlock>;

  TypeId type() override;

protected:
  CBPtr _code_block;
};

class ForStat final : public LoopStat {
public:
  TypeId type() override;
};

class WhileStat final : public LoopStat {
public:
  TypeId type() override;
};

class DoWhileStat final : public LoopStat {
public:
  TypeId type() override;
};

#endif // LOOPSTAT_HPP_
