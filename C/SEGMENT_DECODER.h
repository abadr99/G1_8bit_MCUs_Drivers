#ifndef LCD_H_
#define LCD_H_
#include "../../mcal/GPIO/GPIO.h"
#include "Types.h"

typedef struct 
{
    port_t port_name;
    pin_t pin_name;
   
}pin_info;

typedef struct 
{
 pin_info segment[4] ;  
}SEGMENT_DECODER;

error_t SEGMENT_DECODER_INIT(SEGMENT_DECODER * seven_segment);
error_t SEGMENT_DECODER_SET( SEGMENT_DECODER * seven_segment,uint8_t number);



#endif /* LCD_H_ */