#include <util/delay.h>
#include "common/Types.h"
#include "common/Utils.h"
#include "hal/DC_Motor/DC_Motor.h"
int main(void)
{

  DcMotor_t DcMotor={kPORTA, kPIN0, kPIN1};
  DcMotor_Init(&DcMotor);
  while (1)
  {
      DcMotor_ClockWise(&DcMotor);
      _delay_ms(2000);
      DcMotor_Stop(&DcMotor);
      _delay_ms(500);
      DcMotor_AntiClockWise(&DcMotor);
      _delay_ms(2000);
      DcMotor_Stop(&DcMotor);
      _delay_ms(500);
  }
}
