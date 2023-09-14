#include "Stack.h"
#include "../../../common/Types.h"
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
STACK_DATA_TYPE Stack_Pop(Stack_t *stack)
{
  return stack->StackArr[stack->LastIndex--];
}
STACK_DATA_TYPE Stack_Top(Stack_t *stack)
{
  return stack->StackArr[(stack->LastIndex)-1];
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
	if (stack->LastIndex == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
STACK_DATA_TYPE Is_Full(Stack_t *stack)
{
	if ((stack->LastIndex)==(STACK_SIZE-1))
	{
		return 1;
	}
	else
	{
		return 0;
	}
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
STACK_DATA_TYPE Stack_Top(Stack_t *stack)
{
	return stack->pTop->Value;
}
STACK_DATA_TYPE Stack_Pop(Stack_t *stack)
{
    uint8_t temp = stack ->pTop->Value;
	Node_t*p=stack->pTop;
	stack->pTop=stack->pTop->pPrevNode;
	free(p);
	(stack->size)--;
    return temp;
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
