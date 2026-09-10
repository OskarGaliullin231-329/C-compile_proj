#include "../include/ExprFactory.hpp"

#include "../AST/include/Expressions/BinExpr.hpp"
#include "../AST/include/Expressions/ParenExpr.hpp"
#include "../AST/include/Expressions/UnExpr.hpp"
#include "../AST/include/Expressions/ValExpr.hpp"

typedef Expression::ExprPtr ExprPtr;
typedef std::shared_ptr<IDExpr> IDExprPtr;
typedef std::shared_ptr<LITExpr> LITExprPtr;
typedef std::shared_ptr<FuncExpr> FuncExprPtr;
typedef std::shared_ptr<ArrExpr> ArrExprPtr;
typedef std::shared_ptr<UnExpr> UnExprPtr;
typedef std::shared_ptr<StructExpr> StructExprPtr;
typedef std::shared_ptr<BitExpr> BitExprPtr;
typedef std::shared_ptr<ArithExpr> ArithExprPtr;
typedef std::shared_ptr<LgcExpr> LgcExprPtr;
typedef std::shared_ptr<ASGNExpr> ASGNExprPtr;
typedef std::shared_ptr<ParenExpr> ParenExprPtr;

// public interface

ExprPtr ExprFactory::create() {
  ExprPtr result = nullptr;
  if (!_ok) { return result; }
  switch (_curr_token._tok_tp) {
    // returning ValExpr
    case TokenType::ID:
    case TokenType::DEF_KEY:
    case TokenType::INT_LIT:
    case TokenType::FL_LIT:
    case TokenType::CH_LIT:
    case TokenType::STR_LIT: {
      result = createValExpr();
      break;
    }
    // returning UnExpr
    case TokenType::UN_OP: {
      result = createUnExpr();
      break;
    }
    // returning ExprPtr with higher priority
    case TokenType::SC_PUNC: {
      result = createParenExpr();
      break;
    }
    // TODO: add all cases
    default: {
      _ok = false;
      std::string err_msg = "Invalid token '";
      err_msg += _curr_token._str;
      err_msg += "' in expression.";
      Logger::getInstance().addEvent(Event(_lexer->currLine(), err_msg));
      result = nullptr;
      return result;
    }
  }
  switch(_next_token._tok_tp) {
    case TokenType::BIN_OP:
    case TokenType::ASGN_OP: {
      result = createBinExpr(result, _next_token);
      break;
    }
    case TokenType::TER_OP: {
      result = createTerExpr(result);
      break;
    }
    case TokenType::SC_PUNC:
    case TokenType::ST_PUNC: { break; }
    default: {
      _ok = false;
      Logger::getInstance().addEvent(Event(_lexer->currLine(), "Invalid token sequence in multi-argument expression."));
      result = nullptr;
      break;
    }
  }
  return result;
}

// private interface

// handler for all types of parenthesis
// (<expr>)
ExprPtr ExprFactory::createParenExpr() {
  ExprPtr result = nullptr;
  switch(_curr_token._str[0]) {
    case '(': { break; }
    case ')' : {
      Logger::getInstance().addEvent(Event(_lexer->currLine(), "Stray closing parenthesis."));
      return result;
    }
    default: {
      Logger::getInstance().addEvent(Event(_lexer->currLine(), "Invalid parenthesis type wraps an expression."));
      return result;
    }
  }
  switch(advance()) {
    case true: {
      ExprPtr expr = create();
      result = (expr->type() == 0x11) ? expr : ParenExprPtr(new ParenExpr(expr));
      break;
    }
    case false: {
      _ok = false;
      Logger::getInstance().addEvent(Event(_lexer->currLine(), "Unclosed parethesis till the end."));
      return result;
    }
  }
  switch(_next_token._str[0]) {
    case ')': { break; }
    default: {
      Logger::getInstance().addEvent(Event(_lexer->currLine(), "Unclosed parethesis in statement."));
      return nullptr;
    }
  }
  return result;
}

// _curr_token._tok_tp = <LIT || ID || sizeof>
ExprPtr ExprFactory::createValExpr() {
  ExprPtr result = nullptr;
  switch(_curr_token._tok_tp) {
    case TokenType::ID: {
      result = createValExprIDHandler();
      break;
    }
    case TokenType::INT_LIT:
    case TokenType::FL_LIT:
    case TokenType::CH_LIT:
    case TokenType::STR_LIT: {
      result = createLITExpr();
      break;
    }
    case TokenType::DEF_KEY: {
      result = createFuncExpr();
      break;
    }
  }
  return result;
}

