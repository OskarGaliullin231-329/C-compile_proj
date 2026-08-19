#include <iostream>
#include <vector>

#define DEBUG 1
#include "../Preproc/include/Preproc.hpp"

using namespace std;

int main() {
  Preproc prep;
  vector<string> line_variants;
  line_variants.push_back("    result = 42; // assigning 42 to result");
  line_variants.push_back("  #error // with comment");
  line_variants.push_back("#define NORMAL_DIRECTIVE_CONTAINING_LINE");
  line_variants.push_back("#bad_directive");
  line_variants.push_back("/*\n * A nicely looking comment\n * that is whorthy of attention\n*/");
  line_variants.push_back("/* a comment that\nis\ntoo filthy to\n look at */");
  line_variants.push_back("/* unclosed comment example");
  line_variants.push_back("stray end of comment example */");
  string_view buff;
  bool op_result;

  cout << "--- Comments:\n";
  for (const string& line : line_variants) {
    cout << line << '\n';
  }
  cout << '\n';

  for (const string& line : line_variants) {
    op_result = prep.processLine(line, buff);
    prep._state = Preproc::State::ReadLine;
    cout << "--- Result:" << prep._curr_line << '\n';
    cout << "--- line is ok: " << op_result << '\n';
    cout << "--- processed line:\n" << buff << '\n';
    cout << '\n';
    prep._curr_line++;
  }

  // string line = "stray end of comment example */";
  // string_view clear_line = line;
  // bool op_result;
  // op_result = prep.processLine(line, clear_line);
  // cout << op_result << '\n';
  // cout << line << '\n';
  // cout << clear_line << '\n';
  Logger<StdLogger>::getInstance().loadEvents();

  return 0;
}
