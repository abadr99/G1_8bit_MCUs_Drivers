#include "../../common/Types.h"
#include "../../mcal/GPIO/GPIO.h"
#include "PushButton.h"

void PushButton_Init(PushButton_t* pPB)
{
    GPIO_SetPinDirection(pPB->Port, pPB->Pin, pPB->State);
}

PressedState_t PushButton_GetValue(PushButton_t* pPB)
{
    state_t PinValue = 0;
  PressedState_t PressState = 0;
  if ((pPB->State == kIntPullUp)|| (pPB->State == kExtPullUp))
  {
    GPIO_GetPinValue(pPB->Port, pPB->Pin, &PinValue);
    PressState = PinValue == kHigh ? kNotPressed : kPressed;
  }
  else if (pPB->State == kPullDown)
  {
    GPIO_GetPinValue(pPB->Port, pPB->Pin, &PinValue);
    PressState = PinValue == kHigh ? kPressed : kNotPressed;
  }
  return PressState;
}
