#include "SEGMENT_DECODER.h"
//#include "Types.h"

error_t SEGMENT_DECODER_INIT(sevenSegDecoder_t * pSevenSeg)
{
    error_t Ret_ErrorState = kNoError ;
	/* Make sure that the sevenSegDecoder_t is  valid */
	if(pSevenSeg!= NULL) 
	{
        for (int i = 0 ; i < TOTAL_DECODER_PINS ; i++) 
        {
           GPIO_SetPinDirection(pSevenSeg->segment[i].port_name,pSevenSeg->segment[i].pin_name,kOutput);
        }
    }
    else
    {
        error_t Ret_ErrorState = kFunctioParameterError ;
    }
    return Ret_ErrorState;

}
error_t SEGMENT_DECODER_SET( sevenSegDecoder_t* pSevenSeg,uint8_t number)
{
    error_t Ret_ErrorState = kNoError ;
	/* Make sure that the sevenSegDecoder_t is  valid  and numbedr is in range*/
	if(pSevenSeg!= NULL && number<=MAX_NUM) 
	{
        GPIO_SetPinValue(pSevenSeg->segment[0].port_name,pSevenSeg->segment[0].pin_name, number & 0x01);
        GPIO_SetPinValue(pSevenSeg->segment[1].port_name,pSevenSeg->segment[1].pin_name,(number >>1) & 0x01);
        GPIO_SetPinValue(pSevenSeg->segment[2].port_name,pSevenSeg->segment[2].pin_name,(number >>2) & 0x01);
        GPIO_SetPinValue(pSevenSeg->segment[3].port_name,pSevenSeg->segment[3].pin_name,(number >>3) & 0x01);
    }
    else
    {
        error_t Ret_ErrorState = kFunctioParameterError ;
    }
    return Ret_ErrorState;

}