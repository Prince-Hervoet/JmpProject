#ifndef _TASK_BLOCK_
#define _TASK_BLOCK_
#include "easyEnv.h"

#define TASK_STATUS_NEW 0
#define TASK_STATUS_READY 1
#define TASK_STATUS_RUNNING 2
#define TASK_STATUS_PENDING 4
#define TASK_STATUS_DEAD 8

typedef void (*TaskHandlerType)(void*);

struct TaskBlock {
  unsigned int priority;  // 优先级 0 -- 63，数值越大，优先级越高
  TaskHandlerType taskFunc;
  void* taskArgs;
  char* runtimeStack;  // 运行时栈
  unsigned int stackSize;
  char status;
  EasyEnv context;
};

typedef struct TaskBlock TaskBlock;

#endif