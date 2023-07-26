#include <util/delay.h>
#include "common/Types.h"
#include "common/Utils.h"
#include "hal/LED/LED.h"
int main() {
    
LED_t LED1={LED_PORTA,LED_PIN0,LED_ACTIVE_HIGH};
  LED_Init(LED1);
  while(1)
  {
    LED_LedOn(LED1);
    _delay_ms(500);
    LED_LedOff(LED1);
    _delay_ms(500);
  }
}