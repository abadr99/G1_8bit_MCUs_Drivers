#ifndef STACK_H_
#define STACK_H_

#if STACK_TYPE == STACK_ARRAY
typedef struct
{
  STACK_DATA_TYPE StackArr[STACK_SIZE];
  STACK_DATA_TYPE LastIndex;
}Stack_t;

#elif STACK_TYPE == LINKED_STACK
typedef struct Node_t
{
	STACK_DATA_TYPE Value;
	struct Node_t* pPrevNode;
}Node_t;
typedef struct
{
	Node_t* pTop;
	STACK_DATA_TYPE size;
}Stack_t;
#endif
void Stack_Init(Stack_t *stack);
void Stack_Push(Stack_t *stack,STACK_DATA_TYPE Data);
void Stack_Pop(Stack_t *stack);
void Stack_Top(Stack_t *stack , STACK_DATA_TYPE *Data);
void Stack_GetSize(Stack_t *stack , STACK_DATA_TYPE *size);
void Stack_Traverse(Stack_t *stack,void (*ptr_func)(STACK_DATA_TYPE* x));
STACK_DATA_TYPE Is_Empty(Stack_t*stack);
STACK_DATA_TYPE Is_Full(Stack_t*stack);
void Clear_Stack(Stack_t* stack);
#endif /* STACK_H_ */
