#ifndef TYPENODE_HPP_
#define TYPENODE_HPP_

#include <vector>

#include "ASTNode.hpp"

// <TS_KEY || VS_KEY || NONE> ... <(enum || struct || union <ID>) || TP_KEY || TW_KEY> <* || NONE>
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
  Props _props;     // if 'struct', 'enum' or 'union' occures, then stop and add them to _props
  Token _type;      // TP_KEY, TW_KEY, ID
  bool _is_ptr = false;
};

#endif // TYPENODE_HPP_
