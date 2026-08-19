#include "Logger/include/StdLogger.hpp"
#include <iostream>
#include <sstream>

// #define DEBUG 1
#include "Preproc/include/Preproc.hpp"

using namespace std;

int main() {
  Preproc prep;
  if (prep.process("../test.c")) {
    cout << "--- Congrats! Everything went fine!\n";
  }
  else {
    cout << "Something went wrong...\n";
    Logger<StdLogger>::getInstance().loadEvents();
  }
  cout << "Result:\n";
  stringstream ss;
  ss << prep.result();
  size_t line_count = 0;
  for (string line; getline(ss, line); line_count++) {
    cout << line_count << '\t' << line << '\n';
  }

  return 0;
}
