#include <util/delay.h>
#include "common/Types.h"
#include "common/Utils.h"
#include "hal/LED/LED.h"
int main() {
    
LED_t LED1={kPORTA,kPIN0,ActiveHigh};
  LED_Init(&LED1);
  while(1)
  {
    LED_TurnOn(&LED1);
    _delay_ms(500);
    LED_TurnOff(&LED1);
    _delay_ms(500);
  }
}