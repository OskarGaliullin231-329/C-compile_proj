#ifndef NODEFACTORY_HPP_
#define NODEFACTORY_HPP_

#include "../AST/include/ASTNode.hpp"
#include "../../Logger/include/StdLogger.hpp"

template <typename Type>
class NodeFactory {
public:
  using NodePtr = ASTNode::NodePtr;
  using LexerPtr = std::shared_ptr<Lexer>;
  using Logger = Logger<StdLogger>;
  using Token = Lexer::Token;
  using TokenType = Lexer::TokenType;

  NodeFactory() = default;
  NodeFactory(const NodeFactory&) = default;
  NodeFactory(NodeFactory&&) = default;
  ~NodeFactory() = default;

  void operator() (LexerPtr lexer_ptr) { _lexer = lexer_ptr; }
  bool ok() { return _ok; }
  NodePtr create() {
    static_cast<Type*>(this)->create();
  }

protected:
  bool advance() {
    bool result = _lexer->advance();
    _curr_token = _next_token;
    _next_token = _lexer->currToken();
    return result;
  }

protected:
  Token _curr_token;
  Token _next_token;
  LexerPtr _lexer;
  bool _ok;
};

#endif // NODEFACTORY_HPP_
