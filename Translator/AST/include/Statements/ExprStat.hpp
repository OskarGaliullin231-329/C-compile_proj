#ifndef EXPRSTAT_HPP_
#define EXPRSTAT_HPP_

#include "Statement.hpp"

class ExprStat final : public Statement {
public:
  TypeId type() override;

private:
  ExprPtr _expr;
};

#endif // EXPRSTAT_HPP_
