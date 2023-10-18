#include <util/delay.h>
#include "../../../common/Types.h"
#include "../../../common/Utils.h"
#include "../../../common/Config.h"
#include "../../../hal/LCD/LCD_Interface.h"
#include "../../../hal/Keypad/Keypad_config_only_one.h"
#include "../../../hal/Keypad/Keypad_only_one.h"
#include "Calculator.h"

int main()
{
    lcd_t lcd;
    keypad_t keyPad;
	APP_INIT(&lcd, &keyPad);
	while (1)
	{
		Run_Calculator(&lcd, &keyPad);
	}

}
