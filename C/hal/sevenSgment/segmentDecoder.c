#include "segmentDecoder.h"
#include "Types.h"
#include "../../mcal/GPIO/GPIO.h"
error_t SEGMENT_DECODER_INIT(sevenSegDecoder_t * pSevenSeg)
{
    error_t Ret_ErrorState = kNoError;
	/* Make sure that the sevenSegDecoder_t is  valid */
	if(pSevenSeg!= NULL) 
	{
        for (int i = 0 ; i < TOTAL_DECODER_PINS ; i++) 
        {
           GPIO_SetPinDirection(pSevenSeg->segment[i].port, pSevenSeg->segment[i].pin, kOutput);
        }
    }
    else
    {
        error_t Ret_ErrorState = kFunctioParameterError;
    }
    return Ret_ErrorState;

}
error_t SEGMENT_DECODER_SET( sevenSegDecoder_t* pSevenSeg, uint8_t number)
{
    error_t Ret_ErrorState = kNoError;
	/* Make sure that the sevenSegDecoder_t is  valid  and numbedr is in range*/
	if (pSevenSeg!= NULL && number<=MAX_NUM) 
	{
        GPIO_SetPinValue(pSevenSeg->segment[0].port, pSevenSeg->segment[0].pin, 
        number & 0x01);
        GPIO_SetPinValue(pSevenSeg->segment[1].port, pSevenSeg->segment[1].pin, 
        (number >>1) & 0x01);
        GPIO_SetPinValue(pSevenSeg->segment[2].port, pSevenSeg->segment[2].pin, 
        (number >>2) & 0x01);
        GPIO_SetPinValue(pSevenSeg->segment[3].port, pSevenSeg->segment[3].pin, 
        (number >>3) & 0x01);
    }
    else
    {
        error_t Ret_ErrorState = kFunctioParameterError;
    }
    return Ret_ErrorState;
}
