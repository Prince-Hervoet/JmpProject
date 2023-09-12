#ifndef _EASY_ENV_
#define _EASY_ENV_
#include <setjmp.h>

struct EasyEnv {
  unsigned long rsp;
  unsigned long rbp;
  unsigned long rip;
  unsigned long r12;
  unsigned long r13;
  unsigned long r14;
  unsigned long r15;
};

typedef struct EasyEnv EasyEnv;

#endif