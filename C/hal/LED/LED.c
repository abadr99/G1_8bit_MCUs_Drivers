#include "../../common/Types.h"
#include "../../mcal/GPIO/GPIO.h"
#include "LED.h"

void LED_Init(LED_t LED_Type)
{
    GPIO_SetPinDirection(LED_Type.Port,LED_Type.Pin,kOutput);
}
void LED_LedOn(LED_t LED_Type)
{
    if(LED_Type.ActiveState == LED_ACTIVE_HIGH)
    {
        GPIO_SetPinValue(LED_Type.Port,LED_Type.Pin,kHigh);
    }
    else if(LED_Type.ActiveState == LED_ACTIVE_LOW)
    {
        GPIO_SetPinValue(LED_Type.Port,LED_Type.Pin,kLow);
    }
}
void LED_LedOff(LED_t LED_Type)
{
   if(LED_Type.ActiveState == LED_ACTIVE_HIGH)
    {
        GPIO_SetPinValue(LED_Type.Port,LED_Type.Pin,kLow);
    }
    else if(LED_Type.ActiveState == LED_ACTIVE_LOW)
    {
        GPIO_SetPinValue(LED_Type.Port,LED_Type.Pin,kHigh);
    } 
}