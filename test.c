#include <stdio.h>
#  define VAR 1
#   if VAR
void some_function() {
  printf("some_function was called.\n");
}

struct SomeStruct {
  int id;
};

enum Enum {
  variant1,
  variant2,
};

// struct SomeStruct construct() {
//   struct SomeStruct result;
//   result.id = 8;
//   return result;
// }

// entry point of the program
int main() {
  /*
  let's declare some variables
  */
  int a=2;
  float b=3.14;
  float result;

  result = a + b; // and let's see summation result

  printf("%d", result==a+b);

  for (int i = 0; i < 10; i++) {
    some_function();
  }

  struct SomeStruct s_s;
  s_s.id = 0;

  enum Enum var;

  return 0;
}
#else
# error "VAR is not defined"
#endif
