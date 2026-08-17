#include "../include/Preproc.hpp"

#include <string>

// TODO: find a way to stop work of preprocessor when error occures
// (without exceptions)

// size of string_view is supposed to be no less than 2
void Preproc::readSingleLineComm(const std::string_view& src, std::string_view& dest) {
  size_t str_size = src.size();
  size_t comm_len = 0;
  dest = src;
  for (comm_len = 0; comm_len < str_size; comm_len++) {
    switch(src[comm_len]) {
      case '\n': { goto loop_end; }
    }
  }
  loop_end:
  size_t tail_size = str_size - comm_len;
  dest.remove_suffix(tail_size);
}

bool Preproc::readMultiLineComm(const std::string_view& src, std::string_view& dest) {
  int32_t end_index = (int32_t)src.find("*/");
  bool result = (end_index > 1);
  if (result) {
    dest = src;
    dest.remove_suffix(src.size() - end_index - 2);
  }
  return result;
}

// TODO: implement
bool Preproc::readComm(const std::string_view& src, std::string_view& dest) {
  bool result = true;
  switch(src.size()) {
    case 0: case 1: { return false; }
    default: {
      switch(src[1]) {
        case '/': { readSingleLineComm(src, dest); } // read one-line comment
        case '*': { result = readMultiLineComm(src, dest); } // read multiline comment
        default: {}
      }
    }
  }
  return result;
}

bool Preproc::process(std::ifstream& file) {
  bool result = true;
  std::string_view clear_line;
  size_t line_count = 0;
  for (std::string line; std::getline(file, line) && processLine(line, clear_line); line_count++) {
    result = processLine(line, clear_line);
    _text += clear_line;
  }
  return result;
}
