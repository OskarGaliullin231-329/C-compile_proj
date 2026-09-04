#ifndef LOOPMGRSTAT_HPP_
#define LOOPMGRSTAT_HPP_

#include "Statement.hpp"

// break;
// continue;
class LoopMgrStat final : public Statement {
public:
  LoopMgrStat() = default;
  LoopMgrStat(const LoopMgrStat&) = default;
  LoopMgrStat(const Token&);
  ~LoopMgrStat() = default;

  TypeId type() override;

private:
  Token _key_word;
};

#endif // LOOPMGRSTAT_HPP_
