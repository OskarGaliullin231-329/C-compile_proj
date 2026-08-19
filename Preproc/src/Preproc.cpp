#include "../include/Preproc.hpp"

#include <algorithm>
#include <fstream>
#include <string>
#include <unordered_set>

void Preproc::removeCommFromLine(std::string_view& line) {
  size_t line_size = line.size();
  size_t comm_begin = line.find("//");
  line.remove_suffix((comm_begin < line_size) ? (line_size - comm_begin) : 0);
}

bool Preproc::noClosingCommSeq(const std::string_view& line) {
  bool result = (line.find("*/") >= line.size());
  if (!result) {
    Logger& logger_inst = Logger::getInstance();
    logger_inst.addEvent(Event(_curr_line, "Stray end of multiline comment occured."));
  }
  return result;
}

bool Preproc::dirIsCorrect(const std::string_view& line) {
  bool result = true;
  std::string_view copy = line;
  std::unordered_set<std::string_view> directives = {
    "define", "undef",              // work with macro's
    "if", "elif", "else", "endif",  // conditional compilation
    "ifdef", "ifndef",              // conditional compilation (work with defined macro's)
    "line",                         // change filename and line in compilation logs
    "include",                      // insert contents of file
    "error",                        // show error message
    "pragma"                        // show compiler specific messages
  };
  Logger& logger_inst = Logger::getInstance();
  std::string err_msg;
  if (copy.find('#') < copy.size()) {
    copy.remove_prefix(copy.find('#'));
    if (copy.size() >= 3) {
      copy.remove_prefix(1);
      size_t dir_begin = 0;
      for (dir_begin = 0; dir_begin < copy.size(); dir_begin++) {
        switch(copy[dir_begin]) {
          case ' ': case '\t': { break; }
          default: { goto loop_end; }
        }
      }
      loop_end:
      copy.remove_prefix(dir_begin);
      size_t dir_end_index = std::min({copy.find(' '), copy.find('\n'), copy.find('\0'), copy.find(EOF)});
      size_t copy_size = copy.size();
      copy.remove_suffix((dir_end_index < copy_size) ? (copy_size - dir_end_index) : 0);
      if (directives.find(copy) == directives.end()) {
        result = false;
        err_msg = "Incorrect directive name: ";
        err_msg += copy;
        logger_inst.addEvent(Event(_curr_line, err_msg + '.'));
      }
    }
    else {
      result = false;
      err_msg = "Directive is too short.";
      logger_inst.addEvent(Event(_curr_line, err_msg));
    }
  }
  return result;
}

bool Preproc::processLine(const std::string& line, std::string_view& clear_line) {
  // std::cout << "State of Preproc at line " << _curr_line << ':';
  // if (_state == State::ReadLine) {
  //   std::cout << " ReadLine\n";
  // }
  // else if (_state == State::ReadMultiLineComm) {
  //   std::cout << " ReadMultiLineComm\n";
  // }
  bool result = true;
  clear_line = line;
  switch(_state) {
    case State::ReadLine: {
      removeCommFromLine(clear_line);
      if (!noClosingCommSeq(clear_line)) {
        result = false;
        break;
      }
      if (clear_line.find('#') < clear_line.size()) {
        result = dirIsCorrect(clear_line);
        if (result) {
          clear_line.remove_suffix(clear_line.size());
        }
        break;
      }
      if (clear_line.find("/*") < clear_line.size()) {
        _state = State::ReadMultiLineComm;
        clear_line.remove_suffix(clear_line.size() - clear_line.find("/*"));
      }
      break;
    }
    case State::ReadMultiLineComm: {
      if (line.find("*/") < line.size()) {
        _state = State::ReadLine;
      }
      clear_line.remove_suffix(clear_line.size());
      break;
    }
  }
  return result;
}

bool Preproc::process(const std::string& file_name) {
  std::fstream file(file_name);

  bool result = true;
  std::string_view clear_line;
  for (std::string line; std::getline(file, line) && result; _curr_line++) {
    result = result && processLine(line, clear_line);
    _text += clear_line;
    _text +=  '\n';
  }
  file.close();
  if (_state == State::ReadMultiLineComm) {
    Logger::getInstance().addEvent(Event(_curr_line, "Unterminated multiline comment."));
  }
  result = result && (_state == State::ReadLine);
  return result;
}
