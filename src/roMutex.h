#ifndef _RO_MUTEX_
#define _RO_MUTEX_

struct RoMutex {
  unsigned int flagVar;
};

typedef struct RoMutex RoMutex;

void Lock(RoMutex rm);
void UnLock();

void SetWaiter(unsigned int value);
void SetWoken();
void SetLocked();

unsigned int GetWaiter();
unsigned int GetWoken();
unsigned int GetLocked();

#endif  // !_R_MUTEX_