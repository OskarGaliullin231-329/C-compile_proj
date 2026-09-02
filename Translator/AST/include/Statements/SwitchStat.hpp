#ifndef SWITCHSTAT_HPP_
#define SWITCHSTAT_HPP_

#include "../CodeBlock.hpp"
#include "Statement.hpp"

class SwitchStat : public Statement {
public:
  using CBPtr = std::shared_ptr<CodeBlock>;

  TypeId type() override;

protected:
  CBPtr _code_block;
};

// switch(<expr>) <CodeBlock>
class SwCondStat final : public SwitchStat {
public:
  TypeId type() override;
};

// case <expr>: <CodeBlock>
class CaseStat final : public SwitchStat {
public:
  TypeId type() override;
};

// default: <CodeBlock>
class DefaultStat final : public SwitchStat {
public:
  TypeId type() override;
};

#endif // SWITCHSTAT_HPP_
