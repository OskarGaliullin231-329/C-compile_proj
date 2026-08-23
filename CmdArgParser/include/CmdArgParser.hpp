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
  std::string_view getValue(const std::string&);
#if DEBUG
  void print() {
    for (const auto& pair : _values) {
      std::cout << "name: " << pair.first << '\n';

      std::cout << "value: " << pair.second << '\n';
    }
  }
#endif

#if DEBUG
public:
#else
private:
#endif
  std::string_view getNameFromString(std::string_view);
  std::string_view getValueFromString(std::string_view);

private:
  std::map<std::string_view, std::string_view> _values;
};

#endif // CMDARGPARSER_HPP_
