#include "scheduler.h"

#include <setjmp.h>
#include <stddef.h>

static void test() {}

static void taskRunFunc(void* args) {}

static void executeList(LinkedList* list) {
  ListNode* node = GetNext(list);
  if (node->dataPtr == NULL) {
    return;
  }
  TaskBlock* tb = (TaskBlock*)(node->dataPtr);
  tb->taskFunc(tb->taskArgs);
}

void Schedule(Scheduler* sc) {
  if (sc == NULL) return;
  jmp_buf host;
  LinkedList** lists = sc->taskLists;
  for (int i = DEFAULT_TASK_LIST_COUNT - 1; i >= 0; --i) {
    executeList(lists[i]);
  }
}
