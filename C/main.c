#include <util/delay.h>
#include "common/Types.h"
#include "common/Utils.h"
#include "hal/LED/LED.h"
#include "hal/PushButton/PushButton.h"
int main()
{

PushButton_t Switch ={kPORTA, kPIN0, kExtPullUp};
  LED_t LED1 ={kPORTB, kPIN0, kLedActiveHigh};
  LED_Init(&LED1);
  PushButton_Init(&Switch);
  while (1)
  {
    if (PushButton_GetValue(&Switch) == kPressed)
    {
      LED_TurnOn(&LED1);
      //_delay_ms(500);

    }
    else if (PushButton_GetValue(&Switch) == kNotPressed)
    {
      LED_TurnOff(&LED1);
      //_delay_ms(500);
    }

  }
}
