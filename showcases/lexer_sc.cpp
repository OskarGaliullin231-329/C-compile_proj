#include <iostream>

#define DEBUG 1

#include "../CmdArgParser/include/CmdArgParser.hpp"
#include "../Logger/include/StdLogger.hpp"
#include "../Preproc/include/Preproc.hpp"
#include "../Translator/include/Lexer.hpp"

using namespace std;

int main(int args_num, char** args_names) {
  CmdArgParser arg_parser;
  if (!arg_parser.parse(args_num, args_names)) {
    Logger<StdLogger>::getInstance().loadEvents();
    return 1;
  }
  if (arg_parser.getValue("file").empty()) {
    std::cout << "'file' argument is not provided.\n";
    return 1;
  }
  Preproc prep;
  if (!prep.process(arg_parser.getValue("file"))) {
    Logger<StdLogger>::getInstance().loadEvents();
    return 1;
  }
  cout << "--- Text has been preprocessed successfully.\n";
  cout << "--- Tokens:\n";
  Lexer lexer = Lexer(prep.result());
  size_t counter = 1;
  while (lexer.advance()) {
    cout << counter++ << ". " << to_string(lexer.currToken()) << " at line " << lexer.currLine() << "\n";
  }

  return 0;
}
