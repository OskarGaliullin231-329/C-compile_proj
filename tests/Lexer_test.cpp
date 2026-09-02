#include <iostream>

#define DEBUG 1

#include "../Logger/include/StdLogger.hpp"
#include "../Translator/include/Lexer.hpp"

using namespace std;

// to compile use
// clang++ Logger/src/StdLogger.cpp Translator/src/Lexer.cpp tests/Lexer_test.cpp -o bin/lexer_test
// command from root of the project

int main(int args_num, char** args_names) {
  string text;
  while (true) {
    cout << "Insert text: ";
    getline(cin, text);
    Lexer lexer;
    lexer(text);
    while (lexer.advance()) {
      cout << to_string(lexer.currToken()) << '\n';
    }
    Logger<StdLogger>::getInstance().loadEvents();
  }

  return 0;
}
