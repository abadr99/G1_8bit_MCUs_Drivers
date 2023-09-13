#include <util/delay.h>
#include "../../../common/Types.h"
#include "../../../common/Utils.h"
#include "Stack_Config.h"
#include "Stack.h"
#include "../../../hal/LCD/LCD_Interface.h"
#include "Calculator.h"
uint8_t num =0, num1=0, num2=0, op_char = 0;
void Calculator(Stack_t *opStack, Stack_t *numStack, lcd_t *lcd, uint8_t key)
{
     if ((key >= '0') && (key <= '9'))
        {
            LCD_SendChar(lcd, key);
            num = (num * 10) + (key -'0');
            Stack_Push(numStack, num);
            num =0;
        }
        else if ((key == '+') || (key == '-') || (key == '*') || (key == '/'))
        {
            LCD_SendChar(lcd, key);
            Stack_Push(opStack, key);
        }
        else if (key == '=')
        {
            while ((!Is_Empty(numStack)) && (!Is_Empty(opStack)))
            {
                num2 = Stack_Pop(numStack);
                num1 = Stack_Pop(numStack);
                op_char = Stack_Pop(opStack);
                switch (op_char)
                {
                    case '+':Stack_Push(numStack, (num1 + num2));break;
                    case '-':Stack_Push(numStack, (num1 - num2));break; //fix it 
                    case '/':Stack_Push(numStack, (num1 / num2));break;
                    case '*':Stack_Push(numStack, (num1 * num2));break;
                }
            }
            LCD_SetPosition(lcd, LCD_ROW_2, LCD_COL_1);
            LCD_SendNumber(lcd, Stack_Pop(numStack));
        }
        else if (key == 'C')
        {
            LCD_ClearScreen(lcd);
            key =0;
            num = 0, num1 = 0, num2 = 0;
            op_char = 0;
        }
}