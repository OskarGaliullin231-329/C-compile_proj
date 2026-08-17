#ifndef PREPROC_HPP_
#define PREPROC_HPP_

#include <fstream>
#include <memory>

// #include "StrIter.hpp"
#include "../../Logger/include/StdLogger.hpp"

class Preproc final {
public:
  Preproc() {}
  Preproc(const Preproc&) = delete;
  Preproc(Preproc&&) = delete;

public:
  bool process(std::ifstream&);
  std::string result() { return _text; }

#if DEBUG
public:
#else
private:
#endif
  void readSingleLineComm(const std::string_view&, std::string_view&);
  bool readMultiLineComm(const std::string_view&, std::string_view&);
  bool readComm(const std::string_view&, std::string_view&);
  bool readDirec(const std::string_view&, std::string_view&);
  bool removeComments(const std::string&);
  bool execDirectives(const std::string&);
  bool processLine(const std::string&, std::string_view&);

private:
  std::string _text;
};

#endif // PREPROC_HPP_
