#ifndef CMDARGPARSER_UTILS_HPP_
#define CMDARGPARSER_UTILS_HPP_

#include <string>

#include <cstdint>

// #include "../../include/CmdArgParser.hpp"

bool char_is_end(char c) {
  return (c == '\0') || (c == EOF);
}

bool char_is_delim(char c) {
  return (c == '\n') || (c == '\t') || (c == ' ') || (c == '=');
}

bool char_is_digit(char c) {
  return (c >= '0' && c <= '9');
}

bool char_is_sign(char c) {
  return (c == '-') || (c == '+');
}

bool char_is_in_num(char c) {
  return char_is_digit(c) || char_is_sign(c);
}

std::string_view get_name(std::string_view str) {
  uint16_t name_begin = 0;
  uint16_t res_size = str.size();
  while (name_begin < res_size) {
    if (char_is_delim(str[name_begin])) { name_begin++; }
    else { break; }
  }
  str.remove_prefix(name_begin);
  uint16_t name_len = 0;
  res_size = str.size();
  while((name_len < res_size)) {
    if (!(char_is_end(str[name_len]) || char_is_delim(str[name_len]))) { name_len++; }
    else { break; }
  }
  str.remove_suffix(str.size() - name_len);
  return str;
}

int32_t str_view_to_int(const std::string_view& str_v) {
  if (str_v.empty()) { return 0; }
  int32_t result = 0;
  int16_t str_size = str_v.size();
  for (int16_t i = char_is_sign(str_v[0]) ? 1 : 0; i < str_size; i++) {
    if (char_is_digit(str_v[i])) {
      result = (result * 10) + (str_v[i] - '0');
    }
    else { break; }
  }
  return (str_v[0] == '-') ? -result : result;
}

int16_t get_value(std::string_view str) {
  uint16_t val_begin = 0;
  uint16_t str_size = str.size();
  while(val_begin < str_size) {
    if (char_is_delim(str[val_begin]) && !char_is_in_num(str[val_begin])) { val_begin++; }
    else { break; }
  }
  str.remove_prefix(val_begin);
  uint16_t val_len = 0;
  str_size = str.size();
  while(val_len < str_size) {
    if (!(char_is_delim(str[val_len]) || char_is_end(str[val_len])) && char_is_in_num(str[val_len])) { val_len++; }
    else { break; }
  }
  str.remove_suffix(str.size() - val_len);
  return str_view_to_int(str);
}

#endif //CMDARGPARSER_UTILS_HPP_
