#ifndef TYPENODE_HPP_
#define TYPENODE_HPP_

#include <vector>

#include "ASTNode.hpp"

// <TS_KEY || VS_KEY || NONE> ... <TP_KEY || TW_KEY || enum || struct || ID> <* || NONE>
class TypeNode final : public ASTNode {
public:
  using Props = std::vector<Token>;

  TypeNode() = default;
  TypeNode(const TypeNode&) = default;
  TypeNode(TypeNode&&) = default;
  ~TypeNode() = default;

  TypeId type() override;

  bool setType(const Token&);
  bool setProp(const Token&);
  void makePtr();

private:
  Props _props;
  Token _type;      // TP_KEY, TW_KEY, ID, struct or enum
  bool _is_ptr = false;
};

#endif // TYPENODE_HPP_
