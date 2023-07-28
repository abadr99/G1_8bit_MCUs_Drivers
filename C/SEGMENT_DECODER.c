#include "SEGMENT_DECODER.h"
#include "Types.h"

error_t SEGMENT_DECODER_INIT(SEGMENT_DECODER * seven_segment)
{
    error_t Ret_ErrorState = kNoError ;
	/* Make sure that the seven_segment is  valid */
	if(seven_segment!= NULL) 
	{
        GPIO_SetPinDirection(seven_segment->segment[0].port_name,seven_segment->segment[0].pin_name,kOutput);
        GPIO_SetPinDirection(seven_segment->segment[1].port_name,seven_segment->segment[1].pin_name,kOutput);
        GPIO_SetPinDirection(seven_segment->segment[2].port_name,seven_segment->segment[2].pin_name,kOutput);
        GPIO_SetPinDirection(seven_segment->segment[3].port_name,seven_segment->segment[3].pin_name,kOutput);
    }
    else
    {
        error_t Ret_ErrorState = kFunctioParameterError ;
    }
    return Ret_ErrorState;

}
error_t SEGMENT_DECODER_SET( SEGMENT_DECODER * seven_segment,uint8_t number)
{
    error_t Ret_ErrorState = kNoError ;
	/* Make sure that the seven_segment is  valid  and numbedr is in range*/
	if(seven_segment != NULL && number<=9) 
	{
        GPIO_SetPinValue(seven_segment->segment[0].port_name,seven_segment->segment[0].pin_name, number & 0x01);
        GPIO_SetPinValue(seven_segment->segment[1].port_name,seven_segment->segment[1].pin_name,(number >>1) & 0x01);
        GPIO_SetPinValue(seven_segment->segment[2].port_name,seven_segment->segment[2].pin_name,(number >>2) & 0x01);
        GPIO_SetPinValue(seven_segment->segment[3].port_name,seven_segment->segment[3].pin_name,(number >>3) & 0x01);
    }
    else
    {
        error_t Ret_ErrorState = kFunctioParameterError ;
    }
    return Ret_ErrorState;

}