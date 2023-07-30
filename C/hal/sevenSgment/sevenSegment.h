#ifndef SEVEN_H_
#define SEVEN_H_

#define TOTAL_PINS 7


#define MAX_NUM 9


#define ZERO 0x3F
#define ONE 0x06
#define TWO 0x5B
#define THREE 0x4F
#define FOUR 0x66
#define FIVE 0x6D
#define SIX 0x7D
#define SEVEN 0x07
#define EIGHT 0x7F
#define NINE 0x6F

typedef struct {
    port_t port_number;
    pin_t pin_number;
               }sevenSegPin_t;

typedef struct {
 sevenSegPin_t segment[TOTAL_PINS];
               }sevenSegment_t;

error_t SevenSegmentInit(sevenSegment_t* pSevenSeg);
error_t SevenSegmentSet(sevenSegment_t * pSevenSeg, uint8_t number);
void SetNumber(sevenSegment_t * pSevenSeg, uint8_t number);
#endif /* SEVEN_H_ */
