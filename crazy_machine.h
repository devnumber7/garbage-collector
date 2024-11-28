#include <stdlib.h>
#include <syslog.h>
#include "objects.h"

#ifndef CRAZY_MACHINE_H

#define CRAZY_MACHINE_H

#define STACK_MAX 256 
#define INIT_GC_THRESHOLD


//lets define a stack-based VM
typedef struct {
	Objects* stack[STACK_MAX];
	int	size;
	Objects* firstObj;

	
	int numObjs;
	int maxObjs;
	
}VM;



// lets  initialize a new virutal machine 

VM* newVM(void);


void push(VM* vm, Objects * obj);


Objects*  pop(VM* vm);

#endif


