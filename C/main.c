#include <util/delay.h>
#include "common/Types.h"
#include "common/Utils.h"
#include "hal/Buzzer/Buzzer.h"
int main() {
    
Buzzer_t Buzzer1={kPORTA,kPIN0,kBuzzerActiveHigh};
  Buzzer_Init(&Buzzer1);
  while(1)
  {
    Buzzer_TurnOn(&Buzzer1);
    _delay_ms(500);
    Buzzer_TurnOff(&Buzzer1);
    _delay_ms(500);
  }
}
