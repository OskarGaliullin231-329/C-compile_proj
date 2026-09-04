#ifndef JUMPSTAT_HPP_
#define JUMPSTAT_HPP_

#include "Statement.hpp"

class JumpStat : public Statement {
public:
  JumpStat() = default;
  JumpStat(const JumpStat&) = default;
  JumpStat(JumpStat&&) = default;
  JumpStat(const Token&);
  ~JumpStat() = default;

  TypeId type() override;

private:
  Token _flag_name;
};

// <ID>:
class FlagStat final : public JumpStat {
public:
  TypeId type() override;
};

// goto <ID>;
class GotoStat final : public JumpStat {
public:
  TypeId type() override;
};

#endif // JUMPSTAT_HPP_
