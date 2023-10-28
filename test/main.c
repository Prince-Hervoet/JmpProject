#include <stdio.h>

#include "scheduler.h"

struct A {
  int a;
  int b;
};

struct B {
  int c;
};

int main() {
  Scheduler* sc = MakeScheduler();
  Schedule(sc);
}
