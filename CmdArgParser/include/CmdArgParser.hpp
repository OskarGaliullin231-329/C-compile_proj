#ifndef CMDARGPARSER_HPP_
#define CMDARGPARSER_HPP_

#include <map>
#include <string>

#include <cstdint>

class CmdArgParser {
public:
  bool parse(int16_t, char**);
  int16_t getValAsInt(const std::string& name) {
    return _values[name]._int_val;
  }
  bool getValAsBool(const std::string& name) {
    return _values[name]._bool_val;
  }

private:
  union ArgValue {
    int16_t _int_val;
    bool _bool_val;
  };

private:
  std::map<std::string_view, ArgValue> _values;
};

#endif // CMDARGPARSER_HPP_