// _curr_token._tok_tp = TokenType::ID
ExprPtr ExprFactory::createIDExpr() {
  ExprPtr result = IDExprPtr(new IDExpr(_curr_token));
  return result;
}

// _curr_token._tok_tp = TokenType::INT_LIT
// _curr_token._tok_tp = TokenType::FL_LIT
// _curr_token._tok_tp = TokenType::CH_LIT
// _curr_token._tok_tp = TokenType::STR_LIT
ExprPtr ExprFactory::createLITExpr() {
  ExprPtr result = LITExprPtr(new LITExpr(_curr_token));
  return result;
}

// _curr_token._tok_tp = TokenType::ID
// _next_token._str = '('
ExprPtr ExprFactory::createFuncExpr() {
  ExprPtr result = nullptr;
  // TODO: implement logic
  return result;
}

// _curr_token._tok_tp = TokenType::ID
// _next_token._str = '['
ExprPtr ExprFactory::createArrExpr() {
  ExprPtr result = nullptr;
  Token curr_tok = _curr_token;
  switch(advance() && advance()) {
    case true: { break; }
    case false: {
      Logger::getInstance().addEvent(Event(_lexer->currLine(), "Absence of index-expression in array-expression."));
      return result;
    }
  }
  ExprPtr index_expr = create();
  switch(_next_token._str == "]") {
    case true: {
      result = ArrExprPtr(new ArrExpr(curr_tok, index_expr));
      break;
    }
    case false: {
      _ok = false;
      Logger::getInstance().addEvent(Event(_lexer->currLine(), "Unterminated index expression in array expression."));
    }
  }
  advance();
  return result;
}

// _curr_token._tok_tp = TokenType::UN_OP
ExprPtr ExprFactory::createUnExpr() {
  ExprPtr result = nullptr;
  Token op = _curr_token;
  switch(advance()) {
    case true: {
      ExprPtr expr = create();
      result = (_ok) ? UnExprPtr(new UnExpr(op, expr)) : nullptr;
      break;
    }
    case false: {
      Logger::getInstance().addEvent(Event(_lexer->currLine(), "Expected expression after unary operator."));
      break;
    }
  }
  return result;
}

// _next_token._tok_tp = TokenType::TER_OP
ExprPtr ExprFactory::createTerExpr(ExprPtr cond) {
  ExprPtr result;
  // TODO: implement logic
  return result;
}

// _next_token._tok_tp = TokenType::BIN_OP
// _next_token._tok_tp = TokenType::ASGN_OP
ExprPtr ExprFactory::createBinExpr(ExprPtr l_oper, const Token& tok) {
  ExprPtr result;
  // no 'create()' calls allowed
  // so Expression tree grows to the left and not to the right
  // if operators with same priority are met multiple times

  // TODO: implement logic
  return result;
}

// _next_token._str = "."
// _next_token._str = "->"
ExprPtr ExprFactory::createStructExpr() {
  ExprPtr result;
  // TODO: implement logic
  return result;
}

// _next_token._str = <Bit operator>
ExprPtr ExprFactory::createBitExpr() {
  ExprPtr result;
  // TODO: implement logic
  return result;
}

// _next_token._str = <Arithmetic operator>
ExprPtr ExprFactory::createArithExpr() {
  ExprPtr result;
  // TODO: implement logic
  return result;
}

// _next_token._str = <Logic operator>
ExprPtr ExprFactory::createLgcExpr() {
  ExprPtr result;
  // TODO: implement logic
  return result;
}

// _next_token._tok_tp = TokenType::ASGN_OP
ExprPtr ExprFactory::createASGNExpr() {
  ExprPtr result;
  // TODO: implement logic
  return result;
}

ExprPtr ExprFactory::createValExprIDHandler() {
  ExprPtr result = nullptr;
  switch(_next_token._tok_tp) {
    case TokenType::SC_PUNC:{
      switch(_next_token._str[0]) {
        case '(': { result = createFuncExpr(); break; }
        case '[': { result = createArrExpr(); break; }
        default: {
          Logger::getInstance().addEvent(Event(_lexer->currLine(), "Invalid parenthesis variant after identifier."));
          break;
        }
      }
      break;
    }
    case TokenType::TER_OP:
    case TokenType::BIN_OP:
    case TokenType::ASGN_OP:
    case TokenType::ST_PUNC: {
      result = createIDExpr();
      break;
    }
    default: {
      Logger::getInstance().addEvent(Event(_lexer->currLine(), "Incorrect token after identifier."));
      break;
    }
  }
  return result;
}
