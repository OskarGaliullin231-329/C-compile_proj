#ifndef LOOPSTAT_HPP_
#define LOOPSTAT_HPP_

#include "Statement.hpp"

class LoopStat : public Statement {};

class ForStat final : public LoopStat {};

class WhileStat final : public LoopStat {};

class DoWhileStat final : public LoopStat {};

#endif // LOOPSTAT_HPP_
