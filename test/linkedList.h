#ifndef _LINKEDLIST_
#define _LINKEDLIST_

#define any void*

typedef void (*FreeDataType)(void* args);

struct PseudoListNode {
  struct ListNode* next;
  struct ListNode* prev;
};

struct ListNode {
  struct ListNode* next;
  struct ListNode* prev;
  any dataPtr;
};

struct LinkedList {
  struct PseudoListNode* headNode;
  struct ListNode* cursor;
  FreeDataType freeFunc;
  unsigned int size;
};

typedef struct PseudoListNode PseudoListNode;
typedef struct ListNode ListNode;
typedef struct LinkedList LinkedList;

LinkedList* MakeLinkedList(FreeDataType freeFunc);
void InsertData(LinkedList* list, any data);
ListNode* GetNext(LinkedList* list);
void ResetCursor(LinkedList* list);
void RemoveListNode(LinkedList* list, ListNode* target);
unsigned int Size(LinkedList* list);

#endif