#ifndef SEG_H_
#define SEG_H_
//#include "Types.h"
//#include "../../mcal/GPIO/GPIO.h"

#define TOTAL_DECODER_PINS  4
#define MAX_NUM 9
typedef struct 
{
    port_t port_name;
    pin_t pin_name;
   
}sevenSegPin;

typedef struct 
{
 sevenSegPin segment[TOTAL_DECODER_PINS] ;  
}sevenSegDecoder_t;

error_t SEGMENT_DECODER_INIT(sevenSegDecoder_t * pSevenSeg);
error_t SEGMENT_DECODER_SET( sevenSegDecoder_t * pSevenSeg,uint8_t number);



#endif /* SEG_H_ */