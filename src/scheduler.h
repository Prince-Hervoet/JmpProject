#ifndef _SCHEDULER_
#define _SCHEDULER_
#include "easyEnv.h"
#include "linkedList.h"
#include "taskBlock.h"
#define DEFAULT_TASK_LIST_COUNT 64  // 默认优先级数量

struct Scheduler {
  LinkedList* taskLists[DEFAULT_TASK_LIST_COUNT];
};

typedef struct Scheduler Scheduler;

Scheduler* MakeScheduler();
void Schedule(Scheduler* sc);
void CreateTask(TaskHandlerType taskFunc, void* args, unsigned int priority);
void SwapEnv(EasyEnv* current, EasyEnv* target);
void SaveEnv(EasyEnv* current);

#endif