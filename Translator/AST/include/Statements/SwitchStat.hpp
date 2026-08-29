#ifndef SWITCHSTAT_HPP_
#define SWITCHSTAT_HPP_

#include "Statement.hpp"

class SwitchStat : public Statement {};

class SwCondStat final : public SwitchStat {};

class CaseStat final : public SwitchStat {};

class DefaultStat final : public SwitchStat {};

#endif // SWITCHSTAT_HPP_
