#ifndef SEVEN_H_
#define SEVEN_H_

#include "Types.h"
#include "../../mcal/GPIO/GPIO.h"

#define TOTAL_PINS 7


#define MAX_NUM 9


#define zero 0000001
#define one 1001111
#define two 0010010
#define three 0000110
#define four 1001100
#define five 0100100
#define six 0100000
#define seven 0001111
#define eight 0000000
#define nine 0000100
typedef struct 
{
    port_t port_number;
    pin_t pin_number;
   
}pin_info;

typedef struct 
{
 pin_info segment[TOTAL_PINS];  
}sevenSegment_t;

error_t SEVEN_SEGMENT_INIT(sevenSegment_t* seven_segment);
error_t SEVEN_SEGMENT_SET(sevenSegment_t * seven_segment,uint8_t number);
void SetNumber(sevenSegment_t * pSevenSeg,uint8_t number);
#endif /* SEVEN_H_ */