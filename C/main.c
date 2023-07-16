#include <util/delay.h>
#include "common/Config.h"
#include "common/Types.h"
#include "common/Utils.h"
#include "mcal/GPIO/GPIO.h"

int main() {
    
    GPIO_SetPinDirection(kPORTC , kPIN0 , kOutput);
    while(1) {
        GPIO_SetPinValue(kPORTC , kPIN0 , kHigh);
        _delay_ms(500);
        GPIO_SetPinValue(kPORTC , kPIN0 , kLow);
        _delay_ms(500);
        
    }
}