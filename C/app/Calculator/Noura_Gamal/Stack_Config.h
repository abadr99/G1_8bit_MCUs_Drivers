#ifndef STACK_CONFIG_H_
#define STACK_CONFIG_H_

#include "../../../common/Types.h"
#include <stdlib.h>
#include <stdint.h>

#define STACK_ARRAY    (3)
#define LINKED_STACK   (6)
//Data Type
/*
 * The following line is used to define Data type of the data
 * that will be inserted to the stack
 */
typedef uint8_t STACK_DATA_TYPE;

//Array Size
/*This line used to specify the maximum stack size*/
#define STACK_SIZE (5)
/*************************/
//Stack Type
/*
 * 1)STACK_ARRAY
 * 2)LINKED_STACK
 */
#define STACK_TYPE (LINKED_STACK)
#endif /* STACK_CONFIG_H_ */
