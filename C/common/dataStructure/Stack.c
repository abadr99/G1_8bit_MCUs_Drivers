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
void* StackPop(Stack_t *stack)
{
  void*ptr=stack->StackArr[(stack->lastIndex)-1];
    stack->lastIndex--;
  return ptr;
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
{
  return (stack->lastIndex == 0);
}
uint8_t Is_Full(Stack_t *stack)
{
  return ((stack->lastIndex) == (STACK_SIZE - 1));
}
void Clear_Stack(Stack_t* stack)
{
    stack->lastIndex=0;
}
