#include "../../common/Types.h"
#include "../../mcal/GPIO/GPIO.h"
#include "LED.h"

void LED_Init(LED_t* pLED)
{
    GPIO_SetPinDirection(pLED->Port,pLED->Pin,kOutput);
}
error_t LED_TurnOn(LED_t* pLED)
{
    error_t Ret_ErrorState = kNoError ;
    if(pLED->ActiveState == kLedActiveHigh)
    {
        GPIO_SetPinValue(pLED->Port,pLED->Pin,kHigh);
    }
    else if(pLED->ActiveState == kLedActiveLow)
    {
        GPIO_SetPinValue(pLED->Port,pLED->Pin,kLow);
    }
    else
    {
        Ret_ErrorState = kFunctioParameterError  ;
    }
    return Ret_ErrorState;
}
error_t LED_TurnOff(LED_t* pLED)
{
    error_t Ret_ErrorState = kNoError ;
   if(pLED->ActiveState == kLedActiveHigh)
    {
        GPIO_SetPinValue(pLED->Port,pLED->Pin,kLow);
    }
    else if(pLED->ActiveState == kLedActiveLow)
    {
        GPIO_SetPinValue(pLED->Port,pLED->Pin,kHigh);
    } 
    else
    {
        Ret_ErrorState = kFunctioParameterError  ;
    }
    return Ret_ErrorState;
}
