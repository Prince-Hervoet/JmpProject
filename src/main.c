#include <stdio.h>

#include "easyEnv.h"

struct A {
  int a;
  int b;
};

struct B {
  int c;
};

int main() {
  EasyEnv test;
  int ret;
  ret = saveEnv(&test);
  if (ret == 0) {
    printf("from setjmp\n");
    resumeEnv(&test);
  } else {
    printf("from longjmp\n");
  }
}
