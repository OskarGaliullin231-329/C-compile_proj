#ifndef STATPARSER_HPP_
#define STATPARSER_HPP_

#include "../AST/include/Statements/Statement.hpp"
#include "Lexer.hpp"

class StatParser {
public:
  using LexerPtr = std::shared_ptr<Lexer>;
  using StatPtr = std::shared_ptr<Statement>;

  StatParser() = default;
  StatParser(const StatParser&) = default;
  StatParser(StatParser&&) = default;
  ~StatParser() = default;

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

#endif // STATPARSER_HPP_
