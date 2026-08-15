#ifndef PREPROC_HPP_
#define PREPROC_HPP_

#include <memory>

// #include "StrIter.hpp"
#include "../../Loger/include/StdLoger.hpp"

class Preproc final {
public:
  Preproc(const StdLoger& loger) { _loger = std::make_shared<StdLoger>(loger); }
  Preproc(const Preproc&) = delete;
  Preproc(Preproc&&) = delete;

public:
  bool process(const std::string&);
  std::string result() { return _text; }

private:
  std::string_view oneLineComment(const std::string_view&);
  std::string_view multiLineComment(const std::string_view&);
  std::string_view comment(const std::string_view&);
  std::string_view directive(const std::string_view&);
  bool removeComments(const std::string&);
  bool execDirectives(const std::string&);

private:
  std::string _text;
  std::shared_ptr<StdLoger> _loger;
};

#endif // PREPROC_HPP_
