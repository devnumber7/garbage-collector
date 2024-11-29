

#ifndef MARK_AND_SWEEP_H
#define MARK_AND_SWEEP_H
#include "crazy_machine.h"

void mark(Objects* obj);

void markEverything(VM* vm);

void sweep(VM* vm);

void gc(VM* vm);






#endif 
