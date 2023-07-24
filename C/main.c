#include <util/delay.h>
#include "common/Types.h"
#include "common/Utils.h"
#include "mcal/GPIO/GPIO.h"

int main() {
    
    GPIO_SetPinDirection(kPORTD , kPIN7 , kOutput); // 0
    while(1) {
        GPIO_SetPinValue(ORTD , kPIN7 , kHigh);
        _delay_ms(500);
        GPIO_SetPinValue(kPORTD , kPIN7 , kLow);
        _delay_ms(500);
    }
}