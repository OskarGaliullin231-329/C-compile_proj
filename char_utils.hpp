#ifndef CMDARGPARSER_UTILS_HPP_
#define CMDARGPARSER_UTILS_HPP_

#include <string>

#include <cstdint>

// #include "../../include/CmdArgParser.hpp"

bool char_is_end(char c) {
  return (c == '\0') || (c == EOF);
}

bool char_is_delim(char c) {
  return (c == '\n') || (c == '\t') || (c == ' ');
}

bool char_is_digit(char c) {
  return (c >= '0' && c <= '9');
}

bool char_is_sign(char c) {
  return (c == '-') || (c == '+');
}

bool char_is_low_latin(char c) {
  return (c >= 'a') && (c <= 'z');
}

bool char_is_capit_latin(char c) {
  return (c >= 'A') && (c <= 'Z');
}

bool char_is_latin(char c) {
  return char_is_low_latin(c) || char_is_capit_latin(c);
}

bool is_arg_name(char c) {
  return char_is_latin(c) || char_is_digit(c) || (c == '-') || (c == '_');
}

bool is_file_name(char c) {
  return is_arg_name(c) || (c == '.');
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

#endif //CMDARGPARSER_UTILS_HPP_
