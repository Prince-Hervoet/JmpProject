#include "linkedList.h"

#include <stddef.h>
#include <stdlib.h>

static ListNode* makeListNode(any data) {
  ListNode* node = (ListNode*)malloc(sizeof(ListNode));
  node->dataPtr = data;
  node->next = NULL;
  node->prev = NULL;
  return node;
}

static PseudoListNode* makePseudoListNode() {
  PseudoListNode* pseNode = (PseudoListNode*)malloc(sizeof(PseudoListNode));
  pseNode->next = NULL;
  pseNode->prev = NULL;
  return pseNode;
}

LinkedList* MakeLinkedList(FreeDataType freeFunc) {
  PseudoListNode* headNode = makePseudoListNode();
  headNode->next = headNode;
  headNode->prev = headNode;
  LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
  list->headNode = headNode;
  list->freeFunc = freeFunc;
  list->size = 0;
  list->cursor = (ListNode*)headNode;
  return list;
}

void InsertData(LinkedList* list, any data) {
  if (list == NULL || data == NULL) return;
  ListNode* node = makeListNode(data);  // new a node
  PseudoListNode* headNode = list->headNode;
  node->next = headNode->next;
  headNode->next->prev = node;
  headNode->next = node;
  node->prev = (ListNode*)headNode;
  list->size += 1;
}

void RemoveListNode(LinkedList* list, ListNode* target) {
  if (list == NULL || target == NULL || list->size == 0) return;
  ListNode* nextNode = target->next;
  ListNode* prevNode = target->prev;
  nextNode->prev = prevNode;
  prevNode->next = nextNode;
  list->freeFunc(target->dataPtr);
  target->next = NULL;
  target->prev = NULL;
  free(target);
  list->size -= 1;
}

ListNode* GetNext(LinkedList* list) {
  if (list == NULL || list->size == 0) return NULL;
  while (list->cursor == list->headNode) {
    list->cursor = list->cursor->next;
  }
  return list->cursor;
}

void ResetCursor(LinkedList* list) {
  if (list == NULL) return;
  list->cursor = (ListNode*)list->headNode;
}