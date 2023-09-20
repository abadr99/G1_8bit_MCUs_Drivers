#include "../Config.h"
#include "../Types.h"
#include "Stack.h"

void StackInit(Stack_t *stack)
{
  stack->lastIndex=0;
}
void StackPush(Stack_t *stack, void*Data)
{
  stack->StackArr[stack->lastIndex]=Data;
  stack->lastIndex++;
}
void StackPop(Stack_t *stack)
{
    stack->lastIndex--;
}
void* StackTop(Stack_t *stack)
{
    void*ptr=stack->StackArr[(stack->lastIndex)-1];
    return ptr;
}
void Stack_GetSize(Stack_t *stack, uint8_t*size)
{
    *size=stack->lastIndex;
}
uint8_t Is_Empty(Stack_t*stack)
{ uint8_t state=0;
  if (stack->lastIndex == 0)
  {
    state=1;
  }
  return state;
}
uint8_t Is_Full(Stack_t *stack)
{
 uint8_t state=0;
 if ((stack->lastIndex)==(STACK_SIZE-1))
{
 state=1;
}
  return state;
}
void Clear_Stack(Stack_t* stack)
{
    stack->lastIndex=0;
}
