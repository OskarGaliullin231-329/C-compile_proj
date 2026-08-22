#ifndef CMDARGPARSER_HPP_
#define CMDARGPARSER_HPP_

#include <map>
#include <string>

#if DEBUG
#include <iostream>
#endif

#include <cstdint>

class CmdArgParser {
public:
  bool parse(int16_t, char**);
  int16_t getAsInt(const std::string& name) {
    return _values[name]._int_val;
  }
  bool getAsBool(const std::string& name) {
    return _values[name]._bool_val;
  }
#if DEBUG
  void print() {
    for (const auto& pair : _values) {
      std::cout << "name: " << pair.first << '\n';
      std::cout << "value: " << pair.second._int_val << '\n';
    }
  }
#endif

private:
  union ArgValue {
    int16_t _int_val;
    bool _bool_val;
  };

private:
  std::map<std::string_view, ArgValue> _values;
};

#endif // CMDARGPARSER_HPP_
