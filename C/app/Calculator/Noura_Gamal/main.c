#include <util/delay.h>
#include "../../../common/Types.h"
#include "../../../common/Utils.h"
/*#include "Stack_Config.h"
#include "Stack.h"*/
#include "../../../utils/stack/stack_macros.h"
#include "../../../utils/stack/stack.h"
#include "../../../hal/Keypad/Keypad_config_only_one.h"
#include "../../../hal/Keypad/Keypad_only_one.h"
#include "../../../hal/LCD/LCD_Interface.h"
#include "calc.h"

int main()
{
    keypad_t keypad;
    lcd_t lcd;
    KeypadConf(&keypad);
    LCDConf(&lcd);
    uint8_t key = 0;
    charStack_t opStack;
    sint32_tStack_t numStack;
    sint32_tStack_Init(&numStack);
    charStack_Init(&opStack);
    /*Stack_t numStack, opStack;
    Stack_Init(&numStack);
    Stack_Init(&opStack);*/
    while (1)
    {
        do
        {
            key = Keypad_GetPressedButton(&keypad);
        } while (key == NOT_PRESSED);
        Calculator(&opStack, &numStack, &lcd, key);
    }
}
