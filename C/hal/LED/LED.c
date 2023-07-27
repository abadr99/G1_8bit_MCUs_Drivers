#include "../../common/Types.h"
#include "../../mcal/GPIO/GPIO.h"
#include "LED.h"

void LED_Init(LED_t* pLED_Configration)
{
    GPIO_SetPinDirection(pLED_Configration->Port,pLED_Configration->Pin,kOutput);
}
error_t LED_TurnOn(LED_t* pLED_Configration)
{
    error_t Ret_ErrorState = kNoError ;
    if(pLED_Configration->ActiveState == kHigh)
    {
        GPIO_SetPinValue(pLED_Configration->Port,pLED_Configration->Pin,kHigh);
    }
    else if(pLED_Configration->ActiveState == kLow)
    {
        GPIO_SetPinValue(pLED_Configration->Port,pLED_Configration->Pin,kLow);
    }
    else
    {
        Ret_ErrorState = kFunctioParameterError  ;
    }
    return Ret_ErrorState;
}
error_t LED_TurnOff(LED_t* pLED_Configration)
{
    error_t Ret_ErrorState = kNoError ;
   if(pLED_Configration->ActiveState == kHigh)
    {
        GPIO_SetPinValue(pLED_Configration->Port,pLED_Configration->Pin,kLow);
    }
    else if(pLED_Configration->ActiveState == kLow)
    {
        GPIO_SetPinValue(pLED_Configration->Port,pLED_Configration->Pin,kHigh);
    } 
    else
    {
        Ret_ErrorState = kFunctioParameterError  ;
    }
    return Ret_ErrorState;
}