#include "../include/Preproc.hpp"

#include "utils/Preproc_utils.hpp"


// TODO: find a way to stop work of preprocessor when error occures

std::string_view Preproc::oneLineComment(const std::string_view& str) {
  std::string_view result;
  size_t str_size = str.size();
  size_t comm_len;
  for (comm_len = 0; comm_len < str_size; comm_len++) {
    switch(str[comm_len]) {
      case '\n': goto loop_end;
    }
  }
  loop_end:
  result.remove_suffix(str_size - comm_len);
  return result;
}

// TODO: implement
std::string_view Preproc::multiLineComment(const std::string_view& str) {
  std::string_view result;
  return result;
}


// TODO: implement
std::string_view Preproc::comment(const std::string_view& str) {
  std::string_view result = str;
  switch(result.size()) {
    case 0: { return result; }
    case 1: {
      result.remove_suffix(1);
      return result;
    }
    default: {
      switch(result[1]) {
        case '/': {} // read one-line comment
        case '*': {} // read multiline comment
        default: {}
      }
    }
  }
  return result;
}

// TODO: implement
bool Preproc::removeComments(const std::string& str) {
  bool result = true;
  size_t str_size = str.size();
  for (size_t i = 0; i < str_size; i++) {
    switch(str[i]) {
      case '/': {
        std::string_view comm = str;
        comm.remove_prefix(i);
        break;
      }
      case '*': {
        break;
      }
    }
  }
  return result;
}

// TODO: implement
bool Preproc::process(const std::string& str) {
  bool result = true;

  return result;
}
