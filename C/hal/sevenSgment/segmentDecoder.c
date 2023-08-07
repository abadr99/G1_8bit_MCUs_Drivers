#include "segmentDecoder.h"
#include "Types.h"
#include "../../mcal/GPIO/GPIO.h"
error_t SegmentDecoderInit(sevenSegDecoder_t * pSevenSeg)
{
    error_t retErrorState = kNoError;
	/* Make sure that the sevenSegDecoder_t is  valid */
	if (pSevenSeg!= NULL)
{
        for (uint8_t i = 0 ; i < TOTAL_DECODER_PINS ; i++)
        {
           GPIO_SetPinDirection(pSevenSeg->segment[i].port,
           pSevenSeg->segment[i].pin, kOutput);
        }
}
    else
    {
        error_t retErrorState = kFunctionParameterError;
    }
    return retErrorState;

}
error_t SegmentDecoderSet( sevenSegDecoder_t* pSevenSeg, uint8_t number)
    {
    error_t retErrorState = kNoError;
/* Make sure that the sevenSegDecoder_t is  valid  and numbedr is in range*/
	if (pSevenSeg!= NULL && number<=MAX_NUM)
{
    for (uint8_t i =0;i<TOTAL_DECODER_PINS ;i++)
    {
         GPIO_SetPinValue(pSevenSeg->segment[0].port, pSevenSeg->segment[0].pin,
        GET_BIT(number, i));
    }
}
    else
    {
        error_t retErrorState = kFunctionParameterError;
    }
    return retErrorState;
    }
