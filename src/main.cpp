#include <iostream>
#include <cstdio>
#include "simple_ctx.h"
#include <string>

relaxing::SimpleCtx *sc1 = relaxing::GetSimpleCtx();
relaxing::SimpleCtx *sc2 = relaxing::GetSimpleCtx();

void userFunc() {
  printf("%s\n", "user function");
}


void routineFunc() {
  userFunc();
  printf("%s\n", "routine function");
  relaxing::TestFunc(sc2, sc1);
  printf("%s\n", "routine function2");
  relaxing::TestFunc(sc2, sc1);
}

int main() {
  char *sp = new char[1000];
  memset(sp, 0, 1000);
  relaxing::SetCtxSp(sc2, sp, 1000);
  relaxing::SetCtxBp(sc2, sp + 900);
  relaxing::SetCtxEntry(sc2, (void *) (&routineFunc));
  relaxing::TestFunc(sc1, sc2);
  printf("%s\n", "main function");
  int a = 1231;
  int b = a + 1;
  printf("%d\n", b);
  relaxing::TestFunc(sc1, sc2);
  printf("%s\n", "end");
  delete[] sp;
  return 0;
}