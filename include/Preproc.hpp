#ifndef PREPROC_HPP_
#define PREPROC_HPP_

#include <string_view>
#include <vector>

class Preproc {
public:
  Preproc() {}

  bool process(const std::string&);

private:
  std::vector<std::string_view> _excld_parts;
};

#endif // PREPROC_HPP_
