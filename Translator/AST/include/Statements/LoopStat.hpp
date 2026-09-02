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

// for (<VarDeclStat> <ExprStat> <expr>) <CodeBlock>
class ForStat final : public LoopStat {
public:
  TypeId type() override;
};

// while (<expr>) <CodeBlock>
class WhileStat final : public LoopStat {
public:
  TypeId type() override;
};

// do <CodeBlock> while (<expr>);
class DoWhileStat final : public LoopStat {
public:
  TypeId type() override;
};

#endif // LOOPSTAT_HPP_
