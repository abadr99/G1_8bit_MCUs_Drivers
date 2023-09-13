#ifndef CALC_H_
#define CALC_H_
#define OPERATOR_SIZE (5)
#define NUMBER_SIZE (6)
uint8_t ISNUM(uint8_t num);
uint8_t getPrecedence(uint8_t operator);
sint16 operatr(sint16 x,sint16 y,uint8_t operator);
#endif