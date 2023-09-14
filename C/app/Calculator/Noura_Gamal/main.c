#include <util/delay.h>
#include "../../../common/Types.h"
#include "../../../common/Utils.h"
#include "Stack_Config.h"
#include "Stack.h"
#include "../../../hal/Keypad/Keypad_config_only_one.h"
#include "../../../hal/Keypad/Keypad_only_one.h"
#include "../../../hal/LCD/LCD_Interface.h"
#include "Calculator.h"

int main() {
    keypad_t keypad1;
    keypad1.Keypad_RowArr[0].port =kPORTA;
    keypad1.Keypad_RowArr[1].port =kPORTA;
    keypad1.Keypad_RowArr[2].port =kPORTA;
    keypad1.Keypad_RowArr[3].port =kPORTA;
    keypad1.Keypad_COLArr[0].port =kPORTA;
    keypad1.Keypad_COLArr[1].port =kPORTA;
    keypad1.Keypad_COLArr[2].port =kPORTA;
    keypad1.Keypad_COLArr[3].port =kPORTA;

    keypad1.Keypad_RowArr[0].pin =kPIN0;
    keypad1.Keypad_RowArr[1].pin =kPIN1;
    keypad1.Keypad_RowArr[2].pin =kPIN2;
    keypad1.Keypad_RowArr[3].pin =kPIN3;
    keypad1.Keypad_COLArr[0].pin =kPIN4;
    keypad1.Keypad_COLArr[1].pin =kPIN5;
    keypad1.Keypad_COLArr[2].pin =kPIN6;
    keypad1.Keypad_COLArr[3].pin =kPIN7;
   
    Keypad_Init(&keypad1);
    lcd_t lcd1 ={LCD_8Bit, kPORTC, kPORTD, kPIN0, kPIN1, kPIN2};
    LCD_Init(&lcd1);
    uint8_t key =0;
    Stack_t numStack,opStack;
    Stack_Init(&numStack);
    Stack_Init(&opStack);
    while (1)
    {
        do
        {
            key = Keypad_GetPressedButton(&keypad1);
        } while (key == NOT_PRESSED);
        Calculator(&opStack, &numStack, &lcd1, key);
    }
}