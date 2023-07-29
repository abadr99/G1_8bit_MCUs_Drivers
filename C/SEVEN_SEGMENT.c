#include "SEVEN_SEGMENT.h"


error_t SEVEN_SEGMENT_INIT(sevenSegment_t * pSevenSeg)
{
    error_t Ret_ErrorState = kNoError ;
	/* Make sure that the sevenSegment_t is  valid */
	if(pSevenSeg!= NULL) 
	{
        for (int i = 0 ; i < TOTAL_PINS  ; i++) 
        {
           GPIO_SetPinDirection(pSevenSeg->segment[i].port_number,pSevenSeg->segment[i].pin_number,kOutput);
        }
    }
    else
    {
        error_t Ret_ErrorState = kFunctioParameterError ;
    }
    return Ret_ErrorState;

}
error_t SEVEN_SEGMENT_SET(sevenSegment_t * pSevenSeg,uint8_t number)
{
    error_t Ret_ErrorState = kNoError ;
    if(pSevenSeg!= NULL && number<=MAX_NUM) 
	{
    switch (number)
    {
    
        case 0:SetNumber(pSevenSeg,zero);
        break;
        case 1:SetNumber(pSevenSeg,one);
        break;
        case 2:SetNumber(pSevenSeg,two);
        break;
        case 3:SetNumber(pSevenSeg,three);
        break;
        case 4:SetNumber(pSevenSeg,four);
        break;
        case 5:SetNumber(pSevenSeg,five);
        break;
        case 6:SetNumber(pSevenSeg,six);
        break;
        case 7:SetNumber(pSevenSeg,seven);
        break;
        case 8:SetNumber(pSevenSeg,eight);
        break;
        case 9:SetNumber(pSevenSeg,nine);
        break;
    }
    else
    {
        error_t Ret_ErrorState = kFunctioParameterError ;
    }
    return Ret_ErrorState;

}
void SetNumber(sevenSegment_t * pSevenSeg,uint8_t number)
{
    int i=0;
while(number!=0)
{
GPIO_SetPinValue(pSevenSeg->segment[i].port_name,pSevenSeg->segment[i].pin_name, number %10);
i++;
number/=10;
}
}