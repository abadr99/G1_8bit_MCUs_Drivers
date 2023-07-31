#include <util/delay.h>
#include "common/Types.h"
#include "common/Utils.h"
#include "hal/LED/LED.h"
#include "hal/PB/PB.h"
int main()
{

PB_t Switch ={kPORTA, kPIN0, kExtPullUp};
  LED_t LED1 ={kPORTB, kPIN0, kLedActiveHigh};
  LED_Init(&LED1);
  PB_Init(&Switch);
  while (1)
  {
    if (PB_GetPressed(&Switch) == kPressed)
    {
      LED_TurnOn(&LED1);
      //_delay_ms(500);

    }
    else if (PB_GetPressed(&Switch) == kNotPressed)
    {
      LED_TurnOff(&LED1);
      //_delay_ms(500);
    }

  }
}
