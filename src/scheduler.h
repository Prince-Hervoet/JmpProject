#ifndef _SCHEDULER_
#define _SCHEDULER_
#include "easyEnv.h"
#include "linkedList.h"
#include "taskBlock.h"
#define DEFAULT_TASK_LIST_COUNT 64  // 默认优先级数量
#define boolean char
#define true 1
#define false 0

struct Scheduler {
  LinkedList* taskLists[DEFAULT_TASK_LIST_COUNT];
  unsigned int taskSize;
  unsigned int maxPriority;
  boolean isHigherFlag;
  EasyEnv context;
};

typedef struct Scheduler Scheduler;

Scheduler* MakeScheduler();
void Schedule(Scheduler* sc);
void ScheduleOnce(Scheduler* sc);
void CreateTask(Scheduler* sc, TaskHandlerType taskFunc, void* args,
                unsigned int priority);
void SwapEnv(EasyEnv* current, EasyEnv* target);
void SaveEnv(EasyEnv* current);

#endif