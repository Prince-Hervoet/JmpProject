#include "roMutex.h"

#include <stdio.h>
#include <stdlib.h>
void Lock(RoMutex rm) {}

unsigned int GetWaiter(RoMutex mu) { return (mu.flagVar >> 3); }