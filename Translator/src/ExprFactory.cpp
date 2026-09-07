#include "../include/ExprFactory.hpp"

typedef Expression::ExprPtr ExprPtr;

ExprPtr ExprFactory::create() {
  ExprPtr result = nullptr;
  if (!passDelims()) { return result; }
  switch (_curr_token._tok_tp) {
    case TokenType::ID: case TokenType::INT_LIT: case TokenType::FL_LIT:
    case TokenType::CH_LIT: case TokenType::STR_LIT:{
      result = handleValTok();
      break;
    }
    case TokenType::UN_OP: {
      result = createUnExpr();
      break;
    }
    case TokenType::SC_PUNC: {
      result = handleParenTok();
      break;
    }
    // TODO: add all cases
    default: {
      break;
    }
  }
  return result;
}

ExprPtr ExprFactory::createBinExpr() {
  ExprPtr result;
  // TODO: implement logic
  return result;
}

ExprPtr ExprFactory::createStructExpr() {
  ExprPtr result;
  // TODO: implement logic
  return result;
}

ExprPtr ExprFactory::createBitExpr() {
  ExprPtr result;
  // TODO: implement logic
  return result;
}

ExprPtr ExprFactory::createArithExpr() {
  ExprPtr result;
  // TODO: implement logic
  return result;
}

ExprPtr ExprFactory::createLgcExpr() {
  ExprPtr result;
  // TODO: implement logic
  return result;
}

ExprPtr ExprFactory::createASGNExpr() {
  ExprPtr result;
  // TODO: implement logic
  return result;
}

ExprPtr ExprFactory::createTerExpr() {
  ExprPtr result;
  // TODO: implement logic
  return result;
}

ExprPtr ExprFactory::createUnExpr() {
  ExprPtr result;
  // TODO: implement logic
  return result;
}

ExprPtr ExprFactory::createValExpr() {
  ExprPtr result = nullptr;
  switch(_next_token._str[0]) {
    case '(': {
      result = createFuncExpr();
      break;
    }
    case '[': {
      result = createArrExpr();
      break;
    }
    case ';': {
      result = createIDExpr();
      break;
    }
    default: {
      _ok = false;
      std::string err_msg = "Unexpected symbol: ";
      err_msg += _next_token._str;
      Logger::getInstance().addEvent(Event(_lexer->currLine(), err_msg));
      return result;
    }
  }
  return result;
}

ExprPtr ExprFactory::createIDExpr() {
  ExprPtr result = nullptr;
  // TODO: implement logic
  return result;
}

ExprPtr ExprFactory::createLITExpr() {
  ExprPtr result = nullptr;
  // TODO: implement logic
  return result;
}

ExprPtr ExprFactory::createFuncExpr() {
  ExprPtr result = nullptr;
  // TODO: implement logic
  return result;
}

ExprPtr ExprFactory::createArrExpr() {
  ExprPtr result = nullptr;
  // TODO: implement logic
  return result;
}

ExprPtr ExprFactory::handleValTok() {
  ExprPtr result = nullptr;
  switch (_next_token._tok_tp) {
    case TokenType::BIN_OP: case TokenType::ASGN_OP: {
      result = createBinExpr();
      break;
    }
    case TokenType::TER_OP: {
      result = createTerExpr();
      break;
    }
    case TokenType::SC_PUNC: case TokenType::ST_PUNC: case TokenType::DEL: {
      result = createValExpr();
      break;
    }
    case TokenType::ERR: {
      _ok = false;
      Logger::getInstance().addEvent(Event(_lexer->currLine(), "Incorrect token."));
      return result;
    }
    default: {
      _ok = false;
      Logger::getInstance().addEvent(Event(_lexer->currLine(), "Incorrect token sequence after valued token."));
      return result;
    }
  }
  return result;
}

ExprPtr ExprFactory::handleParenTok() {
  ExprPtr result = nullptr;
  switch(_curr_token._str[0]) {
    case '(': {
      result = create();
      if (_next_token._str != ")") {
        _ok = false;
        Logger::getInstance().addEvent(Event(_lexer->currLine(), "Unclosed parenthesis."));
        return nullptr;
      }
      break;
    }
    default: {
      _ok = false;
      Logger::getInstance().addEvent(Event(_lexer->currLine(), "Incorrect parenthesis variant."));
      return result;
    }
  }
  return result;
}
