#include "crazy_machine.c"

/*
We are going to write a simple mark and sweep algo. 
Idea is Simple:
First Step: Mark
Second Step: Sweep

LOL OK but fr basically the idea is that you flip all the objects that are reachable (aka marking )
and then delete the one that were not flipped , that'd indicate that they are unreachable ( aka sweeping)

THATS ABOUT IT.
 SEE TO BE FAMOUS IN CS DONT FIND OBSCURE STUFF. 
 JUST FIND THE MOST OBVIOUS NO-SHIT SHERLOCK IDEA
 -rephrased from the legend aka Bob Nystrom

*/


	

void mark(Objects* obj){

	if (obj->mark) return;
	
	obj->mark = 1;

	if (obj-> type == OBJ_PAIR){
		mark(obj->head);
		mark(obj->tail);
	}
}



void markEverything(VM* vm){
	for (int i = 0; i < vm -> size ; i++){
		mark(vm->stack[i]);
	}
}


void sweep(VM* vm){
	Objects** obj = &vm -> firstObj;
	while (*obj){
		if (!(*obj)->mark){
			Objects *unreached = *obj;
			*obj = unreached ->next;
			free(unreached);
			vm->numObjs--;
			
		}
		else{
			(*obj)->mark=0;

			obj = &(*obj)->next;
			
		}
	}
}


void gc(VM* vm){

//	int numObjs = vm->numObjs;
	markEverything(vm);
	sweep(vm);

	vm->maxObjs = vm->numObjs *2;
}





