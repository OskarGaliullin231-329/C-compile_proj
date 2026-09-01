#ifndef SWITCHSTAT_HPP_
#define SWITCHSTAT_HPP_

#include "Statement.hpp"

class SwitchStat : public Statement {
public:
  TypeId type() override;
};

class SwCondStat final : public SwitchStat {
public:
  TypeId type() override;
};

class CaseStat final : public SwitchStat {
public:
  TypeId type() override;
};

class DefaultStat final : public SwitchStat {
public:
  TypeId type() override;
};

#endif // SWITCHSTAT_HPP_
