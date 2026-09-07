#ifndef STATFACTORY_HPP_
#define STATFACTORY_HPP_

#include "../AST/include/Statements/Statement.hpp"
#include "Lexer.hpp"

class StatFactory {
public:
  using LexerPtr = std::shared_ptr<Lexer>;
  using StatPtr = std::shared_ptr<Statement>;

  StatFactory() = default;
  StatFactory(const StatFactory&) = default;
  StatFactory(StatFactory&&) = default;
  ~StatFactory() = default;

  StatPtr create();

private:
  StatPtr createCondStat();
  StatPtr createIfStat();
  StatPtr createElseIfStat();
  StatPtr createElse();

  StatPtr createDeclStat();
  StatPtr createVarDeclStat();
  StatPtr createArrDeclStat();
  StatPtr createFuncDeclStat();
  StatPtr createStuctDeclStat();
  StatPtr createTypdefDeclStat();

  StatPtr createExprStat();

  StatPtr createJumpStat();
  StatPtr createFlagStat();
  StatPtr createGotoStat();

  StatPtr createLoopMgrStat();

  StatPtr createLoopStat();
  StatPtr createForStat();
  StatPtr createWhileStat();
  StatPtr createDoWhileStat();

  StatPtr createSwitchStat();
  StatPtr createSwCondStat();
  StatPtr createCaseStat();
  StatPtr createDefaultStat();

private:
  LexerPtr _lexer;
};

#endif // STATFACTORY_HPP_
