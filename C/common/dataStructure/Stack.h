#ifndef STACK_H
#define STACK_H

//typedef uint8_t STACK_DATA_TYPE;
#define STACK_SIZE (5)

typedef struct
{
  uint8_t lastIndex;
  void *StackArr[STACK_SIZE];
}Stack_t;

void StackInit(Stack_t *stack);
void StackPush(Stack_t *stack, void* Data);
void* StackPop(Stack_t *stack);
void* StackTop(Stack_t *stack );
uint8_t Is_Empty(Stack_t*stack);
void Stack_GetSize(Stack_t *stack, uint8_t*size);
uint8_t Is_Full(Stack_t *stack);
void Clear_Stack(Stack_t* stack);
#endif
