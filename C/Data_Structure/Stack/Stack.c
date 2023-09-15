#include "../../common/Types.h"
#include "stdlib.h"
#include "Stack_Config.h"
#include "Stack.h"
#if STACK_TYPE == STACK_ARRAY
//.c related stack array
void Stack_Init(Stack_t *stack)
{
  stack->LastIndex=0;
}
void Stack_Push(Stack_t *stack, STACK_DATA_TYPE Data)
{
  stack->StackArr[stack->LastIndex]=Data;
  stack->LastIndex++;
}
void Stack_Pop(Stack_t *stack)
{
  stack->LastIndex--;
}
void Stack_Top(Stack_t *stack, STACK_DATA_TYPE *Data)
{
  *Data= stack->StackArr[(stack->LastIndex)-1];
}
void Stack_GetSize(Stack_t *stack, STACK_DATA_TYPE *size)
{
  *size=stack->LastIndex;
}
void Stack_Traverse(Stack_t *stack, void (*ptr_func)(STACK_DATA_TYPE* x))
{
  STACK_DATA_TYPE i=0;
  for (i=0;i<(stack->LastIndex);i++)
  {
    (*ptr_func)(&stack->StackArr[i]);
  }
}
STACK_DATA_TYPE Is_Empty(Stack_t*stack)
{
	STACK_DATA_TYPE retVal;
	if (stack->LastIndex == 0)
	{
		retVal =  1;
	}
	else
		retVal = 0;
	return retVal;
}
STACK_DATA_TYPE Is_Full(Stack_t *stack)
{
	STACK_DATA_TYPE retVal;
	if ((stack->LastIndex)==(STACK_SIZE-1))
	{
		retVal =  1;
	}
	else
		retVal = 0;
	return retVal;
}
void Clear_Stack(Stack_t* stack)
{
	stack->LastIndex=0;
}
//*******************************************
//.c related stack linked
#elif STACK_TYPE == LINKED_STACK
void Stack_Init(Stack_t *stack)
{
	stack->pTop=NULL;
	stack->size=0;
}
void Stack_Push(Stack_t *stack, STACK_DATA_TYPE Data)
{
	Node_t*p =(Node_t*)malloc(sizeof(Node_t));
	p->Value=Data;
	p->pPrevNode=stack->pTop;
	stack->pTop=p;
	(stack->size)++;
}
void Stack_Top(Stack_t *stack, STACK_DATA_TYPE *TopVal)
{
	*TopVal=stack->pTop->Value;
}
void Stack_Pop(Stack_t *stack)
{
	Node_t*p=stack->pTop;
	stack->pTop=stack->pTop->pPrevNode;
	free(p);
	(stack->size)--;
}
STACK_DATA_TYPE Is_Full(Stack_t *stack)
{
	return 0;
}
STACK_DATA_TYPE Is_Empty(Stack_t*stack)
{
	return stack->pTop==NULL;
}
void Stack_Traverse(Stack_t *stack, void (*ptr_func)(STACK_DATA_TYPE* x))
{
	Node_t*p=stack->pTop;
	while (p)
	{
		(*ptr_func)(&p->Value);
		p=p->pPrevNode;
	}
}
void Stack_GetSize(Stack_t *stack, STACK_DATA_TYPE *size)
{
	*size = stack->size;
}
void Clear_Stack(Stack_t* stack)
{
	Node_t*p=stack->pTop;
	while (p)
	{
		p=p->pPrevNode;
		free(p);
		stack->pTop=p;
	}
}
#endif
