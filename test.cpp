#include <iostream>

using namespace std;

struct A {
  static int st_num;
  int num;
};

int main() {
  cout << sizeof(A) << '\n';
  return 0;
}
