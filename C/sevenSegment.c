
#include "Types.h"
#include "Utils.h"
#include "../../mcal/GPIO/GPIO.h"
#include "sevenSegment.h" 
error_t SevenSegmentInit(sevenSegment_t * pSevenSeg)
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
error_t SevenSegmentSet(sevenSegment_t * pSevenSeg,uint8_t number)
{
    error_t Ret_ErrorState = kNoError ;
    if(pSevenSeg!= NULL && number<=MAX_NUM) 
	{
    switch (number)
    {
    
        case 0:SetNumber(pSevenSeg,ZERO);
        break;
        case 1:SetNumber(pSevenSeg,ONE);
        break;
        case 2:SetNumber(pSevenSeg,TWO);
        break;
        case 3:SetNumber(pSevenSeg,THREE);
        break;
        case 4:SetNumber(pSevenSeg,FOUR);
        break;
        case 5:SetNumber(pSevenSeg,FIVE);
        break;
        case 6:SetNumber(pSevenSeg,SIX);
        break;
        case 7:SetNumber(pSevenSeg,SEVEN);
        break;
        case 8:SetNumber(pSevenSeg,EIGHT);
        break;
        case 9:SetNumber(pSevenSeg,NINE);
        break;
    }}
    else
    {
        error_t Ret_ErrorState = kFunctioParameterError ;
    }
    return Ret_ErrorState;

}
void SetNumber(sevenSegment_t * pSevenSeg,uint8_t number)
{state_t state;
    for(uint8_t i =0;i<9;i++)
    {
        if (GET_BIT(number,i)==0) state=kLow;
        else state= kHigh;
        GPIO_SetPinValue(pSevenSeg->segment[i].port_number,pSevenSeg->segment[i].pin_number,state);
       
    }


}
