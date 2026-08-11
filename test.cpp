#include <iostream>

#include "Translator/src/utils/Preproc_utils.hpp"

using namespace std;

int main() {
  string str_1 = "#define RAND_MAX 10\n#include <stdio.h>\n\n\nsome code \n #endif";
  std::vector<SubStr> vec;

  find_directives(str_1, vec);

  // for (const auto& el : vec) {
  //   cout << el._begin << ' ' << el._end << '\n';
  // }
  cout << str_1.size() << '\n';

  return 0;
}
