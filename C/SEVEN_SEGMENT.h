#ifndef SEVEN_H_
#define SEVEN_H_



#define TOTAL_PINS 7

#define segmentType COMMON_CATHODE
#define MAX_NUM 9

/*#if segmentType == COMMON_CATHODE
typedef enum  {
    kOFF,
    kON
}level_t;

#elif segmentType == COMMON_ANODE
typedef enum  {
    kON,
    kOFF
}level_t;
#endif*/

#define ZERO 0000001
#define ONE 1001111
#define TWO 0010010
#define THREE 0000110
#define FOUR 1001100
#define FIVE 0100100
#define SIX 0100000
#define SEVEN 0001111
#define EIGHT 0000000
#define NINE 0000100

typedef struct 
{
    port_t port_number;
    pin_t pin_number;
   
}sevenSegPin;

typedef struct 
{
 sevenSegPin segment[TOTAL_PINS];  
}sevenSegment_t;

error_t SEVEN_SEGMENT_INIT(sevenSegment_t* pSevenSeg);
error_t SEVEN_SEGMENT_SET(sevenSegment_t * pSevenSeg,uint8_t number);
void SetNumber(sevenSegment_t * pSevenSeg,uint8_t number);
#endif /* SEVEN_H_ */