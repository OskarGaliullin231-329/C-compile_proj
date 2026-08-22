#include "../include/CmdArgParser.hpp"

#include <iostream>

#include "utils/CmdArgParser_utils.hpp"

bool CmdArgParser::parse(int16_t args_num, char** arg_names) {
  bool result = true;
  for (int16_t i = 1; (i < args_num) && result; i++) {
    std::string_view str(arg_names[i]);
    std::string_view name = get_name(str);
    ArgValue val{ ._bool_val = true };
    if (name.empty()) {
      result = false;
      break;
    }
    str.remove_prefix(name.size());
    if (str.find('=') < str.size()) { val._int_val = get_value(str); }
    if (val._int_val == 0) {
      result = false;
      break;
    }
    _values[name] = val;
  }
  return result;
}
