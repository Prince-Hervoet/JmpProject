#include "scheduler.h"

#include <setjmp.h>
#include <stddef.h>
#include <stdlib.h>
#include <time.h>

Scheduler* sc;

static void timerHandler() {
  // 定时器中断
  if (sc->currentTask == NULL || sc->currentTask->lastUpdateAt == -1) return;
  clock_t now = clock();
}

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

static void clearTaskNode(LinkedList* list, ListNode* target) {
  if (target == NULL) return;
  RemoveListNode(list, target);
}

static void wrapRunFunc(void* args) {}

static void executeList(Scheduler* sc, LinkedList* list) {
  ListNode* node = NULL;
  while ((node = GetNext(list)) != NULL) {
    TaskBlock* tb = (TaskBlock*)(node->dataPtr);
    switch (tb->status) {
      case TASK_STATUS_NEW:
        tb->runtimeStack =
            (char*)malloc(sizeof(char) * TASK_DEFAULT_STACK_SIZE);
        tb->stackSize = TASK_DEFAULT_STACK_SIZE;
        tb->context.rsp = tb->runtimeStack + (TASK_DEFAULT_STACK_SIZE - 1);
        tb->context.rip = &wrapRunFunc;
        tb->context.args = tb;
        tb->status = TASK_STATUS_READY;
        break;
      case TASK_STATUS_READY:
        break;
      case TASK_STATUS_PENDING:
        break;
      default:
        return;
    }
    tb->status = TASK_STATUS_RUNNING;
    if (AsSaveEnv(&(sc->context)) == 0) {
      AsResumeEnv(&(tb->context));
    } else {
      // 清理工作
      if (tb->status == TASK_STATUS_DEAD) {
        RemoveListNode(list, node);
        sc->taskSize -= 1;
      } else {
        tb->status = TASK_STATUS_PENDING;
      }
    }

    if (sc->isHigherFlag) {
      break;
    }
  }
}

static void startTimerInterrupt(unsigned int timerMs) {}

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
  startTimerInterrupt(5);
  LinkedList** taskLists = sc->taskLists;
  while (sc->taskSize != 0) {
    // 从高到低找到第一个有任务的队列
    while (taskLists[currentIndex]->size == 0) {
      --currentIndex;
    }
    executeList(sc, taskLists[currentIndex]);
  }
}
