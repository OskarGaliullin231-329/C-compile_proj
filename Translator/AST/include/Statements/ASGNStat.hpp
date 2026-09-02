#ifndef ASGNSTAT_HPP_
#define ASGNSTAT_HPP_

#include "Statement.hpp"

// <ID> <ASGN_OP> <expr>;
class ASGNStat final : public Statement {
public:
  TypeId type() override;

private:
  Token _l_operand;
  Token _operator;
  ExprPtr _r_operand;
};

#endif // ASGNSTAT_HPP_
