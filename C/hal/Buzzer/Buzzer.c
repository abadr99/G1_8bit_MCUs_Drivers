#include "../../common/Types.h"
#include "../../mcal/GPIO/GPIO.h"
#include "Buzzer.h"

void Buzzer_Init(Buzzer_t* pBuzzer)
{
    GPIO_SetPinDirection(pBuzzer->Port,pBuzzer->Pin,kOutput);
}
error_t Buzzer_TurnOn(Buzzer_t* pBuzzer)
{
    error_t Ret_ErrorState = kNoError ;
    if(pBuzzer->ActiveState == kBuzzerActiveHigh)
    {
        GPIO_SetPinValue(pBuzzer->Port,pBuzzer->Pin,kHigh);
    }
    else if(pBuzzer->ActiveState == kBuzzerActiveLow)
    {
        GPIO_SetPinValue(pBuzzer->Port,pBuzzer->Pin,kLow);
    }
    else
    {
        Ret_ErrorState = kFunctioParameterError  ;
    }
    return Ret_ErrorState;
}
error_t Buzzer_TurnOff(Buzzer_t* pBuzzer)
{
    error_t Ret_ErrorState = kNoError ;
   if(pBuzzer->ActiveState == kBuzzerActiveHigh)
    {
        GPIO_SetPinValue(pBuzzer->Port,pBuzzer->Pin,kLow);
    }
    else if(pBuzzer->ActiveState == kBuzzerActiveLow)
    {
        GPIO_SetPinValue(pBuzzer->Port,pBuzzer->Pin,kHigh);
    } 
    else
    {
        Ret_ErrorState = kFunctioParameterError  ;
    }
    return Ret_ErrorState;
}