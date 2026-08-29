#ifndef ASGNSTAT_HPP_
#define ASGNSTAT_HPP_

#include "Statement.hpp"

class ASGNStat final : public Statement {
public:
private:
  Token _l_operand;
  Token _operator;
  ExprPtr _r_operand;
};

#endif // ASGNSTAT_HPP_
