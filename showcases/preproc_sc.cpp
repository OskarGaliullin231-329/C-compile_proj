#include <iostream>

#include "../CmdArgParser/include/CmdArgParser.hpp"
#include "../Logger/include/StdLogger.hpp"
#include "../Preproc/include/Preproc.hpp"

int main(int argc, char** argv) {
  CmdArgParser arg_parser;
  if (arg_parser.parse(argc, argv)) {
    std::string_view file_name = arg_parser.getValue("file");
    if (file_name.empty()) {
      std::cout << "--- Filename is not proveided.\n";
    } else {
      Preproc prep;
      Logger<StdLogger>::getInstance().configure(file_name);
      if (prep.process(file_name)) {
        std::cout << "--- Preprocessing went fine!\n";
        std::cout << prep.result() << '\n';
      } else {
        std::cout << "--- Something went wrong while preprocessing.\n";
      }
      Logger<StdLogger>::getInstance().loadEvents();
    }
  } else {
    std::cout << "--- cmd arguments parsing failure...\n";
  }

  return 0;
}
