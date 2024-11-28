

#ifndef OBJECTS_H			
#define OBJECTS_H

//We will Pretend that our funny little language only has 2 types 
typedef enum{
	OBJ_INT,
	OBJ_PAIR 
}ObjectType;


//a custom Object structure which can either be int or pair  
typedef struct gObjects{
	unsigned int mark;
	ObjectType type;

	union{
		/*OBJ_INT*/

		int value;

		/*OBJ_PAIR*/
		
		struct{
			struct gObjects* head;
			struct gObjects* tail;
		};
	};
}Objects;

#endif


