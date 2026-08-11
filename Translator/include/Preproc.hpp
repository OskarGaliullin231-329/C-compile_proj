#ifndef PREPROC_HPP_
#define PREPROC_HPP_

#include <string>
#include <vector>

#include "../../Loger/include/StdLoger.hpp"

class Preproc final {
public:
  enum class SubStrTp : u_int8_t { Comm, Dir, Ord, Err };

  struct SubStr final {
   std::size_t _begin;
   std::size_t _end;
   SubStrTp _tag;
  };

  Preproc(const std::string& str) { _buff = str; }
  Preproc(const Preproc&) = delete;
  Preproc(Preproc&&) = delete;

  bool process();
  SubStrTp getLineTp(std::size_t index);

private:
  std::string_view _buff;
  std::vector<SubStr> _comms;
  std::vector<SubStr> _dirs;
};

#endif // PREPROC_HPP_
