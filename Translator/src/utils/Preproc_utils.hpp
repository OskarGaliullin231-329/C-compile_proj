#ifndef PREPROC_UTILS_HPP_
#define PREPROC_UTILS_HPP_

#include <vector>

#include "../../include/Preproc.hpp"

using SubStr = Preproc::SubStr;
using SubStrTp = Preproc::SubStrTp;

SubStr directive_like(const std::string_view& str, size_t start) {
  SubStr dir;
  size_t str_size = str.size();
  size_t begin = start;
  while(begin < str_size) {
    if (str[begin] != '#') { begin++; }
    else { break; }
  }
  size_t end = begin;
  while(end < str_size) {
    if (str[end] != '\n') { end++; }
    else { break; }
  }
  dir = {begin, end, SubStrTp::Dir};
  return dir;
}

bool is_define(const std::string_view& str, const SubStr& sub_str) {}

bool is_undef(const std::string_view& str, const SubStr& sub_str) {}

bool is_if(const std::string_view& str, const SubStr& sub_str) {}

bool is_elif(const std::string_view& str, const SubStr& sub_str) {}

bool is_else(const std::string_view& str, const SubStr& sub_str) {}

bool is_pragma(const std::string_view& str, const SubStr& sub_str) {}

bool is_include(const std::string_view& str, const SubStr& sub_str) {}

bool is_line(const std::string_view& str, const SubStr& sub_str) {}

bool is_error(const std::string_view& str, const SubStr& sub_str) {}

bool is_directive(const std::string_view& str, const SubStr& sub_str) {
  return is_define(str, sub_str) || is_undef(str, sub_str) ||
         is_if(str, sub_str) || is_elif(str, sub_str) || is_else(str, sub_str) ||
         is_pragma(str, sub_str) || is_line(str, sub_str) ||
         is_include(str, sub_str) || is_error(str, sub_str);
}

bool find_directives(const std::string_view& str, std::vector<SubStr>& dirs) {
  bool result = true;
  return result;
}

#endif // PREPROC_UTILS_HPP_
