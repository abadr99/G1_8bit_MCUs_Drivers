#if MCU_TYPE == _AVR
#include <util/delay.h>
#endif
#include "common/Types.h"
#include "common/Utils.h"
#include "hal/LED/LED.h"
#include "hal/Buzzer/Buzzer.h"
void TEST_LedActiveHigh(LED_t *pLed);
void TEST_LedActiveLow(LED_t *pLed);

int main()
{
  LED_t redLed =  {kPORTD, kPIN0, kLedActiveHigh};
  LED_t greenLed = {kPORTD, kPIN1, kLedActiveLow};

  LED_Init(&redLed);
  LED_Init(&greenLed);
  while (1)
  {
    TEST_LedActiveHigh(&redLed);
    _delay_ms(1000);
    TEST_LedActiveLow(&greenLed);
  }
}
void TEST_LedActiveHigh(LED_t *pLed)
{
  LED_TurnOn(pLed);
  _delay_ms(1000);
  LED_TurnOff(pLed);
  _delay_ms(1000);
}
void TEST_LedActiveLow(LED_t *pLed)
{
  LED_TurnOn(pLed);
  _delay_ms(1000);
  LED_TurnOff(pLed);
  _delay_ms(5000);
}
