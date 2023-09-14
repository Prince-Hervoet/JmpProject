#include "scheduler.h"

#include <setjmp.h>
#include <stddef.h>
#include <stdlib.h>

static TaskBlock* makeTaskBlock(TaskHandlerType taskFunc, void* args,
                                unsigned int priority) {
  TaskBlock* tb = (TaskBlock*)malloc(sizeof(TaskBlock));
  tb->taskFunc = taskFunc;
  tb->taskArgs = args;
  tb->priority = priority;
  tb->status = TASK_STATUS_NEW;
  tb->runtimeStack = NULL;
  tb->stackSize = 0;
  return tb;
}

static void wrapRunFunc(void* args) {}

static void executeList(LinkedList* list) {
  ListNode* node = GetNext(list);
  if (node->dataPtr == NULL) {
    return;
  }
  TaskBlock* tb = (TaskBlock*)(node->dataPtr);
  switch (tb->status) {
    case TASK_STATUS_NEW:
      tb->runtimeStack = (char*)malloc(sizeof(char) * TASK_DEFAULT_STACK_SIZE);
      tb->stackSize = TASK_DEFAULT_STACK_SIZE;
      tb->context.rsp = tb->runtimeStack + (TASK_DEFAULT_STACK_SIZE - 1);
      tb->context.rip = &wrapRunFunc;
      tb->context.args = tb;
      tb->status = TASK_STATUS_READY;
      break;
    case TASK_STATUS_READY:
      break;
    default:
      return;
  }
}

void CreateTask(Scheduler* sc, TaskHandlerType taskFunc, void* args,
                unsigned int priority) {
  if (sc == NULL || taskFunc == NULL || priority >= DEFAULT_TASK_LIST_COUNT) {
    return;
  }
  TaskBlock* tb = makeTaskBlock(taskFunc, args, priority);
  LinkedList* list = sc->taskLists[priority];
  InsertData(list, tb);
  sc->maxPriority = priority > sc->maxPriority ? priority : sc->maxPriority;
}

void Schedule(Scheduler* sc) {
  if (sc == NULL) return;
  int currentIndex = DEFAULT_TASK_LIST_COUNT - 1;
}

void ScheduleOnce(Scheduler* sc) {
  if (sc == NULL || sc->taskSize == 0) return;
  int currentIndex = DEFAULT_TASK_LIST_COUNT - 1;
  LinkedList** taskLists = sc->taskLists;
  while (sc->taskSize != 0) {
    // 从高到低找到第一个有任务的队列
    while (taskLists[currentIndex]->size == 0) {
      --currentIndex;
    }
    executeList(taskLists[currentIndex]);
  }
}
