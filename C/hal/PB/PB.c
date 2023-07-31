#include "../../common/Types.h"
#include "../../mcal/GPIO/GPIO.h"
#include "PB.h"

void PB_Init(PB_t* pPB)
{
    GPIO_SetPinDirection(pPB->Port, pPB->Pin, pPB->State);
}

PressedState_t PB_GetPressed(PB_t* pPB)
{
    state_t LocPinValue = 0;
  PressedState_t LocPressState = 0;
  if ((pPB->State == kIntPullUp)|| (pPB->State == kExtPullUp))
  {
    GPIO_GetPinValue(pPB->Port, pPB->Pin, &LocPinValue);
    if (LocPinValue == kHigh)
    {
        LocPressState = kNotPressed;
    }
    else if (LocPinValue == kLow)
    {
        LocPressState = kPressed;
    }
  }
  else if (pPB->State == kPullDown)
  {
    GPIO_GetPinValue(pPB->Port, pPB->Pin, &LocPinValue);
    if (LocPinValue == kHigh)
    {
        LocPressState = kPressed;
    }
    else if (LocPinValue == kLow)
    {
        LocPressState = kNotPressed;
    }
  }
  return LocPressState;
}
