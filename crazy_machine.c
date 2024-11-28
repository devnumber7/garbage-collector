#include "crazy_machine.h"
#include <stdlib.h>
#include <syslog.h>





// lets  initialize a new virutal machine 

VM* newVM (){
	VM* vm = (VM*)malloc(sizeof(VM));
	vm -> size =0;

	vm-> numObjs = 0;
	vm -> maxObjs= INIT_GC_THRESHOLD;
	return vm;

	

}


void push(VM* vm, Objects * obj){
	if (vm->size > STACK_MAX){
		syslog(LOG_ERR, "STACKKK OVERFLOW !!!!");
		exit(EXIT_FAILURE);
	}

	vm ->stack[vm->size]=obj;
	vm->size++;
		
}


Objects*  pop(VM* vm){
	if (vm ->size < 0){
		syslog(LOG_ERR, "STACKKKK UNDERFLOOWWWW!!!!!");
		exit(EXIT_FAILURE);;
	}

	vm->size--;

	int newIndex = vm->size;

	return vm->stack[newIndex];

}



//basically tbhe memory allocator of our thing 


Objects* newObject(VM* vm , ObjectType type){
	Objects* obj = (Objects*)malloc(sizeof(Objects));

	obj->type = type;

	obj -> next = vm-> firstObj;
	vm->firstObj = obj;

	vm->numObjs++;
	

	return obj;
}


//now that we have all the util functions we can proceed with building functions that add different types of objects


void pushInt(VM* vm, int intValue){
	Objects* obj = newObject(vm, OBJ_INT);

	obj-> value = intValue;

	push(vm, obj);
}


Objects* pushPairs(VM* vm){
	Objects* obj = newObject(vm, OBJ_PAIR);
	obj->tail=pop(vm);
	obj->head=pop(vm);
	
	push(vm,obj);
	return obj;
	
}


