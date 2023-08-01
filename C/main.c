#include <util/delay.h>
#include "common/Types.h"
#include "common/Utils.h"
#include "hal/Relay/Relay.h"
int main()
{
  Relay_t Relay1 = {kPORTA, kPIN0};
  Relay_Init(&Relay1);
  while (1)
  {
    Relay_TurnOn(&Relay1);
    //_delay_ms(2000);
    Relay_TurnOff(&Relay1);
    //_delay_ms(2000);
  }
  
}
