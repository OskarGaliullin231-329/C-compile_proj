#include "../include/CmdArgParser.hpp"

#include "../../char_utils/char_utils.hpp"

std::string_view CmdArgParser::getValue(const std::string& name) {
  return _values[name];
}

std::string_view CmdArgParser::getNameFromString(std::string_view str) {
  uint16_t name_begin = 0;
  uint16_t res_size = str.size();
  while (name_begin < res_size) {
    if (char_is_delim(str[name_begin])) { name_begin++; }
    else { break; }
  }
  str.remove_prefix(name_begin);
  uint16_t name_len = 0;
  res_size = str.size();
  while(name_len < res_size) {
    if (is_arg_name(str[name_len])) { name_len++; }
    else { break; }
  }
  str.remove_suffix(str.size() - name_len);
  return str;
}

std::string_view CmdArgParser::getValueFromString(std::string_view str) {
  str.remove_prefix((str.find('=') < str.size()) ? (str.find('=') + 1) : str.size());
  if (str.empty()) { return str; }
  uint16_t str_size = str.size();
  uint16_t val_begin = 0;
  while (val_begin < str_size) {
    if (char_is_delim(str[val_begin])) { val_begin++; }
    else { break; }
  }
  str.remove_prefix(val_begin);
  str_size = str.size();
  uint16_t val_len = 0;
  while (val_len < str_size) {
    if (is_file_name(str[val_len])) { val_len++; }
    else { break; }
  }
  str.remove_suffix(str_size - val_len);
  return str;
}

bool CmdArgParser::parse(int16_t args_num, char** arg_names) {
  bool result = true;
  for (int16_t i = 1; (i < args_num) && result; i++) {
    std::string_view name = getNameFromString(arg_names[i]);
    if (!name.empty()) {
      _values[name] = getValueFromString(arg_names[i]);
    }
  }
  return result;
}
