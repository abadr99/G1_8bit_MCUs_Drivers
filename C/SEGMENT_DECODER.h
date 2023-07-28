#ifndef SEG_H_
#define SEG_H_
#include "Types.h"
#include "../../mcal/GPIO/GPIO.h"
#define TOTAL_DECODER_PINS  4
#define MAX_NUM 9
typedef struct 
{
    port_t port_name;
    pin_t pin_name;
   
}pin_info;

typedef struct 
{
 pin_info segment[4] ;  
}sevenSegDecoder_t;

error_t SEGMENT_DECODER_INIT(sevenSegDecoder_t * seven_segment);
error_t SEGMENT_DECODER_SET( sevenSegDecoder_t * seven_segment,uint8_t number);



#endif /* SEG_H_ */