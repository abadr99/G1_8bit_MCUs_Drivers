#include <util/delay.h>
#include "Config.h"
#include "Types.h"
#include "mcal/GPIO/GPIO.h"

int main() {
    
    GPIO_SetPinDirection(kPORTB , kPIN0 , kOutput);
    while(1) {
        GPIO_SetPinValue(kPORTB , kPIN0 , kHigh);
        _delay_ms(500);
        GPIO_SetPinValue(kPORTB , kPIN0 , kLow);
        _delay_ms(500);
        
    }
}