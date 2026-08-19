#ifndef PREPROC_HPP_
#define PREPROC_HPP_

#include <string>

#include "../../Logger/include/StdLogger.hpp"

class Preproc final {
public:
  using Logger = Logger<StdLogger>;

  Preproc(): _state(State::ReadLine), _curr_line(0) {}
  Preproc(const Preproc&) = delete;
  Preproc(Preproc&&) = delete;

public:
  bool process(const std::string&);
  std::string result() { return _text; }

private:
  enum class State :int8_t { ReadLine, ReadMultiLineComm };

  void removeCommFromLine(std::string_view&);
  bool noClosingCommSeq(const std::string_view&);
  bool dirIsCorrect(const std::string_view&);
  bool processLine(const std::string&, std::string_view&);

private:
  std::string _text;
  size_t _curr_line;
  State _state;
};

#endif // PREPROC_HPP_
